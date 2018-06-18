//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include <string>
#include <vector>
#include "ofVectorMath.h"


namespace ofx {
namespace Geo {


class Coordinate;
class UTMLocation;


/// \brief A collection of utilities for geographic tasks.
class GeoUtils
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

    /// \brief Convert the UTMLocation to an glm::dvec2.
    /// \param location The UTMLocation.
    /// \returns the converted location.
    static glm::dvec2 toVec(const UTMLocation& location);

    /// \brief Convert the Coordinate to an glm::dvec2 via a UTM Location.
    /// \param coordinate The Coordinate.
    /// \returns the converted location.
    static glm::dvec2 toVec(const Coordinate& coordinate);

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

    /// \brief Combine multiple hashes.
    ///
    /// The order of combining hases will affect the final hash value. This uses
    /// std::hash to hash the value, so it is good for being a unique key for
    /// hash tables, but it is not meant for cryptographic hashing.
    ///
    /// \param seed The existing hash to amend.
    /// \param v The value to hash and amend.
    /// \tparam T The type of the value to hash and amend.
    /// \sa http://stackoverflow.com/a/2595226/1518329
    template <class T>
    static void hash(std::size_t& seed, const T& v)
    {
        std::hash<T> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

private:
    GeoUtils() = delete;
    ~GeoUtils() = delete;

};


} } // namespace ofx::Geo
