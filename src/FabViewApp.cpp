#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class FabViewApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void FabViewApp::setup()
{
}

void FabViewApp::mouseDown( MouseEvent event )
{
}

void FabViewApp::update()
{
}

void FabViewApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( FabViewApp, RendererGl )
