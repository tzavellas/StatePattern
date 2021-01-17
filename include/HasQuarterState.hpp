#ifndef HASQUARTERSTATE_HPP
#define HASQUARTERSTATE_HPP

#include <random>
#include "State.hpp"

class HasQuarterState : public State
{
public:
    HasQuarterState(GumballMachine* machine = nullptr);
    ~HasQuarterState() = default;
    
    void insertQuarter() override;
    void ejectQuarter() override;
    bool turnCrank() override;
    void dispense() override;
    const std::string toString() const override;
private:
    std::mt19937 m_Gen;
    std::uniform_int_distribution<> m_IntGenerate;
};

#endif // HASQUARTERSTATE_HPP