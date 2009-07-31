# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/CHS-scons/mootCore/SConscript,v 1.9 2009/05/20 23:13:17 jrb Exp $ 
# Authors: Joanne Bogart <jrb@slac.stanford.edu>
# Version: mootCore-01-24-02
import os
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('mootCoreLib', depsOnly = 1)
mootCore = libEnv.SharedLibrary('mootCore', ['src/MoodConnection.cxx','src/MootSys.cxx','src/DbUtil.cxx', 
		'src/MootQuery.cxx','src/filterConfig.cxx'])

progEnv.Tool('mootCoreLib')

test_mootConnect = progEnv.Program('test_mootConnect', ['src/test/test_connect.cxx'])
test_mootSys = progEnv.Program('test_mootSys', ['src/test/test_mootSys.cxx'])
test_queries = progEnv.Program('test_queries', ['src/test/test_queries.cxx'])

progEnv.Tool('registerTargets', package = 'mootCore',
             libraryCxts = [[mootCore, libEnv]],
             testAppCxts = [[test_mootConnect, progEnv], [test_mootSys,progEnv],
                            [test_queries,progEnv]],
             includes = listFiles(['mootCore/*.h']))




