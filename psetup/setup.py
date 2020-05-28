# create an auto rule
# to load up the auto variables inside of the main code so that larp
# can be auto configured without any change of the actual code by the
# intended user

from setuptools import setup
import psetup

setup( name='psetup',
        version=psetup.__version__,
        description='programming environnement setup',
        url='https://github.com/p4p1/psetup',
        author='Leo Smith',
        author_email='k0oo@icloud.com',
        license='None',
        packages=['psetup'],
        scripts=['bin/psetup'],
        zip_safe=False)

