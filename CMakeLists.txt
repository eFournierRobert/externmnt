cmake_minimum_required(VERSION 4.0)

project(externmnt)

add_executable(externmnt)

include_directories(${CMAKE_SOURCE_DIR}/include)

target_sources(externmnt
    PRIVATE
        src/main.cpp
        src/drive/drive.cpp
        src/drive/cifs/cifsDrive.cpp
        src/utils/util.cpp
        src/drive/driveManager.cpp
)
