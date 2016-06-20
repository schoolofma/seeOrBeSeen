#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // setup the receiver with the port to listen on
    
    // FaceOSC defaults to port 8338
    receiver.setup(8338);
    
    
    // TSPS defaults to port 12000
    // receiver.setup(12000); // tsps
    
    // set variable that is keeping our data
    pos.set(0,0);
}

//--------------------------------------------------------------
void ofApp::update(){

    // loop through all received messages
    while( receiver.hasWaitingMessages() ){
        
        // create an osc message object to copy the message into
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        // we want to look for /pose/position set from faceOSC
        // that has two float values being sent
        if( m.getAddress() == "/pose/position" ){
            pos.x = m.getArgAsFloat(0);
            pos.y = m.getArgAsFloat(1);
        }
        
        // TSPS receive
        /*
        if( m.getAddress() == "/TSPS/personUpdated/" ){
            int oid = m.getArgAsInt(0);
            float centerX = m.getArgAsFloat(3);
            float centerY = m.getArgAsFloat(4);
            if( oid == 0 ){
                // TSPS send data normalized 0 -1 so scale up to use
                pos.set(centerX*ofGetWidth(),centerY*ofGetHeight());
            }
        }*/
        
        // get the address of the message
        //ofLogNotice() << m.getAddress();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(pos.x,pos.y,10);
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
