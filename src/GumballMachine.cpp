#include "GumballMachine.hpp"
#include "SoldOutState.hpp"
#include "NoQuarterState.hpp"
#include "HasQuarterState.hpp"
#include "SoldState.hpp"
#include "WinnerState.hpp"
#include <iostream>

GumballMachine::GumballMachine(unsigned int count) : m_Count(count)
{
    if (count > 0)
    {
        m_State = std::make_unique< NoQuarterState >(this);
    }
    else
    {
        m_State = std::make_unique< SoldOutState >(this);
    }
}

void GumballMachine::insertQuarter()
{
    m_State->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
    m_State->ejectQuarter();
}

void GumballMachine::turnCrank()
{
    if (m_State->turnCrank())
    {
        m_State->dispense();
    }
}

void GumballMachine::refill(unsigned int count)
{
    if (m_State)
    {
        m_Count += count;
        std::cout << "Gumball machined refilled with " << count << " gumballs\n";
        m_State->refill();
    }
}

void GumballMachine::releaseBall()
{
    if (m_Count > 0)
    {
        m_Count--;
        std::cout << "A gumball comes rolling out the slot...\n";
    }
}

unsigned int GumballMachine::getCount() const
{
    return m_Count;
}

std::unique_ptr< State > GumballMachine::getSoldOutState()
{
    return std::make_unique< SoldOutState >(this);
}

std::unique_ptr< State > GumballMachine::getNoQuarterState()
{
    return std::make_unique< NoQuarterState >(this);
}

std::unique_ptr< State > GumballMachine::getHasQuarterState()
{
    return std::make_unique< HasQuarterState >(this);
}

std::unique_ptr< State > GumballMachine::getSoldState()
{
    return std::make_unique< SoldState >(this);
}

std::unique_ptr< State > GumballMachine::getWinnerState()
{
    return std::make_unique< WinnerState >(this);
}

void GumballMachine::transitionTo(std::unique_ptr< State > state)
{
    m_State.swap(state);
}