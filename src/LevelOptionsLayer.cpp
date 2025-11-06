// #include "AddIDs.hpp"

#include <Geode/Bindings.hpp>
#include <Geode/modify/LevelOptionsLayer.hpp>
#include "Geode/utils/NodeIDs.hpp"

using namespace geode::prelude;
using namespace node_ids;

$register_ids(LevelOptionsLayer) {
    setIDs(
        m_mainLayer,
        0,
        "background-layer",
        "spawn-group-background-layer",
        "text-layer",
        "spawn-group-text"
    );
    setIDs(
        m_mainLayer,
        5,
        "button-menu",
        "spawn-group-input"
    );

    if (auto menu = m_mainLayer->getChildByID("button-menu")) {
        setIDs(
            menu,
            0,
            "mini-mode",
            "dual-mode",
            "2-player-mode",
            "2-player-mode-info",
            "mirror-mode",
            "flip-gravity",
            "rotate-gameplay",
            "reverse-gameplay",
            "no-time-penalty",
            "no-time-penalty-info",
            "spawn-group-left",
            "spawn-group-right",
            "spawn-group-info",
            "settings",
            "close",
            "left",
            "right"
        );
    }

    if (auto textLayer = m_mainLayer->getChildByID("text-layer")) {
        setIDs(
            textLayer,
            0,
            "mini-mode-text",
            "dual-mode-text",
            "2-player-mode-text",
            "mirror-mode-text",
            "flip-gravity-text",
            "rotate-gameplay-text",
            "reverse-gameplay-text",
            "no-time-penalty-text"
        );
    }
}

struct LevelOptionsLayerIDs : Modify<LevelOptionsLayerIDs, LevelOptionsLayer> {
    static void onModify(auto &self) {
        if (!self.setHookPriority("LevelOptionsLayer::init", GEODE_ID_PRIORITY)) {
            log::warn("Failed to set LevelOptionsLayer::init hook priority, node IDs may not work properly");
        }
    }

    bool init(LevelSettingsObject *p0) {
        if (!LevelOptionsLayer::init(p0))
            return false;
        NodeIDs::get()->provide(this);
        return true;
    }
};