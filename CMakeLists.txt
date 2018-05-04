cmake_minimum_required(VERSION 3.10)
project(project_infa)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(project_infa
        Test/Test.cpp
        allLibraries.h
        AnaliticGeometry.cpp
        AnaliticGeometry.h
        Components.cpp
        Components.h
        ConverterPairToVector2.h
        Dot.cpp
        Dot.h
        Extractors.cpp
        Extractors.h
        Game.cpp
        Game.h
        GameObject.cpp
        GameObject.h
        IsIn.cpp
        IsIn.h
        main.cpp
        Makefile
        Physics.cpp
        Physics.h
        project_infa.xml
        README.md
        Rendering.cpp
        resources.cpp
        resources.h
        Sprite.h
        StupidDrawMe.cpp
        StupidDrawMe.h
        StupidRendering.cpp
        Triangle.h
        voiceRecognition.py
        Window.h
        WorkWithPairs.cpp
        WorkWithPairs.h drawAll.cpp drawAll.h)
