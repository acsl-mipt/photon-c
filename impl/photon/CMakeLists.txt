if(NOT MSVC)
    add_definitions(-std=c99)
endif()

add_library(photon-impl
    Identification.c
    Identification.h
    Router.c
    Router.h
    Telemetry.c
    Telemetry.h
    Scripting.c
    Scripting.h
)

target_link_libraries(photon-impl photon)
