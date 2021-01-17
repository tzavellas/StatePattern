#include "State.hpp"
#include "GumballMachine.hpp"

State::State(GumballMachine* machine) : m_Machine(machine)
{
    // nothing to do
}

void State::setMachine(GumballMachine* machine)
{
    m_Machine = machine;
}

void State::refill()
{
    // nothing to do
}