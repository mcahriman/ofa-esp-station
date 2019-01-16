#include <Arduino.h>
#include "ICapability.hpp"
#include <list>

using namespace std;

class CapabilityPool {
    public:
        CapabilityPool();
        list<String> getCapabilityList();
        
        void addCapability(ICapability* cap) {
            capabilities.push_back(cap);
        }

    private:
        list<ICapability*> capabilities;
};
