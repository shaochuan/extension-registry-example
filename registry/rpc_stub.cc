#include "registry/rpc_stub.h"

#include <iostream>
#include <string_view>

namespace rpc {
  void RPCStub::send(std::string_view message) const {
    // Simulated RPC send (just a print for this example)
    std::cout << "RPC Message: " << message << std::endl;
}
}  // namespace rpc