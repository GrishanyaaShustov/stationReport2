cmake_minimum_required(VERSION 3.29)
project(stationReport2)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/headers)

add_executable(stationReport2 main.cpp
        buildMain.cpp
        buildMain.h
        src/stationReport.cpp
        headers/stationReport.h
        src/createReportsArray.cpp
        headers/createReportsArray.h
        src/binTreeFuncs.cpp
        headers/binTreeFuncs.h
        headers/printSortedDataFuncs.h
        src/printSortedDataFuncs.cpp
        headers/binTreeSearchFuncs.h
        src/binTreeSearchFuncs.cpp)
