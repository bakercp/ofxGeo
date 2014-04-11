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


#pragma once


#include <string>
#include <vector>


namespace ofx {
namespace Geo {


class Coordinates;


/// \brief A collection of utilities for geographic tasks.
class Utils
{
public:
    /// \brief Convert a string-encoded polyline into a vector of coodinates.
    /// \param encodedPolyline an encoded polyline string.
    /// \sa https://developers.google.com/maps/documentation/utilities/polylinealgorithm?csw=1
    /// \sa http://jeffreysambells.com/2010/05/27/decoding-polylines-from-google-maps-direction-api-with-java
    /// \returns A decoded polyline representing the decorded geo coordinates.
    static std::vector<Coordinates> decodeGeoPolyline(const std::string& encodedPolyline);

    /// \brief Get the distance in kilometers between two GeoLocations on earth.
    ///     Calculation uses the great-circle distance uses the approximated
    ///     radius of a sphereical earth in kilometers.
    /// \sa http://www.movable-type.co.uk/scripts/latlong.html
    /// \param location0 The first location.
    /// \param location1 The second location.
    /// \returns the spherical distance in kilometers.
	static double distanceSpherical(const Coordinates& location0,
                                    const Coordinates& location1);

    /// \brief Get the distance in kilometers between two GeoLocations on earth.
    ///     Calculation uses the haversine formula. Uses the approximated
    ///     radius of a sphereical earth in kilometers.
    /// \sa http://www.movable-type.co.uk/scripts/latlong.html
    /// \param location0 The first location.
    /// \param location1 The second location.
    /// \returns the spherical distance in kilometers.
    static double distanceHaversine(const Coordinates& location0,
                                    const Coordinates& location1);


    /// \brief Get the bearing in degrees between two Coordinates.
    /// \param location0 The first location.
    /// \param location1 The second location.
    /// \returns the bearing in degrees between two GeoLocations.
    static double bearingHaversine(const Coordinates& location0,
                                   const Coordinates& location1);

    static const double EARTH_RADIUS_KM;
        ///< The approximate radius of a spherical earth in kilometers.

};


} } // namespace ofx::Geo
