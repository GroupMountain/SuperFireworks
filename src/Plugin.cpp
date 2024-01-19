#include "Plugin.h"
#include "Global.h"
#include <GMLIB/GMLIB.h>

ll::Logger logger(PLUGIN_NAME);

namespace plugin {

Plugin::Plugin(ll::plugin::NativePlugin& self) : mSelf(self) {
    // Code for loading the plugin goes here.
}

bool Plugin::enable() {
    // Code for enabling the plugin goes here.
    auto requireLibVersion = SemVersion(0, 5, 0, "", "");
    if (GMLIB::Version::checkLibVersionMatch(requireLibVersion)) {
        RegisterFireworksRecipe();
        logger.info("SuperFireworks Recipes Registered Successfully!");
    } else {
        logger.error("GMLIB Version is outdated! Please update your GMLIB!");
        logger.error(
            "Current GMLIB Version {}, Required Lowest GMLIB Version {}",
            GMLIB::Version::getLibVersionString(),
            requireLibVersion.asString()
        );
    }
    return true;
}

bool Plugin::disable() {
    // Code for disabling the plugin goes here.
    return true;
}

} // namespace plugin
