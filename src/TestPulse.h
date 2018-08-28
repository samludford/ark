//
//  TestPulse.h
//  fero
//
//  Created by Sam Ludford on 09/08/2018.
//

#pragma once

#include "Pulsar.h"

class TestPulse : public Pulsar {
    
public:
    
    TestPulse();
    bool shouldPulseAt(int index);
    
};
