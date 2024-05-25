#include "Global.h"

void RegisterFireworksRecipe() {
    auto item = GMLIB_ItemStack{"minecraft:firework_rocket"};
    item.setCustomLore({"", "§r§7由TNT制成的焯级大烟花", "§r§7动力强劲更持久！"});
    item.setCustomName("§r§e焯级大烟花");
    auto nbt = item.getNbt();
    nbt->getCompound("tag")->putCompound("Fireworks", CompoundTag{});
    nbt->getCompound("tag")->getCompound("Fireworks")->put("Explosions", ListTag{});
    item.setNbt(*nbt);
    std::vector<Recipes::Type> ingredients = {Recipes::Type("minecraft:paper", 'A', 1, 0)};
    for (int i = 0; i <= 7; i++) {
        ingredients.push_back(Recipes::Type("minecraft:tnt", 'B', 1, 0));
        std::string recipeId = "groupmountain:superfirework" + std::to_string(i + 1);
        auto        nbt      = item.getNbt();
        nbt->getCompound("tag")->getCompound("Fireworks")->putByte("Flight", 5 * (i + 1));
        item.setNbt(*nbt);
        GMLIB::Mod::CustomRecipe::registerShapelessCraftingTableRecipe(recipeId, ingredients, item);
    }
}

void RegisterCreativeItem() {
    ll::event::EventBus::getInstance().emplaceListener<GMLIB::Event::Registries::CreativeItemInitEvent>(
        [](GMLIB::Event::Registries::CreativeItemInitEvent& ev) {
            auto item = new GMLIB_ItemStack("minecraft:firework_rocket");
            item->setCustomLore({"", "§r§6传说中的终级大烟花", "§r§7该物品仅能从创造模式获得"});
            item->setCustomName("§r§d传说大烟花");
            auto nbt = item->getNbt();
            nbt->getCompound("tag")->putCompound("Fireworks", CompoundTag{});
            nbt->getCompound("tag")->getCompound("Fireworks")->put("Explosions", ListTag{});
            nbt->getCompound("tag")->getCompound("Fireworks")->putByte("Flight", 255);
            item->setNbt(*nbt);
            Item::addCreativeItem(ev.getItemRegistryRef(), *item);
        }
    );
}