//
//  TarotSource.h
//
//
//  Created by Sam Ludford on 28/08/2018.
//

#pragma once

#include "ofMain.h"
#include "FboSource.h"

#define VID_COUNT 18
#define SHUFFLE_LENGTH 120
#define SHUFFLE_INC 3

#define VID_WIDTH 1920
#define VID_HEIGHT 1080
#define PADDING 40

#define SCALE 1

class TarotSource : public ofx::piMapper::FboSource {
public:
    
    void setup();
    void update();
    void draw();
    void reset();
    void setName(string _name);
    void shuffle();
    
    ofVideoPlayer myPlayer1;
    ofVideoPlayer myPlayer2;
    ofVideoPlayer myPlayer3;
    
    vector<ofImage> frames;
    vector<ofVideoPlayer> players;
    int index1;
    int index2;
    int index3;
    
    int frameIndex1;
    int frameIndex2;
    int frameIndex3;
    
    void randomiseVids();
    
    bool isShuffling;
    int shuffleCounter;
    
};
