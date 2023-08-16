#include <typeinfo>

#include "registry/animal.h"
#include "registry/cat.h"
#include "registry/dog.h"
#include "registry/registry.pb.h"
#include "registry/rpc_stub.h"

namespace {
struct SomeOtherDependency {
  int foobar;
};

// Module.
using AllDependencies = std::tuple<rpc::RPCStub *, SomeOtherDependency *>;

template <typename T> struct EntityDependencies;

template <>
struct EntityDependencies<animal::DogEntity> {
  using type = std::tuple<rpc::RPCStub *>;

  static type extract(AllDependencies &deps) {
    return std::make_tuple(std::get<rpc::RPCStub *>(deps));
  }
};

template <>
struct EntityDependencies<animal::CatEntity> {
  using type = std::tuple<>;
  static type extract(AllDependencies & /*deps*/) { return {}; }
};

template <typename ProtoType, typename EntityType>
class EntityMapper {
public:
  static bool CanCreate(const registry::Animal &animal) {
    return animal.HasExtension(ProtoType::ext);
  }

  static std::unique_ptr<animal::Animal> Create(const registry::Animal &animal,
                                                AllDependencies &deps) {
    auto constructorArgs =
        std::tuple_cat(std::make_tuple(animal.GetExtension(ProtoType::ext)),
                       EntityDependencies<EntityType>::extract(deps));
    return std::apply(
        [](auto &&...args) {
          return std::make_unique<EntityType>(
              std::forward<decltype(args)>(args)...);
        },
        constructorArgs);
  }
};

using DogMapper = EntityMapper<registry::Dog, animal::DogEntity>;
using CatMapper = EntityMapper<registry::Cat, animal::CatEntity>;
using GenericAnimalFactory = animal::AnimalFactory<DogMapper, CatMapper>;

}  // namespace

int main(int argc, char *argv[]) {
  rpc::RPCStub rpc_stub;
  SomeOtherDependency other_dep;

  AllDependencies allDeps = std::make_tuple(&rpc_stub, &other_dep);

  registry::Animal dog_config;
  dog_config.MutableExtension(registry::Dog::ext)->set_breed("labrador");

  auto dog = GenericAnimalFactory::CreateAnimal(dog_config, allDeps);
  dog->display();

  registry::Animal cat_config;
  cat_config.MutableExtension(registry::Cat::ext)->set_color("white");
  auto cat = GenericAnimalFactory::CreateAnimal(cat_config, allDeps);
  cat->display();
  return 0;
}