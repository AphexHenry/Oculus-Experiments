#include "cinder/app/App.h"
#include "cinder/gl/Batch.h"
#include "Tools.h"
#include "ParticleManager.h"
#include "VisualRenderer.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class OculusFMODApp : public App {
  public:
	void setup() override;
    void update();
	void draw() override;

    vec3 mPos;
    float mTimer;
};

void OculusFMODApp::setup()
{
    mTimer = 0.f;
    
    VisualRenderer::instance()->addDrawFunction( std::bind( &ParticleManager::draw, *(ParticleManager::instance()) ) );
}

void OculusFMODApp::update()
{
    float lTimeInterval = 0.03f;
    mTimer += lTimeInterval;
    float lFar = 20.f;
    vec3 lNewVec = vec3(lFar * cos(mTimer), lFar * sin(mTimer), 0.f);
    mPos = lNewVec;

    VisualRenderer::instance()->update(lTimeInterval);
    ParticleManager::instance()->update(lTimeInterval);
    
}

void OculusFMODApp::draw()
{
    VisualRenderer::instance()->draw();
}

void prepareSettings( App::Settings *settings )
{
    hmd::RiftManager::initialize();
    
    settings->disableFrameRate();
    settings->setTitle( "Oculus Rift Sample" );
    settings->setWindowSize( 1920, 1080 );
}


CINDER_APP( OculusFMODApp, RendererGl( RendererGl::Options().msaa(0) ), prepareSettings );
