//
//  VisualRenderer.h
//  OculusFMOD
//
//  Created by Baptiste Bohelay on 05/08/2015.
//
//

#ifndef __OculusFMOD__VisualRenderer__
#define __OculusFMOD__VisualRenderer__

#include <stdio.h>
#include "CinderOculus.h"

class VisualRenderer
{
public:
    static VisualRenderer * instance();
    VisualRenderer();
    
    void draw();
    void update(float aTimeInterval);
    
    void addDrawFunction(std::function< void() > aCallback);
    
private:
    std::vector< std::function< void() > > drawingList;
    
    ci::CameraPersp			mCamera;
    hmd::OculusRift         mRift;
    float                   mTime;
    ci::vec3                mViewerPosition;
    ci::vec4			mLightWorldPosition;
    
    ci::gl::GlslProgRef	mShader;
    
    static VisualRenderer * sInstance;
};

#endif /* defined(__OculusFMOD__VisualRenderer__) */
