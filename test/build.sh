#!/bin/bash
# Build Script for engine
set echo on

mkdir -p ../bin

# Get a list of all the .c files.
cFilesnames=$(find . -type f -name "*.c")

# echo "Files:" $cFilenames

assembly="engine"
compilerflags="-g -shared -fdeclspec - fPIC"

includeFlags="-Isrc -I$VULKAN_SDK/include"
linkerFlags="-lvulkan -lxcb -lX11 -lX11-xcb -lxkbcommon -L$VULKAN_SDK/lib -L/usr/X11R6/lib"
defines="-D_DEBUG -DKEXPORT"

echo "Building $assembly..."
echo clang $cFilenames $compilerFlags -o ../bin/lib$assembly.so $defines $includeflags $linkerFlags
clang $cFilenames $compilerFlags -o ../bin/$assembly $defines $includeFlags $linkerFlags
