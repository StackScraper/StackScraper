cmake_minimum_required(VERSION 3.30)

project(syntx VERSION 1.0.0 DESCRIPTION "example lib")

set(CMAKE_CXX_VISIBLITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINE_HIDDEN YES)

set(syntx_src  ./SyntX/SyntX.cpp)
set(syntx_headers ./SyntX/SyntX.hpp ${CMAKE_CURRENT_BINARY_DIR}/syntx_export.h)

include(GenerateExportHeader)

include(CMakePackageConfigHelpers)


configure_package_config_file (
  ${CMAKE_CURRENT_SOURCE_DIR}/syntxConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/syntxConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/syntx
)

write_basic_package_version_file(
${CMAKE_CURRENT_BINARY_DIR}/syntxConfigVersion.cmake
VERSION ${PROJECT_VERSION}
COMPATIBILITY SameMajorVersion
)
add_library(syntx ${syntx_src} ${syntx_headers})
add_library(syntx::syntx ALIAS syntx)

install(TARGETS syntx
EXPORT syntxTargets
LIBRARY
        COMPONENT syntx-lib
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
PUBLIC_HEADER
    COMPONENT syntx-dev
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/syntx
)
export(EXPORT syntxTargets FILE ${CMAKE_CURRENT_BINARY_DIR}/syntxTargets.cmake)
install(EXPORT syntxTargets
NAMESPACE syntx::
COMPONENT syntx-dev
DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/syntx
)
install(
FILES
    ${CMAKE_CURRENT_BINARY_DIR}/syntxConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/syntxConfigVersion.cmake
COMPONENT syntx-dev
DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/syntx
)


set_target_properties(syntx PROPERTIES
PUBLIC_HEADER "${numbers_headers}"
)
generate_export_header(syntx)
target_include_directories(syntx PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include/syntx>
)



