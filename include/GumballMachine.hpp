#ifndef GUMBALLMACHINE_HPP
#define GUMBALLMACHINE_HPP

#include <memory>
#include <ostream>
#include "State.hpp"

class GumballMachine
{
public:
    GumballMachine(unsigned int count = 0);

    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void refill(unsigned int count = 10);
    void releaseBall();
    unsigned int getCount() const;
    std::unique_ptr< State > getSoldOutState();
    std::unique_ptr< State > getNoQuarterState();
    std::unique_ptr< State > getHasQuarterState();
    std::unique_ptr< State > getSoldState();
    std::unique_ptr< State > getWinnerState();
    friend std::ostream& operator<<(std::ostream& os, const GumballMachine& machine);
    
    void transitionTo(std::unique_ptr< State > state);  // State pattern member function
private:
    unsigned int m_Count;

    std::unique_ptr< State > m_State;
};

inline std::ostream& operator<<(std::ostream& os, const GumballMachine& machine)
{
    os << "Mighty Gumball, Inc.\nC++-enabled Standing Gumball Model #2004\n";
    os << "Inventory: " << machine.m_Count << " gumballs\n"; 
    os << machine.m_State->toString();
    return os;
}

#endif // GUMBALLMACHINE_HPP