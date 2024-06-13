#include "MainScene.h"

USING_NS_AX;

bool MainScene::init() {
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = _director->getVisibleSize();
    auto origin = _director->getVisibleOrigin();

    // mode label
    _modeLabel = Label::createWithTTF("Mode: Release", "fonts/Marker Felt.ttf", 60);
    _modeLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + _modeLabel->getContentSize().height));
    addChild(_modeLabel);

    // mode joystick
    _joystickLabel = Label::createWithTTF("Joystick Button: None", "fonts/Marker Felt.ttf", 60);
    _joystickLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, _modeLabel->getPosition().y - _modeLabel->getContentSize().height - 50));
    addChild(_joystickLabel);

    // update mode
    updateModeLabel();

    // controller listener
    Controller::startDiscoveryController();
    auto joystickListener = EventListenerController::create();
    joystickListener->onKeyDown = AX_CALLBACK_3(MainScene::onJoystickButtonPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(joystickListener, this);

    // schedule update
    scheduleUpdate();

    return true;
}

void MainScene::update(float delta) {
    switch (_gameState) {
    case GameState::init: {
        _gameState = GameState::update;
        break;
    }

    case GameState::update: {
        // ignore
        break;
    }
    }
}

void MainScene::updateModeLabel() {
#ifdef _AX_DEBUG
    std::string mode = "Mode: Debug";
#else
    std::string mode = "Mode: Release";
#endif

    _modeLabel->setString(mode);
}

void MainScene::onJoystickButtonPressed(Controller *controller, int keyCode, Event *event) {
    std::string button;

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
    default:
        button = "None";
        break;
    }

    _joystickLabel->setString("Joystick Button: " + button);
}
