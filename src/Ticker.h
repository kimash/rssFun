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
    void setup(ofVec2f pos_);
    void setText(string text_);
    void setColor(ofColor color_);
    void update();
    void draw();
    
    //animation functions
    void startAnim();
    
    //animations
    ofxAnimatableFloat moveAnim;
    ofxAnimatableFloat fadeAnim;
    
    float dt;
    
protected:
    ofColor color;
    string text;
    ofVec2f pos;
    ofTrueTypeFont chFont;
};

#endif /* defined(__rssFun__Ticker__) */
