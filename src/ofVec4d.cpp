#include "ofVec2d.h"
#include "ofVec3d.h"
#include "ofVec4d.h"

ofVec4d::ofVec4d(const ofVec3d& vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = 0;
}

ofVec4d::ofVec4d(const ofVec2d& vec) {
	x = vec.x;
	y = vec.y;
	z = 0;
	w = 0;
}
