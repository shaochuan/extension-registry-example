#ifndef _REGISTRY_CAT_H
#define _REGISTRY_CAT_H

#include "registry/animal.h"
#include "registry/registry.pb.h"
#include <iostream>

namespace animal {

class CatEntity : public Animal {
public:
  explicit CatEntity(const ::registry::Cat &cat_config);
  void display() const override;

private:
  std::string color_;
};

} // namespace animal

#endif // _REGISTRY_CAT_H