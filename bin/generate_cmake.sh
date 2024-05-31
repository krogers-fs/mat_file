#!/bin/bash

prg=$0
if [ ! -e "$prg" ]; then
  case $prg in
    (*/*) exit 1;;
    (*) prg=$(command -v -- "$prg") || exit;;
  esac
fi
dir=$(
  cd -P -- "$(dirname -- "$prg")" && pwd -P
) || exit
prg=$dir || exit 

# printf '%s\n' "$prg"

source=$prg"/../test"
build=$prg"/../build"

cmake -D CMAKE_BUILD_TYPE=Debug CMAKE_INSTALL_PREFIX=/usr/local -S $source -B $build