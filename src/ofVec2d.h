#pragma once

class ofVec3d;
class ofVec4d;
#include "ofConstants.h"

class ofVec2d {
public:
	double x, y;
    
    static const int DIM = 2;
	
	ofVec2d();
	explicit ofVec2d( double _scalar );
	ofVec2d( double _x, double _y );
    ofVec2d( const ofVec3d& vec );
    ofVec2d( const ofVec4d& vec );
	
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
	void set( double _scalar );
    void set( double _x, double _y );
    void set( const ofVec2d& vec );
	
    // Check similarity/equality.
    //
    bool operator==( const ofVec2d& vec ) const;
    bool operator!=( const ofVec2d& vec ) const;
    bool match( const ofVec2d& vec, double tolerance=0.0001 ) const;
    /**
	 * Checks if vectors look in the same direction.
	 * Tolerance is specified in degree.
	 */
    bool isAligned( const ofVec2d& vec, double tolerance=0.0001 ) const;
    bool isAlignedRad( const ofVec2d& vec, double tolerance=0.0001 ) const;
    bool align( const ofVec2d& vec, double tolerance=0.0001 ) const;
    bool alignRad( const ofVec2d& vec, double tolerance=0.0001 ) const;
	
	
    // Overloading for any type to any type
    //
    ofVec2d  operator+( const ofVec2d& vec ) const;
    ofVec2d& operator+=( const ofVec2d& vec );
    ofVec2d  operator-( const ofVec2d& vec ) const;
    ofVec2d& operator-=( const ofVec2d& vec );
    ofVec2d  operator*( const ofVec2d& vec ) const;
    ofVec2d& operator*=( const ofVec2d& vec );
    ofVec2d  operator/( const ofVec2d& vec ) const;
    ofVec2d& operator/=( const ofVec2d& vec );
	
	
    //operator overloading for double
    //
	//    void 	  operator=( const double f);
    ofVec2d  operator+( const double f ) const;
    ofVec2d& operator+=( const double f );
    ofVec2d  operator-( const double f ) const;
    ofVec2d& operator-=( const double f );
    ofVec2d  operator-() const;
    ofVec2d  operator*( const double f ) const;
    ofVec2d& operator*=( const double f );
    ofVec2d  operator/( const double f ) const;
    ofVec2d& operator/=( const double f );
	
	friend ostream& operator<<(ostream& os, const ofVec2d& vec);
	friend istream& operator>>(istream& is, const ofVec2d& vec);
	
    // Scaling
    //
    ofVec2d  getScaled( const double length ) const;
    ofVec2d& scale( const double length );
	
	
    // Rotation
    //
    ofVec2d  getRotated( double angle ) const;
    ofVec2d  getRotatedRad( double angle ) const;
    ofVec2d& rotate( double angle );
    ofVec2d& rotateRad( double angle );
	
    
    // Rotation - point around pivot
    //
    ofVec2d  getRotated( double angle, const ofVec2d& pivot ) const;
    ofVec2d& rotate( double angle, const ofVec2d& pivot );
    ofVec2d  getRotatedRad( double angle, const ofVec2d& pivot ) const;
    ofVec2d& rotateRad( double angle, const ofVec2d& pivot );
	
	
    // Map point to coordinate system defined by origin, vx, and vy.
    //
    ofVec2d getMapped( const ofVec2d& origin,
					  const ofVec2d& vx,
					  const ofVec2d& vy ) const;
    ofVec2d& map( const ofVec2d& origin,
				 const ofVec2d& vx, const ofVec2d& vy );
	
	
    // Distance between two points.
    //
    double distance( const ofVec2d& pnt) const;
    double squareDistance( const ofVec2d& pnt ) const;
	
	
    // Linear interpolation.
    //
    //
    /**
	 * p==0.0 results in this point, p==0.5 results in the
	 * midpoint, and p==1.0 results in pnt being returned.
	 */
    ofVec2d   getInterpolated( const ofVec2d& pnt, double p ) const;
    ofVec2d&  interpolate( const ofVec2d& pnt, double p );
    ofVec2d   getMiddle( const ofVec2d& pnt ) const;
    ofVec2d&  middle( const ofVec2d& pnt );
    ofVec2d&  average( const ofVec2d* points, int num );
    
    
    // Normalization
    //
    ofVec2d  getNormalized() const;
    ofVec2d& normalize();
	
	
    // Limit length.
    //
	ofVec2d  getLimited(double max) const;
    ofVec2d& limit(double max);
	
	
    // Perpendicular normalized vector.
    //
    ofVec2d  getPerpendicular() const;
    ofVec2d& perpendicular();
	
	
    // Length
    //
    double length() const;
    double lengthSquared() const;
	
	
    /**
	 * Angle (deg) between two vectors.
	 * This is a signed relative angle between -180 and 180.
	 */
    double angle( const ofVec2d& vec ) const;
    double angleRad( const ofVec2d& vec ) const;
	
	
    /**
	 * Dot Product.
	 */
    double dot( const ofVec2d& vec ) const;
	
	
	
    //---------------------------------------------------
    // this methods are deprecated in 006 please use:
	
    // getScaled
    ofVec2d rescaled( const double length ) const;
	
    // scale
    ofVec2d& rescale( const double length );
	
    // getRotated
    ofVec2d rotated( double angle ) const;
	
    // getNormalized
    ofVec2d normalized() const;
	
    // getLimited
    ofVec2d limited(double max) const;
	
    // getPerpendicular
    ofVec2d perpendiculared() const;
	
    // getInterpolated
    ofVec2d interpolated( const ofVec2d& pnt, double p ) const;
    
    // getMiddled
    ofVec2d middled( const ofVec2d& pnt ) const;
    
    // getMapped 
    ofVec2d mapped( const ofVec2d& origin, const ofVec2d& vx, const ofVec2d& vy ) const;
    
    // squareDistance
    double distanceSquared( const ofVec2d& pnt ) const;
    
    // use getRotated
    ofVec2d rotated( double angle, const ofVec2d& pivot ) const;    
    
    // return all zero vector
    static ofVec2d zero() { return ofVec2d(0, 0); }

    // return all one vector
    static ofVec2d one() { return ofVec2d(1, 1); }
};





// Non-Member operators
//
ofVec2d operator+( double f, const ofVec2d& vec );
ofVec2d operator-( double f, const ofVec2d& vec );
ofVec2d operator*( double f, const ofVec2d& vec );
ofVec2d operator/( double f, const ofVec2d& vec );







/////////////////
// Implementation
/////////////////

inline ofVec2d::ofVec2d(): x(0), y(0) {};
inline ofVec2d::ofVec2d( double _scalar ): x(_scalar), y(_scalar) {};
inline ofVec2d::ofVec2d( double _x, double _y ):x(_x), y(_y) {}

// Getters and Setters.
//
//
inline void ofVec2d::set( double _scalar ) {
	x = _scalar;
	y = _scalar;
}

inline void ofVec2d::set( double _x, double _y ) {
	x = _x;
	y = _y;
}

inline void ofVec2d::set( const ofVec2d& vec ) {
	x = vec.x;
	y = vec.y;
}


// Check similarity/equality.
//
//
inline bool ofVec2d::operator==( const ofVec2d& vec ) const {
	return (x == vec.x) && (y == vec.y);
}

inline bool ofVec2d::operator!=( const ofVec2d& vec ) const {
	return (x != vec.x) || (y != vec.y);
}

inline bool ofVec2d::match( const ofVec2d& vec, double tolerance ) const {
	return (fabs(x - vec.x) < tolerance)
	&& (fabs(y - vec.y) < tolerance);
}

/**
 * Checks if vectors look in the same direction.
 * Tolerance is specified in degree.
 */
inline bool ofVec2d::isAligned( const ofVec2d& vec, double tolerance ) const { 
	return  fabs( this->angle( vec ) ) < tolerance;
}
inline bool ofVec2d::align( const ofVec2d& vec, double tolerance ) const {
    return isAligned( vec, tolerance );
}

inline bool ofVec2d::isAlignedRad( const ofVec2d& vec, double tolerance ) const {
	return  fabs( this->angleRad( vec ) ) < tolerance;
}
inline bool ofVec2d::alignRad( const ofVec2d& vec, double tolerance ) const {
    return isAlignedRad( vec, tolerance );
}


// Overloading for any type to any type
//
//

inline ofVec2d ofVec2d::operator+( const ofVec2d& vec ) const {
	return ofVec2d( x+vec.x, y+vec.y);
}

inline ofVec2d& ofVec2d::operator+=( const ofVec2d& vec ) {
	x += vec.x;
	y += vec.y;
	return *this;
}

inline ofVec2d ofVec2d::operator-( const ofVec2d& vec ) const {
	return ofVec2d(x-vec.x, y-vec.y);
}

inline ofVec2d& ofVec2d::operator-=( const ofVec2d& vec ) {
	x -= vec.x;
	y -= vec.y;
	return *this;
}

inline ofVec2d ofVec2d::operator*( const ofVec2d& vec ) const {
	return ofVec2d(x*vec.x, y*vec.y);
}

inline ofVec2d& ofVec2d::operator*=( const ofVec2d& vec ) {
	x*=vec.x;
	y*=vec.y;
	return *this;
}

inline ofVec2d ofVec2d::operator/( const ofVec2d& vec ) const {
	return ofVec2d( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y);
}

inline ofVec2d& ofVec2d::operator/=( const ofVec2d& vec ) {
	vec.x!=0 ? x/=vec.x : x;
	vec.y!=0 ? y/=vec.y : y;
	return *this;
}

inline ostream& operator<<(ostream& os, const ofVec2d& vec) {
	os << vec.x << ", " << vec.y;
	return os;
}

inline istream& operator>>(istream& is, ofVec2d& vec) {
	is >> vec.x;
	is.ignore(2);
	is >> vec.y;
	return is;
}

//operator overloading for double
//
//
//inline void ofVec2d::operator=( const double f){
//	x = f;
//	y = f;
//}

inline ofVec2d ofVec2d::operator+( const double f ) const {
	return ofVec2d( x+f, y+f);
}

inline ofVec2d& ofVec2d::operator+=( const double f ) {
	x += f;
	y += f;
	return *this;
}

inline ofVec2d ofVec2d::operator-( const double f ) const {
	return ofVec2d( x-f, y-f);
}

inline ofVec2d& ofVec2d::operator-=( const double f ) {
	x -= f;
	y -= f;
	return *this;
}

inline ofVec2d ofVec2d::operator-() const {
	return ofVec2d(-x, -y);
}

inline ofVec2d ofVec2d::operator*( const double f ) const {
	return ofVec2d(x*f, y*f);
}

inline ofVec2d& ofVec2d::operator*=( const double f ) {
	x*=f;
	y*=f;
	return *this;
}

inline ofVec2d ofVec2d::operator/( const double f ) const {
	if(f == 0) return ofVec2d(x, y);
	
	return ofVec2d(x/f, y/f);
}

inline ofVec2d& ofVec2d::operator/=( const double f ) {
	if(f == 0) return *this;
	
	x/=f;
	y/=f;
	return *this;
}

inline ofVec2d ofVec2d::rescaled( const double length ) const {
	return getScaled(length);
}

inline ofVec2d ofVec2d::getScaled( const double length ) const {
	double l = (double)sqrt(x*x + y*y);
	if( l > 0 )
		return ofVec2d( (x/l)*length, (y/l)*length );
	else
		return ofVec2d();
}

inline ofVec2d& ofVec2d::rescale( const double length ){
	return scale(length);
}

inline ofVec2d& ofVec2d::scale( const double length ) {
	double l = (double)sqrt(x*x + y*y);
	if (l > 0) {
		x = (x/l)*length;
		y = (y/l)*length;
	}
	return *this;
}



// Rotation
//
//
inline ofVec2d ofVec2d::rotated( double angle ) const {
	return getRotated(angle);
}

inline ofVec2d ofVec2d::getRotated( double angle ) const {
	double a = (double)(angle*DEG_TO_RAD);
	return ofVec2d( x*cos(a) - y*sin(a),
				   x*sin(a) + y*cos(a) );
}

inline ofVec2d ofVec2d::getRotatedRad( double angle ) const {
	double a = angle;
	return ofVec2d( x*cos(a) - y*sin(a),
				   x*sin(a) + y*cos(a) );
}

inline ofVec2d& ofVec2d::rotate( double angle ) {
	double a = (double)(angle * DEG_TO_RAD);
	double xrot = x*cos(a) - y*sin(a);
	y = x*sin(a) + y*cos(a);
	x = xrot;
	return *this;
}

inline ofVec2d& ofVec2d::rotateRad( double angle ) {
	double a = angle;
	double xrot = x*cos(a) - y*sin(a);
	y = x*sin(a) + y*cos(a);
	x = xrot;
	return *this;
}



// Rotate point by angle (deg) around pivot point.
//
//

// This method is deprecated in 006 please use getRotated instead
inline ofVec2d ofVec2d::rotated( double angle, const ofVec2d& pivot ) const {
	return getRotated(angle, pivot);
}

inline ofVec2d ofVec2d::getRotated( double angle, const ofVec2d& pivot ) const {
	double a = (double)(angle * DEG_TO_RAD);
	return ofVec2d( ((x-pivot.x)*cos(a) - (y-pivot.y)*sin(a)) + pivot.x,
				   ((x-pivot.x)*sin(a) + (y-pivot.y)*cos(a)) + pivot.y );
}

inline ofVec2d& ofVec2d::rotate( double angle, const ofVec2d& pivot ) {
	double a = (double)(angle * DEG_TO_RAD);
	double xrot = ((x-pivot.x)*cos(a) - (y-pivot.y)*sin(a)) + pivot.x;
	y = ((x-pivot.x)*sin(a) + (y-pivot.y)*cos(a)) + pivot.y;
	x = xrot;
	return *this;
}

inline ofVec2d ofVec2d::getRotatedRad( double angle, const ofVec2d& pivot ) const {
	double a = angle;
	return ofVec2d( ((x-pivot.x)*cos(a) - (y-pivot.y)*sin(a)) + pivot.x,
				   ((x-pivot.x)*sin(a) + (y-pivot.y)*cos(a)) + pivot.y );
}

inline ofVec2d& ofVec2d::rotateRad( double angle, const ofVec2d& pivot ) {
	double a = angle;
	double xrot = ((x-pivot.x)*cos(a) - (y-pivot.y)*sin(a)) + pivot.x;
	y = ((x-pivot.x)*sin(a) + (y-pivot.y)*cos(a)) + pivot.y;
	x = xrot;
	return *this;
}



// Map point to coordinate system defined by origin, vx, and vy.
//
//

// This method is deprecated in 006 please use getMapped instead
inline ofVec2d ofVec2d::mapped( const ofVec2d& origin,
							   const ofVec2d& vx,
							   const ofVec2d& vy ) const{
	return getMapped(origin, vx, vy);
}

inline ofVec2d ofVec2d::getMapped( const ofVec2d& origin,
								  const ofVec2d& vx,
								  const ofVec2d& vy ) const
{
	return ofVec2d( origin.x + x*vx.x + y*vy.x,
				   origin.y + x*vx.y + y*vy.y );
}

inline ofVec2d& ofVec2d::map( const ofVec2d& origin,
							 const ofVec2d& vx, const ofVec2d& vy )
{
	double xmap = origin.x + x*vx.x + y*vy.x;
	y = origin.y + x*vx.y + y*vy.y;
	x = xmap;
	return *this;
}


// Distance between two points.
//
//
inline double ofVec2d::distance( const ofVec2d& pnt) const {
	double vx = x-pnt.x;
	double vy = y-pnt.y;
	return (double)sqrt(vx*vx + vy*vy);
}

//this method is deprecated in 006 please use squareDistance
inline double ofVec2d::distanceSquared( const ofVec2d& pnt ) const {
	return squareDistance(pnt);
}

inline double ofVec2d::squareDistance( const ofVec2d& pnt ) const {
	double vx = x-pnt.x;
	double vy = y-pnt.y;
	return vx*vx + vy*vy;
}



// Linear interpolation.
//
//
/**
 * p==0.0 results in this point, p==0.5 results in the
 * midpoint, and p==1.0 results in pnt being returned.
 */

// this method is deprecated in 006 please use getInterpolated
inline ofVec2d ofVec2d::interpolated( const ofVec2d& pnt, double p ) const{
	return getInterpolated(pnt, p);
}

inline ofVec2d ofVec2d::getInterpolated( const ofVec2d& pnt, double p ) const {
	return ofVec2d( x*(1-p) + pnt.x*p, y*(1-p) + pnt.y*p );
}

inline ofVec2d& ofVec2d::interpolate( const ofVec2d& pnt, double p ) {
	x = x*(1-p) + pnt.x*p;
	y = y*(1-p) + pnt.y*p;
	return *this;
}

// this method is deprecated in 006 please use getMiddle
inline ofVec2d ofVec2d::middled( const ofVec2d& pnt ) const{
	return getMiddle(pnt);
}

inline ofVec2d ofVec2d::getMiddle( const ofVec2d& pnt ) const {
	return ofVec2d( (x+pnt.x)/2.0f, (y+pnt.y)/2.0f );
}

inline ofVec2d& ofVec2d::middle( const ofVec2d& pnt ) {
	x = (x+pnt.x)/2.0f;
	y = (y+pnt.y)/2.0f;
	return *this;
}



// Average (centroid) among points.
// Addition is sometimes useful for calculating averages too.
//
//
inline ofVec2d& ofVec2d::average( const ofVec2d* points, int num ) {
	x = 0.f;
	y = 0.f;
	for( int i=0; i<num; i++) {
		x += points[i].x;
		y += points[i].y;
	}
	x /= num;
	y /= num;
	return *this;
}



// Normalization
//
//
inline ofVec2d ofVec2d::normalized() const {
	return getNormalized();
}

inline ofVec2d ofVec2d::getNormalized() const {
	double length = (double)sqrt(x*x + y*y);
	if( length > 0 ) {
		return ofVec2d( x/length, y/length );
	} else {
		return ofVec2d();
	}
}

inline ofVec2d& ofVec2d::normalize() {
	double length = (double)sqrt(x*x + y*y);
	if( length > 0 ) {
		x /= length;
		y /= length;
	}
	return *this;
}



// Limit length.
//
//
inline ofVec2d ofVec2d::limited(double max) const{
	return getLimited(max);
}

inline ofVec2d ofVec2d::getLimited(double max) const {
    ofVec2d limited;
    double lengthSquared = (x*x + y*y);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        double ratio = max/(double)sqrt(lengthSquared);
        limited.set( x*ratio, y*ratio);
    } else {
        limited.set(x,y);
    }
    return limited;
}

inline ofVec2d& ofVec2d::limit(double max) {
    double lengthSquared = (x*x + y*y);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        double ratio = max/(double)sqrt(lengthSquared);
        x *= ratio;
        y *= ratio;
    }
    return *this;
}



// Perpendicular normalized vector.
//
//
inline ofVec2d ofVec2d::perpendiculared() const {
	return getPerpendicular();
}

inline ofVec2d ofVec2d::getPerpendicular() const {
	double length = (double)sqrt( x*x + y*y );
	if( length > 0 )
		return ofVec2d( -(y/length), x/length );
	else
		return ofVec2d();
}

inline ofVec2d& ofVec2d::perpendicular() {
	double length = (double)sqrt( x*x + y*y );
	if( length > 0 ) {
		double _x = x;
		x = -(y/length);
		y = _x/length;
	}
	return *this;
}


// Length
//
//
inline double ofVec2d::length() const {
	return (double)sqrt( x*x + y*y );
}

inline double ofVec2d::lengthSquared() const {
	return (double)(x*x + y*y);
}


/**
 * Angle (deg) between two vectors.
 * This is a signed relative angle between -180 and 180.
 */
inline double ofVec2d::angle( const ofVec2d& vec ) const {
	return (double)(atan2( x*vec.y-y*vec.x, x*vec.x + y*vec.y )*RAD_TO_DEG);
}

/**
 * Angle (deg) between two vectors.
 * This is a signed relative angle between -180 and 180.
 */
inline double ofVec2d::angleRad( const ofVec2d& vec ) const {
	return atan2( x*vec.y-y*vec.x, x*vec.x + y*vec.y );
}


/**
 * Dot Product.
 */
inline double ofVec2d::dot( const ofVec2d& vec ) const {
	return x*vec.x + y*vec.y;
}







// Non-Member operators
//
//
inline ofVec2d operator+( double f, const ofVec2d& vec ) {
    return ofVec2d( f+vec.x, f+vec.y);
}

inline ofVec2d operator-( double f, const ofVec2d& vec ) {
    return ofVec2d( f-vec.x, f-vec.y);
}

inline ofVec2d operator*( double f, const ofVec2d& vec ) {
    return ofVec2d( f*vec.x, f*vec.y);
}

inline ofVec2d operator/( double f, const ofVec2d& vec ) {
    return ofVec2d( f/vec.x, f/vec.y);
}


