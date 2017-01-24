//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofx/Geo/Coordinate.h"
#include "ofConstants.h"
#include "ofx/IO/Hash.h"


namespace ofx {
namespace Geo {


Coordinate::Coordinate(): Coordinate(0, 0)
{
}


Coordinate::Coordinate(const glm::dvec2& coordinate):
    Coordinate(coordinate.x, coordinate.y)
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
    return glm::radians<double>(_latitude);
}


double Coordinate::getLongitudeRad() const
{
    return glm::radians<double>(_longitude);
}


void Coordinate::setLatitude(double latitude)
{
    _latitude = latitude;
}


void Coordinate::setLongitude(double longitude)
{
    _longitude = longitude;
}


std::string Coordinate::toString(int precision) const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(precision) << getLatitude();
    ss << ",";
    ss << std::fixed << std::setprecision(precision) << getLongitude();
    return ss.str();
}


std::size_t Coordinate::hash() const
{
    std::size_t seed = 0;
    IO::Hash::combine(seed, _latitude);
    IO::Hash::combine(seed, _longitude);
    return seed;
}


ElevatedCoordinate::ElevatedCoordinate(): ElevatedCoordinate(0, 0, 0)
{
}


ElevatedCoordinate::ElevatedCoordinate(const glm::dvec3& coordinate):
    ElevatedCoordinate(coordinate.x, coordinate.y, coordinate.z)
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


std::size_t ElevatedCoordinate::hash() const
{
    std::size_t seed = Coordinate::hash();
    IO::Hash::combine(seed, _elevation);
    return seed;
}


} } // namespace ofx::Geo
