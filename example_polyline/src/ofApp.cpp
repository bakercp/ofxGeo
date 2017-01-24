//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofApp.h"


void ofApp::setup()
{
    encodedPolyline = "_p~iF~ps|U_ulLnnqC_mqNvxq`@";
    
    polyline = ofxGeo::GeoUtils::decodeGeoPolyline(encodedPolyline);
}


void ofApp::draw()
{
    ofBackground(0);
    
    std::stringstream ss;

    ss << "Encoded: " << encodedPolyline << std::endl;
    ss << "Decoded: " << std::endl;

    for (std::size_t i = 0; i < polyline.size(); ++i)
    {
        ss << "    [" << i << "] " << polyline[i].getLatitude() << ", " << polyline[i].getLongitude() << std::endl;
    }

    ofDrawBitmapString(ss.str(), ofVec2f(8, 14));

}
