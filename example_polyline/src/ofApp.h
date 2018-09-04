//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "ofMain.h"
#include "ofxGeo.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    std::string encodedPolyline;
    
    std::vector<ofxGeo::Coordinate> polyline;
};
