#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}


/*

 ofPixels slitPixels;
 slitScan.readToPixels(slitPixels);
 
 ofPixels camPixels = cam.getPixels();
 
 int sltX = x % (int)slitScan.getWidth();
 int camX = cam.getWidth() / 2;
 x++;
 
 for( int y = 0; y < cam.getHeight(); y++){
 ofColor camPix = camPixels.getColor(camX, y);
 slitPixels.setColor(sltX, y, camPix);
 }
 
 
 slitScan.loadData(slitPixels);

*/