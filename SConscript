# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/mootCore/SConscript,v 1.2 2008/08/25 21:00:19 ecephas Exp $ 
# Authors: Joanne Bogart <jrb@slac.stanford.edu>
# Version: mootCore-01-23-02
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

progEnv.Tool('registerObjects', package = 'mootCore', libraries = [mootCore], testApps = [test_mootConnect, 
	test_mootSys, test_queries], includes = listFiles(['mootCore/*.h']))
