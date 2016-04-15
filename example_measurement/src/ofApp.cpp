// =============================================================================
//
// Copyright (c) 2014-2016 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#include "ofApp.h"


void ofApp::setup()
{
    london = ofxGeo::Coordinate(51.5085300, -0.1257400);
    tokyo = ofxGeo::Coordinate(35.6148800, 139.5813000);

    distanceSpherical = ofxGeo::Utils::distanceSpherical(london, tokyo);
    distanceHaversine = ofxGeo::Utils::distanceHaversine(london, tokyo);
    bearingHaversine = ofxGeo::Utils::bearingHaversine(london, tokyo);
    midpoint = ofxGeo::Utils::midpoint(london, tokyo);
}


void ofApp::draw()
{
    ofBackground(0);

    std::stringstream ss;

    ss << "From: London (" << london << "), UTM [" << ofxGeo::Utils::toUTM(london) << "]" << std::endl;
    ss << "  To: Tokyo  (" << tokyo  << "), UTM [" << ofxGeo::Utils::toUTM(tokyo)  << "]" << std::endl;
    ss << "    Distance Spherical: " << distanceSpherical << " km" << std::endl;
    ss << "    Distance Haversine: " << distanceHaversine << " km" << std::endl;
    ss << "     Bearing Haversine: " << bearingHaversine << " degrees" << std::endl;
    ss << "              Midpoint: (" << midpoint << ")" << std::endl;

    ofDrawBitmapString(ss.str(), ofVec2f(8, 14));
}
