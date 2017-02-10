cmake_minimum_required(VERSION 3.6)
project(omega1gpio)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER /home/travis/Projects/openwrt_compiler/OpenWrt-Toolchain-ar71xx-generic_gcc-4.8-linaro_uClibc-0.9.33.2.Linux-x86_64/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mips-openwrt-linux-uclibc-gcc)
set(CMAKE_CXX_COMPILER /home/travis/Projects/openwrt_compiler/OpenWrt-Toolchain-ar71xx-generic_gcc-4.8-linaro_uClibc-0.9.33.2.Linux-x86_64/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mips-openwrt-linux-uclibc-g++)

link_directories(/home/travis/Projects/openwrt_compiler/OpenWrt-Toolchain-ar71xx-generic_gcc-4.8-linaro_uClibc-0.9.33.2.Linux-x86_64/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/mips-openwrt-linux-uclibc/include/c++/4.8.3)
link_libraries(/home/travis/Projects/openwrt_compiler/OpenWrt-Toolchain-ar71xx-generic_gcc-4.8-linaro_uClibc-0.9.33.2.Linux-x86_64/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/ )

include_directories(src/)

set(SOURCE_FILES main.cpp main.h src/Pin/Pin.cpp src/Pin/Pin.h src/Registry/Registry.cpp src/Registry/Registry.h)
add_executable(omega1gpio ${SOURCE_FILES})
