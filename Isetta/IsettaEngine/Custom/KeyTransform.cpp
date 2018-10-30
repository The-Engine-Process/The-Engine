/*
 * Copyright (c) 2018 Isetta
 */
#include "KeyTransform.h"

#include "Core/Math/Vector3.h"
#include "Core/Time/Clock.h"
#include "EngineLoop.h"
#include "Input/Input.h"
#include "Scene/Transform.h"

namespace Isetta {
void KeyTransform::OnEnable() {
  // Translation
  Input::RegisterKeyPressCallback(KeyCode::RIGHT_ARROW, [&]() {
    if (pressed) return;
    this->GetTransform().TranslateLocal(step * Math::Vector3::left);
  });
  Input::RegisterKeyPressCallback(KeyCode::LEFT_ARROW, [&]() {
    if (pressed) return;
    this->GetTransform().TranslateLocal(step * Math::Vector3::right);
  });
  Input::RegisterKeyPressCallback(KeyCode::UP_ARROW, [&]() {
    if (pressed) return;
    this->GetTransform().TranslateLocal(step * Math::Vector3::forward);
  });
  Input::RegisterKeyPressCallback(KeyCode::DOWN_ARROW, [&]() {
    if (pressed) return;
    this->GetTransform().TranslateLocal(step * Math::Vector3::back);
  });

  // Rotation
  Input::RegisterKeyPressCallback(KeyCode::NUM1, [&]() {
    if (pressed) return;
    this->GetTransform().RotateLocal(Math::Vector3::right, step);
  });
  Input::RegisterKeyPressCallback(KeyCode::NUM2, [&]() {
    if (pressed) return;
    this->GetTransform().RotateLocal(Math::Vector3::left, step);
  });
  Input::RegisterKeyPressCallback(KeyCode::NUM3, [&]() {
    if (pressed) return;
    this->GetTransform().RotateLocal(Math::Vector3::down, step);
  });
  Input::RegisterKeyPressCallback(KeyCode::KP_6, [&]() {
    if (pressed) return;
    this->GetTransform().RotateLocal(Math::Vector3::up, step);
  });
  Input::RegisterKeyPressCallback(KeyCode::KP_7, [&]() {
    if (pressed) return;
    this->GetTransform().RotateLocal(Math::Vector3::back, step);
  });
  Input::RegisterKeyPressCallback(KeyCode::KP_9, [&]() {
    if (pressed) return;
    this->GetTransform().RotateLocal(Math::Vector3::forward, step);
  });

  // Scale
  Input::RegisterKeyPressCallback(KeyCode::KP_1, [&]() {
    if (pressed) return;
    this->GetTransform().SetLocalScale(this->GetTransform().GetLocalScale() *
                                       1.1);
  });
  Input::RegisterKeyPressCallback(KeyCode::KP_3, [&]() {
    if (pressed) return;
    this->GetTransform().SetLocalScale(this->GetTransform().GetLocalScale() *
                                       .9);
  });

  Input::RegisterKeyPressCallback(KeyCode::M, [&]() { pressed = !pressed; });
}
void KeyTransform::Update() {
  if (!pressed) return;
  if (Input::IsKeyPressed(KeyCode::RIGHT_ARROW)) {
    this->GetTransform().TranslateLocal(
        10 * step * Math::Vector3::left *
        EngineLoop::GetGameClock().GetDeltaTime());
  }
  if (Input::IsKeyPressed(KeyCode::LEFT_ARROW)) {
    this->GetTransform().TranslateLocal(
        10 * step * Math::Vector3::right *
        EngineLoop::GetGameClock().GetDeltaTime());
  }
  if (Input::IsKeyPressed(KeyCode::UP_ARROW)) {
    this->GetTransform().TranslateLocal(
        10 * step * Math::Vector3::forward *
        EngineLoop::GetGameClock().GetDeltaTime());
  }
  if (Input::IsKeyPressed(KeyCode::DOWN_ARROW)) {
    this->GetTransform().TranslateLocal(
        10 * step * Math::Vector3::back *
        EngineLoop::GetGameClock().GetDeltaTime());
  }
  if (Input::IsKeyPressed(KeyCode::PAGE_UP)) {
    this->GetTransform().TranslateLocal(
        10 * step * Math::Vector3::up *
        EngineLoop::GetGameClock().GetDeltaTime());
  }
  if (Input::IsKeyPressed(KeyCode::PAGE_DOWN)) {
    this->GetTransform().TranslateLocal(
        10 * step * Math::Vector3::down *
        EngineLoop::GetGameClock().GetDeltaTime());
  }

  // Rotation
  if (Input::IsKeyPressed(KeyCode::NUM1)) {
    this->GetTransform().RotateLocal(Math::Vector3::right, 10 * step * EngineLoop::GetGameClock().GetDeltaTime());
  };
  if (Input::IsKeyPressed(KeyCode::NUM2)) {
    this->GetTransform().RotateLocal(
        Math::Vector3::left,
        10 * step * EngineLoop::GetGameClock().GetDeltaTime());
  }
  if (Input::IsKeyPressed(KeyCode::NUM3)) {
    this->GetTransform().RotateLocal(
        Math::Vector3::down,
        10 * step * EngineLoop::GetGameClock().GetDeltaTime());
  }
  if (Input::IsKeyPressed(KeyCode::KP_6)) {
    this->GetTransform().RotateLocal(
        Math::Vector3::up,
        10 * step * EngineLoop::GetGameClock().GetDeltaTime());
  }
  if (Input::IsKeyPressed(KeyCode::KP_7)) {
    this->GetTransform().RotateLocal(
        Math::Vector3::back,
        10 * step * EngineLoop::GetGameClock().GetDeltaTime());
  }
  if (Input::IsKeyPressed(KeyCode::KP_9)) {
    this->GetTransform().RotateLocal(
        Math::Vector3::forward,
        10 * step * EngineLoop::GetGameClock().GetDeltaTime());
  }

  // Scale
  if (Input::IsKeyPressed(KeyCode::KP_1)) {
    this->GetTransform().SetLocalScale(this->GetTransform().GetLocalScale() *
                                       (1 + .1 * EngineLoop::GetGameClock().GetDeltaTime()));
  }
  if (Input::IsKeyPressed(KeyCode::KP_3)) {
    this->GetTransform().SetLocalScale(this->GetTransform().GetLocalScale() *
                                       (1 - .1 * EngineLoop::GetGameClock().GetDeltaTime()));
  }
}
}  // namespace Isetta
