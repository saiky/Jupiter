cmake_minimum_required(VERSION 2.8.11)

set(EXT_BOX2D ext_Box2D)

unset(PATCH_FILE)
unset(ADDITIONAL_FLAGS)

if(MINGW OR MSYS)
    set(PATCH_FILE          ${CMAKE_CURRENT_LIST_DIR}/linux.patch)
    set(ADDITIONAL_FLAGS    -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} 
                            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                            -DCMAKE_GENERATOR=${CMAKE_GENERATOR})

elseif(EMSCRIPTEN)
    set(PATCH_FILE          ${CMAKE_CURRENT_LIST_DIR}/linux.patch)
    set(ADDITIONAL_FLAGS    -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
                            -DCMAKE_GENERATOR=${CMAKE_GENERATOR}
                            -DCMAKE_C_FLAGS="-Wno-warn-absolute-paths"
                            -DCMAKE_CXX_FLAGS="-Wno-warn-absolute-paths")

elseif(ANDROID)
    set(PATCH_FILE          ${CMAKE_CURRENT_LIST_DIR}/box2d.android.patch)
    set(ADDITIONAL_FLAGS    -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
                            -DCMAKE_GENERATOR=${CMAKE_GENERATOR}
    )

else()
    # set(PATCH_FILE          ${CMAKE_CURRENT_LIST_DIR}/linux.patch)

endif()

ExternalProject_Add(
    ${EXT_BOX2D}
    # URL                     https://github.com/erincatto/Box2D/archive/v2.3.1.zip
    URL                     https://github.com/Ingener74/Box2D/archive/master.zip
    # PATCH_COMMAND           patch -p1 < ${PATCH_FILE}
    CONFIGURE_COMMAND       cmake ${CMAKE_BINARY_DIR}/3rdparty/Box2D/${EXT_BOX2D}-prefix/src/${EXT_BOX2D}/Box2D
                            ${ADDITIONAL_FLAGS}
                            -DBOX2D_INSTALL=ON
                            -DBOX2D_BUILD_EXAMPLES=OFF
                            -DBOX2D_BUILD_SHARED=ON
                            -DBOX2D_BUILD_STATIC=ON
                            -DCMAKE_INSTALL_PREFIX=${3RDPARTY_INSTALL}
)
