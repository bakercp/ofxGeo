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
#include "ofx/Geo/Coordinate.h"
#include "ofx/Geo/UTMLocation.h"
#include "UTM/UTM.h"
#include "ofConstants.h"


namespace ofx {
namespace Geo {


const double Utils::EARTH_RADIUS_KM = 6371.01;


std::vector<Coordinate> Utils::decodeGeoPolyline(const std::string& encodedGeoPolyline)
{
    std::vector<Coordinate> polyline;

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

        polyline.push_back(Coordinate(lat / 1E5, lng / 1E5));
    }

    return polyline;
}


double Utils::distanceSpherical(const Coordinate& coordinate0,
                                const Coordinate& coordinate1)
{
    double lat0 = DEG_TO_RAD * coordinate0.getLatitude();
    double lon0 = DEG_TO_RAD * coordinate0.getLongitude();
    double lat1 = DEG_TO_RAD * coordinate1.getLatitude();
    double lon1 = DEG_TO_RAD * coordinate1.getLongitude();

    double sum = sin(lat0) * sin(lat1)
               + cos(lat0) * cos(lat1) * cos(lon1 - lon0);

    return EARTH_RADIUS_KM * acos(sum);

}


double Utils::distanceHaversine(const Coordinate& coordinate0,
                                const Coordinate& coordinate1)
{
    // reference: http://www.movable-type.co.uk/scripts/latlong.html

    double deltaLatRad = DEG_TO_RAD * (coordinate1.getLatitude() - coordinate0.getLatitude());
    double deltaLonRad = DEG_TO_RAD * (coordinate1.getLongitude() - coordinate0.getLongitude());

    double lat0 = DEG_TO_RAD * coordinate0.getLatitude();
    double lat1 = DEG_TO_RAD * coordinate1.getLatitude();

    double s0 = sin(deltaLatRad / 2.0);
    double s1 = sin(deltaLonRad / 2.0);

    double a = s0 * s0 + s1 * s1 * cos(lat0) * cos(lat1);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS_KM * c;
}


double Utils::bearingHaversine(const Coordinate& coordinate0,
                               const Coordinate& coordinate1)
{
    // reference: http://www.movable-type.co.uk/scripts/latlong.html

    double deltaLatRad = DEG_TO_RAD * (coordinate0.getLatitude() - coordinate1.getLatitude());
    double deltaLonRad = DEG_TO_RAD * (coordinate0.getLongitude() - coordinate1.getLongitude());

    double lat0 = DEG_TO_RAD * coordinate0.getLatitude();
    double lat1 = DEG_TO_RAD * coordinate1.getLatitude();

    double s0 = sin(deltaLatRad / 2.0);
    double s1 = sin(deltaLonRad / 2.0);

    double y = sin(deltaLonRad) * cos(lat1);
    double x = cos(lat0) * cos(lat1) -
               sin(lat0) * cos(lat1) * cos(deltaLonRad);

    return RAD_TO_DEG * atan2(y, x);
}


Coordinate Utils::midpoint(const Coordinate& coordinate0,
                            const Coordinate& coordinate1)
{
    // reference: http://www.movable-type.co.uk/scripts/latlong.html

    double deltaLatRad = DEG_TO_RAD * (coordinate0.getLatitude() - coordinate1.getLatitude());
    double deltaLonRad = DEG_TO_RAD * (coordinate0.getLongitude() - coordinate1.getLongitude());

    double lat0 = DEG_TO_RAD * coordinate0.getLatitude();
    double lat1 = DEG_TO_RAD * coordinate1.getLatitude();

    double lon0 = DEG_TO_RAD * coordinate1.getLongitude();
    double lon1 = DEG_TO_RAD * coordinate1.getLongitude();

    double Bx = cos(lat1) * cos(deltaLonRad);
    double By = cos(lat1) * sin(deltaLonRad);

    double t0 = sin(lat0) + sin(lat1);
    double t1 = sqrt( (cos(lat0) + Bx ) * (cos(lat0) + Bx) + By * By );

    double lat3 = atan2(t0, t1);
    double lon3 = lon0 + atan2(By, cos(lat0) + Bx);

    return Coordinate(lat3, lon3);
}


UTMLocation Utils::toUTM(const Coordinate& coordinate)
{
    double northing;
    double easting;
    char zone;

    UTM::LLtoUTM(coordinate.getLatitude(),
                 coordinate.getLongitude(),
                 northing,
                 easting,
                 &zone);

    return UTMLocation(northing, easting, zone);
}

Coordinate Utils::toCoordinate(const UTMLocation& location)
{
    double latitude = 0;
    double longitude = 0;

    char zone = location.getZone();

    UTM::UTMtoLL(location.getNorthing(),
                 location.getEasting(),
                 &zone,
                 latitude,
                 longitude);

    return Coordinate(latitude, longitude);
}


ofVec2f Utils::toVec(const UTMLocation& location)
{
    return ofVec2f(location.getEasting(), location.getNorthing());
}


ofVec2f Utils::toVec(const Coordinate& coordinate)
{
    return toVec(toUTM(coordinate));
}


} } // namespace ofx::Geo
