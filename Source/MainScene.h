#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "axmol.h"

class MainScene : public ax::Scene {
    enum class GameState {
        init = 0,
        update,
    };

public:
    bool init() override;
    void update(float delta) override;

private:
    GameState _gameState = GameState::init;
    ax::Label *_modeLabel;
    ax::Label *_joystickLabel;

    void updateModeLabel();
    void onJoystickButtonPressed(ax::Controller *controller, int keyCode, ax::Event *event);
};

#endif // __MAIN_SCENE_H__
