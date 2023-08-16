#ifndef _REGISTRY_ANIMAL_H
#define _REGISTRY_ANIMAL_H

#include <utility>
#include <memory>
#include "registry/registry.pb.h"

namespace animal {

// Base Class
class Animal {
public:
    virtual ~Animal() = default;
    virtual void display() const = 0;
};

// Factory
template <typename... Mappers>
class AnimalFactory;

template <typename FirstMapper, typename... RestMappers>
class AnimalFactory<FirstMapper, RestMappers...> {
public:
    template <typename... Deps>
    static std::unique_ptr<Animal> CreateAnimal(const registry::Animal& config, Deps... deps) {
        if (FirstMapper::CanCreate(config)) {
            return FirstMapper::Create(config, deps...);
        } else {
            return AnimalFactory<RestMappers...>::CreateAnimal(config, deps...);
        }
    }
};

template <>
class AnimalFactory<> {
public:
    template <typename... Deps>
    static std::unique_ptr<Animal> CreateAnimal(const registry::Animal& config, Deps... /*deps*/) {
        // Unknown config type
        return nullptr;
    }
};

}  // namespace animal

#endif  // _REGISTRY_ANIMAL_H