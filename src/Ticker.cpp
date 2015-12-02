//
//  Ticker.cpp
//  rssFun
//
//  Created by Kim Ash on 12/2/15.
//
//

#include "Ticker.h"

void Ticker::setup(ofVec2f pos_, const vector<string> &textItems_)
{
    pos = pos_;
    dt = 1./60.;
    chFont.load("CooperHewitt-Medium.ttf", 30);
    textItems = &textItems_;
    
    //setText(textItems[0]);
    setColor(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
}

void Ticker::setText(string text_)
{
    text = text_;
}

void Ticker::setColor(ofColor color_)
{
    color = color_;
}

void Ticker::update()
{
    moveAnim.update(dt);
    fadeAnim.update(dt);
}

void Ticker::draw()
{
    ofSetColor(color.r, color.g, color.b, 255*fadeAnim.val());
    chFont.drawString(text, pos.x * moveAnim.val(), pos.y);
}

void Ticker::startAnim()
{
    moveAnim.reset(1.0);
    moveAnim.setCurve(LINEAR);
    moveAnim.setDuration(2.0);
    moveAnim.animateTo(0);
    
    fadeAnim.reset(1.0);
    fadeAnim.setCurve(TANH);
    fadeAnim.setDuration(2.0);
    fadeAnim.animateTo(0);
}