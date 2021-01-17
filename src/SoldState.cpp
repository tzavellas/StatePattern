#include "SoldState.hpp"
#include "GumballMachine.hpp"
#include <iostream>

SoldState::SoldState(GumballMachine* machine) : State(machine)
{
    // nothing to do
}

void SoldState::insertQuarter()
{
    std::cout << "Please wait, we're already giving you a gumball\n";
}

void SoldState::ejectQuarter()
{
    std::cout << "Sorry, you already turned the crank\n";
}

bool SoldState::turnCrank()
{
    std::cout << "Turning twice doesn't get you another gumball!\n";
    return false;
}

void SoldState::dispense()
{
    if (m_Machine)
    {
        m_Machine->releaseBall();
        if (0 == m_Machine->getCount())
        {
            std::cout << "Oops, out of gumballs!\n";
            m_Machine->transitionTo(m_Machine->getSoldOutState());
        }
        else
        {
            m_Machine->transitionTo(m_Machine->getNoQuarterState());
        }
    }
    else
    {
        std::cerr << __func__ << std::endl;
    }
}

const std::string SoldState::toString() const
{
    return "Gumball sold\n";
}