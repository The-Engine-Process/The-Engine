/*
 * Copyright (c) 2018 Isetta
 */
#pragma once
#include "Scene/Component.h"

namespace Isetta {
class ExampleComponent : public Component {
 public:
  void OnEnable() override;
  void Update() override;
};
}  // namespace Isetta
