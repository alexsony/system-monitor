#ifndef CPU_PARSER_HPP
#define CPU_PARSER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

class CpuParser final{
public:
    CpuParser();
    float usage();
    std::string name();
private:
    std::vector<size_t> storeData();
    bool getTime(size_t &, size_t &);
    size_t m_oldIdleTime;
    size_t m_oldTotalTime;
    std::string m_name;
};

#endif