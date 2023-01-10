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
    std::vector<int> storeData();
    bool getTime(int &, int &);
    int m_oldIdleTime;
    int m_oldTotalTime;
    std::string m_name;
};

#endif