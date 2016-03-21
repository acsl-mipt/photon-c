
add_library(photon
    Reader.c
    Reader.h
    Result.c
    Result.h
    RingBuffer.c
    RingBuffer.h
    Writer.c
    Writer.h
    Decoder.c
    Decoder.h
    Encoder.c
    Encoder.h
    Endian.h
    Exchange.c
    Exchange.h
    Ber.c
    Ber.h
    Utils.c
    Utils.h
    photon_prologue.h
    photon_epilogue.h
    ${PHOTON_GENERATED_FILES}
)

add_library(photon-gc
    GcExchange.cpp
    GcExchange.hpp
)

target_link_libraries(photon-gc photon)

if(NOT MSVC)
    target_compile_options(photon PRIVATE -std=c99)
    target_compile_options(photon-gc PRIVATE -std=c++11)
endif()
