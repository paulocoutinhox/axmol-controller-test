#include "MenuWindowGUI.h"
#include "MainScene.h"
#include "base/EventDispatcher.h"
#include "base/EventListenerController.h"

USING_NS_AX;
USING_NS_FGUI;

void MenuWindowGUI::onInit() {
    // create and set content pane
    auto contentPane = UIPackage::createObject("Main", "GameMenuWindow")->as<GComponent>();
    setContentPane(contentPane);

    // fields
    text1 = dynamic_cast<GTextField *>(contentPane->getChild("text1"));
    text2 = dynamic_cast<GTextField *>(contentPane->getChild("text2"));

#ifdef _AX_DEBUG
    text1->setText("Mode: Debug");
#else
    text1->setText("Mode: Release");
#endif

    // add joystick listener
    Controller::startDiscoveryController();
    auto listener = EventListenerController::create();
    listener->onKeyDown = AX_CALLBACK_3(MenuWindowGUI::onControllerKeyDown, this);

    // get the current scene node
    auto scene = Director::getInstance()->getRunningScene();
    if (scene) {
        scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, scene);
    }
}

void MenuWindowGUI::onControllerKeyDown(Controller *controller, int keyCode, Event *event) {
    std::string button;

    if (keyCode == Controller::Key::BUTTON_X) {
        auto scene = utils::createInstance<MainScene>();
        Director::getInstance()->replaceScene(scene);
        return;
    }

    switch (keyCode) {
    case Controller::Key::BUTTON_DPAD_UP:
        button = "Up";
        break;
    case Controller::Key::BUTTON_DPAD_DOWN:
        button = "Down";
        break;
    case Controller::Key::BUTTON_DPAD_LEFT:
        button = "Left";
        break;
    case Controller::Key::BUTTON_DPAD_RIGHT:
        button = "Right";
        break;
    case Controller::Key::BUTTON_A:
        button = "A";
        break;
    case Controller::Key::BUTTON_B:
        button = "B";
        break;
    case Controller::Key::BUTTON_C:
        button = "C";
        break;
    case Controller::Key::BUTTON_X:
        button = "X";
        break;
    case Controller::Key::BUTTON_Y:
        button = "Y";
        break;
    case Controller::Key::BUTTON_Z:
        button = "Z";
        break;
    default:
        button = "None";
        break;
    }

    text2->setText("Joystick Button: " + button);
}
