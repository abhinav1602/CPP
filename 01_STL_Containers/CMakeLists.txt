cmake_minimum_required(VERSION 3.10)
project(STL_Containers LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags
if(MSVC)
    add_compile_options(/W4 /EHsc)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Set optimization flags
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 01_SequenceContainers
add_executable(VectorExample 01_SequenceContainers/VectorExample.cpp)
add_executable(DequeExample 01_SequenceContainers/DequeExample.cpp)
add_executable(ListExample 01_SequenceContainers/ListExample.cpp)
add_executable(ForwardListExample 01_SequenceContainers/ForwardListExample.cpp)
add_executable(ArrayExample 01_SequenceContainers/ArrayExample.cpp)

# 02_AssociativeContainers
add_executable(SetExample 02_AssociativeContainers/SetExample.cpp)
add_executable(MapExample 02_AssociativeContainers/MapExample.cpp)
add_executable(MultisetExample 02_AssociativeContainers/MultisetExample.cpp)
add_executable(MultimapExample 02_AssociativeContainers/MultimapExample.cpp)

# 03_UnorderedContainers
add_executable(UnorderedSetExample 03_UnorderedContainers/UnorderedSetExample.cpp)
add_executable(UnorderedMapExample 03_UnorderedContainers/UnorderedMapExample.cpp)
add_executable(UnorderedMultisetExample 03_UnorderedContainers/UnorderedMultisetExample.cpp)
add_executable(UnorderedMultimapExample 03_UnorderedContainers/UnorderedMultimapExample.cpp)

# 04_ContainerAdaptors
add_executable(StackExample 04_ContainerAdaptors/StackExample.cpp)
add_executable(QueueExample 04_ContainerAdaptors/QueueExample.cpp)
add_executable(PriorityQueueExample 04_ContainerAdaptors/PriorityQueueExample.cpp)

# Optional: Create a custom target to build all examples
add_custom_target(build_all_examples
    DEPENDS
        VectorExample DequeExample ListExample ForwardListExample ArrayExample
        SetExample MapExample MultisetExample MultimapExample
        UnorderedSetExample UnorderedMapExample UnorderedMultisetExample UnorderedMultimapExample
        StackExample QueueExample PriorityQueueExample
)

# Print configuration summary
message(STATUS "===========================================")
message(STATUS "STL Containers Module - Build Configuration")
message(STATUS "===========================================")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "===========================================")

