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
    void setAttributes(ci::vec3 aPosition, ci::vec3 aSpeed);
private:
    FMOD::Channel	*mChannel;
};

#endif /* defined(__OculusFMOD___DSound__) */
