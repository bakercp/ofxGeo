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
    /// \brief Create a MAXIMUM_BOUNDS CooridinateBounds.
    CoordinateBounds();

    /// \brief Create CoordinateBounds from two Coordinates.
    /// \param coordinate0 The first coordinate.
    /// \param coordinate1 The second coordinate.
    CoordinateBounds(const Coordinate& coordinate0,
                     const Coordinate& coordinate1);

    /// \brief Destroy the CooridinateBounds.
    virtual ~CoordinateBounds();

    /// \brief Expand the coordinate bounds to incorporate the given coordinate.
    /// \param coordinate The coordinate to use for expansion.
    void growToInclude(const Coordinate& coordinate);

    /// \brief Get the northwest corner of the CooridinateBounds.
    /// \returns the northwest corner of the CooridinateBounds.
    Coordinate northwest() const;

    /// \brief Get the southeast corner of the CooridinateBounds.
    /// \returns the southeast corner of the CooridinateBounds.
    Coordinate southeast() const;

    /// \returns the southwest corner of the CooridinateBounds.
    Coordinate southwest() const;

    /// \returns the northeast corner of the CooridinateBounds.
    Coordinate northeast() const;

    /// \brief The maximum coordinate bounds possible.
    static const CoordinateBounds MAXIMUM_BOUNDS;

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
    bool _unset = true;
    double _minLatitude = -90.0;
    double _maxLatitude =  90.00;
    double _minLongitude = -180.00;
    double _maxLongitude =  180.00;

};


inline std::ostream& operator<<(std::ostream& os,
                                const CoordinateBounds& bounds)
{
    os << bounds.toString();
    return os;
}


} } // namespace ofx::Geo
