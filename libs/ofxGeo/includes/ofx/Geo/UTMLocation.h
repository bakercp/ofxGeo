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


#include <iostream>


namespace ofx {
namespace Geo {


/// \brief Defines a location in Universal Transverse Mercator (UTM) space.
/// \sa http://en.wikipedia.org/wiki/Universal_Transverse_Mercator_coordinate_system
class UTMLocation
{
public:
    /// \brief Create an empty UTMLocation.
    UTMLocation();

    /// \brief Create an empty UTMLocation with the given values.
    /// \param northing the northing in meters.
    /// \param easting the easting in meters.
    /// \param zone the zone id.
	UTMLocation(double northing, double easting, const std::string& zone);

    /// \brief Destory the UTMLocation.
    virtual ~UTMLocation();

    /// \brief Get the northing in meters.
    /// \returns the northing in meters.
    double getNorthing() const;

    /// \brief Get the easting in meters.
    /// \returns the easting in meters.
    double getEasting() const;

    /// \brief Get the zone id.
    /// \returns the zone id.
    const std::string& getZone() const;

    /// \brief Set the northing in meters.
    /// \param northing the northing in meters.
    void setNorthing(double northing);

    /// \brief Set the easting in meters.
    /// \param easting the easting in meters.
    void setEasting(double easting);

    /// \brief Set the zone id.
    /// \param zone the zone id.
    void setZone(const std::string& zone);

    /// \brief Stream output.
    /// \param os the std::ostream.
    /// \param location The UTMLocation to output.
    /// \returns the updated std::ostream reference.
    friend std::ostream& operator << (std::ostream& os,
                                      const UTMLocation& location);

private:
    double _northing;
        ///< \brief The "northing" coordinate in the UTM system.

    double _easting;
        ///< \brief The "easting" coordinate in the UTM system.

    std::string _zone;
        ///< \brief The Zone in the UTM system.
};


inline std::ostream& operator<<(std::ostream& os, const UTMLocation& location)
{
    os << location.getNorthing() << ", " << location.getEasting() << ", " << location.getZone();
    return os;
}


} } // namespace ofx::Geo
