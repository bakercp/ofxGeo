//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofx/Geo/GeoUtils.h"
#include "ofx/Geo/Coordinate.h"
#include "ofx/Geo/UTMLocation.h"
#include "UTM/UTM.h"
#include "ofConstants.h"
#include "ofMath.h"


namespace ofx {
namespace Geo {


const double GeoUtils::EARTH_RADIUS_KM = 6371.01;
const double GeoUtils::MIN_LATITUDE_RADIANS = - glm::two_pi<double>();
const double GeoUtils::MAX_LATITUDE_RADIANS =   glm::two_pi<double>();
const double GeoUtils::MIN_LATITUDE_DEGREES = glm::degrees(GeoUtils::MIN_LATITUDE_RADIANS);
const double GeoUtils::MAX_LATITUDE_DEGREES = glm::degrees(GeoUtils::MAX_LATITUDE_RADIANS);
const double GeoUtils::MIN_LONGITUDE_RADIANS = - glm::pi<double>();
const double GeoUtils::MAX_LONGITUDE_RADIANS =   glm::pi<double>();
const double GeoUtils::MIN_LONGITUDE_DEGREES = glm::degrees(GeoUtils::MIN_LONGITUDE_RADIANS);
const double GeoUtils::MAX_LONGITUDE_DEGREES = glm::degrees(GeoUtils::MAX_LONGITUDE_RADIANS);


std::vector<Coordinate> GeoUtils::decodeGeoPolyline(const std::string& encodedGeoPolyline)
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


double GeoUtils::distanceSpherical(const Coordinate& coordinate0,
                                   const Coordinate& coordinate1)
{
    double lat0 = coordinate0.getLatitudeRad();
    double lon0 = coordinate0.getLongitudeRad();
    double lat1 = coordinate1.getLatitudeRad();
    double lon1 = coordinate1.getLongitudeRad();

    double sum = std::sin(lat0) * std::sin(lat1)
               + std::cos(lat0) * std::cos(lat1) * std::cos(lon1 - lon0);

    return EARTH_RADIUS_KM * acos(sum);

}


double GeoUtils::distanceHaversine(const Coordinate& coordinate0,
                                   const Coordinate& coordinate1)
{
    // reference: http://www.movable-type.co.uk/scripts/latlong.html

    double deltaLat = coordinate1.getLatitudeRad() - coordinate0.getLatitudeRad();
    double deltaLon = coordinate1.getLongitudeRad() - coordinate0.getLongitudeRad();

    double lat0 = coordinate0.getLatitudeRad();
    double lat1 = coordinate1.getLatitudeRad();

    double s0 = std::sin(deltaLat / 2.0);
    double s1 = std::sin(deltaLon / 2.0);

    double a = s0 * s0 + s1 * s1 * std::cos(lat0) * std::cos(lat1);

    double c = 2 * std::atan2(sqrt(a), std::sqrt(1 - a));

    return EARTH_RADIUS_KM * c;
}


double GeoUtils::bearingHaversine(const Coordinate& coordinate0,
                                  const Coordinate& coordinate1)
{
    // reference: http://www.movable-type.co.uk/scripts/latlong.html

    double deltaLon = coordinate1.getLongitudeRad() - coordinate0.getLongitudeRad();

    double lat0 = coordinate0.getLatitudeRad();
    double lat1 = coordinate1.getLatitudeRad();

    double y = std::sin(deltaLon) * std::cos(lat1);
    double x = std::cos(lat0) * std::cos(lat1) -
               std::sin(lat0) * std::cos(lat1) * cos(deltaLon);

    return ofWrapDegrees(glm::degrees(std::atan2(y, x)));

}


Coordinate GeoUtils::midpoint(const Coordinate& coordinate0,
                              const Coordinate& coordinate1)
{
    // reference: http://www.movable-type.co.uk/scripts/latlong.html

    double deltaLon = coordinate1.getLongitudeRad() - coordinate0.getLongitudeRad();

    double lat0 = coordinate0.getLatitudeRad();
    double lat1 = coordinate1.getLatitudeRad();

    double lon0 = coordinate1.getLongitudeRad();

    double Bx = std::cos(lat1) * std::cos(deltaLon);
    double By = std::cos(lat1) * std::sin(deltaLon);

    double cL0 = std::cos(lat0) + Bx;

    double t0 = std::sin(lat0) + std::sin(lat1);
    double t1 = std::sqrt(cL0 * cL0 + By * By);

    double lat3 = glm::degrees(std::atan2(t0, t1));
    double lon3 = glm::degrees(std::atan2(By, cL0)) + lon0;

    return Coordinate(lat3, lon3);

}


UTMLocation GeoUtils::toUTM(const Coordinate& coordinate)
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


Coordinate GeoUtils::toCoordinate(const UTMLocation& location)
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


Coordinate GeoUtils::randomCoordinate()
{
    return Coordinate(ofRandom(MIN_LATITUDE_DEGREES, MAX_LATITUDE_DEGREES),
                      ofRandom(MIN_LONGITUDE_DEGREES, MAX_LONGITUDE_DEGREES));
}


UTMLocation GeoUtils::randomUTMLocation()
{
    return toUTM(randomCoordinate());
}


glm::dvec2 GeoUtils::toVec(const UTMLocation& location)
{
    return glm::dvec2(location.getEasting(), location.getNorthing());
}


glm::dvec2 GeoUtils::toVec(const Coordinate& coordinate)
{
    return toVec(toUTM(coordinate));
}


} } // namespace ofx::Geo
