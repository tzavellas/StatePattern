#include "NoQuarterState.hpp"
#include "GumballMachine.hpp"
#include <iostream>

NoQuarterState::NoQuarterState(GumballMachine* machine) : State(machine)
{
    // nothing to do
}

void NoQuarterState::insertQuarter()
{
    if (m_Machine)
    {
        m_Machine->transitionTo(m_Machine->getHasQuarterState());
        std::cout << "You inserted a quarter\n";
    }
    else
    {
        std::cerr << __func__ << std::endl;
    }
}

void NoQuarterState::ejectQuarter()
{
    std::cout << "You haven't inserted a quarter\n";
}

bool NoQuarterState::turnCrank()
{
    std::cout << "You turned, but there's no quarter\n";
    return false;
}

void NoQuarterState::dispense()
{
    std::cout << "You need to pay first\n";
}

const std::string NoQuarterState::toString() const
{
    return "Machine is waiting for quarter\n";
}