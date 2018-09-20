cmake_minimum_required(VERSION 3.4.1)
#库文件位置
set(libs_src_DIR ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI})
#本地源文件位置
set(code_src_DIR ${CMAKE_SOURCE_DIR}/src/main/cpp)

#本地头文件位置
include_directories(${code_src_DIR}/include/Native)
#FFmpeg3 头文件位置
include_directories(${code_src_DIR}/include/FFmpeg3)
#runtop 头文件位置
include_directories(${code_src_DIR}/include/rtlib)

#加载FFMPEG3
add_library(ffmpeg SHARED IMPORTED)
set_target_properties(ffmpeg PROPERTIES IMPORTED_LOCATION
                           ${libs_src_DIR}/libffmpeg.so)
#加载rtp2p库
add_library(rtapi STATIC IMPORTED)
set_target_properties(rtapi PROPERTIES IMPORTED_LOCATION
                           ${libs_src_DIR}/librtapi.a)

add_library( native  SHARED
             ${code_src_DIR}/src/NativeCaller.c
             ${code_src_DIR}/src/NativeCallBack.c
             ${code_src_DIR}/src/wheat_codec.c
             ${code_src_DIR}/src/packet_queue.c
             ${code_src_DIR}/src/opensl_io.c
             ${code_src_DIR}/src/h264_decoder.c
             ${code_src_DIR}/src/java_jni_RTMap.c)

find_library(log-lib    log )
find_library(OpenSLES-lib    OpenSLES )
find_library(android-lib    android )
target_link_libraries( native
                       ffmpeg
                       rtapi
                       ${log-lib}
                       ${OpenSLES-lib}
                       ${android-lib})