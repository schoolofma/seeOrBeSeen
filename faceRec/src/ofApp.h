#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "ofxCvFaceRec.h"
#include "face.h"
#include "ofxCvFaceRec.h"

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

		void saveScreen();
		void newPhoto(ofRectangle curFace, int label, int age);


		ofVideoGrabber 			vidGrabber;
        //ofxCvColorImage		colorImg;
		ofImage					colorImg;

        ofxCv::ObjectFinder 	finder;

		int 					threshold;
		unsigned long			frameCounter;
		bool					captured;
		std::map<int, face>		faces;
    
        ofxCvFaceRec rec;
    
};

