cmake_minimum_required(VERSION 3.19)
project(EDA_proyecto)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        )

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


add_executable(EDA_proyecto main.cpp Classes/Travel.cpp Classes/Neighborhood.cpp
                            Parser/NeighborhoodParser.cpp Parser/TravelParser.cpp Classes/TravelPoint.cpp)

target_link_libraries(EDA_proyecto PRIVATE nlohmann_json::nlohmann_json)
