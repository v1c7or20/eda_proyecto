cmake_minimum_required(VERSION 3.19)
project(EDA_proyecto)
set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        )
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(
  googletest)
FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
enable_testing()

add_executable(
  EDA_proyecto
  main.cpp
  Classes/TravelPoint.cpp
  Classes/Travel.cpp
  Classes/Neighborhood.cpp
  Parser/NeighborhoodParser.cpp
  Parser/TravelParser.cpp
  )

target_link_libraries(
  EDA_proyecto PRIVATE nlohmann_json::nlohmann_json
  gtest_main
)
include(GoogleTest)
gtest_discover_tests(EDA_proyecto DISCOVERY_TIMEOUT 200)
