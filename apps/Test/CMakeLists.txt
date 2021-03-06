cmake_minimum_required(VERSION 2.8)

include_directories(.)

add_subdirectory(ViperFreaky)
add_subdirectory(OlivePlastic)
add_subdirectory(HungryStreet)
add_subdirectory(RichLaser)
add_subdirectory(SubtleCreek)

if(OPENGL_WINDOW_SYSTEM STREQUAL "FreeGLUT")
    set(LIBS
        ${OPENGL_LIBRARIES} 
        ${GLEW_LIB} 
        ${GL_WINDOW}
    )

    add_executable(Test-1 
        main.cpp 
        v1/v1.cpp 
        Shaders.cpp 
        Tools.cpp
    )
    if(EMSCRIPTEN)
        target_link_libraries(Test-1 lodepng)
    else()
        target_link_libraries(Test-1 lodepng ${LIBS})
    endif()
    # if(MINGW OR MSYS)
    #     add_dependencies(Test-1 ext_freeglut ext_GLFW ext_GLEW)
    # elseif(EMSCRIPTEN)
    # elseif(ANDROID)
    # elseif(APPLE)
    #     add_dependencies(Test-1 ext_GLFW ext_GLEW)
    # else()
    #     add_dependencies(Test-1 ext_freeglut ext_GLFW ext_GLEW)
    # endif()
        

    add_executable(Test-1-8 
        main.cpp 
        button/button.cpp 
        Shaders.cpp 
        Tools.cpp
    )
    target_link_libraries(Test-1-8 lodepng ${LIBS})

    add_executable(Test-2 
        main.cpp 
        Shaders.cpp 
        Tools.cpp
        v2/v2.cpp 
        v2/Attribute.cpp
        v2/Uniform.cpp
        v2/Program.cpp
    )
    target_link_libraries(Test-2 lodepng ${LIBS})

    add_executable(Test-4
        test-4.cpp
    )
    if(EMSCRIPTEN)
        target_link_libraries(Test-4 lodepng)
    else()
        target_link_libraries(Test-4 ${LIBS})
    endif()
    
    if(EMSCRIPTEN)
        add_executable(Test-5 test-5.cpp)
        target_link_libraries(Test-5 lodepng)
    endif()
    
    add_subdirectory(test-6)
endif()
