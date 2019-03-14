#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
//#include "cinder/Log.h"
#include "ciCEF.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class FabViewApp : public App {
public:
    void setup() override;
    void keyDown(KeyEvent event) override;
    void update() override;
    void draw() override;

    coc::ciCEF vanillaView;
};

void FabViewApp::setup() {

    // Piggy bank (large model)
    //vanillaView.setup("https://skfb.ly/6HLrE", getWindowSize());

    // Wade cup (reduced model)
    // vanillaView.setup("https://skfb.ly/6IvRF", getWindowSize());

    // static page that starts Sketchfab Viewer API
	vanillaView.setup("https://artlensdev.clevelandart.org/static/sketchfab.html", getWindowSize());
    vanillaView.registerEvents();

}

void FabViewApp::keyDown(KeyEvent event) {

	//vanillaView.executeJS("callFromCinder()");

}

void FabViewApp::update() {

	vanillaView.update();

}

void FabViewApp::draw() {

	vanillaView.draw();

}

void prepareSettings(App::Settings *settings) {
	//settings->setWindowSize(1200, 800);

	//settings->setFrameRate(-1);
    settings->setFullScreen();
    char *argv[5] = {};
    coc::initCiCEF(0, argv);
}

CINDER_APP(FabViewApp, RendererGl, &prepareSettings)
