//
//  ParticleManager.h
//  OculusFMOD
//
//  Created by Baptiste Bohelay on 05/08/2015.
//
//

#ifndef __OculusFMOD__ParticleManager__
#define __OculusFMOD__ParticleManager__

#include <stdio.h>
#include "ParticleLightBug.h"
#include "Drawable.h"

class ParticleManager : public Drawable
{
public:
    static ParticleManager* instance();
    
    void update(float aTimeInterval);
    void draw();
    
private:
    ParticleManager();
    std::vector<Particle *> mParticles;
    static ParticleManager* sInstance;
};

#endif /* defined(__OculusFMOD__ParticleManager__) */
