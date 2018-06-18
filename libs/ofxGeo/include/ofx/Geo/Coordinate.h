//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include <iostream>
#include <string>
#include "ofVectorMath.h"


namespace ofx {
namespace Geo {


/// \brief A Coordinate defines a latitude / longitude pair in degrees.
class Coordinate
{
public:
    /// \brief Create a 0, 0 Coordinate.
    Coordinate();

    /// \brief Create a coordinate from a vector.
    ///
    /// Coordinate x will be assigned to latitude.
    /// Coordinate y will be assigned to longitude.
    ///
    /// \param coordinate the coordinate to assign.
    Coordinate(const glm::dvec2& coordinate);

    /// \brief Create a Coordinate with given latitude and logitude.
    /// \param latitude The latitude in degrees.
    /// \param longitude The longitude in degrees.
    Coordinate(double latitude, double longitude);

    /// \brief Destroy the Coordinate.
    virtual ~Coordinate();

    /// \brief Set the latitude and longitude.
    /// \param latitude The latitude in degrees.
    /// \param longitude The longitude in degrees.
    void set(double latitude, double longitude);

    /// \brief Get the latitude in degrees.
    /// \returns the latitude in degrees.
    double getLatitude() const;

    /// \brief Get the longitude in degrees.
    /// \returns the longitude in degrees.
    double getLongitude() const;

    /// \brief Get the latitude in radians.
    /// \returns the latitude in radians
    double getLatitudeRad() const;

    /// \brief Get the longitude in radians.
    /// \returns the longitude in radians
    double getLongitudeRad() const;

    /// \brief Set the latitude in degrees.
    /// \param latitude the latitude in degrees.
    void setLatitude(double latitude);

    /// \brief Set the longitude in degrees.
    /// \param longitude the longitude in degrees.
    void setLongitude(double longitude);

    /// \brief Get coordinate as a string.
    ///
    /// Latitude and longitude require many decimal places at high resolution.
    ///
    /// \param precision The decimal precision coordinates.
    /// \returns the a comma separated latitude / longitude pair.
    std::string toString(int precision = 8) const;

    /// \returns a non-cryptographic hash used for sorting.
    std::size_t hash() const;

    /// \brief Stream output.
    /// \param os the std::ostream.
    /// \param coordinate The Coordiante to output.
    /// \returns the updated std::ostream reference.
    friend std::ostream& operator << (std::ostream& os,
                                      const Coordinate& coordinate);

private:
    struct
    {
        /// \brief The latitude in degrees.
        double _latitude;

        /// \brief The longitude in degrees.
        double _longitude;
    };

};


inline std::ostream& operator<<(std::ostream& os, const Coordinate& coordinate)
{
    os << coordinate.toString();
    return os;
}


class ElevatedCoordinate: public Coordinate
{
public:
    /// \brief Create a 0, 0, 0 ElevatedCoordinate.
    ElevatedCoordinate();

    /// \brief Create a coordinate from a vector.
    ///
    /// coordinate will be assigned to latitude.
    /// coordinate will be assigned to longitude.
    ///
    /// \param coordinate the coordinate to assign.
    ElevatedCoordinate(const glm::dvec3& coordinate);

    /// \brief Create a Coordinate with given latitude, logitude and elevation.
    /// \param latitude The latitude in degrees.
    /// \param longitude The longitude in degrees.
    /// \param elevation The elevation in meters.
    ElevatedCoordinate(double latitude, double longitude, double elevation);

    /// \brief Destroy the Coordinate.
    virtual ~ElevatedCoordinate();

    /// \brief Set  latitude, logitude and elevation.
    /// \param latitude The latitude in degrees.
    /// \param longitude The longitude in degrees.
    /// \param elevation The elevation in meters.
    void set(double latitude, double longitude, double elevation);

    /// \brief Get the elevation in meters.
    /// \returns the elevation in meters.
    double getElevation() const;

    /// \brief Set the elevation in meters.
    /// \param latitude the elevation in meters.
    void setElevation(double elevation);

    /// \brief Get coordinate as a string.
    /// \returns the a comma separated latitude, longitude, elevation.
    std::string toString() const;

    /// \returns a non-cryptographic hash used for sorting.
    std::size_t hash() const;

    /// \brief Stream output.
    /// \param os the std::ostream.
    /// \param coordinate The ElevatedCoordiante to output.
    /// \returns the updated std::ostream reference.
    friend std::ostream& operator << (std::ostream& os,
                                      const ElevatedCoordinate& coordinate);
private:
    struct
    {
        /// \brief The elevation in meters.
        double _elevation;
    };

};


inline std::ostream& operator<<(std::ostream& os, const ElevatedCoordinate& coordinate)
{
    os << coordinate.toString();
    return os;
}


} } // namespace ofx::Geo




namespace std {


template <> struct hash<ofx::Geo::Coordinate>
{
    size_t operator()(const ofx::Geo::Coordinate& coordinate) const
    {
        return coordinate.hash();
    }
};


template <> struct hash<ofx::Geo::ElevatedCoordinate>
{
    size_t operator()(const ofx::Geo::ElevatedCoordinate& coordinate) const
    {
        return coordinate.hash();
    }
};


} // namespace std
