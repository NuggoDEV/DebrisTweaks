#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(PluginConfig,
    // Base Stuff
    CONFIG_VALUE(ModToggle, bool, "Activates/disables DebrisTweaks", true);

    // Physics Stuff
    CONFIG_VALUE(VelocityMult, float, "Velocity of the debris", 1.0f);
    CONFIG_VALUE(DebrisDrag, float, "How much the debris is dragged down", 1.0f);
    CONFIG_VALUE(UseGravity, bool, "Let debris use gravity", true);
    CONFIG_VALUE(PreventRotations, bool, "Allows debris to rotate", false);

    // Cosmetic Stuff
    CONFIG_VALUE(UseMonochromatic, bool, "Uses monochromatic colours on debris", false);
    CONFIG_VALUE(OverrideDebrisLifetime, bool, "Allows for debris to exist for longer", false);
    CONFIG_VALUE(DebrisScale, float, "Size of the debris", 1.0f);
    CONFIG_VALUE(DebrisLifetime, float, "How long the debris will exist for", 3.0f);
)