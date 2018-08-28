//
//  Pulsar.h
//  fero
//
//  Created by Sam Ludford on 09/08/2018.
//

#pragma once

#include "PulsarDelegate.h"

#define MATRIX_COLUMNS 10
#define MATRIX_ROWS 4
#define MATRIX_SIZE (MATRIX_COLUMNS * MATRIX_ROWS)

class Pulsar {
    
public:
    
    Pulsar();
    
    /*
     *
     * This will always be called sequentially,
     * iterating over all magnets in the matrix
     *
     */
    virtual bool shouldPulseAt(int index);
    
    int rowFromIndex(int index);
    int columnFromIndex(int index);
    
    int frame;
    PulsarDelegate *delegate;
    
};
