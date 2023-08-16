#ifndef _REGISTRY_DOG_H
#define _REGISTRY_DOG_H

#include "registry/animal.h"
#include "registry/registry.pb.h"
#include "registry/rpc_stub.h"
#include <iostream>

namespace animal {

class DogEntity : public Animal {
public:
  explicit DogEntity(const ::registry::Dog &dog_config, rpc::RPCStub *rpc_stub);
  void display() const override;

private:
  std::string breed_;
  rpc::RPCStub *rpc_stub_; // Dependency
};

} // namespace animal

#endif // _REGISTRY_DOG_H