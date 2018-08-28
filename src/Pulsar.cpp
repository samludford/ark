//
//  Pulsar.cpp
//  fero
//
//  Created by Sam Ludford on 09/08/2018.
//

#include "Pulsar.h"

//--------------------------------------------------------------
Pulsar::Pulsar() {
    frame = -1;
}

//--------------------------------------------------------------
bool Pulsar::shouldPulseAt(int index) {
    
    // defines a new frame each time index called returns to zero
    if(index == 0) {
        frame++;
    }
    
    // this should be overidden in the subclass
}

//--------------------------------------------------------------
int Pulsar::rowFromIndex(int index) {
    return index / ( (int) MATRIX_COLUMNS);
}

//--------------------------------------------------------------
int Pulsar::columnFromIndex(int index) {
    return index % MATRIX_COLUMNS;
}
