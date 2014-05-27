// =============================================================================
//
// Copyright (c) 2014 Christopher Baker <http://christopherbaker.net>
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


#pragma once


#include "ofMain.h"
#include "ofxGeo.h"


class ofApp: public ofBaseApp
{
public:
    ofApp();
    void setup();
    void update();
    void draw();

    // A collection of Random UTMCoordinates.
    std::vector<ofx::Geo::UTMLocation> locations;

    /// \brief The spatial hash specialized for ofx::Geo::UTMLocation.
    ///
    /// We must also specify the
    ofx::KDTree<ofx::Geo::UTMLocation, double> hash;

    /// \brief The search results specialized for ofx::Geo::UTMLocation.
    ofx::KDTree<ofx::Geo::UTMLocation, double>::SearchResults searchResults;

    /// \brief A mesh to make it easier to draw lots of points.
    ofMesh mesh;

    ofx::Geo::UTMLocation mouse;
    
    ofRectangled bounds;

    enum
    {
        NUM = 1000,
        NEAREST_N = 200
    };

};
