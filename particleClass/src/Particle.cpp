//
//  Particle.cpp
//  makeNewClass
//
//  Created by chris on 6/16/16.
//
//

#include "Particle.h"

Particle::Particle(){
    // this gets called when object is created
    //pos.set( ofRandom(1000), ofRandom(800) );
}

void Particle::setup(){
    
    // set random position
    pos.set( ofRandom(1000), ofRandom(800) );
    
    // set random color
    color = ofColor( ofRandom(255), ofRandom(255), ofRandom(255));
    
    // set some random  initial velocity
    vel.set(ofRandom(-5,5), ofRandom(-5,5));
}

void Particle::update(){
    
    //pos.x += ofRandom(-10,10);
    
    // make some gravity
    // vel.y += .01;
    
    // add velocity to position
    pos += vel;
    
    // add some damping to the velocity so slow down
    vel *= .99;
    
}

void Particle::draw(){
    ofSetColor(color);
    ofDrawCircle(pos.x,pos.y, 10,10);
}