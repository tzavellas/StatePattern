#include <iostream>
#include "GumballMachine.hpp"

int main(int, char**) {

    GumballMachine machine{5};

    std::cout << machine << std::endl;

    machine.insertQuarter();
    machine.turnCrank();

    std::cout << std::endl << machine << std::endl;

    machine.insertQuarter();
    machine.turnCrank();
    machine.insertQuarter();
    machine.turnCrank();

    std::cout << std::endl << machine << std::endl;

    machine.insertQuarter();
    machine.turnCrank();
    machine.insertQuarter();
    machine.turnCrank();

    std::cout << std::endl << machine << std::endl;
    machine.refill();

    std::cout << std::endl << machine << std::endl;

    return 0;
}