if(NOT MSVC)
    add_definitions(-std=c++11)
endif()

include_directories(
    ${PHOTON_INCLUDE_DIRS}
    SYSTEM
    ${GTEST_INCLUDE_DIRS}
)

set(TESTS_DIR ${CMAKE_BINARY_DIR}/bin/tests)
file(MAKE_DIRECTORY ${TESTS_DIR})

macro(add_unit_test test file)
    add_executable(${test} ${file})
    target_link_libraries(${test}
        ${ARGN}
        gtest_main
        gtest
        photon-impl
        photon-gc
        photon
    )

    set_target_properties(${test}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${TESTS_DIR}
        FOLDER "tests"
    )
    add_test(${test} ${TESTS_DIR}/${test})
endmacro()

add_unit_test(ber_tests Ber.cpp)
add_unit_test(exchangepacket_tests ExchangePacket.cpp)
add_unit_test(addresspacket_tests AddressPacket.cpp)
add_unit_test(router_tests Router.cpp)
add_unit_test(exchange Exchange.cpp)
