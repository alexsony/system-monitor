#include <iostream>
#include <unistd.h>

#include "CPUParser.hpp"
#include "MemoryParser.hpp"

int main() {
    CpuParser cpu;
    MemoryParser memory;
    while(1) {
        std::cout << cpu.name() << std::endl;
        std::cout << "CPU: " << cpu.usage() << "%" << std::endl;
        std::cout << memory.usage().first << "Mb of " << memory.total() << "Mb" << std::endl; 
        sleep(5);
    }
}