//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofx/Geo/CoordinateBounds.h"


namespace ofx {
namespace Geo {


const CoordinateBounds CoordinateBounds::MAXIMUM_BOUNDS(Coordinate(90, -180),
                                                        Coordinate(-85, 180));


CoordinateBounds::CoordinateBounds()
{
}


CoordinateBounds::CoordinateBounds(const Coordinate& coordinate0,
                                   const Coordinate& coordinate1)
{
    growToInclude(coordinate0);
    growToInclude(coordinate1);
}


CoordinateBounds::~CoordinateBounds()
{
}


void CoordinateBounds::growToInclude(const Coordinate& coordinate)
{
    if (_unset)
    {
        _minLatitude = coordinate.getLatitude();
        _maxLatitude = coordinate.getLatitude();
        _minLongitude = coordinate.getLongitude();
        _maxLongitude = coordinate.getLongitude();
        _unset = false;
    }

    _minLatitude = std::min(coordinate.getLatitude(), _minLatitude);
    _maxLatitude = std::max(coordinate.getLatitude(), _maxLatitude);
    _minLongitude = std::min(coordinate.getLongitude(), _minLongitude);
    _maxLongitude = std::max(coordinate.getLongitude(), _maxLongitude);

}


Coordinate CoordinateBounds::northwest() const
{
    if (_unset)
        return MAXIMUM_BOUNDS.northeast();

    return Coordinate(_maxLatitude, _minLongitude);
}


Coordinate CoordinateBounds::southeast() const
{
    if (_unset)
        return MAXIMUM_BOUNDS.southeast();

    return Coordinate(_minLatitude, _maxLongitude);
}


Coordinate CoordinateBounds::southwest() const
{
    if (_unset)
        return MAXIMUM_BOUNDS.southwest();

    return Coordinate(_minLatitude, _minLongitude);
}


Coordinate CoordinateBounds::northeast() const
{
    if (_unset)
        return MAXIMUM_BOUNDS.northeast();

    return Coordinate(_maxLatitude, _maxLongitude);
}


std::string CoordinateBounds::toString(int precision) const
{
    return southwest().toString(precision) + "," + northeast().toString(precision);
}


} } // namespace ofx::Geo
