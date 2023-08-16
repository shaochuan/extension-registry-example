load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")
load("@com_github_grpc_grpc//bazel:python_rules.bzl", "py_grpc_library", "py_proto_library")

proto_library(
    name = "registry_proto",
    srcs = [
        "registry.proto",
    ],
    visibility = ["//visibility:public"],
)

cpp_proto_library(
    name = "registry_cc_proto",
    protos = [":registry_proto"],
)

cc_library(
    name = "rpc_stub",
    srcs = [
        "rpc_stub.cc"
    ],
    hdrs = [
        "rpc_stub.h"
    ],
)

cc_library(
    name = "animal",
    hdrs = [
        "animal.h"
    ],
    deps = [
        ":registry_cc_proto",
    ]    
)

cc_library(
    name = "dog",
    srcs = [
        "dog.cc"
    ],
    hdrs = [
        "dog.h"
    ],
    deps = [
        ":animal",
        ":registry_cc_proto",
        ":rpc_stub",
    ]
)

cc_library(
    name = "cat",
    srcs = [
        "cat.cc"
    ],
    hdrs = [
        "cat.h"
    ],
    deps = [
        ":animal",
        ":registry_cc_proto"
    ]
)

cc_binary(
    name = "registry",
    srcs = [
        "registry.cc"
    ],
    deps = [
        ":animal",
        ":dog",
        ":cat",
        ":registry_cc_proto",
        ":rpc_stub",
    ]
)