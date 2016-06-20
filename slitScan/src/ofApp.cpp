#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // initialize camera
    cam.setup(640,480);
    
    // allocate texture
    slitScan.allocate(ofGetWidth(),480,GL_RGB);
    
    // allocate and set initial pixels to black
    slitPixels.allocate(ofGetWidth(),480,OF_IMAGE_COLOR);
    for(int i = 0; i < ofGetWidth()*480*3; i++){
        slitPixels[i] = 0;
    }
    
    // update texture at start
    slitScan.loadData(slitPixels);
    
    // start x position at 0
    x = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    cam.update();
    
    if(cam.isFrameNew()){
        
        
        ofPixels camPixels = cam.getPixels();
        
        int sltX = x % (int)slitScan.getWidth();
        int camX = cam.getWidth() / 2;
        x++;
        
        for( int y = 0; y < cam.getHeight(); y++){
            ofColor camPix = camPixels.getColor(camX, y);
            slitPixels.setColor(sltX, y, camPix);
        }
        
        
        slitScan.loadData(slitPixels);
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    slitScan.draw(0,0);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
