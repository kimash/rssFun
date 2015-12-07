//
//  Ticker.cpp
//  rssFun
//
//  Created by Kim Ash on 12/2/15.
//
//

#include "Ticker.h"

void Ticker::setup(ofVec2f pos_, float fontSize_, const vector<string> &textEntries_)
{
    pos = pos_;
    dt = 1./60.;
    fontSize = fontSize_;
    chFont.load("CooperHewitt-Medium.ttf", fontSize);
    textEntries = &textEntries_;
    entryIndex = 0;
    
    setText(textEntries->at(entryIndex));
    setColor(ofColor(255, ofRandom(50), ofRandom(50)));
    
    ofAddListener(fadeAnim.animFinished, this, &Ticker::onAnimFinished);
}

void Ticker::setText(string text_)
{
    text = text_;
}

void Ticker::setColor(ofColor color_)
{
    color = color_;
}

void Ticker::setPos(ofVec2f pos_)
{
    pos = pos_;
}

void Ticker::update()
{
    moveAnim.update(dt);
    fadeAnim.update(dt);
}

void Ticker::draw()
{
    ofSetColor(color.r, color.g, color.b, 255*fadeAnim.val());
    tickerBounds = chFont.getStringBoundingBox(text, 0, 0);
    tickerBounds.height += 20;
    tickerBounds.width += 20;
    ofDrawRectangle(pos.x * moveAnim.val(), pos.y, tickerBounds.width, tickerBounds.height);
    ofSetColor(255, 255, 255, 255*fadeAnim.val());
    chFont.drawString(text, pos.x * moveAnim.val() + 10, pos.y + tickerBounds.height - 15);
}

void Ticker::startAnim()
{
    moveAnim.reset(1.0);
    moveAnim.setCurve(LINEAR);
    moveAnim.setDuration(5.0);
    moveAnim.animateTo(0);
    
    fadeAnim.reset(1.0);
    fadeAnim.setCurve(TANH);
    fadeAnim.setDuration(3.0);
    fadeAnim.animateToAfterDelay(0, 2.0);
}

void Ticker::onAnimFinished(ofxAnimatable::AnimationEvent &animEvent)
{
    entryIndex++;
    if (entryIndex > textEntries->size() - 1) {
        entryIndex = 0;
    }
    
    setColor(ofColor(255, ofRandom(100), ofRandom(100)));
    setPos(ofVec2f(pos.x, ofRandom(tickerBounds.height, ofGetHeight()-tickerBounds.height)));
    setText(textEntries->at(entryIndex));
    startAnim();
}