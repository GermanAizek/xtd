#!/usr/bin/env bash

if [ -z ${xtd_version+x} ]; then
  echo ""
  echo "---------------------------------------------------------------"
  echo ""
  echo "ERROR : Use ./install from root folder!"
  echo ""
  echo "---------------------------------------------------------------"
  echo ""
  exit 1
fi

echo "Install xtd libraries version $xtd_version, copyright Gammasoft, 2022"
echo ""

#_______________________________________________________________________________
#                                                   Detecting linux distribution
echo "Detecting operating system..."
OSTYPE=`uname -a`
if [[ "$OSTYPE" == *"Linux"* ]]; then
  OSTYPE=`lsb_release -si`;
fi

if [[ "$OSTYPE" == *"MSYS"* ]] || [[ "$OSTYPE" == *"MINGW64"* ]]; then
  echo "  Operating System is Windows"
elif [[ "$OSTYPE" == *"Darwin"* ]]; then
  echo "  Operating System is macOS"; else
  echo "  Operating System is linux"
fi

#_______________________________________________________________________________
#                                                      Check the number of cores
if [[ "$OSTYPE" == *"Darwin"* ]]; then
  build_cores=$(sysctl -n hw.ncpu); else
  build_cores=$(nproc)
fi
if [[ $build_cores -ne 1 ]]; then
  build_cores=$((build_cores - 1))
fi
echo  "Using up to ${build_cores} build cores"

#_______________________________________________________________________________
#                   Install needed packages and libraries for known distribution
echo "Installing needed packages and libraries..."
case "$OSTYPE" in
  *"Darwin"*) brew update; brew install cmake;;
  *"Debian"* | *"elementary"* | *"LinuxMint"* | *"Ubuntu"*) sudo apt update; sudo apt install build-essential codeblocks doxygen libasound2-dev libgsound-dev libgtk-3-dev cmake -y;;
  *"openSUSE"*) sudo zypper update; sudo zypper install -y -t pattern devel_basis; sudo zypper install -y alsa-devel doxygen gsound-devel gtk3-devel cmake;;
  *"CentOS"* | *"Fedora"* | *"RedHat"*) sudo yum update; sudo yum install alsa-lib-devel cmake gsound-devel gtk3-devel -y;;
esac

#_______________________________________________________________________________
#                                                       Get cmake_install_prefix
echo "Get cmake_install_prefix..."
mkdir build
pushd build
mkdir cmake_install_prefix
pushd cmake_install_prefix
cmake ../../scripts/install/cmake_install_prefix "$@"
popd
popd
cmake_install_prefix=`cat build/cmake_install_prefix/cmake_install_prefix.txt`
echo "cmake_install_prefix=\"$cmake_install_prefix\""

#_______________________________________________________________________________
#                                                    Check and install wxWidgets
echo "Checks wxWidgets..."
if [ -d "build" ]; then rm -rf "build"; fi
mkdir build
pushd build
mkdir test_wxwidgets
pushd test_wxwidgets
cmake ../../scripts/install/test_wxwidgets "$@"
popd
popd
if [ ! -f "build/test_wxwidgets/wxwidgets.lck" ]; then
  echo ""
  echo "---------------------------------------------------------------"
  echo ""
  echo "WARNING : wxWidgets is not already installed!"
  echo ""
  echo "If you continue wxWidgets will be downloaded, built and installed automatically."
  echo ""
  echo "---------------------------------------------------------------"
  echo ""
  read -p "Press ENTER to continue or CTRL-C to stop and install wxWidgets manually..."
  scripts/install/install_wxwidgets.sh "$@"
fi

#_______________________________________________________________________________
#                                                Generate, build and install xtd
echo "Installing xtd $xtd_version..."
mkdir build
pushd build
mkdir Release && mkdir Debug
pushd Release
cmake ../..  -DCMAKE_BUILD_TYPE=Release "$@"
cmake --build . -- -j$build_cores
sudo cmake --build . --target install
popd
pushd Debug
cmake ../.. -DCMAKE_BUILD_TYPE=Debug "$@"
cmake --build . -- -j$build_cores
sudo cmake --build . --target install
popd
popd

#_______________________________________________________________________________
#                     Create gui tools shortcut in system operating applications
if [[ "$OSTYPE" == *"MSYS"* ]] || [[ "$OSTYPE" == *"MINGW64"* ]]; then 
  xtd_program_path="$USERPROFILE/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/xtd"
  if [ ! -d "$xtd_program_path" ]; then mkdir -p "$xtd_program_path"; fi
  scripts/install/shortcut.sh "$USERPROFILE\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd\keycode.lnk" "$cmake_install_prefix\xtd\bin\keycode.exe"
  scripts/install/shortcut.sh "$USERPROFILE\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd\xtdc-gui.lnk" "$cmake_install_prefix\xtd\bin\xtdc-gui.exe"
  scripts/install/shortcut.sh "$USERPROFILE\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd\xguidgen-gui.lnk" "$cmake_install_prefix\xtd\bin\guidgen-gui.exe"
elif [[ "$OSTYPE" == *"Darwin"* ]]; then
  if [ -d "/Applications/keycode" ]; then rm "/Applications/keycode"; fi
  ln -s "$cmake_install_prefix/bin/keycode.app" "/Applications/keycode"
  if [ -d "/Applications/xtdc-gui" ]; then rm "/Applications/xtdc-gui"; fi
  ln -s "$cmake_install_prefix/bin/xtdc-gui.app" "/Applications/xtdc-gui"
  if [ -d "/Applications/guidgen-gui" ]; then rm "/Applications/guidgen-gui"; fi
  ln -s "$cmake_install_prefix/bin/guidgen-gui.app" "/Applications/guidgen-gui"
fi

#_______________________________________________________________________________
#                             Copy install manifest files to xtd share directory
sudo cp build/3rdparty/wxwidgets/build_cmake/Release/install_manifest.txt $cmake_install_prefix/share/xtd/wxwidgets_release_install_manifest.txt
sudo cp build/3rdparty/wxwidgets/build_cmake/Debug/install_manifest.txt $cmake_install_prefix/share/xtd/wxwidgets_debug_install_manifest.txt
sudo cp build/Release/install_manifest.txt $cmake_install_prefix/share/xtd/xtd_release_install_manifest.txt
sudo cp build/Debug/install_manifest.txt $cmake_install_prefix/share/xtd/xtd_debug_install_manifest.txt

#_______________________________________________________________________________
#                                                                 Launch xtd-gui
echo "Launching xtdc-gui..."
if [[ "$OSTYPE" == *"MSYS"* ]] || [[ "$OSTYPE" == *"MINGW64"* ]]; then
  start "$cmake_install_prefix\xtd\bin\xtdc-gui.exe"
elif [[ "$OSTYPE" == *"Darwin"* ]]; then
  open $cmake_install_prefix/bin/xtdc-gui.app; else
  $cmake_install_prefix/bin/xtdc-gui &>/dev/null &
fi
