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


#include "ofx/Geo/Coordinate.h"
#include "ofConstants.h"


namespace ofx {
namespace Geo {


Coordinate::Coordinate():
    _latitude(0),
    _longitude(0)
{
}


Coordinate::Coordinate(double latitude, double longitude):
    _latitude(latitude),
    _longitude(longitude)
{
}


Coordinate::~Coordinate()
{
}


void Coordinate::set(double latitude, double longitude)
{
    _latitude = latitude;
    _longitude = longitude;
}


double Coordinate::getLatitude() const
{
    return _latitude;
}


double Coordinate::getLongitude() const
{
    return _longitude;
}


double Coordinate::getLatitudeRad() const
{
    return _latitude * DEG_TO_RAD;
}


double Coordinate::getLongitudeRad() const
{
    return _longitude * DEG_TO_RAD;
}


void Coordinate::setLatitude(double latitude)
{
    _latitude = latitude;
}


void Coordinate::setLongitude(double longitude)
{
    _longitude = longitude;
}


std::string Coordinate::toString() const
{
    std::stringstream ss;
    ss << getLatitude() << "," << getLongitude();
    return ss.str();
}


ElevatedCoordinate::ElevatedCoordinate():
    _elevation(0)
{
}


ElevatedCoordinate::ElevatedCoordinate(double latitude,
                                       double longitude,
                                       double elevation):
    Coordinate(latitude, longitude),
    _elevation(elevation)
{
}


ElevatedCoordinate::~ElevatedCoordinate()
{
}


void ElevatedCoordinate::set(double latitude,
                             double longitude,
                             double elevation)
{
    Coordinate::set(latitude, longitude);
    _elevation = elevation;
}


double ElevatedCoordinate::getElevation() const
{
    return _elevation;
}


void ElevatedCoordinate::setElevation(double elevation)
{
    _elevation = elevation;
}


std::string ElevatedCoordinate::toString() const
{
    std::stringstream ss;
    ss << getLatitude() << "," << getLongitude() << "," << getElevation();
    return ss.str();
}



} } // namespace ofx::Geo
