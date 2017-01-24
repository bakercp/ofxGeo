//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include <iostream>
#include "ofx/Geo/Coordinate.h"


namespace ofx {
namespace Geo {


/// \brief A bounding box using Geo Coordinates.
class CoordinateBounds
{
public:
    /// \brief Create an empty CooridinateBounds.
    CoordinateBounds();

    /// \brief Create CoordinateBounds from two Coordinates.
    /// \param northwest The northwest coordinate of the CoordinateBounds.
    /// \param southeast The southeast coordinate of the CoordinateBounds.
    CoordinateBounds(const Coordinate& northwest, const Coordinate& southeast);

    /// \brief Destroy the CooridinateBounds.
    virtual ~CoordinateBounds();

    /// \brief Set the northwest corner of the CooridinateBounds.
    /// \param northwest The northwest corner of the CooridinateBounds.
    void setNorthwest(const Coordinate& northwest);

    /// \brief Get the northwest corner of the CooridinateBounds.
    /// \returns the northwest corner of the CooridinateBounds.
    Coordinate getNorthwest() const;

    /// \brief Set the southeast corner of the CooridinateBounds.
    /// \param northwest The southeast corner of the CooridinateBounds.
    void setSoutheast(const Coordinate& southeast);

    /// \brief Get the southeast corner of the CooridinateBounds.
    /// \returns the southeast corner of the CooridinateBounds.
    Coordinate getSoutheast() const;

    /// \returns the southwest corner of the CooridinateBounds.
    Coordinate getSouthwest() const;

    /// \returns the northeast corner of the CooridinateBounds.
    Coordinate getNortheast() const;

    /// \brief Get the bounds as a string.
    ///
    /// Latitudes and longitudes require many decimal places at high resolution.
    ///
    /// \param precision The decimal precision coordinates.
    /// \returns the bounds as a comma seperated string.
    std::string toString(int precision = 8) const;

    /// \brief Stream output.
    /// \param os the std::ostream.
    /// \param coordinate The CoordinateBounds to output.
    /// \returns the updated std::ostream reference.
    friend std::ostream& operator << (std::ostream& os,
                                      const CoordinateBounds& bounds);

private:
    /// \brief the northwest corner of the CoordinateBounds.
    Coordinate _northwest;

    /// \brief the southeast corner of the CoordinateBounds.
    Coordinate _southeast;
    
};


inline std::ostream& operator<<(std::ostream& os,
                                const CoordinateBounds& bounds)
{
    os << bounds.toString();
    return os;
}


} } // namespace ofx::Geo
