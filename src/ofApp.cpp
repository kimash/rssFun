#include "ofApp.h"
#include <string>

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofHttpResponse rssFeed = ofSaveURLTo("http://www.npr.org/rss/rss.php?id=1057", "rssFeed.xml");
    rssXml.loadFromBuffer(ofBufferFromFile("rssFeed.xml"));
    rssXml.setTo("channel/item[0]/title");
    cout << rssXml.getValue() << endl;
    
    int i = 0;
    while (rssXml.exists("channel/item[" + ofToString(i) + "]/title")) {
        string currValue = rssXml.getValue();
        cout << currValue << endl;
        
        //collect only titles in vector
        titles.push_back(currValue);
        cout << "added title: " << currValue << endl;
        
        rssXml.setToSibling(); //get next item in tree
        i++;
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
