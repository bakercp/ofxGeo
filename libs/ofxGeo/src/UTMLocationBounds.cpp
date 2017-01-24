//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofx/Geo/UTMLocationBounds.h"


namespace ofx {
namespace Geo {


UTMLocationBounds::UTMLocationBounds()
{
}


UTMLocationBounds::UTMLocationBounds(const UTMLocation& northwest,
                                     const UTMLocation& southeast):
    _northwest(northwest),
    _southeast(southeast)
{
}


UTMLocationBounds::~UTMLocationBounds()
{
}


const UTMLocation& UTMLocationBounds::getNorthwest() const
{
    return _northwest;
}


void UTMLocationBounds::setNorthwest(const UTMLocation& northwest)
{
    _northwest = northwest;
}


const UTMLocation& UTMLocationBounds::getSoutheast() const
{
    return _southeast;
}


void UTMLocationBounds::setSoutheast(const UTMLocation& southeast)
{
    _southeast = southeast;
}


} } // namespace ofx::Geo
