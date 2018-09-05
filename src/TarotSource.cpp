//
//  TarotSource.cpp
//
//
//  Created by Sam Ludford on 28/08/2018.
//

#include "TarotSource.h"

void TarotSource::setup(){
//    allocate(VID_WIDTH, VID_HEIGHT * 3);
    allocate(VID_HEIGHT * 3 + (PADDING * 3), VID_WIDTH);
    
//    ofBackground(0);
    cout << "setup" << endl;
    players.resize(VID_COUNT);
    frames.resize(VID_COUNT);
    for(int i=0 ; i < VID_COUNT ; i++) {
        players[i].load("videos/r" + ofToString(i+1) + ".mov");
        players[i].setVolume(0);
        players[i].setLoopState(OF_LOOP_NORMAL);
        frames[i].load("frames/r" + ofToString(i+1) + ".png");
    }

    randomiseVids();
}

void TarotSource::setName(string _name){
    cout << "name set: " << _name << endl;
    name = _name;
}

void TarotSource::reset(){

}

void TarotSource::shuffle() {
    isShuffling = true;
    randomiseVids();
}

void TarotSource::update(){

    players[index1].update();
    players[index2].update();
    players[index3].update();

    if(isShuffling) {

        if(shuffleCounter > SHUFFLE_LENGTH) {
            isShuffling = false;
            shuffleCounter = 0;
        } else {

            if(shuffleCounter % SHUFFLE_INC == 0) {

                vector<int> indices;
                for(int i=0 ; i<VID_COUNT ; i++) {
                    indices.push_back(i);
                }
                int i1 = floor(ofRandom(indices.size()));
                frameIndex1 = indices[i1];
                indices.erase(indices.begin() + i1);
                int i2 = floor(ofRandom(indices.size()));
                frameIndex2 = indices[i2];

                indices.erase(indices.begin() + i2);
                int i3 = floor(ofRandom(indices.size()));

                frameIndex3 = indices[i3];
            }

            shuffleCounter++;
        }

    }
}


void TarotSource::draw(){
    ofClear(0);
    ofPushMatrix();
    ofTranslate(fbo->getWidth()/2.0, fbo->getHeight()/2.0);
    ofRotate(90);
    ofTranslate(-fbo->getHeight()/2.0, -fbo->getWidth()/2.0);
    if(isShuffling) {
        frames[frameIndex1].draw(0, 0, VID_WIDTH*SCALE, VID_HEIGHT*SCALE);
        frames[frameIndex2].draw(0, VID_HEIGHT*SCALE + PADDING, VID_WIDTH*SCALE, VID_HEIGHT*SCALE);
        frames[frameIndex3].draw(0, VID_HEIGHT*2*SCALE + PADDING * 2, VID_WIDTH*SCALE, VID_HEIGHT*SCALE);
    } else {
        players[index1].draw(0, 0, VID_WIDTH*SCALE, VID_HEIGHT*SCALE);
        players[index2].draw(0, VID_HEIGHT*SCALE + PADDING, VID_WIDTH*SCALE, VID_HEIGHT*SCALE);
        players[index3].draw(0, VID_HEIGHT*2*SCALE + PADDING*2, VID_WIDTH*SCALE, VID_HEIGHT*SCALE);
    }

    ofPopMatrix();
}

//--------------------------------------------------------------
void TarotSource::randomiseVids() {
    
    // stop previous ones
    players[index1].stop();
    players[index2].stop();
    players[index3].stop();
    
    // set new indices
    vector<int> indices;
    for(int i=0 ; i<VID_COUNT ; i++) {
        indices.push_back(i);
    }
    int i1 = floor(ofRandom(indices.size()));
    
    index1 = indices[i1];
    
    indices.erase(indices.begin() + i1);
    int i2 = floor(ofRandom(indices.size()));
    
    index2 = indices[i2];
    
    indices.erase(indices.begin() + i2);
    int i3 = floor(ofRandom(indices.size()));
    
    index3 = indices[i3];
    
    // start new ones
    players[index1].play();
    players[index2].play();
    players[index3].play();
}

