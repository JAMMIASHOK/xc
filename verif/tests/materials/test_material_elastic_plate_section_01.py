# -*- coding: utf-8 -*-
# Home made test

__author__= "Luis C. Pérez Tato (LCPT)"
__copyright__= "Copyright 2014, LCPT"
__license__= "GPL"
__version__= "3.0"
__email__= "l.pereztato@gmail.com"

E= 2.1e6 # Young modulus of the steel.
nu= 0.3 # Poisson's ratio.
h= 0.1 # Thickness.

import xc_base
import geom
import xc
from model import predefined_spaces
from materials import typical_materials

# Model definition
prb= xc.ProblemaEF()
preprocessor=  prb.getPreprocessor
# Define materials
prueba= typical_materials.defElasticPlateSection(preprocessor, "prueba",E,nu,0.0,h)

ratio1= (prueba.E-E)/E
ratio2= (prueba.nu-nu)/nu
ratio3= (prueba.h-h)/h

import os
from miscUtils import LogMessages as lmsg
fname= os.path.basename(__file__)
if (abs(ratio1)<1e-12) & (abs(ratio2)<1e-12) & (abs(ratio3)<1e-12):
  print "test ",fname,": ok."
else:
  lmsg.error(fname+' ERROR.')
