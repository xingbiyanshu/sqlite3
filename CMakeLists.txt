cmake_minimum_required(VERSION 3.16)

project(sqlite3 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sqlite3
    main.cpp
    sqlite3.h
    sqlite3.c
    member.h member.cpp
    department.h department.cpp
    memberdao.h memberdao.cpp
    memberbrief.h memberbrief.cpp

    node.h node.cpp
    domain.h domain.cpp
    bloc.h bloc.cpp
    group.h group.cpp
    repository.h repository.cpp
)

include(GNUInstallDirs)
install(TARGETS sqlite3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
