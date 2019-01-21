#include "CapabilityRegistry.hpp"
using namespace std;

CapabilityRegistry::CapabilityRegistry()
{
}

list<String> CapabilityRegistry::listCapabilities()
{
    list<String> capabilityList;

    for (auto it = begin(); it != end(); ++it)
    {
        capabilityList.push_back((*it)->getName());
    }

    return capabilityList;
}

list<std::pair<String,String>> CapabilityRegistry::getAllReadings() {
    list<std::pair<String,String>> ret;
    for (auto it = begin(); it != end(); ++it)
    {
        ret.push_back( std::pair<String,String>((*it)->getName(),(*it)->getValue()));
    }
    return ret;
}
