C++ Registration Pattern with Protobuf Extension
======================

A minimal example that implements the registry pattern in C++ and protobuf.

Build & Run
======================

gRPC C++ library needs to be built with C++17. Thus, make sure you had
```
export BAZEL_CXXOPTS="-std=c++17"
```
in your `.bashrc`.

    $ blaze run //registry:registry
```
Dog Breed: labrador
RPC Message: Displaying Dog Entity
Cat Color: white
```
