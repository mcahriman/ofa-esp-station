#include "CapabilityPool.hpp"
using namespace std;

CapabilityPool::CapabilityPool()
{
}

list<String> CapabilityPool::getCapabilityList()
{
    list<String> capabilityList;

    for (auto it = capabilities.begin(); it != capabilities.end(); ++it)
    {
        capabilityList.push_back((*it)->getName());
    }

    return capabilityList;
}

list<std::pair<String,String>> CapabilityPool::getAllResults() {
    list<std::pair<String,String>> ret;
    for (auto it = capabilities.begin(); it != capabilities.end(); ++it)
    {
        ret.push_back( std::pair<String,String>((*it)->getName(),(*it)->getValue()));
    }
    return ret;
}
