add_library(game_objects "")
include_directories(includes)
# include_directories(includes)
# file(GLOB _SOURCES sources/*.cpp)
target_sources(game_objects
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/sources/Game.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sources/Snake.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sources/Textbox.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sources/Window.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sources/World.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/includes/Game.hpp
    ${CMAKE_CURRENT_LIST_DIR}/includes/Snake.hpp
    ${CMAKE_CURRENT_LIST_DIR}/includes/World.hpp
    ${CMAKE_CURRENT_LIST_DIR}/includes/Window.hpp
    ${CMAKE_CURRENT_LIST_DIR}/includes/World.hpp
)
target_link_libraries(game_objects PRIVATE sfml-graphics)
target_include_directories(game_objects
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )
# add_library(conversion "")

# target_sources(conversion
#   PRIVATE
#     ${CMAKE_CURRENT_LIST_DIR}/conversion.cpp
#   PUBLIC
#     ${CMAKE_CURRENT_LIST_DIR}/conversion.hpp
#   )

# target_include_directories(conversion
#   PUBLIC
#     ${CMAKE_CURRENT_LIST_DIR}
#   )