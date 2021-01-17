#include "HasQuarterState.hpp"
#include "GumballMachine.hpp"
#include <iostream>

HasQuarterState::HasQuarterState(GumballMachine* machine) : State(machine), m_IntGenerate(0,9)
{
    std::random_device rd;
    m_Gen = std::mt19937{rd()};
}

void HasQuarterState::insertQuarter()
{
    std::cout << "You can't insert another quarter\n";
}

void HasQuarterState::ejectQuarter()
{
    if (m_Machine)
    {
        m_Machine->transitionTo(m_Machine->getNoQuarterState());
        std::cout << "Quarter returned\n";
    }
    else
    {
        std::cerr << __func__ << std::endl;
    }
}

bool HasQuarterState::turnCrank()
{
    bool ret{false};
    if (m_Machine)
    {
        std::cout << "You turned...\n";
        int winner = m_IntGenerate(m_Gen);
        if ((0 == winner) && m_Machine->getCount() > 1)
        {
            m_Machine->transitionTo(m_Machine->getWinnerState());
        }
        else
        {
            m_Machine->transitionTo(m_Machine->getSoldState());
        }
        ret = true;
    }
    else
    {
        std::cerr << __func__ << std::endl;
    }
    return ret;
}

void HasQuarterState::dispense()
{
    std::cout << "No gumball dispensed\n";
}

const std::string HasQuarterState::toString() const
{
    return "Machine has quarter\n";
}