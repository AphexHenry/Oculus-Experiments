//
//  VisualRenderer.cpp
//  OculusFMOD
//
//  Created by Baptiste Bohelay on 05/08/2015.
//
//

#include "VisualRenderer.h"
#include "CinderOculus.h"

using namespace ci;

VisualRenderer* VisualRenderer::sInstance = nullptr;

VisualRenderer* VisualRenderer::instance()
{
    if(!sInstance) sInstance = new VisualRenderer;
    
    return sInstance;
}

VisualRenderer::VisualRenderer()
{
    mViewerPosition = vec3( 0, 0, 1 );
    mTime = 0.f;
    if( mRift.attachToWindow( ci::app::getWindow() ) ) {
        if( mRift.isDesktopExtended() )
            app::setFullScreen();
        else
            app::setWindowSize( mRift.getNativeWindowResolution() );
        CameraPersp host;
        host.setEyePoint( mViewerPosition );
        host.lookAt( vec3( 0 ) );
        mRift.setHostCamera( host );
        mRift.setScreenPercentage( 1.25f );
    }
    
    try {
        mShader = gl::GlslProg::create( gl::GlslProg::Format().vertex( ci::app::loadAsset( "phong.vert" ) ).fragment( ci::app::loadAsset( "phong.frag" ) ) );
    }
    catch( const std::exception& e ) {
        ci::app::console() << e.what() << std::endl;
    }
    
    // Setup camera for the debug (main) window.
    mCamera.setEyePoint( vec3( 0, 2, 5 ) );
    mCamera.lookAt( vec3( 0 ) );
    mCamera.setFov( 45.0f );
    
    // Generally preferable to enable vsync to prevent tearing in the headset display
    gl::enableVerticalSync();
    gl::enableDepthRead();
    gl::enableDepthWrite();
    gl::color( Color::white() );
}

void VisualRenderer::update(float aTimeInterval)
{
    // Animate light position.
    mTime += aTimeInterval;
    float t = float( mTime ) * 0.4f;
    mLightWorldPosition = vec4( 1.0f * math<float>::sin( t ), math<float>::sin( t * 4.0f ), 1.0f * math<float>::cos( t ), 1 );
}


void VisualRenderer::draw()
{
    hmd::ScopedBind bind{ mRift };
    gl::clear( Color( 0.02, 0.02, 0.1 ) );
    
    auto sceneDraw = [&]() {
        for(auto &drawable : drawingList)
            drawable();
    };

    
    if( mRift.hasWindow( ci::app::getWindow() ) ) {
        for( auto eye : mRift.getEyes() ) {
            mRift.enableEye( eye );
            
            mShader->uniform( "uLightViewPosition", mRift.getViewMatrix() * mLightWorldPosition );
            mShader->uniform( "uSkyDirection", mRift.getViewMatrix() * vec4( 0, 1, 0, 0 ) );
            sceneDraw();
            
            // Draw positional tracking camera frustum
//            CameraPersp positional;
//            if( mRift.getPositionalTrackingCamera( &positional ) ) {
//                gl::ScopedModelMatrix push;
//                gl::setModelMatrix( mRift.getHostCamera().getInverseViewMatrix() );
//                gl::lineWidth( 1.0f );
//                gl::drawFrustum( positional );
//            }
        }
    } else {
        gl::viewport( ci::app::getWindowSize() );
        gl::setMatrices( mCamera );
        
        const mat4& view = mCamera.getViewMatrix();
        mShader->uniform( "uLightViewPosition", view * mLightWorldPosition );
        mShader->uniform( "uSkyDirection", view * vec4( 0, 1, 0, 0 ) );
        
        sceneDraw();
    }
    

}



void VisualRenderer::addDrawFunction(std::function< void() > aCallback)
{
    drawingList.push_back(aCallback);
}