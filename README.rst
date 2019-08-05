platform
--------
platform is a C++ library for detecting compiler and platform properties.
Currently, it can detect the following properties:

- Compiler: g++, clang, and MSVC
- Operating system: Linux, Mac OSX, Windows, iOS, and Android
- Target architecture: x86, ARM, and MIPS

.. image:: http://buildbot.steinwurf.dk/svgstatus?project=platform
    :target: http://buildbot.steinwurf.dk/stats?projects=platform

Use as Dependency in CMake
--------------------------

To depend on this project when using the CMake build system, add the following
in your CMake build script:

::

   add_subdirectory("/path/to/platform" )
   target_link_libraries(<my_target> steinwurf::platform)

Where ``<my_target>`` is replaced by your target.

License
-------
The project license is based on the BSD License. Please refer to the LICENSE.rst
file for more details.

Testing
-------
The project is tested on various versions of Windows, Linux and Mac. We run
automated tests on x86, ARM and MIPS architectures with different compilers.

You can see the status by selecting the 'platform' project on the
`Steinwurf buildbot page <http://buildbot.steinwurf.dk:12344/>`_.

