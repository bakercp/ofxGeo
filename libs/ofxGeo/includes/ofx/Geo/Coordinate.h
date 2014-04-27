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


/// \brief A Location defines a latitude / longitude pair in degrees.
class Coordinate
{
public:
    /// \brief Create a 0, 0 Coordinate.
    Coordinate();

    /// \brief Create a Coordinate with given latitude and logitude.
    /// \param latitude The latitude in degrees.
    /// \param longitude The longitude in degrees.
	Coordinate(double latitude, double longitude);

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

    /// \brief Stream output.
    /// \param os the std::ostream.
    /// \param coordinate The Coordiante to output.
    /// \returns the updated std::ostream reference.
    friend std::ostream& operator << (std::ostream& os,
                                      const Coordinate& coordinate);

private:
    double _latitude; ///< \brief the latitude in degrees.
    double _longitude; ///< \brief the longitude in degrees.

};


inline std::ostream& operator<<(std::ostream& os, const Coordinate& coordinate)
{
    os << coordinate.getLatitude() << ", " << coordinate.getLongitude();
    return os;
}


} } // namespace ofx::Geo
