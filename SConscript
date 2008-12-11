# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/CHS-scons/mootCore/SConscript,v 1.5 2008/09/26 00:30:48 glastrm Exp $ 
# Authors: Joanne Bogart <jrb@slac.stanford.edu>
# Version: mootCore-01-24-01
import os
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('mootCoreLib', depsOnly = 1)
mootCore = libEnv.SharedLibrary('mootCore',
                                ['src/MoodConnection.cxx',
                                 'src/MootSys.cxx','src/DbUtil.cxx', 
                                 'src/MootQuery.cxx','src/filterConfig.cxx'])

progEnv.Tool('mootCoreLib')

mootCoreLibs = [mootCore]
if 'CHS' in baseEnv['CPPDEFINES']:
    swigEnv = baseEnv.Clone()
    swigEnv.Tool('mootCoreLib')
    lib_pyMootCore = swigEnv.SharedLibrary('lib_py_mootCore',
                                           'src/py_mootCore.i')
    mootCoreLibs.append(lib_pyMootCore)
                 

test_mootConnect = progEnv.Program('test_mootConnect',
                                   ['src/test/test_connect.cxx'])
test_mootSys = progEnv.Program('test_mootSys', ['src/test/test_mootSys.cxx'])
test_queries = progEnv.Program('test_queries', ['src/test/test_queries.cxx'])

progEnv.Tool('registerObjects', package = 'mootCore', libraries = mootCoreLibs,
             testApps = [test_mootConnect, 
                         test_mootSys, test_queries],
             includes = listFiles(['mootCore/*.h']))
