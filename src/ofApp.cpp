#include "ofApp.h"
#include <string>

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    chFont.load("CooperHewitt-Medium.ttf", 30);
    
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
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < titles.size(); i++) {
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        float x = ofGetWidth() - (ofGetFrameNum() % ofGetWidth());
        chFont.drawString(titles[i], x, (i * 40) + 40);
    }
    
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
