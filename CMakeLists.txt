cmake_minimum_required(VERSION 3.2)
project(LeetCode)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS
                -wd4251 -wd4244 -wd4334 -wd4005 -wd4820 -wd4710
                -wd4514 -wd4056 -wd4996 -wd4099)

macro(SUBDIRLIST result curdir)
  file(GLOB children RELATIVE ${curdir} ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      list(APPEND dirlist ${child})
    endif()
  endforeach()
  set(${result} ${dirlist})
ENDMACRO()

add_subdirectory(JianZhiOffer)