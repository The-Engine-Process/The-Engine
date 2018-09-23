/*
 * Copyright (c) 2018 Isetta
 */
#pragma once

#ifndef __  // GLAD must be placed first
#include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>
#include <list>
#include <string>
#include <unordered_map>
#include "Core/Config/CVar.h"
#include "Core/IsettaAlias.h"
#include "imgui/imgui.h"

class ImVec4;

namespace Isetta {
class GUIModule {
 public:
  struct GUIModuleConfig {};

  void OnUpdate(const Action<>&);

 private:
  GUIModule() = default;
  ~GUIModule() = default;

  void StartUp(GLFWwindow* win);
  void Update(float deltaTime);
  void ShutDown();

  GLFWwindow* winHandle;

  std::list<Action<>> updateCallbacks{};
  // TODO(Jacob) too much?
  static U64 handleCount;

  friend class ModuleManager;

  // Test variables
  bool show_demo_window, show_another_window;
  ImVec4 clear_color;
};
}  // namespace Isetta
