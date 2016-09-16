#! /usr/bin/env python
# encoding: utf-8

APPNAME = 'astyle'
VERSION = '0.1.0'

import waflib.extras.wurf_options


def options(opt):

    opt.load('wurf_common_tools')


def resolve(ctx):

    import waflib.extras.wurf_dependency_resolve as resolve

    ctx.load('wurf_common_tools')

    ctx.add_dependency(resolve.ResolveVersion(
        name='waf-tools',
        git_repository='github.com/steinwurf/waf-tools.git',
        major=3))


def configure(conf):

    conf.load("wurf_common_tools")


def build(bld):

    bld.load("wurf_common_tools")

    bld.env.append_unique(
        'DEFINES_STEINWURF_VERSION',
        'STEINWURF_ASTYLE_VERSION="{}"'.format(VERSION))

    if bld.is_toplevel():

        static_libs = []
        if bld.is_mkspec_platform('windows'):
            static_libs = ['Shell32']

        bld.program(
            features='cxx',
            source=bld.path.ant_glob('src/*.cpp'),
            lib=static_libs,
            target='astyle')

