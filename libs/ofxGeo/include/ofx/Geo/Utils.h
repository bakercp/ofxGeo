// =============================================================================
//
// Copyright (c) 2014-2016 Christopher Baker <http://christopherbaker.net>
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
#include "ofVec2d.h"
#include "ofVec3d.h"


namespace ofx {
namespace Geo {


class Coordinate;
class UTMLocation;


/// \brief A collection of utilities for geographic tasks.
class Utils
{
public:
    /// \brief Convert a string-encoded polyline into a vector of coodinates.
    /// \param encodedPolyline an encoded polyline string.
    /// \sa https://developers.google.com/maps/documentation/utilities/polylinealgorithm?csw=1
    /// \sa http://jeffreysambells.com/2010/05/27/decoding-polylines-from-google-maps-direction-api-with-java
    /// \returns A decoded polyline representing the decorded geo coordinates.
    static std::vector<Coordinate> decodeGeoPolyline(const std::string& encodedPolyline);

    /// \brief Get the distance in kilometers between two GeoLocations on earth.
    ///     Calculation uses the great-circle distance uses the approximated
    ///     radius of a sphereical earth in kilometers.
    /// \sa http://www.movable-type.co.uk/scripts/latlong.html
    /// \param coordinate0 The first location.
    /// \param coordinate1 The second location.
    /// \returns the spherical distance in kilometers.
	static double distanceSpherical(const Coordinate& coordinate0,
                                    const Coordinate& coordinate1);

    /// \brief Get the distance in kilometers between two GeoLocations on earth.
    ///     Calculation uses the haversine formula. Uses the approximated
    ///     radius of a sphereical earth in kilometers.
    /// \sa http://www.movable-type.co.uk/scripts/latlong.html
    /// \param coordinate0 The first location.
    /// \param coordinate1 The second location.
    /// \returns the spherical distance in kilometers.
    static double distanceHaversine(const Coordinate& coordinate0,
                                    const Coordinate& coordinate1);

    /// \brief Get the bearing in degrees between two Coordinates.
    /// \param coordinate0 The first location.
    /// \param coordinate1 The second location.
    /// \returns the bearing in degrees between two GeoLocations.
    static double bearingHaversine(const Coordinate& coordinate0,
                                   const Coordinate& coordinate1);

    /// \brief Get the bearing in degrees between two Coordinates.
    /// \param coordinate0 The first location.
    /// \param coordinate1 The second location.
    /// \returns the bearing in degrees between two GeoLocations.
    static Coordinate midpoint(const Coordinate& coordinate0,
                               const Coordinate& coordinate1);

    /// \brief Convert the Coordinate to a UTMLocation using the WGS84 Datum.
    /// \param coordinate The location.
    /// \returns the converted UTMLocation.
    static UTMLocation toUTM(const Coordinate& coordinate);

    /// \brief Convert the UTMLocation to a Coordinate using the WGS84 Datum.
    /// \param location The UTMLocation.
    /// \returns the converted Coordinate.
    static Coordinate toCoordinate(const UTMLocation& location);

    /// \brief Convert the UTMLocation to an ofVec2f.
    /// \param location The UTMLocation.
    /// \returns the converted location.
    static ofVec2d toVec(const UTMLocation& location);

    /// \brief Convert the Coordinate to an ofVec2f via a UTM Location.
    /// \param coordinate The Coordinate.
    /// \returns the converted location.
    static ofVec2d toVec(const Coordinate& coordinate);

    /// \brief Generate a random Coordiante.
    /// \returns A Coordiante with
    ///     MIN_LATITUDE_DEGREES <= latitude < MAX_LATITUDE_DEGREES and
    ///     MIN_LONGITUDE_DEGREES <= longitude < MAX_LONGITUDE_DEGREES
    /// \warning Internally this method uses ofRandom() which is not threadsafe.
    static Coordinate randomCoordinate();

    /// \brief Generate a random UTMLocation.
    /// \returns A UTMLocation corresponding to a Coordinate with
    ///     MIN_LATITUDE_DEGREES <= latitude < MAX_LATITUDE_DEGREES and
    ///     MIN_LONGITUDE_DEGREES <= longitude < MAX_LONGITUDE_DEGREES
    /// \warning Internally this method uses ofRandom() which is not threadsafe.
    static UTMLocation randomUTMLocation();

    /// \brief The approximate radius of a spherical earth in kilometers.
    ///
    /// The value is 6371.01.
    ///
    /// Is subject to notable error, particularly around the poles.
    static const double EARTH_RADIUS_KM;

    /// \brief The minimum value for a latitude, - 2 * PI.
    static const double MIN_LATITUDE_RADIANS;

    /// \brief The maximum value for a latitude, + 2 * PI.
    static const double MAX_LATITUDE_RADIANS;

    /// \brief The minimum value for a latitude, - 360 degrees.
    static const double MIN_LATITUDE_DEGREES;

    /// \brief The maximum value for a latitude, + 360 degrees.
    static const double MAX_LATITUDE_DEGREES;

    /// \brief The minimum value for a longitude, - PI.
    static const double MIN_LONGITUDE_RADIANS;

    /// \brief The maximum value for a longitude, + PI.
    static const double MAX_LONGITUDE_RADIANS;

    /// \brief The minimum value for a longitude, - 180 degrees.
    static const double MIN_LONGITUDE_DEGREES;

    /// \brief The maximum value for a longitude, + 180 degrees.
    static const double MAX_LONGITUDE_DEGREES;

private:
    Utils() = delete;
    ~Utils() = delete;

};


} } // namespace ofx::Geo
