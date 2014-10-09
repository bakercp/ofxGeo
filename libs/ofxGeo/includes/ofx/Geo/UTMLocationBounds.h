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
#include "ofx/Geo/UTMLocation.h"


namespace ofx {
namespace Geo {


/// \brief A bounding box using UTM Locations.
class UTMLocationBounds
{
public:
    /// \brief Create an empty UTMLocationBounds.
    UTMLocationBounds();

    /// \brief Create UTMLocationBounds from two UTM Locations.
    /// \param northwest The northwest location of the UTMLocationBounds.
    /// \param southeast The southeast location of the UTMLocationBounds.
    UTMLocationBounds(const UTMLocation& northwest, const UTMLocation& southeast);

    /// \brief Destroy the UTMLocationBounds.
    virtual ~UTMLocationBounds();

    /// \brief Get the northwest corner of the UTMLocationBounds.
    /// \returns the northwest corner of the UTMLocationBounds.
    const UTMLocation& getNorthwest() const;

    /// \brief Set the northwest corner of the UTMLocationBounds.
    /// \param northwest The northwest corner of the UTMLocationBounds.
    void setNorthwest(const UTMLocation& northwest);

    /// \brief Get the southeast corner of the UTMLocationBounds.
    /// \returns the southeast corner of the UTMLocationBounds.
    const UTMLocation& getSoutheast() const;

    /// \brief Set the southeast corner of the UTMLocationBounds.
    /// \param northwest The southeast corner of the UTMLocationBounds.
    void setSoutheast(const UTMLocation& southeast);

private:
    /// \brief the northwest corner of the UTMLocationBounds.
    UTMLocation _northwest;

    /// \brief the southeast corner of the UTMLocationBounds.
    UTMLocation _southeast;
    
};


} } // namespace ofx::Geo
