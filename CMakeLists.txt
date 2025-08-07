cmake_minimum_required(VERSION 3.16)
project(ChartExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick WebEngineQuick WebChannel Qml)

qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME}
    main.cpp
    Bridge.h
    Bridge.cpp
)

qt_add_qml_module(${PROJECT_NAME}
    URI ChartExample
    VERSION 1.0
    QML_FILES Main.qml
    RESOURCES chart.html
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Core Qt6::Quick Qt6::WebEngineQuick Qt6::WebChannel Qt6::Qml
)

target_compile_definitions(${PROJECT_NAME} PUBLIC
    QT_DEBUG=1
)
