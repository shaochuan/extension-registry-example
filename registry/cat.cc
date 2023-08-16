#include "registry/cat.h"
#include "registry/registry.pb.h"
#include <iostream>

namespace animal {

CatEntity::CatEntity(const ::registry::Cat &cat_config)
    : color_(cat_config.color()) {}

void CatEntity::display() const {
  std::cout << "Cat Color: " << color_ << std::endl;
}

} // namespace animal
