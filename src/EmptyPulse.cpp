//
//  EmptyPulse.cpp
//  fero
//
//  Created by Sam Ludford on 09/08/2018.
//

#include "EmptyPulse.h"
#include "ofMain.h"

//--------------------------------------------------------------
EmptyPulse::EmptyPulse() : Pulsar() {
    
}

//--------------------------------------------------------------
bool EmptyPulse::shouldPulseAt(int index) {
    Pulsar::shouldPulseAt(index);
    return false;
}
