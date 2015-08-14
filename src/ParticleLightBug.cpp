//
//  ParticleLightBug.cpp
//  OculusFMOD
//
//  Created by Baptiste Bohelay on 04/08/2015.
//
//

#include "ParticleLightBug.h"
#include "SoundManager.h"
#include "cinder/gl/gl.h"
#include "cinder/rand.h"

using namespace ci;

ParticleLightBug::ParticleLightBug()
{
    mSound.play();
    mIntensity = 0.f;
    mTime = 0.f;
    mSpeedRotation = randFloat(2.f);
    float lDistanceStart = 1.f;
    float lDistanceZ = 3.f;
    mRadius = 2.f + randFloat(2.f);
    mPositionStart = vec3(Rand::randFloat() - 0.5f, Rand::randFloat() - 0.5f, -Rand::randFloat() * lDistanceZ) * lDistanceStart;
}

void ParticleLightBug::update(float aTimeInterval)
{
    mTime += aTimeInterval * mSpeedRotation;
    float lDistance = 1.f * mRadius;
    vec3 lNewPos = mPositionStart + vec3(lDistance * cos(mTime * 0.4), lDistance * sin(mTime * 0.4), 0.f);
    mSpeed = (lNewPos - mPosition) / aTimeInterval;
    mPosition = lNewPos;
    mSound.update(mPosition, mSpeed);
}

void ParticleLightBug::draw()
{
    gl::ScopedModelMatrix push;
    gl::lineWidth( 3.0f );
    gl::drawCoordinateFrame( 2 );
    gl::drawSphere(mPosition, 0.05f, 36 );
}