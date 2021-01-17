#ifndef NOQUARTERSTATE_HPP
#define NOQUARTERSTATE_HPP

#include "State.hpp"

class NoQuarterState : public State
{
public:
    NoQuarterState(GumballMachine* machine = nullptr);
    ~NoQuarterState() = default;
    
    void insertQuarter() override;
    void ejectQuarter() override;
    bool turnCrank() override;
    void dispense() override;
    const std::string toString() const override;
};

#endif // NOQUARTERSTATE_HPP