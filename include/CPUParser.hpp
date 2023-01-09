#ifndef CPU_PARSER_HPP
#define CPU_PARSER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

class CpuParser final{
public:
    CpuParser();
    float display();
private:
    std::vector<size_t> storeData();
    bool getTime(size_t &, size_t &);
    size_t m_oldIdleTime;
    size_t m_oldTotalTime;
};

#endif