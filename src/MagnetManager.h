//
//  MagnetManager.hpp
//  morphogenetic-feedback
//
//  Created by Sam Ludford on 18/04/2018.
//

#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "Pulsar.h"

#define ARDUINO_UNO_TTY "tty.usbmodem1421"
#define NUM_MAGNETS 40

class MagnetManager {
    
public:
    
    MagnetManager();
    void audioLoop();
    void update();
    void setPulse(Pulsar *pulse);
    
    
protected:
    
    // Arduino
    ofArduino ard;
    bool bSetupArduino;
    void setupArduino(const int & version);
    bool motorState;
    int magnetPins[NUM_MAGNETS];
    bool magnetStates[NUM_MAGNETS];
    
    // Maximilian
    float tempo;
    maxiClock clock;
    int counter;
    
    Pulsar *pulse;
    
};
