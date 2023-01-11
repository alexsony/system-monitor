#ifndef NET_PARSER_HPP
#define NET_PARSER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using Net = std::map<std::string, std::pair<int, int>>;

class NetParser final {
public:
    NetParser();
    Net usage();
private:
    Net m_oldNet;
    bool storeData(Net &);
};

#endif