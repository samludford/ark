#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);

	ofx::piMapper::VideoSource::enableAudio = true;
	ofx::piMapper::VideoSource::useHDMIForAudio = false;
    
    tarotSource = new TarotSource();
    tarotSource->setup();
    tarotSource->setName("Tarot Source");
    piMapper.registerFboSource(tarotSource);
	piMapper.setup();
	
	ofSetFullscreen(Settings::instance()->getFullscreen());
	ofSetEscapeQuitsApp(false);

    dummyObjects.load("screen.png");

    sceneManager.setup("scenes.json", &piMapper);
    
    //ofxMaxim
    sampleRate = 44100;
    bufferSize = 512;
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4);
    
    // magentManager
    magnetManager = new MagnetManager();
    magnetManager->setPulse(new EmptyPulse());
    
}

void ofApp::update(){
	piMapper.update();
    sceneManager.update();
}

void ofApp::draw(){
    dummyObjects.draw(ofGetWidth()/2.0 - dummyObjects.getWidth()/2.0,ofGetHeight()/2.0 - dummyObjects.getHeight()/2.0);
    piMapper.draw();
}

void ofApp::keyPressed(int key){
    //press 5 to go to previous preset (scene)
    if (key=='5') {
        if (piMapper.getNumPresets()>1){
            int targetScene = piMapper.getActivePresetIndex() - 1;
            if (targetScene<0) targetScene = piMapper.getNumPresets()-1;
            piMapper.setPreset(targetScene);
            cout << "Switched to preset: " << piMapper.getActivePresetIndex() << endl;
        } else cout << "only one preset available" << endl;
    }
    //press 6 to go to next preset (scene)
    else if (key=='6') {
        if (piMapper.getNumPresets()>1){
            piMapper.setNextPreset();
            cout << "Switched to preset: " << piMapper.getActivePresetIndex() << endl;
        } else cout << "only one preset available" << endl;
    }
    else if (key == '7'){
        piMapper.cloneActivePreset();
        piMapper.setPreset(piMapper.getNumPresets()-1);
        cout << "Cloned and switched to preset: " << piMapper.getActivePresetIndex() << endl;
    }

	piMapper.keyPressed(key);
    
    if(key == ' ') {
        tarotSource -> shuffle();
    }
}

void ofApp::keyReleased(int key){
	piMapper.keyReleased(key);
}

void ofApp::mousePressed(int x, int y, int button){
	piMapper.mousePressed(x, y, button);
}

void ofApp::mouseReleased(int x, int y, int button){
	piMapper.mouseReleased(x, y, button);
}

void ofApp::mouseDragged(int x, int y, int button){
	piMapper.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    for (int i = 0; i < bufferSize; i++){
        magnetManager->audioLoop();
    }
}


