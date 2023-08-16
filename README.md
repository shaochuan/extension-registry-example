C++ Registration Pattern with Protobuf Extension
======================

A minimal example that implements the registry pattern in C++ and protobuf. In particular, it's implementing Variadic Factory pattern to achieve config-driven factory method without having to update the call sites.

Build & Run
======================

The binary needs to be built with C++17 via bazel. Thus, make sure you had
```
export BAZEL_CXXOPTS="-std=c++17"
```
in your `.bashrc`.

    $ bazel run //registry:registry
```
Dog Breed: labrador
RPC Message: Displaying Dog Entity
Cat Color: white
```
