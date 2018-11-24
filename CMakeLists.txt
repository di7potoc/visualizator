cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(QtCommon)
project(Visualizator VERSION 1.0)

fix_project_version()

set(SOURCE_FILES
	src/geffect.cpp
	src/gobject.cpp
	src/gcircleitem.cpp
	src/gsquareitem.cpp
	src/gtriangleitem.cpp
    src/main.cpp
    src/mainwindow.cpp
	src/model.cpp
	src/outliner.cpp
	src/renderarea.cpp
	src/visualizer.cpp
)

add_project_meta(META_FILES_TO_INCLUDE)

find_package(Qt5Widgets REQUIRED)

add_executable(${PROJECT_NAME} ${OS_BUNDLE}
    ${SOURCE_FILES} ${META_FILES_TO_INCLUDE} ${RESOURCE_FILES}
)
#
qt5_use_modules(${PROJECT_NAME} Widgets)
