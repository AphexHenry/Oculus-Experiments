//
//  ParticleLightBug.h
//  OculusFMOD
//
//  Created by Baptiste Bohelay on 04/08/2015.
//
//

#ifndef __OculusFMOD__ParticleLightBug__
#define __OculusFMOD__ParticleLightBug__

#include <stdio.h>
#include "Particle.h"

class ParticleLightBug : public Particle
{
public:
    ParticleLightBug();
    void update(float aTimeInterval) override;
    void draw() override;
private:
    ci::vec3  mPositionStart;
    float mIntensity;
    float mTime;
    float mRadius;
    float mSpeedRotation;
};

#endif /* defined(__OculusFMOD__ParticleLightBug__) */
