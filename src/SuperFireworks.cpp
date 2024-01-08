#include "Global.h"
#include <GMLIB/Server/CompoundTagAPI.h>
#include <GMLIB/Mod/CustomRecipe.h>

void RegisterFireworksRecipe() {
    auto item = ItemStack{"minecraft:firework_rocket"};
    item.setCustomLore({"", "§r§7由TNT制成的焯级大烟花", "§r§7动力强劲更持久！"});
    item.setCustomName("§r§e焯级大烟花");
    auto nbt = GMLIB::CompoundTagHelper::getNbt(&item);
    nbt->getCompound("tag")->putCompound("Fireworks", CompoundTag{});
    nbt->getCompound("tag")->getCompound("Fireworks")->put("Explosions", ListTag{});
    GMLIB::CompoundTagHelper::setNbt(&item, nbt.get());
    std::vector<Recipes::Type> ingredients = {
        Recipes::Type("minecraft:paper", 'A', 1, 0)
    };
    for (int i = 0; i <= 7; i++) {
        ingredients.push_back(Recipes::Type("minecraft:tnt", 'B', 1, 0));
        std::string recipeId = "groupmountain:superfirework" + std::to_string(i + 1);
        auto nbt = GMLIB::CompoundTagHelper::getNbt(&item);
        nbt->getCompound("tag")->getCompound("Fireworks")->putByte("Flight", 5 * (i + 1));
        GMLIB::CompoundTagHelper::setNbt(&item, nbt.get());
        GMLIB::Mod::Recipe::RapidRecipeLoader::registerLockedShapelessCraftingTableRecipe(recipeId, ingredients, item);
    }
}