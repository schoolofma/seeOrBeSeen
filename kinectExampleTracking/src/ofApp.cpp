#include "ofApp.h"



using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup() {
	
    ofSetLogLevel(OF_LOG_VERBOSE);
	
	
    // --------- KINECT AND TRACKING SETUP
    // enable depth->video image calibration
	kinect.setRegistration(true);
    
	kinect.init();
	//kinect.init(false, false); // disable video image (faster fps)
	kinect.open();		// opens first available kinect
	
	colorImg.allocate(kinect.width, kinect.height);
	grayImage.allocate(kinect.width, kinect.height);
	grayThreshNear.allocate(kinect.width, kinect.height);
	grayThreshFar.allocate(kinect.width, kinect.height);
		
	// zero the tilt on startup
	angle = 0;
	kinect.setCameraTiltAngle(angle);
    // -----------
    
    
    contourFinder.setMinAreaRadius(1);
    contourFinder.setMaxAreaRadius(3000);
    contourFinder.setThreshold(100);
    //contourFinder.getTracker().setSmoothingRate(.8);

    // wait for half a frame before forgetting something
    contourFinder.getTracker().setPersistence(15);
    // an object can move up to 32 pixels per frame
    contourFinder.getTracker().setMaximumDistance(32);
    
    
    //------- gui
    gui.setup("panel"); // most of the time you don't need a name but don't forget to call setup
    gui.setPosition(10, 500);
    gui.add(nearThreshold.set("near", 255,0,255));
    gui.add(farThreshold.set("far", 200,0,255));

	
	
}

//--------------------------------------------------------------
void ofApp::update() {
	
	ofBackground(100, 100, 100);
	
	// --------- KINECT AND TRACKING
    kinect.update();
	
	// there is a new frame and we are connected
	if(kinect.isFrameNew()) {
		
		// load grayscale depth image from the kinect source
		grayImage.setFromPixels(kinect.getDepthPixels());
		
		grayThreshNear = grayImage;
        grayThreshFar = grayImage;
        grayThreshNear.threshold(nearThreshold, true);
        grayThreshFar.threshold(farThreshold);
        cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
		
        grayImage.flagImageChanged();
        
        grayImage.dilate();
        grayImage.blurGaussian();
        contourFinder.findContours(grayImage);
		
		
	}
    // ---------
    
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	ofSetColor(255, 255, 255);

    // draw from the live kinect
    // kinect.drawDepth(0,0);//10, 10, 400, 300);
    //kinect.draw(420, 10, 400, 300);
		
    grayImage.draw(0,0);//10, 320, 400, 300);
    
    contourFinder.draw();
    
    RectTracker& tracker = contourFinder.getTracker();

    ofSetColor(255, 0, 255);
    for(int i = 0; i < contourFinder.size(); i++) {
        int label = contourFinder.getLabel(i);
        float smoothX = tracker.getSmoothed(label).x + tracker.getSmoothed(label).width*.5;
        float smoothY = tracker.getSmoothed(label).y + tracker.getSmoothed(label).height*.5;
        ofDrawCircle(smoothX,smoothY,4);

        ofPushMatrix();
        ofTranslate(contourFinder.getCenter(i).x, contourFinder.getCenter(i).y);
        string msg = ofToString(label) + ":" + ofToString(tracker.getAge(label));
        ofDrawBitmapString(msg, 0, 0);
        ofPopMatrix();
    }
    
    
    gui.draw();
    
}



//--------------------------------------------------------------
void ofApp::exit() {
	kinect.setCameraTiltAngle(0); // zero the tilt on exit
	kinect.close();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed (int key) {
	switch (key) {
		case '>':
		case '.':
			farThreshold ++;
			if (farThreshold > 255) farThreshold = 255;
			break;
			
		case '<':
		case ',':
			farThreshold --;
			if (farThreshold < 0) farThreshold = 0;
			break;
			
		case '+':
		case '=':
			nearThreshold ++;
			if (nearThreshold > 255) nearThreshold = 255;
			break;
			
		case '-':
			nearThreshold --;
			if (nearThreshold < 0) nearThreshold = 0;
			break;
			
		case 'w':
			kinect.enableDepthNearValueWhite(!kinect.isDepthNearValueWhite());
			break;
			
		case 'o':
			kinect.setCameraTiltAngle(angle); // go back to prev tilt
			kinect.open();
			break;
			
		case 'c':
			kinect.setCameraTiltAngle(0); // zero the tilt
			kinect.close();
			break;
			
		case '1':
			kinect.setLed(ofxKinect::LED_GREEN);
			break;
			
		case '2':
			kinect.setLed(ofxKinect::LED_YELLOW);
			break;
			
		case '3':
			kinect.setLed(ofxKinect::LED_RED);
			break;
			
		case '4':
			kinect.setLed(ofxKinect::LED_BLINK_GREEN);
			break;
			
		case '5':
			kinect.setLed(ofxKinect::LED_BLINK_YELLOW_RED);
			break;
			
		case '0':
			kinect.setLed(ofxKinect::LED_OFF);
			break;
			
		case OF_KEY_UP:
			angle++;
			if(angle>30) angle=30;
			kinect.setCameraTiltAngle(angle);
			break;
			
		case OF_KEY_DOWN:
			angle--;
			if(angle<-30) angle=-30;
			kinect.setCameraTiltAngle(angle);
			break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}