#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // create single Particle object
    myParticle.setup();
    
    
    // make a ton of Particle objects and add to the vector
    for( int i = 0; i < 100; i++){
        
        Particle p;
        p.setup();
        allParticles.push_back( p );

        
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // loop through all particles and call update functon for each one
    for( int i = 0; i < allParticles.size(); i++){
        allParticles[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // loop through all items currently in the vector
    // and call each draw function for each one
    for( int i = 0; i < allParticles.size(); i++){
        allParticles[i].draw();
    }
    
    // draw single Particle object
    myParticle.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // add new Particle object to vector when key is pressed
    Particle p;
    p.setup();
    allParticles.push_back( p );
    
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
