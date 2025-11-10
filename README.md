Build Notes / Modifications

The following changes were made to ensure successful builds of ONNX Runtime
on both x64 and ARM64 systems within SPECworkstation:

1. Architecture Handling

The Build_SPEC.bat script now automatically detects host architecture (x64 or ARM64).

Output binaries are copied to:

bin/win_x64/ for Intel/AMD systems

bin/win_arm64/ for ARM-based systems

2. CMake Compatibility

For policy-related errors (e.g.,
“Compatibility with CMake <3.5 has been removed”),
ensure this line is present in affected CMakeLists.txt:

cmake_minimum_required(VERSION 3.5)
