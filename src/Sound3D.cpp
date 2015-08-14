//
//  3DSound.cpp
//  OculusFMOD
//
//  Created by Baptiste Bohelay on 04/08/2015.
//
//

#include "Sound3D.h"
#include "cinder/rand.h"

using namespace ci;

Sound3D::Sound3D()
{
    mChannel = 0;
}

void Sound3D::play()
{
    SoundManager::instance()->playSound(SOUND_FLIES, &mChannel);
    mChannel->setPosition(Rand::randFloat() * 10000.f, FMOD_TIMEUNIT_MS);
}

void Sound3D::update(ci::vec3 aPosition, ci::vec3 aSpeed)
{
    mPos = makeFMOD_VECTOR(aPosition);
    mSpeed = makeFMOD_VECTOR(aSpeed);
    mChannel->set3DAttributes(&mPos, &mSpeed);
}

FMOD_VECTOR Sound3D::makeFMOD_VECTOR(vec3 aCiVec)
{
    FMOD_VECTOR rVec;
    rVec.x = aCiVec.x;
    rVec.y = aCiVec.y;
    rVec.z = aCiVec.z;
    return rVec;
}