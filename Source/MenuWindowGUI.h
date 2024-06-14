#pragma once

#include <vector>

#include "FairyGUI.h"
#include "axmol.h"

class MenuWindowGUI : public fairygui::Window {
public:
    CREATE_FUNC(MenuWindowGUI);
    void onControllerKeyDown(ax::Controller *controller, int keyCode, ax::Event *event);

protected:
    virtual void onInit() override;

private:
    fairygui::GTextField *text1;
    fairygui::GTextField *text2;
};
