// #include "AddIDs.hpp"

#include <Geode/Bindings.hpp>
#include <Geode/modify/LevelSettingsLayer.hpp>
#include "Geode/utils/NodeIDs.hpp"

using namespace geode::prelude;
using namespace node_ids;

$register_ids(LevelSettingsLayer) {
    setIDs(
        m_mainLayer,
        0,
        "background-layer",
        "song-background-layer",
        "select-color-text",
        "bg-color-text",
        "ground-color-text",
        "ground-2-color-text",
        "line-color-text",
        "middle-ground-color-text",
        "middle-ground-2-color-text",
        "more-colors-text",
        "background-text",
        "ground-text",
        "middle-ground-text",
        "select-song-text"
    );
    setIDs(
        m_mainLayer,
        16,
        "speed-text",
        "game-mode-text",
        "options-text",
        "select-song",
        "button-menu",
        "game-type-text"
    );
    if (auto menu = m_mainLayer->getChildByID("button-menu")) {
        setIDs(
            menu,
            0,
            "bg-color",
            "ground-color",
            "ground-2-color",
            "line-color",
            "middle-ground-color",
            "middle-ground-2-color",
            "more-colors",
            "bg-color-live",
            "ground-color-live",
            "ground-2-color-live",
            "line-color-live",
            "middle-ground-color-live",
            "middle-ground-2-color-live",
            "classic-game-type",
            "platformer-game-type",
            "bg",
            "ground",
            "middle-ground",
            "font",
            "ok",
            "left",
            "right",
            "normal-song",
            "custom-song",
            "select-custom-song",
            "new-song",
            "speed",
            "mode",
            "options"
        );
    }
}

struct LevelSettingsLayerIDs : Modify<LevelSettingsLayerIDs, LevelSettingsLayer> {
    static void onModify(auto &self) {
        if (!self.setHookPriority("LevelSettingsLayer::init", GEODE_ID_PRIORITY)) {
            log::warn("Failed to set LevelSettingsLayer::init hook priority, node IDs may not work properly");
        }
    }

    bool init(LevelSettingsObject *p0, LevelEditorLayer *p1) {
        if (!LevelSettingsLayer::init(p0, p1))
            return false;
        NodeIDs::get()->provide(this);
        return true;
    }
};