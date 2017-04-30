# -*- coding: utf-8 -*-

#*    Nov. 2015   Ana Ortega    *

# Home made test

import math
import xc_base
import geom
import xc
from materials import concreteBase
from materials.ehe import EHE_concrete

__author__= "Luis C. Pérez Tato (LCPT) and Ana Ortega (AOO)"
__copyright__= "Copyright 2015, LCPT and AOO"
__license__= "GPL"
__version__= "3.0"
__email__= "l.pereztato@gmail.com"

# Model definition
prueba= xc.ProblemaEF()
prueba.logFileName= "/tmp/borrar.log" # Para no imprimir mensajes de advertencia
mdlr= prueba.getPreprocessor
concr=EHE_concrete.HA25
concr.alfacc=0.85 #f_maxd= 0.85*fcd
errMax= concreteBase.testDiagDHormigon(mdlr,concr)


#print "errMax= ",(errMax)

import os
fname= os.path.basename(__file__)
if errMax<1e-8:
  print "test ",fname,": ok."
else:
  print "test ",fname,": ERROR."
