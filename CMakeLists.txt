cmake_minimum_required(VERSION 3.22)


option(BUILD_TESTS "Build tests" OFF)
option(PACK "pack" OFF)
project(prototype)

file(GLOB SOURCES "ConceptualExample01.hpp" , "ConceptualExample02.hpp" , "Program.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

if(PACK)
  install(TARGETS prototype
    RUNTIME DESTINATION bin
  )
  include(CPack.cmake)
endif()

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third-party/gtest)
  file(GLOB TEST_SOURCES "ConceptualExample01.hpp" , "ConceptualExample02.hpp" , "Test.cpp")
  add_executable(check ${TEST_SOURCES})
  target_link_libraries(check gtest_main)
  add_test(NAME check COMMAND check)
endif()
