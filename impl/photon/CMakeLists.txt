if(NOT MSVC)
    add_definitions(-std=c99)
endif()

add_library(photon-impl
    #Identification.c
    Router.c
)

target_link_libraries(photon-impl photon)
