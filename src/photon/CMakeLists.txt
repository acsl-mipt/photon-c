
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


