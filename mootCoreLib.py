# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/mootCore/mootCoreLib.py,v 1.1 2008/08/15 21:42:39 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['mootCore'])
    env.Tool('rdbModelLib')
def exists(env):
    return 1;
