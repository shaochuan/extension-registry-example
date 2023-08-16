#ifndef _REGISTRY_RPC_STUB_H
#define _REGISTRY_RPC_STUB_H

#include <string_view>

namespace rpc {

// RPC Stub definition
class RPCStub {
  public:
    void send(std::string_view message) const;
};

}  // namespace rpc

#endif  // _RPC_RPC_STUB_H