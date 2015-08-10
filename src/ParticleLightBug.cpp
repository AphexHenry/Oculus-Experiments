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
    mIntensity = 0.f;
    mTime = 0.f;
    mSpeed = randFloat(2.f);
    float lDistanceStart = 1.f;
    mRadius = randFloat(2.f);
    mPositionStart = vec3(Rand::randFloat() - 0.5, Rand::randFloat() - 0.5, Rand::randFloat() - 0.5) * lDistanceStart;
}

void ParticleLightBug::update(float aTimeInterval)
{
    mTime += aTimeInterval * mSpeed;
    float lDistance = 1.f * mRadius;
    mPosition = mPositionStart + vec3(lDistance * cos(mTime), lDistance * sin(mTime), 0.f);
}

void ParticleLightBug::draw()
{
    gl::ScopedModelMatrix push;
    gl::lineWidth( 3.0f );
    gl::drawCoordinateFrame( 2 );
    gl::drawSphere(mPosition, 0.05f, 36 );
}