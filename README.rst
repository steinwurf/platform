platform
--------
platform is a C++ library for detecting compiler and platform properties.
Currently, it can detect the following properties:

- Compiler: g++, clang, and MSVC
- Operating system: Linux, Mac OSX, Windows, iOS, and Android
- Target architecture: x86, x86_64, ARM, and MIPS

.. image:: https://travis-ci.org/steinwurf/platform.svg?branch=master
    :target: https://travis-ci.org/steinwurf/platform

Use as Dependency in CMake
--------------------------

To depend on this project when using the CMake build system, add the following
in your CMake build script::

   add_subdirectory("/path/to/platform" platform)
   target_link_libraries(<my_target> steinwurf::platform)

Where ``<my_target>`` is replaced by your target.

License
-------
The project license is based on the BSD License. Please refer to the LICENSE.rst
file for more details.

