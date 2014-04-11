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


namespace ofx {
namespace Geo {


/// \brief A Location defines a latitude / longitude pair.
class Coordinates
{
public:
    /// \brief Create 0, 0 Coordinates.
    Coordinates();

    /// \brief Create a coordinate with given latitude and logitude.
    /// \param latitude The latitude in degrees.
    /// \param longitude The longitude in degrees.
	Coordinates(double latitude, double longitude);

    /// \returns the latitude in degrees.
    double getLatitude() const;

    /// \returns the longitude in degrees.
    double getLongitude() const;

    /// \brief Set the latitude in degrees.
    /// \param latitude the latitude in degrees.
    void setLatitude(double latitude);

    /// \brief Set the longitude in degrees.
    /// \param the longitude in degrees.
    void setLongitude(double longitude);

private:
    double _latitude; ///< \brief the latitude in degrees.
    double _longitude; ///< \brief the longitude in degrees.

};


} } // namespace ofx::Geo
