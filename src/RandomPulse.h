//
//  RandomPulse.h
//  ark
//
//  Created by Sam Ludford on 05/09/2018.
//

#pragma once

#include "Pulsar.h"

class RandomPulse : public Pulsar {
    
public:
    
    RandomPulse();
    bool shouldPulseAt(int index);
    
};

