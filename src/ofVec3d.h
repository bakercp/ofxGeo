#pragma once

#include "ofVec2d.h"
#include "ofVec4d.h"
#include "ofConstants.h"

#include <cmath>
#include <iostream>

class ofVec3d {
public:
	double x,y,z;
    
    static const int DIM = 3;
	
	ofVec3d();
	ofVec3d( double _x, double _y, double _z=0 );
	/// assigns scalar to x, y, and z
	explicit ofVec3d( double _scalar );
	
    ofVec3d( const ofVec2d& vec );
    ofVec3d( const ofVec4d& vec );
	
	double * getPtr() {
		return (double*)&x;
	}
	const double * getPtr() const {
		return (const double *)&x;
	}
	
	double& operator[]( int n ){
		return getPtr()[n];
	}
	
	double operator[]( int n ) const {
		return getPtr()[n];
	}
	
    
	// Getters and Setters.
    //
    void set( double _x, double _y, double _z = 0 );
    void set( const ofVec3d& vec );
	void set( double _scalar );
	
    // Check similarity/equality.
    //
    bool operator==( const ofVec3d& vec ) const;
    bool operator!=( const ofVec3d& vec ) const;
    bool match( const ofVec3d& vec, double tolerance=0.0001 ) const;
    /**
	 * Checks if vectors look in the same direction.
	 */
    bool isAligned( const ofVec3d& vec, double tolerance=0.0001 ) const;
    bool align( const ofVec3d& vec, double tolerance=0.0001 ) const;
    bool isAlignedRad( const ofVec3d& vec, double tolerance=0.0001 ) const;
    bool alignRad( const ofVec3d& vec, double tolerance=0.0001 ) const;
	
	
    // Operator overloading for ofVec3d
    //
    ofVec3d  operator+( const ofVec3d& pnt ) const;
    ofVec3d& operator+=( const ofVec3d& pnt );
    ofVec3d  operator-( const ofVec3d& vec ) const;
    ofVec3d& operator-=( const ofVec3d& vec );
    ofVec3d  operator*( const ofVec3d& vec ) const;
    ofVec3d& operator*=( const ofVec3d& vec );
    ofVec3d  operator/( const ofVec3d& vec ) const;
    ofVec3d& operator/=( const ofVec3d& vec );
    ofVec3d  operator-() const;
	
    //operator overloading for double
    //
	//    void 	  operator=( const double f);
    ofVec3d  operator+( const double f ) const;
    ofVec3d& operator+=( const double f );
 	ofVec3d  operator-( const double f ) const;
    ofVec3d& operator-=( const double f );
    ofVec3d  operator*( const double f ) const;
    ofVec3d& operator*=( const double f );
    ofVec3d  operator/( const double f ) const;
    ofVec3d& operator/=( const double f );
	
	friend ostream& operator<<(ostream& os, const ofVec3d& vec);
	friend istream& operator>>(istream& is, ofVec3d& vec);
	
    //Scale
    //
    ofVec3d  getScaled( const double length ) const;
    ofVec3d& scale( const double length );
    
	
    // Rotation
    //
    ofVec3d  getRotated( double angle, const ofVec3d& axis ) const;
    ofVec3d  getRotatedRad( double angle, const ofVec3d& axis ) const;
    ofVec3d& rotate( double angle, const ofVec3d& axis );
    ofVec3d& rotateRad( double angle, const ofVec3d& axis );
    ofVec3d  getRotated(double ax, double ay, double az) const;
    ofVec3d  getRotatedRad(double ax, double ay, double az) const;
    ofVec3d& rotate(double ax, double ay, double az);
    ofVec3d& rotateRad(double ax, double ay, double az);
    
    
    // Rotation - point around pivot
    //    
    ofVec3d   getRotated( double angle, const ofVec3d& pivot, const ofVec3d& axis ) const;
    ofVec3d&  rotate( double angle, const ofVec3d& pivot, const ofVec3d& axis );
    ofVec3d   getRotatedRad( double angle, const ofVec3d& pivot, const ofVec3d& axis ) const;
    ofVec3d&  rotateRad( double angle, const ofVec3d& pivot, const ofVec3d& axis );    
	
	
    // Map point to coordinate system defined by origin, vx, vy, and vz.
    //
    ofVec3d getMapped( const ofVec3d& origin,
					  const ofVec3d& vx,
					  const ofVec3d& vy,
					  const ofVec3d& vz ) const;
    ofVec3d& map( const ofVec3d& origin,
				 const ofVec3d& vx,
				 const ofVec3d& vy,
				 const ofVec3d& vz );
	
	
    // Distance between two points.
    //
    double distance( const ofVec3d& pnt) const;
    double squareDistance( const ofVec3d& pnt ) const;
	
	
    // Linear interpolation.
    //
    /**
	 * p==0.0 results in this point, p==0.5 results in the
	 * midpoint, and p==1.0 results in pnt being returned.
	 */
    ofVec3d   getInterpolated( const ofVec3d& pnt, double p ) const;
    ofVec3d&  interpolate( const ofVec3d& pnt, double p );
    ofVec3d   getMiddle( const ofVec3d& pnt ) const;
    ofVec3d&  middle( const ofVec3d& pnt );
    ofVec3d&  average( const ofVec3d* points, int num );
    
	
    // Normalization
    //
    ofVec3d  getNormalized() const;
    ofVec3d& normalize();
	
	
    // Limit length.
    //
    ofVec3d  getLimited(double max) const;
    ofVec3d& limit(double max);
	
	
    // Perpendicular vector.
    //
    ofVec3d  getCrossed( const ofVec3d& vec ) const;
    ofVec3d& cross( const ofVec3d& vec );
    /**
	 * Normalized perpendicular.
	 */
    ofVec3d  getPerpendicular( const ofVec3d& vec ) const;
    ofVec3d& perpendicular( const ofVec3d& vec );
	
	
    // Length
    //
    double length() const;
    double lengthSquared() const;

    /**
	 * Angle (deg) between two vectors.
	 * This is an unsigned relative angle from 0 to 180.
	 * http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/index.htm
	 */
    double angle( const ofVec3d& vec ) const;
    double angleRad( const ofVec3d& vec ) const;
	
	
    // Dot Product
    //
    double dot( const ofVec3d& vec ) const;
	
	
	
    //-----------------------------------------------
    // this methods are deprecated in 006 please use:
	
    // getScaled
    ofVec3d rescaled( const double length ) const;
	
    // scale
    ofVec3d& rescale( const double length );
	
    // getRotated
    ofVec3d rotated( double angle, const ofVec3d& axis ) const;
	
    // getRotated should this be const???
    ofVec3d rotated(double ax, double ay, double az);
	
    // getNormalized
    ofVec3d normalized() const;
	
    // getLimited
    ofVec3d limited(double max) const;
	
    // getCrossed
    ofVec3d crossed( const ofVec3d& vec ) const;
	
    // getPerpendicular
    ofVec3d perpendiculared( const ofVec3d& vec ) const;
    
    // use getMapped
    ofVec3d  mapped( const ofVec3d& origin,
					const ofVec3d& vx,
					const ofVec3d& vy,
					const ofVec3d& vz ) const;
	
    // use squareDistance
    double  distanceSquared( const ofVec3d& pnt ) const;
	
    // use getInterpolated
    ofVec3d 	interpolated( const ofVec3d& pnt, double p ) const;
	
    // use getMiddle
    ofVec3d 	middled( const ofVec3d& pnt ) const;
    
    // use getRotated
    ofVec3d 	rotated( double angle,
						const ofVec3d& pivot,
						const ofVec3d& axis ) const;    

    // return all zero vector
    static ofVec3d zero() { return ofVec3d(0, 0, 0); }
    
    // return all one vector
    static ofVec3d one() { return ofVec3d(1, 1, 1); }
};




// Non-Member operators
//
//
ofVec3d operator+( double f, const ofVec3d& vec );
ofVec3d operator-( double f, const ofVec3d& vec );
ofVec3d operator*( double f, const ofVec3d& vec );
ofVec3d operator/( double f, const ofVec3d& vec );


/////////////////
// Implementation
/////////////////


inline ofVec3d::ofVec3d( const ofVec2d& vec ):x(vec.x), y(vec.y), z(0) {}
inline ofVec3d::ofVec3d( const ofVec4d& vec ):x(vec.x), y(vec.y), z(vec.z) {}
inline ofVec3d::ofVec3d(): x(0), y(0), z(0) {};
inline ofVec3d::ofVec3d( double _all ): x(_all), y(_all), z(_all) {};
inline ofVec3d::ofVec3d( double _x, double _y, double _z ):x(_x), y(_y), z(_z) {}


// Getters and Setters.
//
//
inline void ofVec3d::set( double _scalar ) {
	x = _scalar;
	y = _scalar;
	z = _scalar;
}

inline void ofVec3d::set( double _x, double _y, double _z ) {
	x = _x;
	y = _y;
	z = _z;
}

inline void ofVec3d::set( const ofVec3d& vec ) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
}


// Check similarity/equality.
//
//
inline bool ofVec3d::operator==( const ofVec3d& vec ) const {
	return (x == vec.x) && (y == vec.y) && (z == vec.z);
}

inline bool ofVec3d::operator!=( const ofVec3d& vec ) const {
	return (x != vec.x) || (y != vec.y) || (z != vec.z);
}

inline bool ofVec3d::match( const ofVec3d& vec, double tolerance ) const{
	return (fabs(x - vec.x) < tolerance)
	&& (fabs(y - vec.y) < tolerance)
	&& (fabs(z - vec.z) < tolerance);
}

/**
 * Checks if vectors look in the same direction.
 */
inline bool ofVec3d::isAligned( const ofVec3d& vec, double tolerance ) const {
	double angle = this->angle( vec );
	return  angle < tolerance;
}
inline bool ofVec3d::align( const ofVec3d& vec, double tolerance ) const {
    return isAligned( vec, tolerance );
}

inline bool ofVec3d::isAlignedRad( const ofVec3d& vec, double tolerance ) const {
	double angle = this->angleRad( vec );
	return  angle < tolerance;
}
inline bool ofVec3d::alignRad( const ofVec3d& vec, double tolerance ) const {
    return isAlignedRad( vec, tolerance );
}


// Operator overloading for ofVec3d
//
//

inline ostream& operator<<(ostream& os, const ofVec3d& vec) {
	os << vec.x << ", " << vec.y << ", " << vec.z;
	return os;
}

inline istream& operator>>(istream& is, ofVec3d& vec) {
	is >> vec.x;
	is.ignore(2);
	is >> vec.y;
	is.ignore(2);
	is >> vec.z;
	return is;
}

inline ofVec3d ofVec3d::operator+( const ofVec3d& pnt ) const {
	return ofVec3d( x+pnt.x, y+pnt.y, z+pnt.z );
}

inline ofVec3d& ofVec3d::operator+=( const ofVec3d& pnt ) {
	x+=pnt.x;
	y+=pnt.y;
	z+=pnt.z;
	return *this;
}

inline ofVec3d ofVec3d::operator-( const ofVec3d& vec ) const {
	return ofVec3d( x-vec.x, y-vec.y, z-vec.z );
}

inline ofVec3d& ofVec3d::operator-=( const ofVec3d& vec ) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

inline ofVec3d ofVec3d::operator*( const ofVec3d& vec ) const {
	return ofVec3d( x*vec.x, y*vec.y, z*vec.z );
}

inline ofVec3d& ofVec3d::operator*=( const ofVec3d& vec ) {
	x*=vec.x;
	y*=vec.y;
	z*=vec.z;
	return *this;
}

inline ofVec3d ofVec3d::operator/( const ofVec3d& vec ) const {
	return ofVec3d( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y, vec.z!=0 ? z/vec.z : z );
}

inline ofVec3d& ofVec3d::operator/=( const ofVec3d& vec ) {
	vec.x!=0 ? x/=vec.x : x;
	vec.y!=0 ? y/=vec.y : y;
	vec.z!=0 ? z/=vec.z : z;
	return *this;
}

inline ofVec3d ofVec3d::operator-() const {
	return ofVec3d( -x, -y, -z );
}


//operator overloading for double
//
//
//inline void ofVec3d::operator=( const double f){
//	x = f;
//	y = f;
//	z = f;
//}

inline ofVec3d ofVec3d::operator+( const double f ) const {
	return ofVec3d( x+f, y+f, z+f);
}

inline ofVec3d& ofVec3d::operator+=( const double f ) {
	x += f;
	y += f;
	z += f;
	return *this;
}

inline ofVec3d ofVec3d::operator-( const double f ) const {
	return ofVec3d( x-f, y-f, z-f);
}

inline ofVec3d& ofVec3d::operator-=( const double f ) {
	x -= f;
	y -= f;
	z -= f;
	return *this;
}

inline ofVec3d ofVec3d::operator*( const double f ) const {
	return ofVec3d( x*f, y*f, z*f );
}

inline ofVec3d& ofVec3d::operator*=( const double f ) {
	x*=f;
	y*=f;
	z*=f;
	return *this;
}

inline ofVec3d ofVec3d::operator/( const double f ) const {
	if(f == 0) return ofVec3d( x, y, z);
	
	return ofVec3d( x/f, y/f, z/f );
}

inline ofVec3d& ofVec3d::operator/=( const double f ) {
	if(f == 0) return *this;
	
	x/=f;
	y/=f;
	z/=f;
	return *this;
}


//Scale
//
//
inline ofVec3d ofVec3d::rescaled( const double length ) const {
	return getScaled(length);
}
inline ofVec3d ofVec3d::getScaled( const double length ) const {
	double l = (double)sqrt(x*x + y*y + z*z);
	if( l > 0 )
		return ofVec3d( (x/l)*length, (y/l)*length, (z/l)*length );
	else
		return ofVec3d();
}
inline ofVec3d& ofVec3d::rescale( const double length ) {
	return scale(length);
}
inline ofVec3d& ofVec3d::scale( const double length ) {
	double l = (double)sqrt(x*x + y*y + z*z);
	if (l > 0) {
		x = (x/l)*length;
		y = (y/l)*length;
		z = (z/l)*length;
	}
	return *this;
}



// Rotation
//
//
inline ofVec3d ofVec3d::rotated( double angle, const ofVec3d& axis ) const {
	return getRotated(angle, axis);
}
inline ofVec3d ofVec3d::getRotated( double angle, const ofVec3d& axis ) const {
	ofVec3d ax = axis.normalized();
	double a = (double)(angle*DEG_TO_RAD);
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0f - cosa;
	
	return ofVec3d( x*(ax.x*ax.x*cosb + cosa)
				   + y*(ax.x*ax.y*cosb - ax.z*sina)
				   + z*(ax.x*ax.z*cosb + ax.y*sina),
				   x*(ax.y*ax.x*cosb + ax.z*sina)
				   + y*(ax.y*ax.y*cosb + cosa)
				   + z*(ax.y*ax.z*cosb - ax.x*sina),
				   x*(ax.z*ax.x*cosb - ax.y*sina)
				   + y*(ax.z*ax.y*cosb + ax.x*sina)
				   + z*(ax.z*ax.z*cosb + cosa) );
}

inline ofVec3d ofVec3d::getRotatedRad( double angle, const ofVec3d& axis ) const {
	ofVec3d ax = axis.normalized();
	double a = angle;
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0f - cosa;
	
	return ofVec3d( x*(ax.x*ax.x*cosb + cosa)
				   + y*(ax.x*ax.y*cosb - ax.z*sina)
				   + z*(ax.x*ax.z*cosb + ax.y*sina),
				   x*(ax.y*ax.x*cosb + ax.z*sina)
				   + y*(ax.y*ax.y*cosb + cosa)
				   + z*(ax.y*ax.z*cosb - ax.x*sina),
				   x*(ax.z*ax.x*cosb - ax.y*sina)
				   + y*(ax.z*ax.y*cosb + ax.x*sina)
				   + z*(ax.z*ax.z*cosb + cosa) );
}

inline ofVec3d& ofVec3d::rotate( double angle, const ofVec3d& axis ) {
	ofVec3d ax = axis.normalized();
	double a = (double)(angle*DEG_TO_RAD);
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0f - cosa;
	
	double nx = x*(ax.x*ax.x*cosb + cosa)
	+ y*(ax.x*ax.y*cosb - ax.z*sina)
	+ z*(ax.x*ax.z*cosb + ax.y*sina);
	double ny = x*(ax.y*ax.x*cosb + ax.z*sina)
	+ y*(ax.y*ax.y*cosb + cosa)
	+ z*(ax.y*ax.z*cosb - ax.x*sina);
	double nz = x*(ax.z*ax.x*cosb - ax.y*sina)
	+ y*(ax.z*ax.y*cosb + ax.x*sina)
	+ z*(ax.z*ax.z*cosb + cosa);
	x = nx; y = ny; z = nz;
	return *this;
}


inline ofVec3d& ofVec3d::rotateRad(double angle, const ofVec3d& axis ) {
	ofVec3d ax = axis.normalized();
	double a = angle;
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0f - cosa;
	
	double nx = x*(ax.x*ax.x*cosb + cosa)
	+ y*(ax.x*ax.y*cosb - ax.z*sina)
	+ z*(ax.x*ax.z*cosb + ax.y*sina);
	double ny = x*(ax.y*ax.x*cosb + ax.z*sina)
	+ y*(ax.y*ax.y*cosb + cosa)
	+ z*(ax.y*ax.z*cosb - ax.x*sina);
	double nz = x*(ax.z*ax.x*cosb - ax.y*sina)
	+ y*(ax.z*ax.y*cosb + ax.x*sina)
	+ z*(ax.z*ax.z*cosb + cosa);
	x = nx; y = ny; z = nz;
	return *this;
}

// const???
inline ofVec3d ofVec3d::rotated(double ax, double ay, double az) {
	return getRotated(ax,ay,az);
}

inline ofVec3d ofVec3d::getRotated(double ax, double ay, double az) const {
	double a = (double)cos(DEG_TO_RAD*(ax));
	double b = (double)sin(DEG_TO_RAD*(ax));
	double c = (double)cos(DEG_TO_RAD*(ay));
	double d = (double)sin(DEG_TO_RAD*(ay));
	double e = (double)cos(DEG_TO_RAD*(az));
	double f = (double)sin(DEG_TO_RAD*(az));
	
	double nx = c * e * x - c * f * y + d * z;
	double ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
	double nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
	
	return ofVec3d( nx, ny, nz );
}

inline ofVec3d ofVec3d::getRotatedRad(double ax, double ay, double az) const {
	double a = cos(ax);
	double b = sin(ax);
	double c = cos(ay);
	double d = sin(ay);
	double e = cos(az);
	double f = sin(az);
	
	double nx = c * e * x - c * f * y + d * z;
	double ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
	double nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
	
	return ofVec3d( nx, ny, nz );
}


inline ofVec3d& ofVec3d::rotate(double ax, double ay, double az) {
	double a = (double)cos(DEG_TO_RAD*(ax));
	double b = (double)sin(DEG_TO_RAD*(ax));
	double c = (double)cos(DEG_TO_RAD*(ay));
	double d = (double)sin(DEG_TO_RAD*(ay));
	double e = (double)cos(DEG_TO_RAD*(az));
	double f = (double)sin(DEG_TO_RAD*(az));
	
	double nx = c * e * x - c * f * y + d * z;
	double ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
	double nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
	
	x = nx; y = ny; z = nz;
	return *this;
}


inline ofVec3d& ofVec3d::rotateRad(double ax, double ay, double az) {
	double a = cos(ax);
	double b = sin(ax);
	double c = cos(ay);
	double d = sin(ay);
	double e = cos(az);
	double f = sin(az);
	
	double nx = c * e * x - c * f * y + d * z;
	double ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
	double nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
	
	x = nx; y = ny; z = nz;
	return *this;
}


// Rotate point by angle (deg) around line defined by pivot and axis.
//
//
inline ofVec3d ofVec3d::rotated( double angle,
								const ofVec3d& pivot,
								const ofVec3d& axis ) const{
	return getRotated(angle, pivot, axis);
}

inline ofVec3d ofVec3d::getRotated( double angle,
								   const ofVec3d& pivot,
								   const ofVec3d& axis ) const
{
	ofVec3d ax = axis.normalized();
	double tx = x - pivot.x;
	double ty = y - pivot.y;
	double tz = z - pivot.z;
	
	double a = (double)(angle*DEG_TO_RAD);
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0f - cosa;
	
	double xrot = tx*(ax.x*ax.x*cosb + cosa)
	+ ty*(ax.x*ax.y*cosb - ax.z*sina)
	+ tz*(ax.x*ax.z*cosb + ax.y*sina);
	double yrot = tx*(ax.y*ax.x*cosb + ax.z*sina)
	+ ty*(ax.y*ax.y*cosb + cosa)
	+ tz*(ax.y*ax.z*cosb - ax.x*sina);
	double zrot = tx*(ax.z*ax.x*cosb - ax.y*sina)
	+ ty*(ax.z*ax.y*cosb + ax.x*sina)
	+ tz*(ax.z*ax.z*cosb + cosa);
	
	
	return ofVec3d( xrot+pivot.x, yrot+pivot.y, zrot+pivot.z );
}


inline ofVec3d ofVec3d::getRotatedRad( double angle,
									  const ofVec3d& pivot,
									  const ofVec3d& axis ) const
{
	ofVec3d ax = axis.normalized();
	double tx = x - pivot.x;
	double ty = y - pivot.y;
	double tz = z - pivot.z;
	
	double a = angle;
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0f - cosa;
	
	double xrot = tx*(ax.x*ax.x*cosb + cosa)
	+ ty*(ax.x*ax.y*cosb - ax.z*sina)
	+ tz*(ax.x*ax.z*cosb + ax.y*sina);
	double yrot = tx*(ax.y*ax.x*cosb + ax.z*sina)
	+ ty*(ax.y*ax.y*cosb + cosa)
	+ tz*(ax.y*ax.z*cosb - ax.x*sina);
	double zrot = tx*(ax.z*ax.x*cosb - ax.y*sina)
	+ ty*(ax.z*ax.y*cosb + ax.x*sina)
	+ tz*(ax.z*ax.z*cosb + cosa);
	
	
	return ofVec3d( xrot+pivot.x, yrot+pivot.y, zrot+pivot.z );
}


inline ofVec3d& ofVec3d::rotate( double angle,
								const ofVec3d& pivot,
								const ofVec3d& axis )
{
	ofVec3d ax = axis.normalized();
	x -= pivot.x;
	y -= pivot.y;
	z -= pivot.z;
	
	double a = (double)(angle*DEG_TO_RAD);
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0f - cosa;
	
	double xrot = x*(ax.x*ax.x*cosb + cosa)
	+ y*(ax.x*ax.y*cosb - ax.z*sina)
	+ z*(ax.x*ax.z*cosb + ax.y*sina);
	double yrot = x*(ax.y*ax.x*cosb + ax.z*sina)
	+ y*(ax.y*ax.y*cosb + cosa)
	+ z*(ax.y*ax.z*cosb - ax.x*sina);
	double zrot = x*(ax.z*ax.x*cosb - ax.y*sina)
	+ y*(ax.z*ax.y*cosb + ax.x*sina)
	+ z*(ax.z*ax.z*cosb + cosa);
	
	x = xrot + pivot.x;
	y = yrot + pivot.y;
	z = zrot + pivot.z;
	
	return *this;
}


inline ofVec3d& ofVec3d::rotateRad( double angle,
								   const ofVec3d& pivot,
								   const ofVec3d& axis )
{
	ofVec3d ax = axis.normalized();
	x -= pivot.x;
	y -= pivot.y;
	z -= pivot.z;
	
	double a = angle;
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0f - cosa;
	
	double xrot = x*(ax.x*ax.x*cosb + cosa)
	+ y*(ax.x*ax.y*cosb - ax.z*sina)
	+ z*(ax.x*ax.z*cosb + ax.y*sina);
	double yrot = x*(ax.y*ax.x*cosb + ax.z*sina)
	+ y*(ax.y*ax.y*cosb + cosa)
	+ z*(ax.y*ax.z*cosb - ax.x*sina);
	double zrot = x*(ax.z*ax.x*cosb - ax.y*sina)
	+ y*(ax.z*ax.y*cosb + ax.x*sina)
	+ z*(ax.z*ax.z*cosb + cosa);
	
	x = xrot + pivot.x;
	y = yrot + pivot.y;
	z = zrot + pivot.z;
	
	return *this;
}




// Map point to coordinate system defined by origin, vx, vy, and vz.
//
//
inline ofVec3d ofVec3d::mapped( const ofVec3d& origin,
							   const ofVec3d& vx,
							   const ofVec3d& vy,
							   const ofVec3d& vz ) const{
	return getMapped(origin, vx, vy, vz);
}

inline ofVec3d ofVec3d::getMapped( const ofVec3d& origin,
								  const ofVec3d& vx,
								  const ofVec3d& vy,
								  const ofVec3d& vz ) const
{
	return ofVec3d( origin.x + x*vx.x + y*vy.x + z*vz.x,
				   origin.y + x*vx.y + y*vy.y + z*vz.y,
				   origin.z + x*vx.z + y*vy.z + z*vz.z );
}

inline ofVec3d& ofVec3d::map( const ofVec3d& origin,
							 const ofVec3d& vx,
							 const ofVec3d& vy,
							 const ofVec3d& vz )
{
	double xmap = origin.x + x*vx.x + y*vy.x + z*vz.x;
	double ymap =  origin.y + x*vx.y + y*vy.y + z*vz.y;
	z = origin.z + x*vx.z + y*vy.z + z*vz.z;
	x = xmap;
	y = ymap;
	return *this;
}


// Distance between two points.
//
//
inline double ofVec3d::distance( const ofVec3d& pnt) const {
	double vx = x-pnt.x;
	double vy = y-pnt.y;
	double vz = z-pnt.z;
	return (double)sqrt(vx*vx + vy*vy + vz*vz);
}

inline double  ofVec3d::distanceSquared( const ofVec3d& pnt ) const{
	return squareDistance(pnt);
}

inline double  ofVec3d::squareDistance( const ofVec3d& pnt ) const {
	double vx = x-pnt.x;
	double vy = y-pnt.y;
	double vz = z-pnt.z;
	return vx*vx + vy*vy + vz*vz;
}



// Linear interpolation.
//
//
/**
 * p==0.0 results in this point, p==0.5 results in the
 * midpoint, and p==1.0 results in pnt being returned.
 */

inline ofVec3d ofVec3d::interpolated( const ofVec3d& pnt, double p ) const {
	return getInterpolated(pnt,p);
}

inline ofVec3d ofVec3d::getInterpolated( const ofVec3d& pnt, double p ) const {
	return ofVec3d( x*(1-p) + pnt.x*p,
				   y*(1-p) + pnt.y*p,
				   z*(1-p) + pnt.z*p );
}

inline ofVec3d& ofVec3d::interpolate( const ofVec3d& pnt, double p ) {
	x = x*(1-p) + pnt.x*p;
	y = y*(1-p) + pnt.y*p;
	z = z*(1-p) + pnt.z*p;
	return *this;
}


inline ofVec3d ofVec3d::middled( const ofVec3d& pnt ) const {
	return getMiddle(pnt);
}

inline ofVec3d ofVec3d::getMiddle( const ofVec3d& pnt ) const {
	return ofVec3d( (x+pnt.x)/2.0f, (y+pnt.y)/2.0f, (z+pnt.z)/2.0f );
}

inline ofVec3d& ofVec3d::middle( const ofVec3d& pnt ) {
	x = (x+pnt.x)/2.0f;
	y = (y+pnt.y)/2.0f;
	z = (z+pnt.z)/2.0f;
	return *this;
}


// Average (centroid) among points.
// Addition is sometimes useful for calculating averages too.
//
//
inline ofVec3d& ofVec3d::average( const ofVec3d* points, int num ) {
	x = 0.f;
	y = 0.f;
	z = 0.f;
	for( int i=0; i<num; i++) {
		x += points[i].x;
		y += points[i].y;
		z += points[i].z;
	}
	x /= num;
	y /= num;
	z /= num;
	return *this;
}



// Normalization
//
//
inline ofVec3d ofVec3d::normalized() const {
	return getNormalized();
}

inline ofVec3d ofVec3d::getNormalized() const {
	double length = (double)sqrt(x*x + y*y + z*z);
	if( length > 0 ) {
		return ofVec3d( x/length, y/length, z/length );
	} else {
		return ofVec3d();
	}
}

inline ofVec3d& ofVec3d::normalize() {
	double length = (double)sqrt(x*x + y*y + z*z);
	if( length > 0 ) {
		x /= length;
		y /= length;
		z /= length;
	}
	return *this;
}



// Limit length.
//
//

inline ofVec3d ofVec3d::limited(double max) const {
	return getLimited(max);
}

inline ofVec3d ofVec3d::getLimited(double max) const {
    ofVec3d limited;
    double lengthSquared = (x*x + y*y + z*z);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        double ratio = max/(double)sqrt(lengthSquared);
        limited.set( x*ratio, y*ratio, z*ratio);
    } else {
        limited.set(x,y,z);
    }
    return limited;
}

inline ofVec3d& ofVec3d::limit(double max) {
    double lengthSquared = (x*x + y*y + z*z);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        double ratio = max/(double)sqrt(lengthSquared);
        x *= ratio;
        y *= ratio;
        z *= ratio;
    }
    return *this;
}


// Perpendicular vector.
//
//
inline ofVec3d ofVec3d::crossed( const ofVec3d& vec ) const {
	return getCrossed(vec);
}
inline ofVec3d ofVec3d::getCrossed( const ofVec3d& vec ) const {
	return ofVec3d( y*vec.z - z*vec.y,
				   z*vec.x - x*vec.z,
				   x*vec.y - y*vec.x );
}

inline ofVec3d& ofVec3d::cross( const ofVec3d& vec ) {
	double _x = y*vec.z - z*vec.y;
	double _y = z*vec.x - x*vec.z;
	z = x*vec.y - y*vec.x;
	x = _x;
	y = _y;
	return *this;
}

/**
 * Normalized perpendicular.
 */
inline ofVec3d ofVec3d::perpendiculared( const ofVec3d& vec ) const {
	return getPerpendicular(vec);
}

inline ofVec3d ofVec3d::getPerpendicular( const ofVec3d& vec ) const {
	double crossX = y*vec.z - z*vec.y;
	double crossY = z*vec.x - x*vec.z;
	double crossZ = x*vec.y - y*vec.x;
	
	double length = (double)sqrt(crossX*crossX +
							   crossY*crossY +
							   crossZ*crossZ);
	
	if( length > 0 )
		return ofVec3d( crossX/length, crossY/length, crossZ/length );
	else
		return ofVec3d();
}

inline ofVec3d& ofVec3d::perpendicular( const ofVec3d& vec ) {
	double crossX = y*vec.z - z*vec.y;
	double crossY = z*vec.x - x*vec.z;
	double crossZ = x*vec.y - y*vec.x;
	
	double length = (double)sqrt(crossX*crossX +
							   crossY*crossY +
							   crossZ*crossZ);
	
	if( length > 0 ) {
		x = crossX/length;
		y = crossY/length;
		z = crossZ/length;
	} else {
		x = 0.f;
		y = 0.f;
		z = 0.f;
	}
	
	return *this;
}


// Length
//
//
inline double ofVec3d::length() const {
	return (double)sqrt( x*x + y*y + z*z );
}

inline double ofVec3d::lengthSquared() const {
	return (double)(x*x + y*y + z*z);
}



/**
 * Angle (deg) between two vectors.
 * This is an unsigned relative angle from 0 to 180.
 * http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/index.htm
 */
inline double ofVec3d::angle( const ofVec3d& vec ) const {
	ofVec3d n1 = this->normalized();
	ofVec3d n2 = vec.normalized();
	return (double)(acos( n1.dot(n2) )*RAD_TO_DEG);
}

inline double ofVec3d::angleRad( const ofVec3d& vec ) const {
	ofVec3d n1 = this->normalized();
	ofVec3d n2 = vec.normalized();
	return (double)acos( n1.dot(n2) );
}



/**
 * Dot Product.
 */
inline double ofVec3d::dot( const ofVec3d& vec ) const {
	return x*vec.x + y*vec.y + z*vec.z;
}





// Non-Member operators
//
//
inline ofVec3d operator+( double f, const ofVec3d& vec ) {
    return ofVec3d( f+vec.x, f+vec.y, f+vec.z );
}

inline ofVec3d operator-( double f, const ofVec3d& vec ) {
    return ofVec3d( f-vec.x, f-vec.y, f-vec.z );
}

inline ofVec3d operator*( double f, const ofVec3d& vec ) {
    return ofVec3d( f*vec.x, f*vec.y, f*vec.z );
}

inline ofVec3d operator/( double f, const ofVec3d& vec ) {
    return ofVec3d( f/vec.x, f/vec.y, f/vec.z);
}
