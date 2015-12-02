//
//  Ticker.h
//  rssFun
//
//  Created by Kim Ash on 12/2/15.
//
//

#ifndef __rssFun__Ticker__
#define __rssFun__Ticker__

#include <stdio.h>
#include "ofMain.h"
#include "ofxAnimatableFloat.h"

class Ticker {
public:
    void setup(ofVec2f pos_, const vector<string> &textItems_);
    void setText(string text_);
    void setColor(ofColor color_);
    void update();
    void draw();
    
    //animation functions
    void startAnim();
    
    //animations
    ofxAnimatableFloat moveAnim;
    ofxAnimatableFloat fadeAnim;
    
protected:
    string text;
    float dt;
    ofVec2f pos;
    ofColor color;
    ofTrueTypeFont chFont;
    
    const vector<string> *textItems;
};

#endif /* defined(__rssFun__Ticker__) */
