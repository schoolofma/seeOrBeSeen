#pragma once

#include "ofMain.h"
#include "ofxOsc.h"


/*
 This example shows a sime receive of osc data from eiher FaceOsc or TSPS
 
FaceOsc
download: https://github.com/kylemcdonald/ofxFaceTracker/releases
osc protocol: https://github.com/kylemcdonald/ofxFaceTracker/wiki/Osc-message-specification
 
 TSPS
 download: http://www.tsps.cc/download/
 osc protocol: http://www.tsps.cc/docs/tsps-osc-protocol
 */

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        // declare an ofxOSc receiver object
        ofxOscReceiver receiver;
        ofPoint pos;    // variable to keep head position
    
		
};
