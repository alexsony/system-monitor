#include "NetParser.hpp"

NetParser::NetParser(){
    storeData(m_oldNet);
}

Net NetParser::usage() {
    Net net;
    storeData(net);
    int rxBytes, txBytes;

    Net::iterator currentIterator = net.begin();
    Net::iterator oldIterator = m_oldNet.begin();

    while(currentIterator!= net.end() && oldIterator != m_oldNet.end()) {
        rxBytes = currentIterator->second.first; 
        txBytes = currentIterator->second.second;

        currentIterator->second.first -= oldIterator->second.first;
        currentIterator->second.second -= oldIterator->second.second;

        oldIterator->second.first = rxBytes;
        oldIterator->second.second = txBytes;

        currentIterator++;
        oldIterator++;
    }
    // for (const auto &entry: net) {
    //     std::cout << entry.first <<" " <<  entry.second.first <<"Kbs " << entry.second.second <<"Kbs"<<std::endl;
    // }
    return net;
}

bool NetParser::storeData(Net &net) {
    std::ifstream procNet("/proc/net/dev");
    if(!procNet) return false;
    std::string line;

    auto extractInterface = [&](){
        std::string interfaceName;
        int rxBytes, txBytes;        
        std::stringstream values(line);
        std::string value;

        values >> value;
        interfaceName = value.substr(0, value.find(":"));

        values >> value;
        rxBytes = std::stoi(value)/1024; //Kbs

        for(int i = 0;values >> value; ++i) if(i>6) break; 
        txBytes = std::stoi(value)/1024; //Kbs

        net.try_emplace(interfaceName, std::make_pair(rxBytes, txBytes));

    };

    //skip first 2 lines
    getline(procNet, line);
    getline(procNet, line);
    while(getline(procNet, line)) {
        // std::cout << line << std::endl;
        extractInterface();
    }
    return true;

}