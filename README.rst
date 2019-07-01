music-adapters
==============

A collection of adapters for the MUSIC library (https://github.com/INCF/MUSIC).

Run 'doxygen' to create the documentation including example configurations.

Installation
============
.. code:: bash

  sudo apt install pkg-config libjsoncpp-dev libzmq3-dev libblas-dev libgsl-dev
  cmake -DCMAKE_INSTALL_PREFIX:PATH=<PREFIX> -DMUSIC_LIBRARY=<path/to/libmusic.so> -DMUSIC_INCLUDE_DIR=<path/to/music/include> <music-adapters_SOURCE>
  make
  make install

If MUSIC is not found you can provide the MUSIC root path by specifying ``-DMUSIC_ROOT_DIR=<MUSIC_INSTALL_DIR>``.
