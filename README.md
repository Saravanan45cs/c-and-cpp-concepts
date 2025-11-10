Build Notes / Modifications

The following changes were made to ensure successful builds of ONNX Runtime on both x64 and ARM64 systems within SPECworkstation:

Architecture Detection:
Updated Build_SPEC.bat to automatically detect the host architecture (x64 or ARM64) and trigger the appropriate build configuration.
Output binaries are now copied to:

bin/win_x64/ for Intel/AMD systems

bin/win_arm64/ for ARM-based systems

CMake Compatibility:
Handled newer CMake policy requirements.
If a policy version error appears (e.g.,
“Compatibility with CMake <3.5 has been removed”),
update the relevant submodule’s CMakeLists.txt to include:
cmake_minimum_required(VERSION 3.5)
