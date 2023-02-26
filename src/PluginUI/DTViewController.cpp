#include "main.hpp"
#include "PluginUI/DTViewController.hpp"
using namespace DebrisTweaks::UI;
DEFINE_TYPE(DebrisTweaks::UI, DTViewController);

#include "PluginConfig.hpp"

#include "assets.hpp"
#include "bsml/shared/BSML.hpp"

#include "UnityEngine/Resources.hpp"
#include "GlobalNamespace/SimpleLevelStarter.hpp"
#include "GlobalNamespace/BeatmapLevelData.hpp"
#include "GlobalNamespace/BeatmapLevelSO.hpp"

#include <sstream>
#include <iomanip>

#define BSML_VALUE(type, name)                                                             \
type DTViewController::get_##name() { return getPluginConfig().name.GetValue(); }          \
void DTViewController::set_##name(type value) { getPluginConfig().name.SetValue(value); }

namespace DebrisTweaks::UI
{
    std::function<std::string(float)> LifetimeFormatter = [](float value)
    {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << value;
        return stream.str() + "s";
    };

    void DTViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
    {
        if (!firstActivation) return;
        BSML::parse_and_construct(IncludedAssets::settings_bsml, this->get_transform(), this);

        DebrisLifetimeID->formatter = LifetimeFormatter;
    }

    void DTViewController::ActivateTestLevel() 
    {
        auto simpleLevelStarters = UnityEngine::Resources::FindObjectsOfTypeAll<GlobalNamespace::SimpleLevelStarter*>();
        for (auto& starter : simpleLevelStarters)
        {
            if (starter->get_gameObject()->get_name()->Contains("PerformanceTestLevelButton"))
            {
                starter->level->set_name("DebrisTweaks Test");
                starter->StartLevel();
                return;
            }
        }
    }

    void DTViewController::ResetDefault() 
    {
        getPluginConfig().ModToggle.SetValue(getPluginConfig().ModToggle.GetDefaultValue());
        getPluginConfig().DebrisScale.SetValue(getPluginConfig().DebrisScale.GetDefaultValue());
    }

    void DTViewController::DebrisLifetimeEvent() 
    {
        DebrisLifetimeID->formatter = LifetimeFormatter;
    }

    BSML_VALUE(bool, ModToggle);
    BSML_VALUE(float, VelocityMult);
    BSML_VALUE(float, DebrisDrag);
    BSML_VALUE(bool, UseGravity);
    BSML_VALUE(bool, PreventRotations);
    BSML_VALUE(bool, UsePCDebris);
    BSML_VALUE(bool, UseMonochromatic);
    BSML_VALUE(bool, OverrideDebrisLifetime);
    BSML_VALUE(float, DebrisScale);
    BSML_VALUE(float, DebrisLifetime);

}