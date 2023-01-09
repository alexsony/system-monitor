#ifndef MEMORY_PARSER_HPP
#define MEMORY_PARSER_HPP

#include <iostream>
#include <utility>
#include <fstream>
#include <vector>
#include <string>

using Memory = std::pair<float, float>;

class MemoryParser final {
public:
    MemoryParser();
    float display();   
private:
    Memory storeData();
    float m_totalMemory;
};

#endif