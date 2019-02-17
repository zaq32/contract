# Prevent GoogleTest from overriding our compiler/linker options when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(googletest_url https://github.com/google/googletest.git)
set(googletet_version master)

# Download and unpack googletest at configure time
if (CMAKE_VERSION VERSION_LESS 3.11)
    # the old way
    configure_file(${CMAKE_CURRENT_LIST_DIR}/gtest.in ${CMAKE_CURRENT_BINARY_DIR}/googletest-download/CMakeLists.txt)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download
        )

    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download 
        )

    add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src ${CMAKE_CURRENT_BINARY_DIR}/googletest-build)
else()
    # the new way
    include(FetchContent)

    FetchContent_Declare(
        googletest
        GIT_REPOSITORY ${googletest_url}
        GIT_TAG        ${googletet_version}
    )

    FetchContent_GetProperties(googletest)
    if(NOT googletest_POPULATED)
        FetchContent_Populate(googletest)
        add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
    endif()

endif()

set_property(TARGET gtest PROPERTY FOLDER "extern/googletest")
set_property(TARGET gmock PROPERTY FOLDER "extern/googletest")
set_property(TARGET gtest_main PROPERTY FOLDER "extern/googletest")
set_property(TARGET gmock_main PROPERTY FOLDER "extern/googletest")
