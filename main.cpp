#include <iostream>
#include <unistd.h>

#include "CPUParser.hpp"
#include "MemoryParser.hpp"

int main() {
    CpuParser cpu;
    MemoryParser memory;
    memory.display();
    // while(1) {
    //     std::cout << "CPU: " << cpu.display() << "%" << std::endl;
    //     sleep(1);
    // }
}