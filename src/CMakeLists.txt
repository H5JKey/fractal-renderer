add_executable(fractal_renderer
    main.cpp
    renderer.cpp
    animation.cpp
)

target_link_libraries(fractal_renderer
    sfml-graphics
    sfml-window
    sfml-system
)


add_custom_command(TARGET fractal_renderer PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/shader.glsl
        $<TARGET_FILE_DIR:fractal_renderer>/
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/shader.glsl 
    COMMENT "Copying shader.glsl"
)

if(WIN32)
  if (BUILD_SHARED_LIBS)
    add_custom_command(TARGET fractal_renderer POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
          $<TARGET_FILE:ImGui-SFML::ImGui-SFML>
          $<TARGET_FILE:sfml-graphics>
          $<TARGET_FILE:sfml-window>
          $<TARGET_FILE:sfml-system>
          $<TARGET_FILE_DIR:fractal_renderer>)
  endif()
endif()