//
//  Particle.h
//  OculusFMOD
//
//  Created by Baptiste Bohelay on 04/08/2015.
//
//

#ifndef __OculusFMOD__Particle__
#define __OculusFMOD__Particle__

#include <stdio.h>
#include "Sound3D.h"

class Particle {
public:
    virtual void update(float aTimeInterval);
    virtual void draw() = 0;

protected:
    Sound3D mSound;
    ci::vec3 mPosition;
    ci::vec3 mSpeed;
};

#endif /* defined(__OculusFMOD__Particle__) */
