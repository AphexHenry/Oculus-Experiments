//
//  3DSound.h
//  OculusFMOD
//
//  Created by Baptiste Bohelay on 04/08/2015.
//
//

#ifndef __OculusFMOD___DSound__
#define __OculusFMOD___DSound__

#include <stdio.h>
#include "SoundManager.h"

class Sound3D
{
public:
    Sound3D();
    void update(ci::vec3 aPosition, ci::vec3 aSpeed);
    void play();
    FMOD_VECTOR makeFMOD_VECTOR(ci::vec3 aCiVec);

private:
    FMOD_VECTOR mPos;
    FMOD_VECTOR mSpeed;
    FMOD::Channel	*mChannel;
};

#endif /* defined(__OculusFMOD___DSound__) */
