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


#include "ofx/Geo/Utils.h"
#include "ofx/Geo/Coordinate.h"
#include "ofx/Geo/UTMLocation.h"
#include "UTM/UTM.h"
#include "ofConstants.h"
#include "ofMath.h"


namespace ofx {
namespace Geo {


const double Utils::EARTH_RADIUS_KM = 6371.01;
const double Utils::MIN_LATITUDE_RADIANS = - TWO_PI;
const double Utils::MAX_LATITUDE_RADIANS =   TWO_PI;
const double Utils::MIN_LATITUDE_DEGREES = Utils::MIN_LATITUDE_RADIANS * RAD_TO_DEG;
const double Utils::MAX_LATITUDE_DEGREES = Utils::MAX_LATITUDE_RADIANS * RAD_TO_DEG;
const double Utils::MIN_LONGITUDE_RADIANS = - PI;;
const double Utils::MAX_LONGITUDE_RADIANS =   PI;
const double Utils::MIN_LONGITUDE_DEGREES = Utils::MIN_LONGITUDE_RADIANS * RAD_TO_DEG;
const double Utils::MAX_LONGITUDE_DEGREES = Utils::MAX_LONGITUDE_RADIANS * RAD_TO_DEG;


std::vector<Coordinate> Utils::decodeGeoPolyline(const std::string& encodedGeoPolyline)
{
    std::vector<Coordinate> polyline;

    std::size_t index = 0;

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
    double lat0 = coordinate0.getLatitudeRad();
    double lon0 = coordinate0.getLongitudeRad();
    double lat1 = coordinate1.getLatitudeRad();
    double lon1 = coordinate1.getLongitudeRad();

    double sum = sin(lat0) * sin(lat1)
               + cos(lat0) * cos(lat1) * cos(lon1 - lon0);

    return EARTH_RADIUS_KM * acos(sum);

}


double Utils::distanceHaversine(const Coordinate& coordinate0,
                                   const Coordinate& coordinate1)
{
    // reference: http://www.movable-type.co.uk/scripts/latlong.html

    double deltaLat = coordinate1.getLatitudeRad() - coordinate0.getLatitudeRad();
    double deltaLon = coordinate1.getLongitudeRad() - coordinate0.getLongitudeRad();

    double lat0 = coordinate0.getLatitudeRad();
    double lat1 = coordinate1.getLatitudeRad();

    double s0 = sin(deltaLat / 2.0);
    double s1 = sin(deltaLon / 2.0);

    double a = s0 * s0 + s1 * s1 * cos(lat0) * cos(lat1);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS_KM * c;
}


double Utils::bearingHaversine(const Coordinate& coordinate0,
                                  const Coordinate& coordinate1)
{
    // reference: http://www.movable-type.co.uk/scripts/latlong.html

    double deltaLon = coordinate1.getLongitudeRad() - coordinate0.getLongitudeRad();

    double lat0 = coordinate0.getLatitudeRad();
    double lat1 = coordinate1.getLatitudeRad();

    double y = sin(deltaLon) * cos(lat1);
    double x = cos(lat0) * cos(lat1) -
               sin(lat0) * cos(lat1) * cos(deltaLon);

    return ofWrapDegrees(RAD_TO_DEG * atan2(y, x));

}


Coordinate Utils::midpoint(const Coordinate& coordinate0,
                              const Coordinate& coordinate1)
{
    // reference: http://www.movable-type.co.uk/scripts/latlong.html

    double deltaLon = coordinate1.getLongitudeRad() - coordinate0.getLongitudeRad();

    double lat0 = coordinate0.getLatitudeRad();
    double lat1 = coordinate1.getLatitudeRad();

    double lon0 = coordinate1.getLongitudeRad();

    double Bx = cos(lat1) * cos(deltaLon);
    double By = cos(lat1) * sin(deltaLon);

    double cL0 = (cos(lat0) + Bx);

    double t0 = sin(lat0) + sin(lat1);
    double t1 = sqrt(cL0 * cL0 + By * By);

    double lat3 = RAD_TO_DEG * atan2(t0, t1);
    double lon3 = RAD_TO_DEG * atan2(By, cL0) + lon0;

    return Coordinate(lat3, lon3);

}


UTMLocation Utils::toUTM(const Coordinate& coordinate)
{
    double northing;
    double easting;

    char zoneBuffer[1024];

    UTM::LLtoUTM(coordinate.getLatitude(),
                 coordinate.getLongitude(),
                 northing,
                 easting,
                 zoneBuffer);

    std::string zone = std::strlen(zoneBuffer) > 0 ? "" : std::string(zoneBuffer);

    return UTMLocation(easting, northing, zone);
}


Coordinate Utils::toCoordinate(const UTMLocation& location)
{
    double latitude = 0;
    double longitude = 0;

    UTM::UTMtoLL(location.getNorthing(),
                 location.getEasting(),
                 location.getZone().c_str(),
                 latitude,
                 longitude);

    return Coordinate(latitude, longitude);
}


Coordinate Utils::randomCoordinate()
{
    return Coordinate(ofRandom(MIN_LATITUDE_DEGREES, MAX_LATITUDE_DEGREES),
                      ofRandom(MIN_LONGITUDE_DEGREES, MAX_LONGITUDE_DEGREES));
}


UTMLocation Utils::randomUTMLocation()
{
    return toUTM(randomCoordinate());
}


ofVec2d Utils::toVec(const UTMLocation& location)
{
    return ofVec2d(location.getEasting(), location.getNorthing());
}


ofVec2d Utils::toVec(const Coordinate& coordinate)
{
    return toVec(toUTM(coordinate));
}


} } // namespace ofx::Geo
