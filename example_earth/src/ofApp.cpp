// =============================================================================
//
// Copyright (c) 2010-2014 Christopher Baker <http://christopherbaker.net>
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


#include "ofApp.h"


void ofApp::setup()
{
    ofEnableDepthTest();

    london = Geo::Coordinate(51.5085300, -0.1257400);
    tokyo = Geo::Coordinate(35.6148800, 139.5813000);

    colorMap.loadImage("color_map_1024.jpg");


    earthSphere.set(Geo::GeoUtils::EARTH_RADIUS_KM, 24);

    ofQuaternion quat;
    quat.makeRotate(180, 0, 1, 0);
    earthSphere.rotate(quat);

    earthSphere.mapTexCoords(0,
                             colorMap.getTextureReference().getTextureData().tex_u,
                             colorMap.getTextureReference().getTextureData().tex_t,
                             0);

    scaler = 300 / Geo::GeoUtils::EARTH_RADIUS_KM;

	ofSetFrameRate(30);
	ofEnableAlphaBlending();
	ofNoFill();

    cam.setPosition(0, 0, 0);

}


void ofApp::update()
{
}


void ofApp::draw()
{
	ofBackground(0);

    cam.begin();

	ofPushMatrix();

    ofScale(scaler, scaler, scaler);

    ofQuaternion latRot;
    ofQuaternion longRot;
    ofQuaternion spinQuat;

    Geo::ElevatedCoordinate pos(london.getLatitude(), london.getLongitude(), 0);//(-87.6278, 41.8819, 0);

    latRot.makeRotate(pos.getLatitude(), 1, 0, 0);
    longRot.makeRotate(pos.getLongitude(), 0, 1, 0);
    //		spinQuat.makeRotate(ofGetFrameNum()/100, 0, 1, 0);

    //our starting point is 0,0, on the surface of our sphere, this is where the meridian and equator meet
    ofVec3f center = ofVec3f(0,0, pos.getElevation() / 1000 + Geo::GeoUtils::EARTH_RADIUS_KM);
    //multiplying a quat with another quat combines their rotations into one quat
    //multiplying a quat to a vector applies the quat's rotation to that vector
    //so to to generate our point on the sphere, multiply all of our quaternions together then multiple the centery by the combined rotation
    ofVec3f worldPoint = latRot * longRot * spinQuat * center;

    ofFill();
    ofSetColor(255, 0, 0, 127);
    ofCircle(worldPoint, 30);

    ofNoFill();
    ofSetColor(255, 0, 0, 255);
    ofCircle(worldPoint, 30);

    ofSetColor(255);

    colorMap.bind();
    earthSphere.draw();
    colorMap.unbind();

	ofPopMatrix();
    cam.end();

}


void ofApp::keyPressed(int key)
{
}
