#include "registry/dog.h"
#include "registry/registry.pb.h"
#include "registry/rpc_stub.h"
#include <iostream>

namespace animal {

DogEntity::DogEntity(const ::registry::Dog &dog_config, rpc::RPCStub *rpc_stub)
    : breed_(dog_config.breed()), rpc_stub_(rpc_stub) {}

void DogEntity::display() const {
  std::cout << "Dog Breed: " << breed_ << std::endl;
  rpc_stub_->send("Displaying Dog Entity");
}

} // namespace animal
