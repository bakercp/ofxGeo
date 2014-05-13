#include "ofVec2d.h"
#include "ofVec3d.h"
#include "ofVec4d.h"

ofVec2d::ofVec2d( const ofVec3d& vec ) {
	x = vec.x;
	y = vec.y;
}

ofVec2d::ofVec2d( const ofVec4d& vec ) {
	x = vec.x;
	y = vec.y;
}
