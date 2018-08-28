//
//  SweepLeftRightPulse.cpp
//  fero
//
//  Created by Sam Ludford on 09/08/2018.
//

#include "SweepLeftRightPulse.h"

//--------------------------------------------------------------
SweepLeftRightPulse::SweepLeftRightPulse() : Pulsar() {
    
}

//--------------------------------------------------------------
bool SweepLeftRightPulse::shouldPulseAt(int index) {
    
    Pulsar::shouldPulseAt(index);
    
    int columnToPulse = frame % MATRIX_COLUMNS;
    
    int currentColumn = Pulsar::columnFromIndex(index);
    
    return columnToPulse == currentColumn;
}
