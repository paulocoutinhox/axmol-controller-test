#include "MainScene.h"

USING_NS_AX;
USING_NS_FGUI;

bool MainScene::init() {
    if (!Scene::init()) {
        return false;
    }

    // schedule update
    scheduleUpdate();

    return true;
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
