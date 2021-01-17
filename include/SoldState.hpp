#ifndef SOLDSTATE_HPP
#define SOLDSTATE_HPP

#include "State.hpp"

class SoldState : public State
{
public:
    SoldState(GumballMachine* machine = nullptr);
    ~SoldState() = default;
    
    void insertQuarter() override;
    void ejectQuarter() override;
    bool turnCrank() override;
    void dispense() override;
    const std::string toString() const override;
};

#endif // SOLDSTATE_HPP