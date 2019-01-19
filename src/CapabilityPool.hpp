#include <Arduino.h>
#include "ICapability.hpp"
#include <list>
#include <utility>

using namespace std;

class CapabilityPool {
    public:
        CapabilityPool();
        list<String> getCapabilityList();
        list<std::pair<String,String>> getAllResults();
        
        void addCapability(ICapability* cap) {
            capabilities.push_back(cap);
        }

    private:
        list<ICapability*> capabilities;
};
