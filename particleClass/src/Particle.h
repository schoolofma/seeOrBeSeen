//
//  Particle.h
//  particleClass
//
//  Created by chris on 6/20/16.
//
//

#ifndef Particle_h
#define Particle_h

#include "ofMain.h"

class Particle{
public:
    
    Particle(); // constructor
    //~Particle();    // destructor, we dont' need but would be called when object destroyed
    
    void setup();
    void update();
    void draw();
    
    ofPoint pos;
    ofVec2f vel;
    ofColor color;
    
};

#endif /* Particle_h */
