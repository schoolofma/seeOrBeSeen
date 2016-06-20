#pragma once

#include "ofMain.h"
#include "Particle.h"

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
    
        // Particle is the class type and myParticle is the object we create from it
        // myParticle can have any other name we want but Particle must be Particle because
        // we named our class Particle :)
        Particle myParticle;
        
        // making lots of particles from our class
        // using c++ vector
        vector<Particle> allParticles;
		
};
