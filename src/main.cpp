#include "ofMain.h"
#include "ofApp.h"
#include <string>
#include <vector>
#include "Settings.h"

int main(int argc, char * argv[]){
	bool fullscreen = false;

	vector<string> arguments = vector<string>(argv, argv + argc);
	for(int i = 0; i < arguments.size(); ++i){
		if(arguments.at(i) == "-f"){
			fullscreen = true;
			break;
		}
	}
	
//    Settings::instance()->setFullscreen(fullscreen);
//
//    ofSetupOpenGL(1000, 700, OF_FULLSCREEN);
//    ofRunApp(new ofApp());
    
        // setup for samsung tv
        ofGLFWWindowSettings settingsMain;
        settingsMain.width = 1920;   // LG monitor resolution
        settingsMain.height = 1080;
        settingsMain.setPosition(ofVec2f(-1920, 0));
        settingsMain.decorated = false;     // false = get rid of window border
        settingsMain.resizable = false; // false = fixed window
        shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settingsMain); // Draws window in ofApp.cpp
        shared_ptr<ofApp> mainApp(new ofApp);
        ofRunApp( mainWindow, mainApp );
        ofRunMainLoop();
}
