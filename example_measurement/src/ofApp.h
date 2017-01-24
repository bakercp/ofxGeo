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
    void setup();
    void draw();

    ofxGeo::Coordinate london;
    ofxGeo::Coordinate tokyo;

    double distanceSpherical = 0;
    double distanceHaversine = 0;
    double bearingHaversine = 0;

    ofxGeo::Coordinate midpoint;

};
