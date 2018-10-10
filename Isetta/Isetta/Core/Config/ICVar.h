/*
 * Copyright (c) 2018 Isetta
 */
#pragma once

#include <string>
#include <unordered_map>
#include "Core/Math/Vector3.h"
#include "SID/sid.h"

namespace Isetta {
/**
 * @brief Base class of console variables
 *
 */
class ICVar {
 public:
  /// Key name of CVar
  const std::string name;
  /// StringId of CVar
  const StringId nameID;

  /**
   * @brief Set the Val object, abstract
   *
   * @param strVal convert from this string
   */
  virtual void SetVal(const std::string& strVal) = 0;
  // virtual StringId GetType() const { return typeID; }

 protected:
  // const StringId typeID;
  /**
   * @brief Construct a new ICVar object, cannot publicly create ICVar
   *
   * @param name
   */
  explicit ICVar(std::string name) : name{name}, nameID{SID(name.c_str())} {}
  /**
   * @brief Destroy the ICVar object, cannot instance ICVar
   *
   */
  virtual ~ICVar() {}
};
}  // namespace Isetta
