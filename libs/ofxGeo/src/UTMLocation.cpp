//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


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
