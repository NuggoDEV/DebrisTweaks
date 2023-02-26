#pragma once

#include "custom-types/shared/macros.hpp"
#include "HMUI/ViewController.hpp"
#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSML/Components/Settings/SliderSetting.hpp"
#include "bsml/shared/BSML/Components/Settings/ToggleSetting.hpp"

DECLARE_CLASS_CODEGEN(DebrisTweaks::UI, DTViewController, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

    DECLARE_INSTANCE_METHOD(void, ActivateTestLevel);
    DECLARE_INSTANCE_METHOD(void, ResetDefault);
    DECLARE_INSTANCE_METHOD(void, DebrisLifetimeEvent);

    // Base Stuff
    DECLARE_BSML_PROPERTY(bool, ModToggle);
    DECLARE_INSTANCE_FIELD(BSML::ToggleSetting*, ModToggleID);

    // Physics Stuff
    DECLARE_BSML_PROPERTY(float, VelocityMult);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, VelocityMultID);

    DECLARE_BSML_PROPERTY(float, DebrisDrag);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, DebrisDragID);

    DECLARE_BSML_PROPERTY(bool, UseGravity);
    DECLARE_INSTANCE_FIELD(BSML::ToggleSetting*, UseGravityID);

    DECLARE_BSML_PROPERTY(bool, PreventRotations);
    DECLARE_INSTANCE_FIELD(BSML::ToggleSetting*, PreventRotationsID);


    // Cosmetic Stuff
    DECLARE_BSML_PROPERTY(bool, UseMonochromatic);
    DECLARE_INSTANCE_FIELD(BSML::ToggleSetting*, UseMonochromaticID);

    DECLARE_BSML_PROPERTY(bool, OverrideDebrisLifetime);
    DECLARE_INSTANCE_FIELD(BSML::ToggleSetting*, OverrideDebrisLifetimeID);

    DECLARE_BSML_PROPERTY(float, DebrisScale);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, DebrisScaleID);

    DECLARE_BSML_PROPERTY(float, DebrisLifetime);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, DebrisLifetimeID);
)