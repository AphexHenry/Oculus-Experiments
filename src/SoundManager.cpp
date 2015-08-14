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

FMOD::Channel   *channel1 = 0;

SoundManager::SoundManager()
{
    const float DISTANCEFACTOR = 1.0f;
    FMOD::System_Create( &mSystem );
    FMOD_RESULT      result;
    result = mSystem->init(100, FMOD_INIT_NORMAL, NULL);
    result = mSystem->set3DSettings(1.0, DISTANCEFACTOR, 1.0f);

    FMOD::Sound * lSound;
    mSystem->createSound( getAssetPath( "Craquement.wav" ).string().c_str(), FMOD_3D, 0, &lSound );
    lSound->set3DMinMaxDistance(1.f * DISTANCEFACTOR, 5000.0f * DISTANCEFACTOR);
    lSound->setMode(FMOD_LOOP_NORMAL);
    mSounds[SOUND_FLIES] = lSound;
    mDebugTime = 0.f;
}

SoundManager::~SoundManager()
{
    for (auto& lSound : mSounds) {
        lSound.second->release();
    }
    
    mSystem->close();
    mSystem->release();
}

void SoundManager::playSound(SoundEnum aSound, FMOD::Channel ** aChannel)
{
    float lDistanceFactor = 1.f;
    FMOD::Sound * lSound = mSounds[aSound];
    lSound->set3DMinMaxDistance(0.5f * lDistanceFactor, 5000.0f * lDistanceFactor);
    lSound->setMode( FMOD_LOOP_NORMAL );
    mSystem->playSound( FMOD_CHANNEL_REUSE, lSound, false, aChannel );
    (*aChannel)->setPaused(false);
}

FMOD::Channel *  SoundManager::getChannel()
{
    return nullptr;
}

void SoundManager::update()
{
    mDebugTime += 0.03f;
    FMOD_VECTOR forward        = { 0.0f, 0.0f, 1.0f };
    FMOD_VECTOR up             = { 0.0f, 1.0f, 0.0f };
    FMOD_VECTOR lPosFMOD = { static_cast<float>(5.f * cos(mDebugTime)), 0.0f, 0.0f };
    FMOD_VECTOR lSpeedFMOD = { 0.0f, 0.0f, 0.0f };
    mSystem->set3DListenerAttributes(0, &lPosFMOD, &lSpeedFMOD, &forward, &up);
    mSystem->update();
}