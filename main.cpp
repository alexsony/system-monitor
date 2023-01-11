#include <iostream>
#include <unistd.h>
#include <set>
#include <matplot/matplot.h>

#include "CPUParser.hpp"
#include "MemoryParser.hpp"
#include "NetParser.hpp"

using namespace matplot;

int main() {
    CpuParser cpuObject;
    MemoryParser memoryObject;
    NetParser  netObject;
    Net net;

    std::vector<int> Y;
    std::vector<int> cpu;
    int i = 0;

    auto h = figure();
    auto ax = h->current_axes();
    axis({0, 60, 0, 100});

    while(1) {
        if (i < 60) {
            Y.push_back(i);
            i++;
        } else {
            cpu.erase(cpu.begin());
        }
        
        cpu.push_back(cpuObject.usage());
        plot(ax, Y, cpu);
        sleep(1);
    }

    // while(1) {
    //     // net = netO.usage();
    //     // std::cout << cpu.name() << std::endl;
    //     // std::cout << "CPU: " << cpu.usage() << "%" << std::endl;
    //     // std::cout << "Memory:"<< memory.usage().first << "Mb of " << memory.total() << "Mb" << std::endl; 

    //     // for (const auto &entry: net) {
    //     //     std::cout << "Interface "<< entry.first <<": " <<  entry.second.first <<"Kbs " << entry.second.second <<"Kbs"<<std::endl;
    //     // }
    //     // std::cout << "------------------------------------" << std::endl;
    //     // sleep(1);
    // }
}