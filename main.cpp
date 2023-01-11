#include <iostream>
#include <unistd.h>

#include "CPUParser.hpp"
#include "MemoryParser.hpp"
#include "NetParser.hpp"

int main() {
    CpuParser cpu;
    MemoryParser memory;
    NetParser  netO;
    Net net;
    while(1) {
        net = netO.usage();
        std::cout << cpu.name() << std::endl;
        std::cout << "CPU: " << cpu.usage() << "%" << std::endl;
        std::cout << "Memory:"<< memory.usage().first << "Mb of " << memory.total() << "Mb" << std::endl; 

        for (const auto &entry: net) {
            std::cout << "Interface "<< entry.first <<": " <<  entry.second.first <<"Kbs " << entry.second.second <<"Kbs"<<std::endl;
        }
        std::cout << "------------------------------------" << std::endl;
        sleep(1);
    }
}