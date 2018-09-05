//
//  RandomPulse.cpp
//  ark
//
//  Created by Sam Ludford on 05/09/2018.
//

#include "RandomPulse.h"
#include "ofMain.h"

//--------------------------------------------------------------
RandomPulse::RandomPulse() : Pulsar() {
    
}

//--------------------------------------------------------------
bool RandomPulse::shouldPulseAt(int index) {
    Pulsar::shouldPulseAt(index);
    float c = ofRandom(1);
    return c < 0.3;
}
