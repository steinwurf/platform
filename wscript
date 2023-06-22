#! /usr/bin/env python
# encoding: utf-8

APPNAME = "platform"
VERSION = "4.0.0"


def build(bld):
    bld.env.append_unique(
        "DEFINES_STEINWURF_VERSION", 'STEINWURF_PLATFORM_VERSION="{}"'.format(VERSION)
    )

    bld(includes="./src", export_includes="./src", name="platform_includes")

    if bld.is_toplevel():
        # Only build tests when executed from the top-level wscript,
        # i.e. not when included as a dependency
        bld.recurse("test")
        bld.recurse("examples/print_platform")
