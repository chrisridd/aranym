#!/bin/bash
#
# Easy ARAnyM compilation under Cygwin
# (c) october 2003 Xavier Joubert for the ARAnyM team
#
#
# This script allows to easily build ARAnyM under Cygwin. The problem
# is that SDL needs to be slightly modified under Cygwin to allow to use
# it for real Cygwin applications (instead of MinGW32 applications).
# This modification is a dirty hack (see comments below)...
#
# To use this, simply create a directory where everything will be
# contained. This script is designed to avoid polluting your Cygwin
# install. The hacked SDL build will be contained in this directory, so
# you can even keep a "normal" SDL install on your system an continue
# working on other normal SDL applications.
#
# Copy this script in this directory (please check it has the executable
# flag set - if not, "chmod +x build-cygwin.sh").
#
# Untar SDL sources in this directory. I used SDL 1.2.7, but it should
# work with newer releases as they will be available (CVS won't work !).
# Please edit the SDL_SOURCES variable below to reflect the path where
# SDL sources lie.
#
# Untar ARAnyM sources at the same place. You can also pull sources from
# CVS (see http://aranym.sourceforge.net/development.html for details on
# how to do this). Please edit ARANYM_SOURCES variable below to reflect
# the path where ARAnyM sources lie.
#
# Now you can run "./build-cygwin.sh" to run the build ! You'll get your
# binary after a few minutes (depending on your system).
#
# Any parameter given to build-cygwin.sh will be transmitted to ARAnyM's
# configure script, so you can run "./build-cygwin.sh --enable-fullmmu"
# if you want to build with MMU support. Run
# "aranym-build/src/Unix/configure --help" after first build for a list
# of configure options for ARAnyM.
#
# If you happen to modify some sources, you can run "./build-cygwin.sh"
# again which will simply run "make" in the correct directory
# (aranym-build/src/Unix). Please note that configure options will be
# ignored in this case !
#
# If you want to re-configure, simply
# "rm aranym-build/src/Unix/Makefile" and run build-cygwin.sh again.
#
# If you modify aranym-build/src/Unix/configure.ac, build-cygwin.sh
# will automaticaly re-configure sources. Don't forget to give any
# configure options you need !
#
# If you want a clean rebuild from original sources, simply "rm -r
# aranym-build/" and run build-cygwin.sh again.
#
# Cygwin packages that should be installed :
# - gcc
# - gcc-g++
# - make
# - xorg-x11-bin (for the makedepend binary)
# - cvs, autoconf and automake (if you want to use CVS version, or if
#   you modify configure.ac)
#
# Questions about building ARAnyM should go to the developper mailing
# list. See http://aranym.sourceforge.net/development.html for
# informations on how to subscribe to this list.
#

#----------------------------------------------
# EDIT this to suit your configuration !
SDL_SOURCES=${PWD}/SDL-1.2.8
ARANYM_SOURCES=${PWD}/aranym
#----------------------------------------------

# A small function used to report errors
function check_return() {
  if [ $? -ne 0 ] ; then
    if [ -z "$*" ] ; then
      echo "$0: ERROR" 1>&2
    else
      echo "$0: ERROR: $*" 1>&2
    fi
    exit 1
  fi
}

if [ "x"`uname -o` != "xCygwin" ] ; then
  echo "$0: ERROR: This script is intended for Cygwin only."
  exit 1
fi

# Go to the build directory...
# This is done for the path below to be correctly generated.
cd `dirname $0`

SDL_BUILD=${PWD}/SDL-build
SDL_PREFIX=${PWD}/SDL-prefix

ARANYM_BUILD=${PWD}/aranym-build

LINE="-------------------------------------------------------------------------------"
LINE2="==============================================================================="

# Firstly, SDL
if [ ! -x ${SDL_PREFIX}/bin/sdl-config -o \
     ! -f ${SDL_PREFIX}/bin/sdl-config.bak ] ; then
  # If not compiled and hacked, restart from the beginning...
  # This could be optimized a lot, but compiling SDL is not the
  # main purpose here.
  echo ${LINE2}
  echo "Building SDL... "
  if [ -d ${SDL_BUILD} ] ; then
    rm -r ${SDL_BUILD}
    check_return "Unable to remove ${SDL_BUILD}."
  fi
  if [ -d ${SDL_PREFIX} ] ; then
    rm -r ${SDL_PREFIX}
    check_return "Unable to remove ${SDL_PREFIX}."
  fi
  mkdir -p ${SDL_BUILD}
  check_return "Unable to create ${SDL_BUILD}."
  mkdir -p ${SDL_PREFIX}
  check_return "Unable to create ${SDL_PREFIX}."

  cd ${SDL_BUILD}
  ${SDL_SOURCES}/configure --prefix=${SDL_PREFIX} && \
  make && \
  make install
  check_return "Unable to compile SDL from ${SDL_SOURCES}."

  # To save disk space
  cd ${SDL_PREFIX}
  rm -r ${SDL_BUILD}
  check_return "Unable to remove ${SDL_BUILD}."

  echo "done."

  echo ${LINE}
  echo -n "Modifying sdl-config script to allow building ARAnyM... "
  cd ${SDL_PREFIX}/bin
  check_return "Unable to change directory to ${SDL_PREFIX}/bin."

  # Here is the hack. We remove some flags which make GCC compile for
  # MinGW32 instead of Cygwin. We remove SDLmain from the link since
  # it's a MinGW32 object... So SDL can not parse args given to ARAnyM
  # under Cygwin.
  sed -f- -i.bak sdl-config << EOF
s/-Dmain=SDL_main//
s=-I/usr/include/mingw==
s/-DWIN32//
s/-Uunix//
s/-mno-cygwin//
s/-lmingw32//
s/-lSDLmain//
s/-mwindows//
EOF
  check_return "Unable to edit ${SDL_PREFIX}/bin/sdl-config."

  # Just in case. GNU sed keeps exec flag, but who knows...
  chmod u+x sdl-config
  check_return "Unable to make ${SDL_PREFIX}/bin/sdl-config executable."

  echo "done."
fi

echo ${LINE2}
if [ ! -d ${ARANYM_BUILD} ] ; then
  echo -n "Copying sources... "
  cp -r -p ${ARANYM_SOURCES} ${ARANYM_BUILD}
  check_return "Unable to copy ${ARANYM_SOURCES} to ${ARANYM_BUILD}."
  echo "done."
  echo ${LINE}
fi

cd ${ARANYM_BUILD}/src/Unix
check_return "${ARANYM_BUILD} doesn't contains ARAnyM sources."

if [ configure.ac -nt configure ] ; then
  # This is needed for CVS sources only
  # or if you modified configure.ac

  echo -n "Running aclocal... "
  aclocal -I ${SDL_PREFIX}/share/aclocal
  check_return "aclocal failed. Check your automake installation."
  echo "done."
  echo ${LINE}

  echo -n "Running autoheader... "
  autoheader
  check_return "autoheader failed. Check your autoconf installation."
  echo "done."
  echo ${LINE}

  echo -n "Running autoconf... "
  autoconf
  check_return "autoconf failed."
  echo "done."
  echo ${LINE}
fi

if [ configure.ac -nt Makefile ] ; then
  echo "Running \"./configure $@\"..."
  PATH=${SDL_PREFIX}/bin:${PATH} \
  ./configure "$@"
  check_return "Unable to configure ARAnyM."
  echo "done."
  echo ${LINE}

  echo "Running make depend..."
  make depend
  check_return "Unable to create dependencies. Check your XFree86-bin installation."
  echo "done."
  echo ${LINE}
else
  if [ ! -z $@ ] ; then
    echo "$0: WARNING: configure options ignored. if you want to re-configure, please run :" 1>&2
    echo "rm ${ARANYM_BUILD}/src/Unix/Makefile && $0 $@" 1>&2
    echo ${LINE}
  fi
fi

echo "Running make... "
make
check_return "Compilation failed."
echo "done."

echo ${LINE2}

echo "Congratulations ! Your home made ARAnyM binary is available in \"${ARANYM_BUILD}/src/Unix/\"."
