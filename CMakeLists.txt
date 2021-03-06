cmake_minimum_required(VERSION 3.19)
project(EDA_proyecto)
set(CMAKE_CXX_STANDARD 17)
include(FetchContent)


function(download_file url filename hash_type hash)

    if(NOT EXISTS ${filename})
        file(DOWNLOAD ${url} ${filename}
                TIMEOUT 120 # seconds
                EXPECTED_HASH ${hash_type}=${hash})
    endif()

endfunction(download_file)

# === example
download_file(
        https://s3.amazonaws.com/nyc-tlc/trip+data/green_tripdata_2015-01.csv
        ./../green_tripdata_2015-01.csv
        SHA256 70F272893AFDAC822853AAE07FFCBF8C0EA5364E0988BB4E50506C2244C1B988)


execute_process(COMMAND python3 parsing.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

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
  Classes/Spatial/Point.h
  Classes/Spatial/Rectangle.h
  Classes/Spatial/RNode.cpp
  Classes/Spatial/RTree.cpp
  Classes/Basic/TravelPoint.cpp
  Classes/Basic/Travel.cpp
  Classes/Basic/Neighborhood.cpp
  Classes/Parser/NeighborhoodParser.cpp
  Classes/Parser/TravelParser.cpp
  )

target_link_libraries(
  EDA_proyecto PRIVATE nlohmann_json::nlohmann_json
  gtest_main
)
include(GoogleTest)
gtest_discover_tests(EDA_proyecto DISCOVERY_TIMEOUT 200)
