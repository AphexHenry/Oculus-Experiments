//
//  SoundManager.h
//  OculusFMOD
//
//  Created by Baptiste Bohelay on 04/08/2015.
//
//

#ifndef __OculusFMOD__SoundManager__
#define __OculusFMOD__SoundManager__

#include <stdio.h>
#include "FMOD.hpp"

enum SoundEnum {
    SOUND_FLIES
};

class SoundManager {

    private:
        static SoundManager* sInstance;
    
        FMOD::System	*mSystem;
        std::vector<FMOD::Sound * > mSounds;
    
    public:
        static SoundManager* instance();
        void init();
        void update();
        void playSound(SoundEnum aSound, FMOD::Channel * aChannel);
};

#endif /* defined(__OculusFMOD__SoundManager__) */
