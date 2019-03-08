#include "CapabilityRegistry.hpp"
using namespace std;

void CapabilityRegistry::registerCapability( ICapability* capability ) {
    capabilities.push_back(shared_ptr<ICapability>(capability));
};

list<String> CapabilityRegistry::listCapabilities()
{
    list<String> capabilityList;
    for (auto it = capabilities.begin(); it != capabilities.end(); ++it)
    {
        capabilityList.push_back((*it)->getName());
    }

    return capabilityList;
}

list<std::pair<String,String>> CapabilityRegistry::getAllReadings() {
    list<std::pair<String,String>> ret;
    for (auto it = capabilities.begin(); it != capabilities.end(); ++it)
    {
        ret.push_back( std::pair<String,String>((*it)->getName(),(*it)->getValue()));
    }
    return ret;
}

list<std::pair<String,String>> CapabilityRegistry::getReadingsByType(ICapabilityType capabilityType) {
    list<std::pair<String,String>> ret;
    for (auto it = capabilities.begin(); it != capabilities.end(); ++it)
    {
        if((*it)->getCapabilityType() == capabilityType) {
            ret.push_back( std::pair<String,String>((*it)->getName(),(*it)->getValue()));
        }
    }
    return ret;
}
