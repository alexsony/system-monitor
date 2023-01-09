#include "MemoryParser.hpp"

MemoryParser::MemoryParser() {
    auto totalMemory = [&](){
        std::ifstream proc_mem("/proc/meminfo");
        proc_mem.ignore(10, ' ');
        proc_mem >> m_totalMemory;
        m_totalMemory /= 1024;
    };
    totalMemory();
}

Memory MemoryParser::usage() {
    return storeData();
}

float MemoryParser::total() {
    return m_totalMemory;
}

Memory MemoryParser::storeData() {
    std::ifstream proc_mem("/proc/meminfo");
    std::string line;
    float freeMemory;
    Memory memory;

    if (proc_mem.good()) {
        getline(proc_mem, line);
        proc_mem.ignore(10, ' ');
        proc_mem >> freeMemory;
        freeMemory /= 1024;
        memory = std::make_pair(freeMemory, m_totalMemory - freeMemory);
    }
    return memory;
}