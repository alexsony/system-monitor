#include "CPUParser.hpp"

CpuParser::CpuParser() {
    m_oldIdleTime = 0;
    m_oldTotalTime = 0;
}

float CpuParser::display() {
    float utilization = 0;
    size_t idleTime, totalTime;
    if(getTime(idleTime, totalTime)) {
        const float idleTimeDelta = idleTime - m_oldIdleTime;
        const float totalTimeDelta = totalTime - m_oldTotalTime;
        utilization = 100.0 * (1.0 - idleTimeDelta / totalTimeDelta);
        m_oldIdleTime = idleTime;
        m_oldTotalTime = totalTime;
    }
    return utilization;
}

bool CpuParser::getTime(size_t &t_idleTime, size_t &t_totalTime) {
    const std::vector<size_t> times = storeData();
    if (times.size() < 4) return false;
    t_idleTime = times[3];
    t_totalTime = std::accumulate(times.begin(), times.end(), 0);
    return true;
}

std::vector<size_t> CpuParser::storeData() {
    std::ifstream proc_stat("/proc/stat");
    proc_stat.ignore(5, ' '); //ignore "cpu" prefix
    std::vector<size_t> times;
    for (size_t time; proc_stat >> time; times.push_back(time));
    return times;
}