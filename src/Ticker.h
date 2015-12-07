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
    void setup(ofVec2f pos_, float fontSize_, const vector<string> &textEntries_);
    void setText(string text_);
    void setColor(ofColor color_);
    void setPos(ofVec2f pos_);
    void update();
    void draw();
    
    void startAnim();
    
    //animation callback - prompt for changing ticker entry
    void onAnimFinished(ofxAnimatable::AnimationEvent& animEvent);
    
    //animations
    ofxAnimatableFloat moveAnim;
    ofxAnimatableFloat fadeAnim;
    
protected:
    string text;
    float dt;
    float fontSize;
    ofVec2f pos;
    ofColor color;
    ofTrueTypeFont chFont;
    
    const vector<string> *textEntries;
    int entryIndex;
};

#endif /* defined(__rssFun__Ticker__) */
