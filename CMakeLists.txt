cmake_minimum_required(VERSION 3.5)

project(EpiChess2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

file(GLOB src
     "*.hpp"
     "*.cpp"
)

set(PROJECT_SOURCES
		Application.cpp
		Chessboard.cpp
		Application.hpp
		Chessboard.hpp
		Game.hpp
		Rect.hpp
		APiece.cpp
		Bishop.cpp
		King.cpp
		Knight.cpp
		Pawn.cpp
		Queen.cpp
		Tower.cpp
		APiece.hpp
		Bishop.hpp
		IPiece.hpp
		King.hpp
		Knight.hpp
		Pawn.hpp
		Queen.hpp
		Tower.hpp
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(EpiChess2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET EpiChess2 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(EpiChess2 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(EpiChess2
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(EpiChess2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(EpiChess2 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(EpiChess2)
endif()
