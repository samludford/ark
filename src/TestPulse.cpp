//
//  TestPulse.cpp
//  fero
//
//  Created by Sam Ludford on 09/08/2018.
//

#include "TestPulse.h"

//--------------------------------------------------------------
TestPulse::TestPulse() : Pulsar() {
    
}

//--------------------------------------------------------------
bool TestPulse::shouldPulseAt(int index) {
    Pulsar::shouldPulseAt(index);
    return index == (frame % MATRIX_SIZE);
}
