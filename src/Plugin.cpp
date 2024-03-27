#include "Plugin.h"
#include "Global.h"
#include <GMLIB/GMLIB.h>

ll::Logger logger(PLUGIN_NAME);

namespace plugin {

Plugin::Plugin(ll::plugin::NativePlugin& self) : mSelf(self) {
    // Code for loading the plugin goes here.
    RegisterCreativeItem();
}

bool Plugin::enable() {
    // Code for enabling the plugin goes here.
    RegisterFireworksRecipe();
    logger.info("SuperFireworks Recipes Registered Successfully!");
    return true;
}

bool Plugin::disable() {
    // Code for disabling the plugin goes here.
    return true;
}

} // namespace plugin
