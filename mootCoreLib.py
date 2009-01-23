# $Header: /nfs/slac/g/glast/ground/cvs/CHS-scons/mootCore/mootCoreLib.py,v 1.2 2008/08/25 20:58:10 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['mootCore'])
    env.Tool('rdbModelLib')
    env.Tool('xmlBaseLib')
    env.Tool('facilitiesLib')
def exists(env):
    return 1;
