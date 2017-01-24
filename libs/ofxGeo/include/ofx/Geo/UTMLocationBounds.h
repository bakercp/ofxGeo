//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include <iostream>
#include "ofx/Geo/UTMLocation.h"


namespace ofx {
namespace Geo {


/// \brief A bounding box using UTM Locations.
class UTMLocationBounds
{
public:
    /// \brief Create an empty UTMLocationBounds.
    UTMLocationBounds();

    /// \brief Create UTMLocationBounds from two UTM Locations.
    /// \param northwest The northwest location of the UTMLocationBounds.
    /// \param southeast The southeast location of the UTMLocationBounds.
    UTMLocationBounds(const UTMLocation& northwest, const UTMLocation& southeast);

    /// \brief Destroy the UTMLocationBounds.
    virtual ~UTMLocationBounds();

    /// \brief Get the northwest corner of the UTMLocationBounds.
    /// \returns the northwest corner of the UTMLocationBounds.
    const UTMLocation& getNorthwest() const;

    /// \brief Set the northwest corner of the UTMLocationBounds.
    /// \param northwest The northwest corner of the UTMLocationBounds.
    void setNorthwest(const UTMLocation& northwest);

    /// \brief Get the southeast corner of the UTMLocationBounds.
    /// \returns the southeast corner of the UTMLocationBounds.
    const UTMLocation& getSoutheast() const;

    /// \brief Set the southeast corner of the UTMLocationBounds.
    /// \param northwest The southeast corner of the UTMLocationBounds.
    void setSoutheast(const UTMLocation& southeast);

private:
    /// \brief the northwest corner of the UTMLocationBounds.
    UTMLocation _northwest;

    /// \brief the southeast corner of the UTMLocationBounds.
    UTMLocation _southeast;
    
};


} } // namespace ofx::Geo
