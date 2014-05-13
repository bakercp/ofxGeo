#pragma once

class ofVec2d;
class ofVec3d;
#include "ofConstants.h"

class ofVec4d {
public:
	double x, y, z, w;
    
    static const int DIM = 4;
	
	ofVec4d();
	explicit ofVec4d( double _scalar );
	ofVec4d( double _x, double _y, double _z, double _w );
	ofVec4d( const ofVec2d& vec);
	ofVec4d( const ofVec3d& vec);
	
    // Getters and Setters.
    //
	void set( double _scalar );
    void set( double _x, double _y, double _z, double _w );
    void set( const ofVec4d& vec );
	
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
	
	
    // Check similarity/equality.
    //
    bool operator==( const ofVec4d& vec ) const;
    bool operator!=( const ofVec4d& vec ) const;
    bool match( const ofVec4d& vec, double tolerance=0.0001) const;
	
	
    // Additions and Subtractions.
    //
    ofVec4d  operator+( const ofVec4d& vec ) const;
    ofVec4d& operator+=( const ofVec4d& vec );
    ofVec4d  operator-( const double f ) const;
    ofVec4d& operator-=( const double f );
    ofVec4d  operator-( const ofVec4d& vec ) const;
    ofVec4d& operator-=( const ofVec4d& vec );
    ofVec4d  operator+( const double f ) const;
    ofVec4d& operator+=( const double f );
    ofVec4d  operator-() const;
	
	
    // Scalings
    //
    ofVec4d  operator*( const ofVec4d& vec ) const;
    ofVec4d& operator*=( const ofVec4d& vec );
    ofVec4d  operator*( const double f ) const;
    ofVec4d& operator*=( const double f );
    ofVec4d  operator/( const ofVec4d& vec ) const;
    ofVec4d& operator/=( const ofVec4d& vec );
    ofVec4d  operator/( const double f ) const;
    ofVec4d& operator/=( const double f );
	
	friend ostream& operator<<(ostream& os, const ofVec4d& vec);
	friend istream& operator>>(istream& is, const ofVec4d& vec);
	
    /// \brief Returns a new ofVec4d that is the result of scaling this vector up or down so that it has the requested length.
    ///
    /// \param length The desired length of the new ofVec4d object.
    /// \returns The result of scaling the this vector up or down.
    ofVec4d  getScaled( const double length ) const;
    
    /// \brief Scales this vector up or down so that it has the requested length.
    ///
    /// \param length The desired length of the vector.
    ofVec4d& scale( const double length );
	
	
    /// \brief Treats this vector and 'pnt' as points in 4D space and calculates the distance between them.
    ///
    /// \param pnt The vector used in the distance calculation with the current vector.
    /// \returns The distance between the two vectors in 4D space.
    double distance( const ofVec4d& pnt) const;
    double squareDistance( const ofVec4d& pnt ) const;
	
	
    /// \brief Performs a linear interpolation of this vector towards 'pnt'.
    ///
    /// \param pnt The vector the interpolation will be performed on. 
    /// \param p The amount to move towards 'pnt'; 'p' is normally between 0 and 1 and where 0 means stay the original position and 1 means move all the way to 'pnt', but you can also have 'p' greater than 1 overshoot 'pnt', or less than 0 to move backwards away from 'pnt'.
    /// \returns The interpolation as an ofVec4d. 
    ofVec4d   getInterpolated( const ofVec4d& pnt, double p ) const;
    
    /// \brief Performs a linear interpolation of this vector towards 'pnt'. This modifies the current vector to the interpolated value.
    ///
    /// \param pnt The vector the interpolation will be performed on. 
    /// \param p The amount to move towards 'pnt'; 'p' is normally between 0 and 1 and where 0 means stay the original position and 1 means move all the way to 'pnt', but you can also have 'p' greater than 1 overshoot 'pnt', or less than 0 to move backwards away from 'pnt'.
    ofVec4d&  interpolate( const ofVec4d& pnt, double p );
    
    /// \brief Calculates and returns the midpoint (as a vector) between this vector and 'pnt'.
    ///
    /// \param pnt The vector used in the midpoint calculation with this vector.
    /// \returns The midpoint between this vector and 'pnt' as an ofVec4d.
    ofVec4d   getMiddle( const ofVec4d& pnt ) const;
    
    /// \brief Calculates and returns the midpoint (as a vector) between this vector and 'pnt'. This modifies the current vector to the midpoint value.
    ///
    /// \param pnt The vector used in the midpoint calculation with this vector.
    /// \returns The midpoint between this vector and 'pnt' as an ofVec4d.
    ofVec4d&  middle( const ofVec4d& pnt );
    
    /// \brief Sets this vector to be the average (center of gravity or centroid) of a given array of 'ofVec4d's.
    /// 
    /// \param points The array of 'ofVec4d's used in the average calculation.
    /// \param num The number of ofVec4d objects in the array.
    ofVec4d&  average( const ofVec4d* points, int num );
    
    /// \brief Returns a normalized copy of this vector.
    ///
    /// Normalization means to scale the vector so that its length (magnitude) is exactly 1, 
    /// at which stage all that is left is the direction. A normalized vector is usually called 
    /// a unit vector, and can be used to represent a pure direction (heading).
    ///
    /// \returns The normalized copy of the current vector.
    ofVec4d  getNormalized() const;
    
    /// \brief Normalizes the vector. This changes the current vector to its normalized value. 
    ///
    /// Normalization means to scale the vector so that its length (magnitude) is exactly 1, 
    /// at which stage all that is left is the direction. A normalized vector is usually called 
    /// a unit vector, and can be used to represent a pure direction (heading).
    ofVec4d& normalize();
	
	
    /// \brief Returns a copy of this vector with its length (magnitude) restricted to a maximum of 'max' units by scaling down if necessary.
    ///
    /// \param max The maximum length of the new vector. 
    /// \returns A copy of the current vector that is at most 'max' units long. 
    ofVec4d  getLimited(double max) const;
    /// \brief Restrict the length (magnitude) of this vector to a maximum of 'max' units by scaling down if necessary.
    ///
    /// \param max The maximum length of the current vector.
    ofVec4d& limit(double max);
	
	
    /// \brief Returns the length (magnitude) of this vector.
    ///
    /// \returns The magnitude of the current vector. 
    double length() const;
    double lengthSquared() const;

    /// \brief Calculates and returns the dot product of this vector with 'vec'.
    ///
    /// Dot product (less commonly known as Euclidean inner product) expresses the angular 
    /// relationship between two vectors. In other words it is a measure of how parallel two vectors 
    /// are. If they are completely perpendicular the dot product is 0; if they are completely parallel 
    /// their dot product is either 1 if they are pointing in the same direction, or -1 if they are pointing 
    /// in opposite directions.
    /// 
    /// \param vec The vector used in the dot product calculation with this vector.
    /// \returns The dot product of this vector with 'vec'. 
    double dot( const ofVec4d& vec ) const;
	
	
	
	
    //---------------------------------------
    // this methods are deprecated in 006 please use:
	
    // getScaled
    ofVec4d rescaled( const double length ) const;
	
    // scale
    ofVec4d& rescale( const double length );
	
    // getNormalized
    ofVec4d normalized() const;
	
    // getLimited
    ofVec4d limited(double max) const;
	
    // use squareDistance
    double  distanceSquared( const ofVec4d& pnt ) const;
	
    // use getInterpolated
    ofVec4d 	interpolated( const ofVec4d& pnt, double p ) const;
	
    // use getMiddle
    ofVec4d 	middled( const ofVec4d& pnt ) const;    
    
    // return all zero vector
    static ofVec4d zero() { return ofVec4d(0, 0, 0, 0); }
    
    // return all one vector
    static ofVec4d one() { return ofVec4d(1, 1, 1, 1); }

};




// Non-Member operators
//
//
ofVec4d operator+( double f, const ofVec4d& vec );
ofVec4d operator-( double f, const ofVec4d& vec );
ofVec4d operator*( double f, const ofVec4d& vec );
ofVec4d operator/( double f, const ofVec4d& vec );







/////////////////
// Implementation
/////////////////

inline ofVec4d::ofVec4d(): x(0), y(0), z(0), w(0) {};
inline ofVec4d::ofVec4d(double _s): x(_s), y(_s), z(_s), w(_s) {};
inline ofVec4d::ofVec4d( double _x,
						double _y,
						double _z,
						double _w ):x(_x), y(_y), z(_z), w(_w) {}

// Getters and Setters.
//
//
inline void ofVec4d::set( double _x, double _y, double _z, double _w ) {
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

inline void ofVec4d::set( const ofVec4d& vec ) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = vec.w;
}


// Check similarity/equality.
//
//
inline bool ofVec4d::operator==( const ofVec4d& vec ) const {
	return (x == vec.x) && (y == vec.y) && (z == vec.z) && (w == vec.w);
}

inline bool ofVec4d::operator!=( const ofVec4d& vec ) const {
	return (x != vec.x) || (y != vec.y) || (z != vec.z) || (w != vec.w);
}

inline bool ofVec4d::match( const ofVec4d& vec, double tolerance) const {
	return (fabs(x - vec.x) < tolerance)
	&& (fabs(y - vec.y) < tolerance)
	&& (fabs(z - vec.z) < tolerance)
	&& (fabs(w - vec.w) < tolerance);
}




// Additions and Subtractions.
//
//
inline ofVec4d ofVec4d::operator+( const ofVec4d& vec ) const {
	return ofVec4d( x+vec.x, y+vec.y, z+vec.z, w+vec.w);
}

inline ofVec4d& ofVec4d::operator+=( const ofVec4d& vec ) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
	w += vec.w;
	return *this;
}

inline ofVec4d ofVec4d::operator-( const double f ) const {
	return ofVec4d( x-f, y-f, z-f, w-f );
}

inline ofVec4d& ofVec4d::operator-=( const double f ) {
	x -= f;
	y -= f;
	z -= f;
	w -= f;
	return *this;
}

inline ofVec4d ofVec4d::operator-( const ofVec4d& vec ) const {
	return ofVec4d( x-vec.x, y-vec.y, z-vec.z, w-vec.w );
}

inline ofVec4d& ofVec4d::operator-=( const ofVec4d& vec ) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	w -= vec.w;
	return *this;
}

inline ofVec4d ofVec4d::operator+( const double f ) const {
	return ofVec4d( x+f, y+f, z+f, w+f );
}

inline ofVec4d& ofVec4d::operator+=( const double f ) {
	x += f;
	y += f;
	z += f;
	w += f;
	return *this;
}

inline ofVec4d ofVec4d::operator-() const {
	return ofVec4d( -x, -y, -z, -w );
}


// Scalings
//
//
inline ofVec4d ofVec4d::operator*( const ofVec4d& vec ) const {
	return ofVec4d( x*vec.x, y*vec.y, z*vec.z, w*vec.w );
}

inline ofVec4d& ofVec4d::operator*=( const ofVec4d& vec ) {
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
	w *= vec.w;
	return *this;
}

inline ofVec4d ofVec4d::operator*( const double f ) const {
	return ofVec4d( x*f, y*f, z*f, w*f );
}

inline ofVec4d& ofVec4d::operator*=( const double f ) {
	x *= f;
	y *= f;
	z *= f;
	w *= f;
	return *this;
}

inline ofVec4d ofVec4d::operator/( const ofVec4d& vec ) const {
	return ofVec4d( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y, vec.z!=0 ? z/vec.z : z, vec.w!=0 ? w/vec.w : w  );
}

inline ofVec4d& ofVec4d::operator/=( const ofVec4d& vec ) {
	vec.x!=0 ? x/=vec.x : x;
	vec.y!=0 ? y/=vec.y : y;
	vec.z!=0 ? z/=vec.z : z;
	vec.w!=0 ? w/=vec.w : w;
	return *this;
}

inline ofVec4d ofVec4d::operator/( const double f ) const {
	if(f == 0) return ofVec4d(x, y, z, w);
	
	return ofVec4d( x/f, y/f, z/f, w/f );
}

inline ofVec4d& ofVec4d::operator/=( const double f ) {
	if(f == 0)return *this;
	
	x /= f;
	y /= f;
	z /= f;
	w /= f;
	return *this;
}


inline ostream& operator<<(ostream& os, const ofVec4d& vec) {
	os << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
	return os;
}

inline istream& operator>>(istream& is, ofVec4d& vec) {
	is >> vec.x;
	is.ignore(2);
	is >> vec.y;
	is.ignore(2);
	is >> vec.z;
	is.ignore(2);
	is >> vec.w;
	return is;
}


inline ofVec4d ofVec4d::rescaled( const double length ) const {
	return getScaled(length);
}

inline ofVec4d ofVec4d::getScaled( const double length ) const {
	double l = (double)sqrt(x*x + y*y + z*z + w*w);
	if( l > 0 )
		return ofVec4d( (x/l)*length, (y/l)*length,
					   (z/l)*length, (w/l)*length );
	else
		return ofVec4d();
}

inline ofVec4d& ofVec4d::rescale( const double length ) {
	return scale(length);
}

inline ofVec4d& ofVec4d::scale( const double length ) {
	double l = (double)sqrt(x*x + y*y + z*z + w*w);
	if (l > 0) {
		x = (x/l)*length;
		y = (y/l)*length;
		z = (z/l)*length;
		w = (w/l)*length;
	}
	return *this;
}



// Distance between two points.
//
//
inline double ofVec4d::distance( const ofVec4d& pnt) const {
	double vx = x-pnt.x;
	double vy = y-pnt.y;
	double vz = z-pnt.z;
	double vw = w-pnt.w;
	return (double)sqrt( vx*vx + vy*vy + vz*vz + vw*vw );
}

inline double ofVec4d::distanceSquared( const ofVec4d& pnt ) const {
	return squareDistance(pnt);
}

inline double ofVec4d::squareDistance( const ofVec4d& pnt ) const {
	double vx = x-pnt.x;
	double vy = y-pnt.y;
	double vz = z-pnt.z;
	double vw = w-pnt.w;
	return vx*vx + vy*vy + vz*vz + vw*vw;
}



// Linear interpolation.
//
//
/**
 * p==0.0 results in this point, p==0.5 results in the
 * midpoint, and p==1.0 results in pnt being returned.
 */
inline ofVec4d ofVec4d::interpolated( const ofVec4d& pnt, double p ) const{
	return getInterpolated(pnt,p);
}

inline ofVec4d ofVec4d::getInterpolated( const ofVec4d& pnt, double p ) const {
	return ofVec4d( x*(1-p) + pnt.x*p,
				   y*(1-p) + pnt.y*p,
				   z*(1-p) + pnt.z*p,
				   w*(1-p) + pnt.w*p );
}

inline ofVec4d& ofVec4d::interpolate( const ofVec4d& pnt, double p ) {
	x = x*(1-p) + pnt.x*p;
	y = y*(1-p) + pnt.y*p;
	z = z*(1-p) + pnt.z*p;
	w = w*(1-p) + pnt.w*p;
	return *this;
}

inline ofVec4d ofVec4d::middled( const ofVec4d& pnt ) const {
	return getMiddle(pnt);
}

inline ofVec4d ofVec4d::getMiddle( const ofVec4d& pnt ) const {
	return ofVec4d( (x+pnt.x)/2.0f, (y+pnt.y)/2.0f,
				   (z+pnt.z)/2.0f, (w+pnt.w)/2.0f );
}

inline ofVec4d& ofVec4d::middle( const ofVec4d& pnt ) {
	x = (x+pnt.x)/2.0f;
	y = (y+pnt.y)/2.0f;
	z = (z+pnt.z)/2.0f;
	w = (w+pnt.w)/2.0f;
	return *this;
}


// Average (centroid) among points.
// (Addition is sometimes useful for calculating averages too)
//
//
inline ofVec4d& ofVec4d::average( const ofVec4d* points, int num ) {
	x = 0.f;
	y = 0.f;
	z = 0.f;
	w = 0.f;
	for( int i=0; i<num; i++) {
		x += points[i].x;
		y += points[i].y;
		z += points[i].z;
		w += points[i].w;
	}
	x /= num;
	y /= num;
	z /= num;
	w /= num;
	return *this;
}



// Normalization
//
//
inline ofVec4d ofVec4d::normalized() const {
	return getNormalized();
}

inline ofVec4d ofVec4d::getNormalized() const {
	double length = (double)sqrt(x*x + y*y + z*z + w*w);
	if( length > 0 ) {
		return ofVec4d( x/length, y/length, z/length, w/length );
	} else {
		return ofVec4d();
	}
}

inline ofVec4d& ofVec4d::normalize() {
	double lenght = (double)sqrt(x*x + y*y + z*z + w*w);
	if( lenght > 0 ) {
		x /= lenght;
		y /= lenght;
		z /= lenght;
		w /= lenght;
	}
	return *this;
}



// Limit length.
//
//
inline ofVec4d ofVec4d::limited(double max) const {
	return getLimited(max);
}

inline ofVec4d ofVec4d::getLimited(double max) const {
    ofVec4d limited;
    double lengthSquared = (x*x + y*y + z*z + w*w);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        double ratio = max/(double)sqrt(lengthSquared);
        limited.set( x*ratio, y*ratio, z*ratio, w*ratio );
    } else {
        limited.set(x,y,z,w);
    }
    return limited;
}

inline ofVec4d& ofVec4d::limit(double max) {
    double lengthSquared = (x*x + y*y + z*z + w*w);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        double ratio = max/(double)sqrt(lengthSquared);
        x *= ratio;
        y *= ratio;
        z *= ratio;
        w *= ratio;
    }
    return *this;
}



// Length
//
//
inline double ofVec4d::length() const {
	return (double)sqrt( x*x + y*y + z*z + w*w );
}

inline double ofVec4d::lengthSquared() const {
	return (double)(x*x + y*y + z*z + w*w);
}




/**
 * Dot Product.
 */
inline double ofVec4d::dot( const ofVec4d& vec ) const {
	return x*vec.x + y*vec.y + z*vec.z + w*vec.w;
}





// Non-Member operators
//
//
inline ofVec4d operator+( double f, const ofVec4d& vec ) {
    return ofVec4d( f+vec.x, f+vec.y, f+vec.z, f+vec.w );
}

inline ofVec4d operator-( double f, const ofVec4d& vec ) {
    return ofVec4d( f-vec.x, f-vec.y, f-vec.z, f-vec.w );
}

inline ofVec4d operator*( double f, const ofVec4d& vec ) {
    return ofVec4d( f*vec.x, f*vec.y, f*vec.z, f*vec.w );
}

inline ofVec4d operator/( double f, const ofVec4d& vec ) {
    return ofVec4d( f/vec.x, f/vec.y, f/vec.z, f/vec.w);
}




