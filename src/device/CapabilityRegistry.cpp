#include "CapabilityRegistry.hpp"
using namespace std;

list<string> CapabilityRegistry::listCapabilities()
{
    list<string> capabilityList;

    for (auto it = begin(); it != end(); ++it)
    {
        capabilityList.push_back((*it)->getName());
    }

    return capabilityList;
}

list<std::pair<string,string>> CapabilityRegistry::getAllReadings() {
    list<std::pair<string,string>> ret;
    for (auto it = begin(); it != end(); ++it)
    {
        ret.push_back( std::pair<string,string>((*it)->getName(),(*it)->getValue()));
    }
    return ret;
}
