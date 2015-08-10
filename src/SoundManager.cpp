//
//  SoundManager.cpp
//  OculusFMOD
//
//  Created by Baptiste Bohelay on 04/08/2015.
//
//

#include "SoundManager.h"
#include "VisualRenderer.h"
#include "ParticleManager.h"

using namespace ci;
using namespace app;

SoundManager* SoundManager::sInstance = nullptr;

SoundManager* SoundManager::instance()
{
    if(!sInstance) sInstance = new SoundManager;
    return sInstance;
}

void SoundManager::init()
{
    FMOD::Sound * lSound;
    mSystem->createSound( getAssetPath( "Blank__Kytt_-_08_-_RSPN.mp3" ).string().c_str(), FMOD_3D, NULL, &lSound );
    mSounds.push_back(lSound);
    
    const float DISTANCEFACTOR = 1.0f;
    FMOD::System_Create( &mSystem );
    FMOD_RESULT      result;
    result = mSystem->init(100, FMOD_INIT_NORMAL, NULL);
    result = mSystem->set3DSettings(1.0, DISTANCEFACTOR, 1.0f);
    
//    VisualRenderer * lRenderer = VisualRenderer::instance();
//    lRenderer->addDrawFunction(std::bind( &ParticleManager::draw, *(ParticleManager::instance()) ));
}

void SoundManager::playSound(SoundEnum aSound, FMOD::Channel * aChannel)
{
    float lDistanceFactor = 1.f;
    FMOD::Sound * lSound = mSounds[aSound];
    lSound->set3DMinMaxDistance(0.5f * lDistanceFactor, 5000.0f * lDistanceFactor);
    lSound->setMode( FMOD_LOOP_NORMAL );
    mSystem->playSound( FMOD_CHANNEL_FREE, lSound, false, &aChannel );
}

void SoundManager::update()
{
//    FMOD_VECTOR forward        = { 0.0f, 0.0f, 1.0f };
//    FMOD_VECTOR up             = { 0.0f, 1.0f, 0.0f };
//    mSystem->set3DListenerAttributes(0, &lPosFMOD, &lSpeedFMOD, &forward, &up);
    mSystem->update();
}