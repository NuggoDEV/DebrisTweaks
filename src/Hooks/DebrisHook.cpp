#include "hooks.hpp"
#include "PluginConfig.hpp"

#include "GlobalNamespace/NoteDebris.hpp"
#include "GlobalNamespace/ColorType.hpp"
#include "GlobalNamespace/ConditionalMaterialSwitcher.hpp"
#include "GlobalNamespace/MaterialPropertyBlockController.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Vector3.hpp"
#include "UnityEngine/Quaternion.hpp"
#include "UnityEngine/Rigidbody.hpp"
#include "UnityEngine/Transform.hpp"
#include "UnityEngine/Renderer.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/MaterialPropertyBlock.hpp"
#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

void set_freezeRotation(UnityEngine::Rigidbody *rigidBody, bool value)
{
    static auto set_freezeRotation = reinterpret_cast<function_ptr_t<void, Rigidbody*, bool>>(il2cpp_functions::resolve_icall("UnityEngine.Rigidbody::set_freezeRotation"));
    set_freezeRotation(rigidBody, value);
}

void set_drag(UnityEngine::Rigidbody *rigidbody, float value)
{
    static auto set_drag = reinterpret_cast<function_ptr_t<void, Rigidbody*, float>>(il2cpp_functions::resolve_icall("UnityEngine.Rigidbody::set_drag"));
    set_drag(rigidbody, value);
}

MAKE_AUTO_HOOK_MATCH(NoteDebris_Init, &NoteDebris::Init, void, NoteDebris* self, ColorType colorType, Vector3 notePos, Quaternion noteRot, Vector3 noteMoveVec, Vector3 noteScale, Vector3 positionOffset, Quaternion rotationOffset, Vector3 cutPoint, Vector3 cutNormal, Vector3 force, Vector3 torque, float lifeTime)
{
    if (getPluginConfig().ModToggle.GetValue())
    {
        float velocity = getPluginConfig().VelocityMult.GetValue();

        lifeTime = getPluginConfig().OverrideDebrisLifetime.GetValue() ? getPluginConfig().DebrisLifetime.GetValue() : lifeTime;
        /*noteScale = Vector3().get_one() * getPluginConfig().DebrisScale.GetValue();
        
        force.x *= velocity; 
        force.y *= velocity; 
        force.z *= velocity;*/
    }

    NoteDebris_Init(self, colorType, notePos, noteRot, noteMoveVec, noteScale, positionOffset, rotationOffset, cutPoint, cutNormal, force, torque, lifeTime);

    if (getPluginConfig().ModToggle.GetValue() && self)
    {
        Rigidbody *rb = self->GetComponent<Rigidbody*>();

        set_freezeRotation(rb, getPluginConfig().PreventRotations.GetValue());

        set_drag(rb, getPluginConfig().DebrisDrag.GetValue());

        Transform *transform = self->get_transform();
        rb->set_useGravity(getPluginConfig().UseGravity.GetValue());

        Renderer *render = transform->get_gameObject()->GetComponentInChildren<Renderer*>();
        if (render)
        {
            ConditionalMaterialSwitcher *matSwitcher = transform->GetComponentInChildren<ConditionalMaterialSwitcher*>();
            if (getPluginConfig().UsePCDebris.GetValue())
                render->SetMaterial(matSwitcher->material1);
            
            if (getPluginConfig().UseMonochromatic.GetValue())
            {
                self->materialPropertyBlockController->materialPropertyBlock->SetColor(self->_get__colorID(), Color::get_gray());
                self->materialPropertyBlockController->ApplyChanges();
            }
        }
    }
}