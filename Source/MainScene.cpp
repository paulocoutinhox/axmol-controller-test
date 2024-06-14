#include "MainScene.h"

USING_NS_AX;
USING_NS_FGUI;

bool MainScene::init() {
    if (!Scene::init()) {
        return false;
    }

    // add joystick listener
    Controller::startDiscoveryController();
    auto listener = EventListenerController::create();
    listener->onKeyDown = AX_CALLBACK_3(MainScene::onControllerKeyDown, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    // schedule update
    scheduleUpdate();

    return true;
}

void MainScene::onControllerKeyDown(Controller *controller, int keyCode, Event *event) {
    if (window) {
        window->onControllerKeyDown(controller, keyCode, event);
    }
}

void MainScene::update(float delta) {
    switch (_gameState) {
    case GameState::init: {

        groot = GRoot::create(this);
        groot->retain();

        window = MenuWindowGUI::create();
        window->retain();
        window->initWindow();
        window->show();

        _gameState = GameState::update;
        break;
    }

    case GameState::update: {
        // ignore
        break;
    }
    }
}

MainScene::~MainScene() {
    AX_SAFE_RELEASE(window);
    AX_SAFE_RELEASE(groot);
}
