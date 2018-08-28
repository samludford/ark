//
//  EmptyPulse.h
//  fero
//
//  Created by Sam Ludford on 09/08/2018.
//

#pragma once

#include "Pulsar.h"

class EmptyPulse : public Pulsar {
    
public:
    
    EmptyPulse();
    bool shouldPulseAt(int index);
    
};
