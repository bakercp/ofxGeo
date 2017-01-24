//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofx/Geo/CoordinateBounds.h"


namespace ofx {
namespace Geo {


CoordinateBounds::CoordinateBounds()
{
}


CoordinateBounds::CoordinateBounds(const Coordinate& northwest,
                                   const Coordinate& southeast):
    _northwest(northwest),
    _southeast(southeast)
{
}


CoordinateBounds::~CoordinateBounds()
{
}


void CoordinateBounds::setNorthwest(const Coordinate& northwest)
{
    _northwest = northwest;
}


Coordinate CoordinateBounds::getNorthwest() const
{
    return _northwest;
}


void CoordinateBounds::setSoutheast(const Coordinate& southeast)
{
    _southeast = southeast;
}


Coordinate CoordinateBounds::getSoutheast() const
{
    return _southeast;
}


Coordinate CoordinateBounds::getSouthwest() const
{
    return Coordinate(_southeast.getLatitude(), _northwest.getLongitude());
}


Coordinate CoordinateBounds::getNortheast() const
{
    return Coordinate(_northwest.getLatitude(), _southeast.getLongitude());
}


std::string CoordinateBounds::toString(int precision) const
{
    return _northwest.toString(precision) + "," + _southeast.toString(precision);
}


} } // namespace ofx::Geo
