#include <cfloat>
#include "ofRectangled.h"
 
//----------------------------------------------------------
ofRectangled::ofRectangled() : x(position.x), y(position.y) {
    set(0,0,0,0);
}

//----------------------------------------------------------
ofRectangled::~ ofRectangled(){}

//----------------------------------------------------------
ofRectangled::ofRectangled(double px, double py, double w, double h) : x(position.x), y(position.y) {
	set(px,py,w,h);
}

//----------------------------------------------------------
ofRectangled::ofRectangled(const ofVec2d& p, double w, double h) : x(position.x), y(position.y) {
    set(p,w,h);
}

//----------------------------------------------------------
ofRectangled::ofRectangled(const ofRectangled& rect) : x(position.x), y(position.y) {
    set(rect);
}

//----------------------------------------------------------
ofRectangled::ofRectangled(const ofVec2d& p0, const ofVec2d& p1) : x(position.x), y(position.y) {
    set(p0,p1);
}

//----------------------------------------------------------
void ofRectangled::set(double px, double py, double w, double h) {
	x		= px;
	y		= py;
	width	= w;
	height	= h;
}

//----------------------------------------------------------
void ofRectangled::set(const ofVec2d& p, double w, double h) {
    set(p.x, p.y, w, h);
}

//----------------------------------------------------------
void ofRectangled::set(const ofRectangled& rect){
    set(rect.x, rect.y, rect.width, rect.height);
}

//----------------------------------------------------------
void ofRectangled::set(const ofVec2d& p0, const ofVec2d& p1) {
    double x0,y0,x1,y1;
    
    x0 = MIN(p0.x, p1.x);
    x1 = MAX(p0.x, p1.x);
    y0 = MIN(p0.y, p1.y);
    y1 = MAX(p0.y, p1.y);
    
    double w = x1 - x0;
    double h = y1 - y0;

    set(x0,y0,w,h);
}

//----------------------------------------------------------
void ofRectangled::setX(double px) {
    x = px;
}

//----------------------------------------------------------
void ofRectangled::setY(double py) {
    y = py;
}

//----------------------------------------------------------
void ofRectangled::setWidth(double w) {
    width = w;
}

//----------------------------------------------------------
void ofRectangled::setHeight(double h) {
    height = h;
}

//----------------------------------------------------------
void ofRectangled::setPosition(double px, double py) {
    position.x = px;
    position.y = py;
}

//----------------------------------------------------------
void ofRectangled::setPosition(const ofVec2d& p) {
    position = p;
}

//----------------------------------------------------------
void ofRectangled::setFromCenter(double px, double py, double w, double h) {
    set(px - w*0.5f, py - h*0.5f, w, h);
}

//----------------------------------------------------------
void ofRectangled::setFromCenter(const ofVec2d& p, double w, double h) {
    setFromCenter(p.x, p.y, w, h);
}

//----------------------------------------------------------
void ofRectangled::translate(double dx, double dy) {
    translateX(dx);
    translateY(dy);
}

//----------------------------------------------------------
void ofRectangled::translate(const ofVec2d& dp) {
    translateX(dp.x);
    translateY(dp.y);
}

//----------------------------------------------------------
void ofRectangled::translateX(double dx) {
    x += dx;
}

//----------------------------------------------------------
void ofRectangled::translateY(double dy) {
    y += dy;
}

//----------------------------------------------------------
void ofRectangled::scale(double s) {
    scaleWidth(s);
    scaleHeight(s);
}

//----------------------------------------------------------
void ofRectangled::scale(double sX, double sY) {
    scaleWidth(sX);
    scaleHeight(sY);
}

//----------------------------------------------------------
void ofRectangled::scale(const ofVec2d& s) {
    scaleWidth(s.x);
    scaleHeight(s.y);
}

//----------------------------------------------------------
void ofRectangled::scaleWidth(double  sX) {
    width  *= sX;
}
//----------------------------------------------------------
void ofRectangled::scaleHeight(double sY) {
    height *= sY;
}

//----------------------------------------------------------
void ofRectangled::scaleFromCenter(double s) {
    scaleFromCenter(s,s);
}

//----------------------------------------------------------
void ofRectangled::scaleFromCenter(double sX, double sY) {
    scaleFromCenter(ofVec2d(sX,sY));
}

//----------------------------------------------------------
void ofRectangled::scaleFromCenter(const ofVec2d& s) {
    if(s.x == 1.0f && s.y == 1.0f) return; // nothing to do
    
    double newWidth  = width  * s.x;
    double newHeight = height * s.y;

    ofVec2d center = getCenter();
    
    x = center.x - newWidth  / 2.0f;
    y = center.y - newHeight / 2.0f; 
    
    width  = newWidth;
    height = newHeight;
}

//----------------------------------------------------------
void ofRectangled::scaleTo(const ofRectangled& targetRect,
                          ofScaleMode scaleMode) {
    
    if(scaleMode == OF_SCALEMODE_FIT) {
        scaleTo(targetRect,
                OF_ASPECT_RATIO_KEEP,
                OF_ALIGN_HORZ_CENTER,
                OF_ALIGN_VERT_CENTER);
    } else if(scaleMode == OF_SCALEMODE_FILL) {
        scaleTo(targetRect,
                OF_ASPECT_RATIO_KEEP_BY_EXPANDING,
                OF_ALIGN_HORZ_CENTER,
                OF_ALIGN_VERT_CENTER);
    } else if(scaleMode == OF_SCALEMODE_CENTER) {
        alignTo(targetRect,
                OF_ALIGN_HORZ_CENTER,
                OF_ALIGN_VERT_CENTER);
    } else if(scaleMode == OF_SCALEMODE_STRETCH_TO_FILL) {
        scaleTo(targetRect,
                OF_ASPECT_RATIO_IGNORE,
                OF_ALIGN_HORZ_CENTER,
                OF_ALIGN_VERT_CENTER);
    } else {
        scaleTo(targetRect,
                OF_ASPECT_RATIO_KEEP);
    }
}

//----------------------------------------------------------
void ofRectangled::scaleTo(const ofRectangled& targetRect,
                          ofAspectRatioMode subjectAspectRatioMode,
                          ofAlignHorz sharedHorzAnchor,
                          ofAlignVert sharedVertAnchor) {
    scaleTo(targetRect,
            subjectAspectRatioMode,
            sharedHorzAnchor,
            sharedVertAnchor,
            sharedHorzAnchor,
            sharedVertAnchor);
}

//----------------------------------------------------------
void ofRectangled::scaleTo(const ofRectangled& targetRect,
                                 ofAspectRatioMode aspectRatioMode,
                                 ofAlignHorz modelHorzAnchor,
                                 ofAlignVert modelVertAnchor,
                                 ofAlignHorz thisHorzAnchor,
                                 ofAlignVert thisVertAnchor) {

    double tw = targetRect.getWidth();    // target width
    double th = targetRect.getHeight();   // target height
    double sw = getWidth();   // subject width
    double sh = getHeight();  // subject height

    if(aspectRatioMode == OF_ASPECT_RATIO_KEEP_BY_EXPANDING ||
       aspectRatioMode == OF_ASPECT_RATIO_KEEP) {
        if(fabs(sw) >= FLT_EPSILON || fabs(sh) >= FLT_EPSILON) {
            double wRatio = fabs(tw) / fabs(sw);
            double hRatio = fabs(th) / fabs(sh);
            if(aspectRatioMode == OF_ASPECT_RATIO_KEEP_BY_EXPANDING) {
                scale(MAX(wRatio,hRatio));
            } else if(aspectRatioMode == OF_ASPECT_RATIO_KEEP) {
                scale(MIN(wRatio,hRatio));
            }
        } else {
            ofLogWarning("ofRectangled") << "scaleTo(): no scaling applied to avoid divide by zero, rectangle has 0 width and/or height: " << sw << "x" << sh;
        }
    } else if(aspectRatioMode == OF_ASPECT_RATIO_IGNORE) {
        width  = tw;
        height = th;
    } else {
        ofLogWarning("ofRectangled") << "scaleTo(): unknown ofAspectRatioMode = " << aspectRatioMode << ", using OF_ASPECT_RATIO_IGNORE";
        width  = tw;
        height = th;
    }

    // now align if anchors are not ignored.
    alignTo(targetRect,
            modelHorzAnchor,
            modelVertAnchor,
            thisHorzAnchor,
            thisVertAnchor);

}

//----------------------------------------------------------
void ofRectangled::alignToHorz(const double& targetX,
                              ofAlignHorz thisHorzAnchor) {

    if(thisHorzAnchor != OF_ALIGN_HORZ_IGNORE) {
        translateX(targetX - getHorzAnchor(thisHorzAnchor));
    } else {
        ofLogVerbose("ofRectangled") << "alignToHorz(): thisHorzAnchor == OF_ALIGN_HORZ_IGNORE, no alignment applied";
    }
}

//----------------------------------------------------------
void ofRectangled::alignToHorz(const ofRectangled& targetRect,
                              ofAlignHorz sharedAnchor) {
    
    alignToHorz(targetRect, sharedAnchor, sharedAnchor);
}

//----------------------------------------------------------
void ofRectangled::alignToHorz(const ofRectangled& targetRect,
                              ofAlignHorz targetHorzAnchor,
                              ofAlignHorz thisHorzAnchor) {
    
    if(targetHorzAnchor != OF_ALIGN_HORZ_IGNORE &&
       thisHorzAnchor   != OF_ALIGN_HORZ_IGNORE) {
        alignToHorz(targetRect.getHorzAnchor(targetHorzAnchor),thisHorzAnchor);
    } else {
        if(targetHorzAnchor == OF_ALIGN_HORZ_IGNORE) {
            ofLogVerbose("ofRectangled") << "alignToHorz(): targetHorzAnchor == OF_ALIGN_HORZ_IGNORE, no alignment applied";
        } else {
            ofLogVerbose("ofRectangled") << "alignToHorz(): thisHorzAnchor == OF_ALIGN_HORZ_IGNORE, no alignment applied";
        }
    }
    
}

//----------------------------------------------------------
void ofRectangled::alignToVert(const double& targetY,
                              ofAlignVert thisVertAnchor) {

    if(thisVertAnchor != OF_ALIGN_VERT_IGNORE) {
        translateY(targetY - getVertAnchor(thisVertAnchor));
    } else {
        ofLogVerbose("ofRectangled") << "alignToVert(): thisVertAnchor == OF_ALIGN_VERT_IGNORE, no alignment applied";
    }
}

//----------------------------------------------------------
void ofRectangled::alignToVert(const ofRectangled& targetRect,
                              ofAlignVert sharedAnchor) {
    
    alignToVert(targetRect,sharedAnchor,sharedAnchor);
}

//----------------------------------------------------------
void ofRectangled::alignToVert(const ofRectangled& targetRect,
                              ofAlignVert targetVertAnchor,
                              ofAlignVert thisVertAnchor) {

    if(targetVertAnchor != OF_ALIGN_VERT_IGNORE &&
       thisVertAnchor   != OF_ALIGN_VERT_IGNORE) {
        alignToVert(targetRect.getVertAnchor(targetVertAnchor),thisVertAnchor);
    } else {
        if(targetVertAnchor == OF_ALIGN_VERT_IGNORE) {
            ofLogVerbose("ofRectangled") << "alignToVert(): targetVertAnchor == OF_ALIGN_VERT_IGNORE, no alignment applied";
        } else {
            ofLogVerbose("ofRectangled") << "alignToVert(): thisVertAnchor == OF_ALIGN_VERT_IGNORE, no alignment applied";
        }
        
    }
}

//----------------------------------------------------------
void ofRectangled::alignTo(const ofVec2d& targetPoint,
                          ofAlignHorz thisHorzAnchor,
                          ofAlignVert thisVertAnchor) {

    alignToHorz(targetPoint.x, thisHorzAnchor);
    alignToVert(targetPoint.y, thisVertAnchor);
}


//----------------------------------------------------------
void ofRectangled::alignTo(const ofRectangled& targetRect,
                          ofAlignHorz sharedHorzAnchor,
                          ofAlignVert sharedVertAnchor) {
    alignTo(targetRect,
            sharedHorzAnchor,
            sharedVertAnchor,
            sharedHorzAnchor,
            sharedVertAnchor);
}

//----------------------------------------------------------
void ofRectangled::alignTo(const ofRectangled& targetRect,
                                 ofAlignHorz targetHorzAnchor,
                                 ofAlignVert targetVertAnchor,
                                 ofAlignHorz thisHorzAnchor,
                                 ofAlignVert thisVertAnchor) {

    alignToHorz(targetRect,targetHorzAnchor,thisHorzAnchor);
    alignToVert(targetRect,targetVertAnchor,thisVertAnchor);
}

//----------------------------------------------------------
bool ofRectangled::inside(double px, double py) const {
	return inside(ofVec2d(px,py));
}

//----------------------------------------------------------
bool ofRectangled::inside(const ofVec2d& p) const {
    return p.x > getMinX() && p.y > getMinY() && 
           p.x < getMaxX() && p.y < getMaxY();
}

//----------------------------------------------------------
bool ofRectangled::inside(const ofRectangled& rect) const {
    return inside(rect.getMinX(),rect.getMinY()) &&
           inside(rect.getMaxX(),rect.getMaxY());
}

//----------------------------------------------------------
bool ofRectangled::inside(const ofVec2d& p0, const ofVec2d& p1) const {
    // check to see if a line segment is inside the rectangle
    return inside(p0) && inside(p1);
}

//----------------------------------------------------------
bool ofRectangled::intersects(const ofRectangled& rect) const {
    return (getMinX() < rect.getMaxX() && getMaxX() > rect.getMinX() &&
            getMinY() < rect.getMaxY() && getMaxY() > rect.getMinY());
}

////----------------------------------------------------------
//bool ofRectangled::intersects(const ofVec2d& p0, const ofVec2d& p1) const {
//    // check for a line intersection
//    ofVec2d p;
//    
//    ofVec2d topLeft     = getTopLeft();
//    ofVec2d topRight    = getTopRight();
//    ofVec2d bottomRight = getBottomRight();
//    ofVec2d bottomLeft  = getBottomLeft();
//    
//    return inside(p0) || // check end inside
//           inside(p1) || // check end inside
//           ofLineSegmentIntersection(p0, p1, topLeft,     topRight,    p) || // cross top
//           ofLineSegmentIntersection(p0, p1, topRight,    bottomRight, p) || // cross right
//           ofLineSegmentIntersection(p0, p1, bottomRight, bottomLeft,  p) || // cross bottom
//           ofLineSegmentIntersection(p0, p1, bottomLeft,  topLeft,     p);   // cross left
//}

//----------------------------------------------------------
void ofRectangled::growToInclude(double px, double py) {
    growToInclude(ofVec2d(px,py));
}

//----------------------------------------------------------
void ofRectangled::growToInclude(const ofVec2d& p) {
    double x0 = MIN(getMinX(),p.x);
    double x1 = MAX(getMaxX(),p.x);
    double y0 = MIN(getMinY(),p.y);
    double y1 = MAX(getMaxY(),p.y);
    double w = x1 - x0;
    double h = y1 - y0;
    set(x0,y0,w,h);
}

//----------------------------------------------------------
void ofRectangled::growToInclude(const ofRectangled& rect) {
    double x0 = MIN(getMinX(),rect.getMinX());
    double x1 = MAX(getMaxX(),rect.getMaxX());
    double y0 = MIN(getMinY(),rect.getMinY());
    double y1 = MAX(getMaxY(),rect.getMaxY());
    double w = x1 - x0;
    double h = y1 - y0;
    set(x0,y0,w,h);
}

//----------------------------------------------------------
void ofRectangled::growToInclude(const ofVec2d& p0, const ofVec2d& p1) {
    growToInclude(p0);
    growToInclude(p1);
}

//----------------------------------------------------------
ofRectangled ofRectangled::getIntersection(const ofRectangled& rect) const {

    double x0 = MAX(getMinX(),rect.getMinX());
    double x1 = MIN(getMaxX(),rect.getMaxX());
    
    double w = x1 - x0;
    if(w < 0.0f) return ofRectangled(0,0,0,0); // short circuit if needed
    
    double y0 = MAX(getMinY(),rect.getMinY());
    double y1 = MIN(getMaxY(),rect.getMaxY());
    
    double h = y1 - y0;
    if(h < 0.0f) return ofRectangled(0,0,0,0);  // short circuit if needed
    
    return ofRectangled(x0,y0,w,h);
}

//----------------------------------------------------------
ofRectangled ofRectangled::getUnion(const ofRectangled& rect) const {
    ofRectangled united = *this;
    united.growToInclude(rect);
    return united;
}

//----------------------------------------------------------
void ofRectangled::standardize() {
    if(width < 0.0f) {
        x += width;
        width = -1.0f * width;
    } 
    
    if(height < 0.0f) {
        y += height;
        height = -1.0f * height;
    }
}

//----------------------------------------------------------
ofRectangled ofRectangled::getStandardized() const {
    if(isStandardized()) {
        return *this;
    } else {
        ofRectangled canRect(*this); // copy it
        canRect.standardize();
        return canRect;
    }
}

//----------------------------------------------------------
bool ofRectangled::isStandardized() const {
    return width >= 0.0f && height >= 0.0f;
}

//----------------------------------------------------------
double ofRectangled::getArea() const {
    return fabs(width) * fabs(height);
}

//----------------------------------------------------------
double ofRectangled::getPerimeter() const {
    return 2.0f * fabs(width) + 2.0f * fabs(height);
}

//----------------------------------------------------------
double ofRectangled::getAspectRatio() const {
    return fabs(width) / fabs(height);
}

//----------------------------------------------------------
bool ofRectangled::isEmpty() const {
    return width == 0.0f && height == 0.0f;
}

//----------------------------------------------------------
ofVec2d ofRectangled::getMin() const {
    return ofVec2d(getMinX(),getMinY());
}

//----------------------------------------------------------
ofVec2d ofRectangled::getMax() const {
    return ofVec2d(getMaxX(),getMaxY());
}

//----------------------------------------------------------
double ofRectangled::getMinX() const {
    return MIN(x, x + width);  // - width
}

//----------------------------------------------------------
double ofRectangled::getMaxX() const {
    return MAX(x, x + width);  // - width
}

//----------------------------------------------------------
double ofRectangled::getMinY() const{
    return MIN(y, y + height);  // - height
}

//----------------------------------------------------------
double ofRectangled::getMaxY() const {
    return MAX(y, y + height);  // - height
}

//----------------------------------------------------------
double ofRectangled::getLeft() const {
    return getMinX();
}

//----------------------------------------------------------
double ofRectangled::getRight() const {
    return getMaxX();
}

//----------------------------------------------------------
double ofRectangled::getTop() const {
    return getMinY();
}

//----------------------------------------------------------
double ofRectangled::getBottom() const {
    return getMaxY();
}

//----------------------------------------------------------
ofVec2d ofRectangled::getTopLeft() const {
    return getMin();
}

//----------------------------------------------------------
ofVec2d ofRectangled::getTopRight() const {
    return ofVec2d(getRight(),getTop());
}

//----------------------------------------------------------
ofVec2d ofRectangled::getBottomLeft() const {
    return ofVec2d(getLeft(),getBottom());
}

//----------------------------------------------------------
ofVec2d ofRectangled::getBottomRight() const {
    return getMax();
}

//----------------------------------------------------------
double ofRectangled::getHorzAnchor(ofAlignHorz anchor) const {
    switch (anchor) {
        case OF_ALIGN_HORZ_IGNORE:
            ofLogError("ofRectangled") << "getHorzAnchor(): unable to get anchor for OF_ALIGN_HORZ_IGNORE, returning 0";
            return 0.0f;
        case OF_ALIGN_HORZ_LEFT:
            return getLeft();
        case OF_ALIGN_HORZ_RIGHT:
            return getRight();
        case OF_ALIGN_HORZ_CENTER:
            return getCenter().x;
        default:
            ofLogError("ofRectangled") << "getHorzAnchor(): unknown ofAlignHorz = " << anchor << ", returning 0.0";
            return 0.0f;
    }
}

//----------------------------------------------------------
double ofRectangled::getVertAnchor(ofAlignVert anchor) const {
    switch (anchor) {
        case OF_ALIGN_VERT_IGNORE:
            ofLogError("ofRectangled") << "getVertAnchor(): unable to get anchor for OF_ALIGN_VERT_IGNORE, returning 0.0";
            return 0.0f;
        case OF_ALIGN_VERT_TOP:
            return getTop();
        case OF_ALIGN_VERT_BOTTOM:
            return getBottom();
        case OF_ALIGN_VERT_CENTER:
            return getCenter().y;
        default:
            ofLogError("ofRectangled") << "getVertAnchor(): unknown ofAlignVert = " << anchor << ", returning 0.0";
            return 0.0f;
    }
}

//----------------------------------------------------------
bool ofRectangled::operator != (const ofRectangled& rect) const {
	return (x != rect.x) || (y != rect.y) || (width != rect.width) || (height != rect.height);
}

//----------------------------------------------------------
ofVec2d ofRectangled::getPosition() const {
    return position;
}

//----------------------------------------------------------
ofVec2d& ofRectangled::getPositionRef() {
    return position;
}

//----------------------------------------------------------
ofVec2d ofRectangled::getCenter() const {
	return ofVec2d(x + width * 0.5f, y + height * 0.5f);
}

//----------------------------------------------------------
double ofRectangled::getX() const {
    return x;
}

//----------------------------------------------------------
double ofRectangled::getY() const {
    return y;
}

//----------------------------------------------------------
double ofRectangled::getWidth() const {
    return width;
}

//----------------------------------------------------------
double ofRectangled::getHeight() const {
    return height;
}

//----------------------------------------------------------
ofRectangled& ofRectangled::operator = (const ofRectangled& rect) {
    set(rect);
	return *this;
}

//----------------------------------------------------------
ofRectangled ofRectangled::operator + (const ofVec2d & point){
	ofRectangled rect=*this;
	rect.x += point.x;
	rect.y += point.y;
	return rect;
}

//----------------------------------------------------------
bool ofRectangled::operator == (const ofRectangled& rect) const {
	return (x == rect.x) && (y == rect.y) && (width == rect.width) && (height == rect.height);
}

//----------------------------------------------------------
ostream& operator<<(ostream& os, const ofRectangled& rect){
	os << rect.position << ", " << rect.width << ", " << rect.height;
	return os;
}

//----------------------------------------------------------
istream& operator>>(istream& is, ofRectangled& rect){
	is >> rect.position;
	is.ignore(2);
	is >> rect.width;
	is.ignore(2);
	is >> rect.height;
	return is;
}
