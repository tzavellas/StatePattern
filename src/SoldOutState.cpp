#include "SoldOutState.hpp"
#include "GumballMachine.hpp"
#include <iostream>

SoldOutState::SoldOutState(GumballMachine* machine) : State(machine)
{
    // nothing to do
}

void SoldOutState::insertQuarter()
{
    std::cout << "You can't insert another quarter, the machines is sold out\n";
}

void SoldOutState::ejectQuarter()
{
    std::cout << "You can't eject, you haven't inserted a quarter yet\n";
}

bool SoldOutState::turnCrank()
{
    std::cout << "You turned, but there are no gumballs\n";
    return false;
}

void SoldOutState::dispense()
{
    std::cout << "No gumball dispensed\n";
}

void SoldOutState::refill()
{
    if (m_Machine)
    {
        m_Machine->transitionTo(m_Machine->getNoQuarterState());
    }
}

const std::string SoldOutState::toString() const
{
    return "Machine is sold out\n";
}