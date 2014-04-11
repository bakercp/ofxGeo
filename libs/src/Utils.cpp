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


#include "ofx/Geo/Utils.h"
#include "ofx/Geo/Coordinates.h"
#include "ofConstants.h"


namespace ofx {
namespace Geo {


const double Utils::EARTH_RADIUS_KM = 6371.01;


std::vector<Coordinates> Utils::decodeGeoPolyline(const std::string& encodedGeoPolyline)
{
    std::vector<Coordinates> polyline;

    int index = 0;

    std::size_t len = encodedGeoPolyline.length();

    int lat = 0;
    int lng = 0;

    while (index < len)
    {
        int b = 0;
        int shift = 0;
        int result = 0;

        do
        {
            b = encodedGeoPolyline[index++] - 63;
            result |= (b & 0x1f) << shift;
            shift += 5;
        }
        while (b >= 0x20);

        int dlat = ((result & 1) != 0 ? ~(result >> 1) : (result >> 1));

        lat += dlat;

        shift = 0;
        result = 0;

        do
        {
            b = encodedGeoPolyline[index++] - 63;
            result |= (b & 0x1f) << shift;
            shift += 5;
        }
        while (b >= 0x20);

        int dlng = ((result & 1) != 0 ? ~(result >> 1) : (result >> 1));

        lng += dlng;

        polyline.push_back(Coordinates(lat / 1E5, lng / 1E5));
    }

    return polyline;
}


double Utils::distanceSpherical(const Coordinates& location0,
                                const Coordinates& location1)
{
    double lat0 = DEG_TO_RAD * location0.getLatitude();
    double lon0 = DEG_TO_RAD * location0.getLongitude();
    double lat1 = DEG_TO_RAD * location1.getLatitude();
    double lon1 = DEG_TO_RAD * location1.getLongitude();

    double sum = sin(lat0) * sin(lat1)
               + cos(lat0) * cos(lat1) * cos(lon1 - lon0);

    return EARTH_RADIUS_KM * acos(sum);

}


double Utils::distanceHaversine(const Coordinates& location0,
                                const Coordinates& location1)
{
    // reference: http://www.movable-type.co.uk/scripts/latlong.html

    double deltaLatRad = DEG_TO_RAD * (location1.getLatitude() - location0.getLatitude());
    double deltaLonRad = DEG_TO_RAD * (location1.getLongitude() - location0.getLongitude());

    double lat0 = DEG_TO_RAD * location0.getLatitude();
    double lat1 = DEG_TO_RAD * location1.getLatitude();

    double s0 = sin(deltaLatRad / 2.0);
    double s1 = sin(deltaLonRad / 2.0);

    double a = s0 * s0 + s1 * s1 * cos(lat0) * cos(lat1);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS_KM * c;
}


double Utils::bearingHaversine(const Coordinates& location0,
                               const Coordinates& location1)
{
    // reference: http://www.movable-type.co.uk/scripts/latlong.html

    double deltaLatRad = DEG_TO_RAD * (location0.getLatitude() - location1.getLatitude());
    double deltaLonRad = DEG_TO_RAD * (location0.getLongitude() - location1.getLongitude());

    double lat0 = DEG_TO_RAD * location0.getLatitude();
    double lat1 = DEG_TO_RAD * location1.getLatitude();

    double s0 = sin(deltaLatRad / 2.0);
    double s1 = sin(deltaLonRad / 2.0);

    double y = sin(deltaLonRad) * cos(lat1);
    double x = cos(lat0) * cos(lat1) -
               sin(lat0) * cos(lat1) * cos(deltaLonRad);

    return RAD_TO_DEG * atan2(y, x);
}


} } // namespace ofx::Geo
