#include "main.hpp"
#include "hooks.hpp"

#include "PluginConfig.hpp"
#include "PluginUI/DTManager.hpp"
using namespace DebrisTweaks::UI;

static ModInfo modInfo;

Configuration& getConfig() {
    static Configuration config(modInfo);
    return config;
}

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load();
    getLogger().info("Completed setup!");
}

extern "C" void load() {
    il2cpp_functions::Init();

    BSML::Init();
    manager.Init();
    getPluginConfig().Init(modInfo);

    getLogger().info("Installing DebrisTweaks Hooks!");
    Hooks::InstallHooks(getLogger());
    getLogger().info("Installed DebrisTweaks Hooks Successfully!");
}