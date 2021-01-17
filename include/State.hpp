#ifndef STATE_HPP
#define STATE_HPP

#include <string>

class GumballMachine;

class State
{
public:
    virtual ~State() = default;
    void setMachine(GumballMachine* machine);
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual bool turnCrank() = 0;
    virtual void dispense() = 0;
    virtual void refill();
    virtual const std::string toString() const = 0;
protected:
    State(GumballMachine* machine = nullptr);
    
    GumballMachine* m_Machine;
};

#endif // STATE_HPP