#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Log.h"
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
	ci::Font mFont;

private:
	void gotMessageFromJS(const coc::ciCEFJSMessageArgs& msg);
	bool jsFunctionBinded = false;
};

void FabViewApp::setup() {

    mFont = Font("Arial", 18.0f);
    CI_LOG_I("Info log test");

    // Piggy bank (large model)
    vanillaView.setup("https://skfb.ly/6HLrE", getWindowSize());

    // Wade cup (reduced model)
    // vanillaView.setup("https://skfb.ly/6IvRF", getWindowSize());
	
	//vanillaView.setup("chrome://settings", getWindowSize());
    vanillaView.registerEvents();

}

void FabViewApp::keyDown(KeyEvent event) {

	vanillaView.executeJS("callFromCinder()");

}

void FabViewApp::update() {

	if (!jsFunctionBinded && vanillaView.isReady()) {

		CI_LOG_I("Ready to bind to JS");
		vanillaView.bind(this, "DataToCinder", &FabViewApp::gotMessageFromJS);
		jsFunctionBinded = true;

	}

	vanillaView.update();

}


void FabViewApp::gotMessageFromJS(const coc::ciCEFJSMessageArgs& msg) {

	CI_LOG_I("gotMessageFromJS()");

	for (int i = 0; i < msg.args->GetSize(); i++) {
		CefValueType type = msg.args->GetType(i);
		CI_LOG_I( "  Message index " + std::to_string(i) + " of type " + std::to_string(type));

		switch (type) {
		case VTYPE_BOOL:
			CI_LOG_I("  Bool content: " << std::to_string(msg.args->GetBool(i)));
			break;
		case VTYPE_INT:
			CI_LOG_I("  Int content: " << std::to_string(msg.args->GetInt(i)));
			break;
		case VTYPE_DOUBLE:
			CI_LOG_I("  Double content: " << std::to_string(msg.args->GetDouble(i)));
			break;
		case VTYPE_STRING:
			CI_LOG_I("  String content: " << msg.args->GetString(i).ToString());
			break;

		default:
			CI_LOG_I("  Might be a VTYPE_BINARY, VTYPE_DICTIONARY or VTYPE_LIST");
			break;
		}
	}
}


void FabViewApp::draw() {

    gl::clear(Color{1, 1, 1});

	vanillaView.draw();

	gl::drawString("FPS: " + std::to_string(getAverageFps()), ci::vec2(10.0f, 10.0f), Color::black(), mFont);

}

void prepareSettings(App::Settings *settings) {
	settings->setWindowSize(1200, 800);
#if defined(CINDER_MSW)
	settings->setConsoleWindowEnabled();
#endif
	settings->setFrameRate(-1);
    char *argv[5] = {};
    coc::initCiCEF(0, argv);
	CI_LOG_I(argv);
}

CINDER_APP(FabViewApp, RendererGl, &prepareSettings)
