#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "FairyGUI.h"
#include "MenuWindowGUI.h"
#include "axmol.h"

class MainScene : public ax::Scene {
    enum class GameState {
        init = 0,
        update,
    };

public:
    ~MainScene();
    bool init() override;
    void update(float delta) override;

private:
    GameState _gameState = GameState::init;

    fairygui::GRoot *groot;
    MenuWindowGUI *window;

    void onControllerKeyDown(ax::Controller *controller, int keyCode, ax::Event *event);
};

#endif // __MAIN_SCENE_H__
