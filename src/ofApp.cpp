#include "ofApp.h"
#include <string>

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    ofHttpResponse rssFeed = ofSaveURLTo("http://www.npr.org/rss/rss.php?id=1057", "rssFeed.xml");
    rssXml.loadFromBuffer(ofBufferFromFile("rssFeed.xml"));
    rssXml.setTo("channel");
    
    int i = 0;
    string tagPath = "item[" + ofToString(i) + "]/title";

    while (rssXml.exists(tagPath)) {
        string currValue = rssXml.getValue(tagPath);
        
        //collect only titles in vector
        titles.push_back(currValue);
        cout << "added title: " << currValue << endl;
        
        i++;
        tagPath = "item[" + ofToString(i) + "]/title";
    }
    
    ticker.setup(ofVec2f(ofGetWidth(), ofRandom(30, ofGetHeight())), titles);
    ticker.startAnim();
}

//--------------------------------------------------------------
void ofApp::update(){
    ticker.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ticker.draw();
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
