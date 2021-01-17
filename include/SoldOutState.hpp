#ifndef SOLDOUTSTATE_HPP
#define SOLDOUTSTATE_HPP

#include "State.hpp"

class SoldOutState : public State
{
public:
    SoldOutState(GumballMachine* machine = nullptr);
    ~SoldOutState() = default;

    void insertQuarter() override;
    void ejectQuarter() override;
    bool turnCrank() override;
    void dispense() override;
    void refill() override;
    const std::string toString() const override;
};

#endif // SOLDOUTSTATE_HPP