file(GLOB GAME_OBJECTS_SRC "gameObjects/*.cpp")

idf_component_register(
    SRCS "game_loop.cpp" "game_utils.cpp" "main.cpp" "global_vars.cpp" "display.cpp" "controller.cpp" "speaker.cpp" ${GAME_OBJECTS_SRC}
    INCLUDE_DIRS ""
)
