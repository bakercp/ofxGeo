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


#include "ofApp.h"
#include <GeographicLib/GeoCoords.hpp>


void ofApp::setup()
{
    london = Geo::Coordinate(51.5085300, -0.1257400);
    tokyo = Geo::Coordinate(35.6148800, 139.5813000);

    distanceSpherical = Geo::GeoUtils::distanceSpherical(london, tokyo);
    distanceHaversine = Geo::GeoUtils::distanceHaversine(london, tokyo);
    bearingHaversine = Geo::GeoUtils::bearingHaversine(london, tokyo);
    midpoint = Geo::GeoUtils::midpoint(london, tokyo);

    try {
        // Miscellaneous conversions
        double lat = 33.3, lon = 44.4;
        GeographicLib::GeoCoords c(lat, lon);
        cout << c.MGRSRepresentation(-3) << "\n";
        c.Reset("18TWN0050");
        cout << c.DMSRepresentation() << "\n";
        cout << c.Latitude() << " " << c.Longitude() << "\n";
        c.Reset("1d38'W 55d30'N");
        cout << c.GeoRepresentation() << "\n";

        cout << c.UTMUPSRepresentation() << endl;
    }
    catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << "\n";
    }

}


void ofApp::draw()
{
    ofBackground(0);

    std::stringstream ss;

    ss << "From: London (" << london << "), UTM [" << Geo::GeoUtils::toUTM(london) << "]" << std::endl;
    ss << "  To: Tokyo  (" << tokyo  << "), UTM [" << Geo::GeoUtils::toUTM(tokyo)  << "]" << std::endl;
    ss << "    Distance Spherical: " << distanceSpherical << " km" << std::endl;
    ss << "    Distance Haversine: " << distanceHaversine << " km" << std::endl;
    ss << "     Bearing Haversine: " << bearingHaversine << " degrees" << std::endl;
    ss << "              Midpoint: (" << midpoint << ")" << std::endl;

    ofDrawBitmapString(ss.str(), ofVec2f(8, 14));
}
