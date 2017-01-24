//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "ofx/Geo/Coordinate.h"


namespace ofx {
namespace Geo {


class CoordinatePolyline
{
public:
    CoordinatePolyline();
    virtual ~CoordinatePolyline();


private:
    std::vector<Coordinate> _coordinates;

};


} } // namespace ofx::Geo
