#ifndef WINNERSTATE_HPP
#define WINNERSTATE_HPP

#include "State.hpp"

class WinnerState : public State
{
public:
    WinnerState(GumballMachine* machine = nullptr);
    ~WinnerState() = default;

    void insertQuarter() override;
    void ejectQuarter() override;
    bool turnCrank() override;
    void dispense() override;
    const std::string toString() const override;
};

#endif // WINNERSTATE_HPP