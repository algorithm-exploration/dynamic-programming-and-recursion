#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class CakeType
{
public:
    const unsigned int weight_;
    const unsigned int value_;

    CakeType(unsigned int weight = 0, unsigned int value = 0) :
        weight_(weight),
        value_(value)
    {
    }
};

unsigned long long maxDuffelBagValue(const std::vector<CakeType>& cakeTypes,
                                     unsigned int weightCapacity)
{
    // calculate the maximum value that we can carry
    

    return 0;
}
