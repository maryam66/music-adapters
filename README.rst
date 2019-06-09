music-adapters
==============

A collection of adapters for the MUSIC library (https://github.com/INCF/MUSIC).

Run 'doxygen' to create the documentation including example configurations.

Installation
============
.. code:: bash

  cmake -DCMAKE_INSTALL_PREFIX:PATH=<PREFIX> <music-adapters_SOURCE>
  make
  make install

If MUSIC is not found you can provide the MUSIC root path by specifying ``-DMUSIC_ROOT_DIR=<MUSIC_INSTALL_DIR>``.
