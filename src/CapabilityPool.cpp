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
