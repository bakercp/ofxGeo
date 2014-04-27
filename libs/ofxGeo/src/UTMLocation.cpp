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


#include "ofx/Geo/UTMLocation.h"


namespace ofx {
namespace Geo {


UTMLocation::UTMLocation():
    _northing(0),
    _easting(0),
    _zoneNumber(0),
    _zoneLetter('Z')
{
}


UTMLocation::UTMLocation(double northing,
                         double easting,
                         int zoneNumber,
                         char zoneLetter):
    _northing(northing),
    _easting(easting),
    _zoneNumber(zoneNumber),
    _zoneLetter(zoneLetter)
{
}


UTMLocation::~UTMLocation()
{
}


double UTMLocation::getNorthing() const
{
    return _northing;
}


double UTMLocation::getEasting() const
{
    return _easting;
}


int UTMLocation::getZoneNumber() const
{
    return _zoneNumber;
}


char UTMLocation::getZoneLetter() const
{
    return _zoneLetter;
}


void UTMLocation::setNorthing(double northing)
{
    _northing = northing;
}


void UTMLocation::setEasting(double easting)
{
    _easting = easting;
}


void UTMLocation::setZoneNumber(int zoneNumber)
{
    _zoneNumber = zoneNumber;
}


void UTMLocation::setZoneLetter(char zoneLetter)
{
    _zoneLetter = zoneLetter;
}


} } // namespace ofx::Geo
