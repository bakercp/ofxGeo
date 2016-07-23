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


#include "ofx/Geo/UTMLocation.h"


namespace ofx {
namespace Geo {


UTMLocation::UTMLocation():
    glm::dvec2(0, 0),
    _zone("")
{
}


UTMLocation::UTMLocation(double easting,
                         double northing,
                         const std::string& zone):
    glm::dvec2(easting, northing),
    _zone(zone)
{
}


UTMLocation::~UTMLocation()
{
}


double UTMLocation::getEasting() const
{
    return x;
}

    
double UTMLocation::getNorthing() const
{
    return y;
}


const std::string& UTMLocation::getZone() const
{
    return _zone;
}


void UTMLocation::setEasting(double easting)
{
    x = easting;
}

    
void UTMLocation::setNorthing(double northing)
{
    y = northing;
}


void UTMLocation::setZone(const std::string& zone)
{
    _zone = zone;
}


std::string UTMLocation::toString() const
{
    std::stringstream ss;
    ss << x << ", " << y << ", " << _zone;
    return ss.str();
}


ElevatedUTMLocation::ElevatedUTMLocation():
    glm::dvec3(0, 0, 0),
    _zone("")
{
}


ElevatedUTMLocation::ElevatedUTMLocation(double easting,
                                         double northing,
                                         double elevation,
                                         const std::string& zone):
    glm::dvec3(easting, northing, elevation),
    _zone(zone)
{
}


ElevatedUTMLocation::~ElevatedUTMLocation()
{
}


double ElevatedUTMLocation::getEasting() const
{
    return x;
}


double ElevatedUTMLocation::getNorthing() const
{
    return y;
}


double ElevatedUTMLocation::getElevation() const
{
    return z;
}


const std::string& ElevatedUTMLocation::getZone() const
{
    return _zone;
}


void ElevatedUTMLocation::setEasting(double easting)
{
    x = easting;
}


void ElevatedUTMLocation::setNorthing(double northing)
{
    y = northing;
}


void ElevatedUTMLocation::setElevation(double elevation)
{
    z = elevation;
}


void ElevatedUTMLocation::setZone(const std::string& zone)
{
    _zone = zone;
}


std::string ElevatedUTMLocation::toString() const
{
    std::stringstream ss;
    ss << x << ", " << y << "," << z << ", " << _zone;
    return ss.str();
}


} } // namespace ofx::Geo
