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
#include "ofx/Geo/Coordinate.h"


namespace ofx {
namespace Geo {


/// \brief A bounding box using Geo Coordinates.
class CoordinateBounds
{
public:
    /// \brief Create an empty CooridinateBounds.
    CoordinateBounds();

    /// \brief Create CoordinateBounds from two Coordinates.
    /// \param northwest The northwest coordinate of the CoordinateBounds.
    /// \param southeast The southeast coordinate of the CoordinateBounds.
    CoordinateBounds(const Coordinate& northwest, const Coordinate& southeast);

    /// \brief Destroy the CooridinateBounds.
    virtual ~CoordinateBounds();

    /// \brief Get the northwest corner of the CooridinateBounds.
    /// \returns the northwest corner of the CooridinateBounds.
    const Coordinate& getNorthwest() const;

    /// \brief Set the northwest corner of the CooridinateBounds.
    /// \param northwest The northwest corner of the CooridinateBounds.
    void setNorthwest(const Coordinate& northwest);

    /// \brief Get the southeast corner of the CooridinateBounds.
    /// \returns the southeast corner of the CooridinateBounds.
    const Coordinate& getSoutheast() const;

    /// \brief Set the southeast corner of the CooridinateBounds.
    /// \param northwest The southeast corner of the CooridinateBounds.
    void setSoutheast(const Coordinate& southeast);

private:
    /// \brief the northwest corner of the CoordinateBounds.
    Coordinate _northwest;

    /// \brief the southeast corner of the CoordinateBounds.
    Coordinate _southeast;
    
};


} } // namespace ofx::Geo
