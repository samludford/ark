#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "ofxPiMapper.h"
#include "TarotSource.h"
#include "VideoSource.h"
#include "SceneManager.h"

#include "ofxMaxim.h"
#include "MagnetManager.h"
#include "EmptyPulse.h"

class ofApp : public ofBaseApp {
	public:
		void setup();
		void update();
		void draw();
	
		void keyPressed(int key);
		void keyReleased(int key);
	
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseDragged(int x, int y, int button);

        // ofxPiMapper
        ofxPiMapper piMapper;
        ofImage dummyObjects;
        SceneManager sceneManager;
        TarotSource *tarotSource;
    
        // ofxMaxim (used in the MagnetManager for handling the timing of pulse patterns)
        void audioOut(float * output, int bufferSize, int nChannels);
        int  bufferSize;
        int  sampleRate;
    
        // magnet manager (class handling communication with the arduino)
        MagnetManager *magnetManager;
};
