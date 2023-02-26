#include "PluginUI/DTFlowCoordinator.hpp"
#include "PluginUI/DTViewController.hpp"
using namespace DebrisTweaks::UI;

DEFINE_TYPE(DebrisTweaks::UI, DTFlowCoordinator);

#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"
using namespace HMUI;

#include "bsml/shared/Helpers/creation.hpp"

void DTFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) 
{
    if (!firstActivation) return;
    viewController = BSML::Helpers::CreateViewController<DebrisTweaks::UI::DTViewController*>();

    showBackButton = true;
    ProvideInitialViewControllers(viewController, nullptr, nullptr, nullptr, nullptr);
    SetTitle("DebrisTweaks", ViewController::AnimationType::In);
}

void DTFlowCoordinator::BackButtonWasPressed(ViewController *topViewController) 
{
    this->parentFlowCoordinator->DismissFlowCoordinator(this, ViewController::AnimationDirection::Horizontal, nullptr, false);
}