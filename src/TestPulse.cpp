//
//  TestPulse.cpp
//  fero
//
//  Created by Sam Ludford on 09/08/2018.
//

#include "TestPulse.h"
#include "ofMain.h"

//--------------------------------------------------------------
TestPulse::TestPulse() : Pulsar() {
    
}

//--------------------------------------------------------------
bool TestPulse::shouldPulseAt(int index) {
    Pulsar::shouldPulseAt(index);
//    return index == (frame % MATRIX_SIZE);
    
    float c = ofRandom(1);
    return c < 0.2;
//    return (index == 29);
}
