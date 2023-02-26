#pragma once

#include "custom-types/shared/macros.hpp"
#include "HMUI/ViewController.hpp"
#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSML/Components/Settings/SliderSetting.hpp"

DECLARE_CLASS_CODEGEN(DebrisTweaks::UI, DTViewController, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

    DECLARE_INSTANCE_METHOD(void, ActivateTestLevel);
    DECLARE_INSTANCE_METHOD(void, ResetDefault);

    DECLARE_BSML_PROPERTY(bool, ModToggle);


    // Physics Stuff
    DECLARE_BSML_PROPERTY(float, VelocityMult);
    DECLARE_BSML_PROPERTY(float, DebrisDrag);
    DECLARE_BSML_PROPERTY(bool, UseGravity);
    DECLARE_BSML_PROPERTY(bool, PreventRotations);

    DECLARE_BSML_PROPERTY(bool, UsePCDebris);
    DECLARE_BSML_PROPERTY(bool, UseMonochromatic);
    DECLARE_BSML_PROPERTY(bool, OverrideDebrisLifetime);
    DECLARE_BSML_PROPERTY(float, DebrisScale);
    DECLARE_BSML_PROPERTY(float, DebrisLifetime);

    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, DebrisLifetimeID);
    DECLARE_INSTANCE_METHOD(void, DebrisLifetimeEvent);
)