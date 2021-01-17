#include "WinnerState.hpp"
#include "GumballMachine.hpp"
#include <iostream>

WinnerState::WinnerState(GumballMachine* machine) : State(machine)
{
    // nothing to do
}

void WinnerState::insertQuarter()
{
    std::cout << "You can't insert another quarter\n";
}

void WinnerState::ejectQuarter()
{
    std::cout << "Quarter returned\n";
}

bool WinnerState::turnCrank()
{
    std::cout << "You turned...\n";
    return true;
}

void WinnerState::dispense()
{
    if (m_Machine)
    {
        m_Machine->releaseBall();
        if (0 == m_Machine->getCount())
        {
            m_Machine->transitionTo(m_Machine->getSoldOutState());
        }
        else
        {
            m_Machine->releaseBall();
            std::cout << "YOU'RE A WINNER! You got two gumballs for your quarter\n";
            if (m_Machine->getCount() > 0)
            {
                m_Machine->transitionTo(m_Machine->getNoQuarterState());
            }
            else
            {
                std::cout << "Oops, out of gumballs!\n";
                m_Machine->transitionTo(m_Machine->getSoldOutState());
            }
        }
    }
    else
    {
        std::cerr << __func__ << std::endl;
    }
}

const std::string WinnerState::toString() const
{
    return "--\n";
}