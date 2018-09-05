//
//  MagnetManager.cpp
//  morphogenetic-feedback
//
//  Created by Sam Ludford on 18/04/2018.
//

#include "MagnetManager.h"

/*
 Code used for communicating with the Arduino in this class follows the openFrameworks Firmata example:
 https://github.com/openframeworks/openFrameworks/tree/master/examples/communication/firmataExample
*/


//--------------------------------------------------------------
MagnetManager::MagnetManager() {
    
//     establish connection with arduino (via Firmata)
    ard.connect(ARDUINO_UNO_TTY, 57600);
    ofAddListener(ard.EInitialized, this, &MagnetManager::setupArduino);    // setupArduino called once connection made
    bSetupArduino    = false;
    
//     initialise the clocks, counters, magnet pin numbers,
    tempo = 100.0;
    counter = 0;
    clock.setTempo(tempo);
    clock.setTicksPerBeat(4);

    for(int i=0 ; i < NUM_MAGNETS ; i++) {
        magnetPins[i] = i + 2;
    }
    
}


//--------------------------------------------------------------
void MagnetManager::audioLoop() {
    
    // don't do anything until arduino setup complete
    if( !bSetupArduino ) return;

    clock.ticker();
    if(clock.tick) {

        for(int i=0 ; i < NUM_MAGNETS ; i++) {
            
            if(counter == 0) {
                bool p = pulse->shouldPulseAt(i);
                magnetStates[i] = p;
                if(p) ard.sendDigital(magnetPins[i], ARD_HIGH);
            } else if (counter == 1 && magnetStates[i]) {
                ard.sendDigital(magnetPins[i], ARD_LOW);
            }

        }

        counter++;
        if(counter==4) counter = 0;

    }
    
}

//--------------------------------------------------------------
void MagnetManager::update() {
    ard.update();
}

//--------------------------------------------------------------
void MagnetManager::setPulse(Pulsar *pulse) {
    this->pulse = pulse;
}

//--------------------------------------------------------------
void MagnetManager::setupArduino(const int & version) {
    
    // uses tutorial :
    cout << "setup arduino" << endl;
    // remove listener because we don't need it anymore
    ofRemoveListener(ard.EInitialized, this, &MagnetManager::setupArduino);

    // it is now safe to send commands to the Arduino
    bSetupArduino = true;

    // print firmware name and version to the console
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();

    // set magnet pins as outputs
    for(int i=0 ; i < NUM_MAGNETS ; i++) {
        ard.sendDigitalPinMode(magnetPins[i], ARD_OUTPUT);
    }
}
