#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    theImage.load("creed_squares.jpeg"); //     Martin Creed Work No. 2762, 2016
    imagePixels = theImage.getPixels();
    
    numChannels = imagePixels.getNumChannels();
    
    outPixels.allocate(theImage.getWidth(), theImage.getHeight(), numChannels);
    
    
    numRows = theImage.getHeight();
    numCols = theImage.getWidth();
    
    skew = 0;
    
    myTexture.clear();
    
    bAtoms = false;
    
    numSteps = 7;
    ripSize = 1;
    
    step = TWO_PI/(numRows*numCols);
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    myTexture.clear();
    
    
   // step = TWO_PI/(numCols-2)*(numRows-2)*numSteps;
    
    float theta = 1.;
    
        for (int i=1; i<numRows-1; i++){
            for (int j=1; j<numCols-1; j++){
                
                int rowStride = i*numCols*3;
                
                if (rowStride+j*numChannels + skew*numChannels < numRows*numCols*3){
                
                outPixels[(rowStride)+(j*numChannels)]   = imagePixels[rowStride+(j*numChannels) + skew*numChannels];
                outPixels[(rowStride)+(j*numChannels)+1] = imagePixels[rowStride+(j*numChannels) + skew*numChannels+1];
                outPixels[(rowStride)+(j*numChannels)+2] = imagePixels[rowStride+(j*numChannels) + skew*numChannels+2];
                }
                               
                theta = fmod(theta, TWO_PI);
                
                if (bAtoms){
                    theta +=step;
                    step = floor(sin(theta)*numCols*numRows*numSteps);
                    skew *=2;
                }
                
                skew = floor(cos(theta)*ripSize);
                
                theta += 0.02 * numSteps;//step;
                
            }
            
        }
   

    myTexture.allocate(outPixels);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    ofDrawBitmapString(ofToString(*pIndex),50, 50);

    
    ofTranslate(ofGetWidth()*.5, ofGetHeight()*.5);
    
    myTexture.draw(0 - myTexture.getWidth()*.5, 0 - myTexture.getHeight()*.5);
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == OF_KEY_UP) numSteps++;
    if (key == OF_KEY_DOWN) numSteps--;
    
    if (key == ' ') bAtoms =! bAtoms;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    int width = ofGetWidth()*0.5;
    int pos = mouseX-width;
    
    ripSize = ofMap(pos,-width ,width, -20, 20, true );
//    cout << mouseX << ":" << xFact << endl;
    
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
