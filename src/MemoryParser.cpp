#include "MemoryParser.hpp"

MemoryParser::MemoryParser() {
    std::invoke([&](){
        std::ifstream procMem("/proc/meminfo");
        procMem.ignore(10, ' ');
        procMem >> m_totalMemory;
        m_totalMemory /= 1024;
    });
}

Memory MemoryParser::usage() {
    return storeData();
}

float MemoryParser::total() {
    return m_totalMemory;
}

Memory MemoryParser::storeData() {
    std::ifstream procMem("/proc/meminfo");
    std::string line;
    float freeMemory;
    Memory memory;

    if (procMem.good()) {
        getline(procMem, line);
        procMem.ignore(10, ' ');
        procMem >> freeMemory;
        freeMemory /= 1024;
        memory = std::make_pair(freeMemory, m_totalMemory - freeMemory);
    }
    return memory;
}