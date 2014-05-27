#pragma once


#include "ofConstants.h"
#include "ofVec2d.h"
#include "ofLog.h"


/// \brief A class representing a 2D rectangle.
///
/// ofRectangled is a simple container for describing the position and size of a
/// 2D rectangle.  Since the `width` and `height` variables can be negative, the
/// x/y position is not garanteed to represent the upper right hand corner.  For
/// example, two visually identical rectangles can be represented in the
/// following ways:
///
///     ofRectangled myRect(0, 0, 100, 100);
///
/// or
///
///     ofRectangled myRect(100, 100, -100, -100);
///
/// While both representations will yield the same visual results in all
/// openFrameworks renderers, the results of some method operations that modify
/// x, y, width and height (such as scaling) produce mathematically correct, but
/// visually different results for each of the above representations.
///
/// To avoid this ambiguity, users planning to should prefer "standardized"
/// rectangles.  "Standardized" rectangles are rectangles whose width >= 0 and
/// height >= 0.  The ofRectangled::standardize() method can be used to ensure
/// that the is in it the "standard" form.
class ofRectangled{
public:
    /// \brief Construct a rectangle with zero width and zero height at 0, 0.
    ofRectangled();

    /// \brief Destroy the rectangle.
    virtual ~ofRectangled();

    /// \brief Construct a rectangle using location and size.
    ///
    /// To produce consistent results, users are encouraged to initialize
    /// rectangles in the standardized form with width >=0 and height >= 0.
    ///
    /// \param px The x location of the rectangle.
    /// \param py The y location of the rectangle.
    /// \param w The width of the rectangle.
    /// \param h The height of the rectangle.
    ofRectangled(double px, double py, double w, double h);

    /// \brief Construct a rectangle from a point and dimensions.
    ///
    /// To produce consistent results, users are encouraged to initialize
    /// rectangles in the standardized form with width >=0 and height >= 0.
    ///
    /// \param p The ofVec2d representing the location of the rectangle.
    /// \param w The width of the rectangle.
    /// \param h The height of the rectangle.
    ofRectangled(const ofVec2d& p, double w, double h);

    /// \brief Construct a rectangle by copying another rectangle.
    ///
    /// To produce consistent results, users are encouraged to initialize
    /// rectangles in the standardized form with width >=0 and height >= 0.
    ///
    /// \param rect The rectangle to copy.
    ofRectangled(const ofRectangled& rect);

    /// \brief Construct a rectangle by defining two corners.
    /// \param p The ofVec2d representing the upper left hand corner.
    /// \param p The ofVec2d representing the lower right hand corner.
    ofRectangled(const ofVec2d& p0, const ofVec2d& p1);

    /// \brief Set the position and size of a rectangle.
    ///
    /// To produce consistent results, users are encouraged to initialize
    /// rectangles in the standardized form with width >=0 and height >= 0.
    ///
    /// \param px The x location of the rectangle.
    /// \param py The y location of the rectangle.
    /// \param w The width of the rectangle.
    /// \param h The height of the rectangle.
    void set(double px, double py, double w, double h);

    /// \brief Set the position and size of a rectangle.
    ///
    /// To produce consistent results, users are encouraged to initialize
    /// rectangles in the standardized form with width >=0 and height >= 0.
    ///
    /// \param p The ofVec2d representing the location of the rectangle.
    /// \param w The width of the rectangle.
    /// \param h The height of the rectangle.
    void set(const ofVec2d& p, double w, double h);

    /// \brief Set the position and size of a rectangle by defining two corners.
    ///
    /// \param rect The rectangle to copy.
    void set(const ofRectangled& rect);

    /// \brief Set the position and size of a rectangle using corners.
    /// \param p The ofVec2d representing the upper left hand corner.
    /// \param p The ofVec2d representing the lower right hand corner.
    void set(const ofVec2d& p0, const ofVec2d& p1);

    /// \brief Set the x position of a rectangle.
    /// \param px The x position.
    void setX(double px);

    /// \brief Set the y position of a rectangle.
    /// \param py The y position.
    void setY(double py);
    
    /// \brief Set the width of a rectangle.
    /// \param w The width.
    void setWidth(double w);

    /// \brief Set the height of a rectangle.
    /// \param h The height.
    void setHeight(double h);

    /// \brief Set the position of a rectangle.
    /// \param px The x position.
    /// \param py The y position.
    void setPosition(double px, double py);

    /// \brief Set the position of a rectangle.
    /// \param p The position as an ofVec2d.
    void setPosition(const ofVec2d& p);

    /// \brief Set position and size of a rectangle from the center.
    ///
    /// The center of the rectangle is defined and the width and height grow
    /// out around the center.
    ///
    /// \param px The x position of the rectangle's center.
    /// \param py The y position of the rectangle's center.
    /// \param w The width of the rectangle.
    /// \param h The height of the rectangle.
    void setFromCenter(double px, double py, double w, double h);

    /// \brief Set position and size of a rectangle from the center.
    ///
    /// The center of the rectangle is defined and the width and height grow
    /// out around the center.
    ///
    /// \param p The position of the rectangle's center as an ofVec2d.
    /// \param w The width of the rectangle.
    /// \param h The height of the rectangle.
    void setFromCenter(const ofVec2d& p, double w, double h);

    /// \brief Translate the rectangle's position by an x and y amount.
    /// \param dx The amount to translate in the x direction.
    /// \param dy The amount to translate in the y direction.
    void translate(double dx, double dy);

    /// \brief Translate the rectangle's position by an x and y amount.
    /// \param dp The amount to translate as an ofVec2d.
    void translate(const ofVec2d& dp);
    
    /// \brief Translate the x position of the rectangle.
    /// \param dx the amount to translate on the x-axis.
    void translateX(double dx);

    /// \brief Translate the y position of the rectangle.
    /// \param dy the amount to translate on the y-axis.
    void translateY(double dy);

    /// \brief Scale the rectangle.
    ///
    /// Scaling will scale the width and the height, but will not change the
    /// position.
    ///
    /// \param s sclaing factor.
    void scale(double s);

    /// \brief Scale the rectangle.
    ///
    /// Scaling will scale the width and the height, but will not change the
    /// position.
    ///
    /// \param sX the x scaling factor.  The new width = sX * width.
    /// \param sY the y scaling factor.  The new height = sY * height.
    void scale(double sX, double sY);

    /// \brief Scale the rectangle.
    ///
    /// Scaling will scale the width and the height, but will not change the position.
    ///
    /// \param s Scales x and y.  The new width = sX * width and the new height
    ///        = sY * height.
    void scale(const ofVec2d& s);
    
    void scaleWidth(double  sX);
    void scaleHeight(double sY);
    
    void scaleFromCenter(double s);
    void scaleFromCenter(double sX, double sY);
    void scaleFromCenter(const ofVec2d& s);
    
    void scaleTo(const ofRectangled& targetRect,
                 ofScaleMode scaleMode = OF_SCALEMODE_FIT);

    void scaleTo(const ofRectangled& targetRect,
                 ofAspectRatioMode subjectAspectRatioMode,
                 ofAlignHorz sharedHorzAnchor = OF_ALIGN_HORZ_CENTER,
                 ofAlignVert sharedVertAnchor = OF_ALIGN_VERT_CENTER);

    void scaleTo(const ofRectangled& targetRect,
                 ofAspectRatioMode subjectAspectRatioMode,
                 ofAlignHorz modelHorzAnchor,
                 ofAlignVert modelVertAnchor,
                 ofAlignHorz subjectHorzAnchor,
                 ofAlignVert subjectVertAnchor);

    void alignToHorz(const double& targetX,
                     ofAlignHorz thisHorzAnchor = OF_ALIGN_HORZ_CENTER);

    void alignToHorz(const ofRectangled& targetRect,
                     ofAlignHorz sharedAnchor = OF_ALIGN_HORZ_CENTER);

    void alignToHorz(const ofRectangled& targetRect,
                     ofAlignHorz targetHorzAnchor,
                     ofAlignHorz thisHorzAnchor);

    void alignToVert(const double& targetY,
                     ofAlignVert sharedAnchor = OF_ALIGN_VERT_CENTER);

    void alignToVert(const ofRectangled& targetRect,
                     ofAlignVert sharedAnchor = OF_ALIGN_VERT_CENTER);

    void alignToVert(const ofRectangled& targetRect,
                     ofAlignVert targetVertAnchor,
                     ofAlignVert thisVertAnchor);

    void alignTo(const ofVec2d& targetPoint,
                ofAlignHorz thisHorzAnchor = OF_ALIGN_HORZ_CENTER,
                ofAlignVert thisVertAnchor = OF_ALIGN_VERT_CENTER);
    
    void alignTo(const ofRectangled& targetRect,
                 ofAlignHorz sharedHorzAnchor = OF_ALIGN_HORZ_CENTER,
                 ofAlignVert sharedVertAnchor = OF_ALIGN_VERT_CENTER);

    void alignTo(const ofRectangled& targetRect,
                 ofAlignHorz targetHorzAnchor,
                 ofAlignVert targetVertAnchor,
                 ofAlignHorz thisHorzAnchor,
                 ofAlignVert thisVertAnchor);

    bool inside(double px, double py) const;
    bool inside(const ofVec2d& p) const;
    bool inside(const ofRectangled& rect) const;
    bool inside(const ofVec2d& p0, const ofVec2d& p1) const;

    bool intersects(const ofRectangled& rect) const;
//    bool intersects(const ofVec2d& p0, const ofVec2d& p1) const;

    void growToInclude(double px, double py);
    void growToInclude(const ofVec2d& p);
    void growToInclude(const ofRectangled& rect);
    void growToInclude(const ofVec2d& p0, const ofVec2d& p1);

    ofRectangled getIntersection(const ofRectangled& rect) const;

    ofRectangled getUnion(const ofRectangled& rect) const;
    
    void standardize();
    ofRectangled getStandardized() const;
    bool isStandardized() const;  // are width/height >= 0.0f
    
    double getArea() const;
    double getPerimeter() const;
    double getAspectRatio() const;
    
    bool isEmpty() const;     // are width/height == 0.0f
    
    ofVec2d getMin() const;
    ofVec2d getMax() const;
    
    double getMinX() const;
    double getMaxX() const;
    double getMinY() const;
    double getMaxY() const;
    
    double getLeft()   const;
    double getRight()  const;
    double getTop()    const;
    double getBottom() const;
    
    ofVec2d getTopLeft() const;
    ofVec2d getTopRight() const;
    ofVec2d getBottomLeft() const;
    ofVec2d getBottomRight() const;
    
    double getHorzAnchor(ofAlignHorz anchor) const;
    double getVertAnchor(ofAlignVert anchor) const;
    
    ofVec2d  getPosition() const;
    ofVec2d& getPositionRef();

    ofVec2d getCenter() const;
    
    double getX() const;
    double getY() const;
    double getWidth() const;
    double getHeight() const;

    ofRectangled& operator = (const ofRectangled& rect);
    ofRectangled operator + (const ofVec2d& p);
    
    bool operator == (const ofRectangled& rect) const;
    bool operator != (const ofRectangled& rect) const;
    
    ofVec2d position;
    double& x;
    double& y;
    double width;
    double height;
};

ostream& operator<<(ostream& os, const ofRectangled& rect);
istream& operator>>(istream& is, ofRectangled& rect);
