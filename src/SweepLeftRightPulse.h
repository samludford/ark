//
//  SweepLeftRightPulse.h
//  fero
//
//  Created by Sam Ludford on 09/08/2018.
//

#pragma once
#include "Pulsar.h"

class SweepLeftRightPulse : public Pulsar {
    
public:
    
    SweepLeftRightPulse();
    bool shouldPulseAt(int index);
    
};
