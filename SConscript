# -*- python -*-
# $Header$ 
# Authors: Joanne Bogart <jrb@slac.stanford.edu>
# Version: mootCore-01-23-01
import os
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('mootCoreLib', depsOnly = 1)
mootCore = libEnv.SharedLibrary('mootCore', ['MoodConnection.cxx', \
  'MootSys.cxx', \
  'DbUtil.cxx', \
  'MootQuery.cxx', \
  'filterConfig.cxx'])

progEnv.Tool('mootCoreLib')

test_mootConnect = progEnv.Program('test_mootConnect', ['src/test/test_connect.cxx'])
test_mootSys = progEnv.Program('test_mootSys', ['src/test/test_mootSys.cxx'])
test_queries = progEnv.Program('test_queries', ['src/test/test_queries.cxx'])

progEnv.Tool('registerObjects', package = 'mootCore', libraries = [mootCore], testApps = [test_mootConnect, \
test_mootSys, test_queries], includes = listFiles(['mootCore/*.h']))
