# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/mootCore/SConscript,v 1.20 2012/06/12 01:28:37 jrb Exp $ 
# Authors: Joanne Bogart <jrb@slac.stanford.edu>
# Version: mootCore-01-24-09
import os
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='mootCore', toBuild='shared')
mootCore = libEnv.SharedLibrary('mootCore', ['src/MoodConnection.cxx','src/MootSys.cxx','src/DbUtil.cxx', 
		'src/MootQuery.cxx','src/filterConfig.cxx'])

progEnv.Tool('mootCoreLib')

test_mootConnect = progEnv.Program('test_mootConnect', ['src/test/test_connect.cxx'])
test_mootSys = progEnv.Program('test_mootSys', ['src/test/test_mootSys.cxx'])
test_queries = progEnv.Program('test_queries', ['src/test/test_queries.cxx'])

progEnvKwArgs = { 'package' : 'mootCore',
                  'libraryCxts' : [[mootCore, libEnv]],
                  'testAppCxts' : [[test_mootConnect, progEnv], [test_mootSys,progEnv],
                                   [test_queries,progEnv]],
                  'includes' : listFiles(['mootCore/*.h']),
                  'xml' : listFiles(['xml/*'], recursive=True)
                  }


# If this is being built in the CHS container, build the SWIG stuff too.
if 'CHS' in progEnv.Dictionary()['CPPDEFINES']:
    swigEnv = baseEnv.Clone()
    swigEnv.Tool("mootCoreLib")
    lib_py_mootCore = swigEnv.SwigLibrary("_py_mootCore", 'src/py_mootCore.i')
    progEnvKwArgs['swigLibraryCxts'] = [[lib_py_mootCore, swigEnv]]

progEnv.Tool('registerTargets', **progEnvKwArgs)
