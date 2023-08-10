# author:klug
# 我从未许诺你玫瑰花园
# start:230710
# last:230810

cmake_minimum_required(VERSION 3.5)

project(ichhabedirnieeinenrosengartenversprochen VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# pcl
find_package(PCL REQUIRED)
# opencv
find_package(OpenCV REQUIRED)
# eigen
find_package(Eigen3 REQUIRED)

# opencv
include_directories(${OpenCV_INCLUDE_DIRS})
#include_directories(/usr/local/include/opencv4)

# pcl
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# eigen
include_directories(${EIGEN3_INCLUDE_DIRS})

# VTK
find_package(VTK REQUIRED)
include_directories(/usr/include/vtk-7.1)

include_directories(~/ichhabedirnieeinenrosengartenversprochen)
include_directories(~/undb)

set(PROJECT_SOURCES
    main.cpp
    source.hpp

    # ein camera
    ~/ichhabedirnieeinenrosengartenversprochen/PhaseRefactoring/phase_img.hpp
    ~/ichhabedirnieeinenrosengartenversprochen/PhaseRefactoring/phase_img.cpp
    ~/ichhabedirnieeinenrosengartenversprochen/PhaseRefactoring/phase_cal.hpp
    ~/ichhabedirnieeinenrosengartenversprochen/PhaseRefactoring/phase_cal.cpp
    ~/ichhabedirnieeinenrosengartenversprochen/PhaseRefactoring/phase_construct.hpp
    ~/ichhabedirnieeinenrosengartenversprochen/PhaseRefactoring/phase_construct.cpp

    # zwei camera
    ~/ichhabedirnieeinenrosengartenversprochen/zweiPhaseRefactoring/zwei_phase_img.hpp
    ~/ichhabedirnieeinenrosengartenversprochen/zweiPhaseRefactoring/zwei_phase_img.cpp
    ~/ichhabedirnieeinenrosengartenversprochen/zweiPhaseRefactoring/zwei_phase_cal.hpp
    ~/ichhabedirnieeinenrosengartenversprochen/zweiPhaseRefactoring/zwei_phase_cal.cpp
    ~/ichhabedirnieeinenrosengartenversprochen/zweiPhaseRefactoring/zwei_phase_construct.hpp
    ~/ichhabedirnieeinenrosengartenversprochen/zweiPhaseRefactoring/zwei_phase_construct.cpp

    # common
    ~/ichhabedirnieeinenrosengartenversprochen/projectedImg/projectedImg.hpp
    ~/ichhabedirnieeinenrosengartenversprochen/projectedImg/projectedImg.cpp

    # undb
    ~/undb/cameraGene/cameraGene.cpp
    ~/undb/cameraGene/cameraGene.hpp
    ~/undb/meinCV/meinCamera.cpp
    ~/undb/meinCV/meinCamera.hpp
    ~/undb/math/geometry.cpp
    ~/undb/math/geometry.hpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ichhabedirnieeinenrosengartenversprochen
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ichhabedirnieeinenrosengartenversprochen APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ichhabedirnieeinenrosengartenversprochen SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ichhabedirnieeinenrosengartenversprochen
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ichhabedirnieeinenrosengartenversprochen PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    pthread

    ${OpenCV_LIBS}

    ${PCL_LIBRARIES}

    ${VTK_LIBRARIES}
    )

set_target_properties(ichhabedirnieeinenrosengartenversprochen PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ichhabedirnieeinenrosengartenversprochen)
endif()
