platform
--------

|Linux make-specs| |Windows make-specs| |MacOS make-specs| |Linux CMake| |Windows CMake| |MacOS CMake| |Valgrind| |No Assertions| |Clang Format| |Cppcheck|

.. |Linux make-specs| image:: https://github.com/steinwurf/platform/actions/workflows/linux_mkspecs.yml/badge.svg
   :target: https://github.com/steinwurf/platform/actions/workflows/linux_mkspecs.yml
   
.. |Windows make-specs| image:: https://github.com/steinwurf/platform/actions/workflows/windows_mkspecs.yml/badge.svg
   :target: https://github.com/steinwurf/platform/actions/workflows/windows_mkspecs.yml

.. |MacOS make-specs| image:: https://github.com/steinwurf/platform/actions/workflows/macos_mkspecs.yml/badge.svg
   :target: https://github.com/steinwurf/platform/actions/workflows/macos_mkspecs.yml
   
.. |Linux CMake| image:: https://github.com/steinwurf/platform/actions/workflows/linux_cmake.yml/badge.svg
   :target: https://github.com/steinwurf/platform/actions/workflows/linux_cmake.yml

.. |Windows CMake| image:: https://github.com/steinwurf/platform/actions/workflows/windows_cmake.yml/badge.svg
   :target: https://github.com/steinwurf/platform/actions/workflows/windows_cmake.yml
   
.. |MacOS CMake| image:: https://github.com/steinwurf/platform/actions/workflows/macos_cmake.yml/badge.svg
   :target: https://github.com/steinwurf/platform/actions/workflows/macos_cmake.yml

.. |Clang Format| image:: https://github.com/steinwurf/platform/actions/workflows/clang-format.yml/badge.svg
   :target: https://github.com/steinwurf/platform/actions/workflows/clang-format.yml

.. |No Assertions| image:: https://github.com/steinwurf/platform/actions/workflows/nodebug.yml/badge.svg
   :target: https://github.com/steinwurf/platform/actions/workflows/nodebug.yml

.. |Valgrind| image:: https://github.com/steinwurf/platform/actions/workflows/valgrind.yml/badge.svg
   :target: https://github.com/steinwurf/platform/actions/workflows/valgrind.yml

.. |Cppcheck| image:: https://github.com/steinwurf/platform/actions/workflows/cppcheck.yml/badge.svg
   :target: https://github.com/steinwurf/platform/actions/workflows/cppcheck.yml
    
platform is a C++ library for detecting compiler and platform properties.
Currently, it can detect the following properties:

- Compiler: g++, clang, and MSVC
- Operating system: Linux, Mac OSX, Windows, iOS, and Android
- Target architecture: x86, x86_64, ARM, and MIPS

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

