add_executable(
    "${EXECUTABLE_NAME}"
    main.cpp
    Node.h
    Button.h
    Graph.h
    )

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries("${EXECUTABLE_NAME}" sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
