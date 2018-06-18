//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include <iostream>
#include <sstream>
#include "ofVectorMath.h"


namespace ofx {
namespace Geo {


/// \brief Defines a location in Universal Transverse Mercator (UTM) space.
/// \sa http://en.wikipedia.org/wiki/Universal_Transverse_Mercator_coordinate_system
class UTMLocation: public glm::dvec2
{
public:
    /// \brief Create an empty UTMLocation.
    UTMLocation();

    /// \brief Create an empty UTMLocation with the given values.
    /// \param easting the easting in meters.
    /// \param northing the northing in meters.
    /// \param zone the zone id.
    UTMLocation(double easting, double northing, const std::string& zone);

    /// \brief Destory the UTMLocation.
    virtual ~UTMLocation();

    /// \brief Get the easting in meters.
    /// \returns the easting in meters.
    double getEasting() const;

    /// \brief Get the northing in meters.
    /// \returns the northing in meters.
    double getNorthing() const;

    /// \brief Get the zone id.
    /// \returns the zone id.
    const std::string& getZone() const;

    /// \brief Set the easting in meters.
    /// \param easting the easting in meters.
    void setEasting(double easting);

    /// \brief Set the northing in meters.
    /// \param northing the northing in meters.
    void setNorthing(double northing);

    /// \brief Set the zone id.
    /// \param zone the zone id.
    void setZone(const std::string& zone);

    /// \brief Get coordinate as a string.
    /// \returns the a comma separated easting, northing, zone.
    std::string toString() const;

    /// \returns a non-cryptographic hash.
    std::size_t hash() const;
    
    /// \brief Stream output.
    /// \param os the std::ostream.
    /// \param location The UTMLocation to output.
    /// \returns the updated std::ostream reference.
    friend std::ostream& operator << (std::ostream& os,
                                      const UTMLocation& location);

private:
    /// \brief The Zone in the UTM system.
    std::string _zone;

};


inline std::ostream& operator << (std::ostream& os, const UTMLocation& location)
{
    os << location.x << ", " << location.y << ", " << location._zone;
    return os;
}


class ElevatedUTMLocation: public glm::dvec3
{
public:
    /// \brief Create a 0, 0, 0 ElevatedUTMLocation.
    ElevatedUTMLocation();

    /// \brief Create a Coordinate with given latitude and logitude.
    /// \param latitude The latitude in degrees.
    /// \param longitude The longitude in degrees.
    ElevatedUTMLocation(double easting,
                        double northing,
                        double elevation,
                        const std::string& zone);

    /// \brief Destroy the Coordinate.
    virtual ~ElevatedUTMLocation();

    /// \brief Get the easting in meters.
    /// \returns the easting in meters.
    double getEasting() const;

    /// \brief Get the northing in meters.
    /// \returns the northing in meters.
    double getNorthing() const;

    /// \brief Get the zone id.
    /// \returns the zone id.
    const std::string& getZone() const;

    /// \brief Set the easting in meters.
    /// \param easting the easting in meters.
    void setEasting(double easting);

    /// \brief Set the northing in meters.
    /// \param northing the northing in meters.
    void setNorthing(double northing);

    /// \brief Set the zone id.
    /// \param zone the zone id.
    void setZone(const std::string& zone);

    /// \brief Get the elevation in meters.
    /// \returns the elevation in meters.
    double getElevation() const;

    /// \brief Set the elevation in meters.
    /// \param latitude the elevation in meters.
    void setElevation(double elevation);

    /// \brief Get coordinate as a string.
    /// \returns the a comma separated easting, northing, zone, elevation.
    std::string toString() const;

    /// \returns a non-cryptographic hash used for sorting.
    std::size_t hash() const;

    /// \brief Stream output.
    /// \param os the std::ostream.
    /// \param coordinate The ElevatedUTMLocation to output.
    /// \returns the updated std::ostream reference.
    friend std::ostream& operator << (std::ostream& os,
                                      const ElevatedUTMLocation& coordinate);
private:
    /// \brief The Zone in the UTM system.
    std::string _zone;

};


inline std::ostream& operator << (std::ostream& os, const ElevatedUTMLocation& coordinate)
{
    os << coordinate.x << ", " << coordinate.y << "," << coordinate.z << ", " << coordinate._zone;
    return os;
}


} } // namespace ofx::Geo


namespace std {


template <> struct hash<ofx::Geo::UTMLocation>
{
    size_t operator()(const ofx::Geo::UTMLocation& coordinate) const
    {
        return coordinate.hash();
    }
};


template <> struct hash<ofx::Geo::ElevatedUTMLocation>
{
    size_t operator()(const ofx::Geo::ElevatedUTMLocation& coordinate) const
    {
        return coordinate.hash();
    }
};



} // namespace std
