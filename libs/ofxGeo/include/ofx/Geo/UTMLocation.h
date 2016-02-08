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


#include <iostream>
#include <sstream>
#include "ofVec3d.h"


namespace ofx {
namespace Geo {


/// \brief Defines a location in Universal Transverse Mercator (UTM) space.
/// \sa http://en.wikipedia.org/wiki/Universal_Transverse_Mercator_coordinate_system
class UTMLocation: public ofVec2d
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


class ElevatedUTMLocation: public ofVec3d
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
