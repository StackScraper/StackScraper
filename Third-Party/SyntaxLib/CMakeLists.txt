cmake_minimum_required(VERSION 3.30)

project(logger VERSION 1.0.0 DESCRIPTION "example lib")

set(CMAKE_CXX_VISIBLITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINE_HIDDEN YES)

set(logger_src  ./Logger/Logger.cpp)
set(logger_headers ./Logger/Logger.hpp ${CMAKE_CURRENT_BINARY_DIR}/logger_export.h)

include(GenerateExportHeader)

include(CMakePackageConfigHelpers)


configure_package_config_file (
  ${CMAKE_CURRENT_SOURCE_DIR}/loggerConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/loggerConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/logger
)

write_basic_package_version_file(
${CMAKE_CURRENT_BINARY_DIR}/loggerConfigVersion.cmake
VERSION ${PROJECT_VERSION}
COMPATIBILITY SameMajorVersion
)
add_library(logger ${logger_src} ${logger_headers})
add_library(logger::logger ALIAS logger)

install(TARGETS logger
EXPORT loggerTargets
LIBRARY
        COMPONENT logger-lib
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
PUBLIC_HEADER
    COMPONENT logger-dev
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/logger
)
export(EXPORT loggerTargets FILE ${CMAKE_CURRENT_BINARY_DIR}/loggerTargets.cmake)
install(EXPORT loggerTargets
NAMESPACE logger::
COMPONENT logger-dev
DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/logger
)
install(
FILES
    ${CMAKE_CURRENT_BINARY_DIR}/loggerConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/loggerConfigVersion.cmake
COMPONENT logger-dev
DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/logger
)


set_target_properties(logger PROPERTIES
PUBLIC_HEADER "${numbers_headers}"
)
generate_export_header(logger)
target_include_directories(logger PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include/logger>
)



