//
//  ParticleManager.cpp
//  OculusFMOD
//
//  Created by Baptiste Bohelay on 05/08/2015.
//
//

#include "ParticleManager.h"

ParticleManager* ParticleManager::sInstance = nullptr;

ParticleManager* ParticleManager::instance()
{
    if(!sInstance) sInstance = new ParticleManager;
    return sInstance;
}

ParticleManager::ParticleManager()
{
    for(int i = 0; i < 20; i++)
    {
        mParticles.push_back(new ParticleLightBug());
    }
}

void ParticleManager::update(float aTimeInterval)
{
    for(auto lParticle : mParticles)
    {
        lParticle->update(aTimeInterval);
    }
}

void ParticleManager::draw()
{
    for(auto lParticle : mParticles)
    {
        lParticle->draw();
    }
}