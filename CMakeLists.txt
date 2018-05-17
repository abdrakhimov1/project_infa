cmake_minimum_required(VERSION 3.10)
project(project_infa)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(project_infa
        Python/Test/Test.cpp
        allLibraries.h
        Physics/AnaliticGeometry.cpp
        Physics/AnaliticGeometry.h
        Resources/Components.cpp
        Resources/Components.h
        Logic/ConverterPairToVector2.h
        Resources/Dot.cpp
        Resources/Dot.h
        Logic/Extractors.cpp
        Logic/Extractors.h
        Resources/Game.cpp
        Resources/Game.h
        Resources/GameObject.cpp
        Resources/GameObject.h
        Logic/IsIn.cpp
        Logic/IsIn.h
        main.cpp
        Makefile
        Physics/Physics.cpp
        Physics/Physics.h
        project_infa.xml
        README.md
        Drawing/Rendering.cpp
        Resources/resources.cpp
        Resources/resources.h
        Drawing/Sprite.h
        Drawing/StupidDrawMe.cpp
        Drawing/StupidDrawMe.h
        Drawing/StupidRendering.cpp
        Resources/Triangle.h
        Python/voiceRecognition.py
        Drawing/Window.h
        Logic/WorkWithPairs.cpp
        Logic/WorkWithPairs.h Drawing/drawAll.cpp Drawing/drawAll.h Resources/simpleFactory.cpp Resources/simpleFactory.h Drawing/drawLines.cpp Drawing/drawLines.h)
