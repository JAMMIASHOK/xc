# -*- coding: utf-8 -*-
'''Stiff beam between two nodes. Home made test'''

import xc_base
import geom
import xc
from solution import predefined_solutions
from model import predefined_spaces
from materials import typical_materials
import math


# Geometry
L= 15 # Bar length (m)

# Load
F= 1.5e3 # Load magnitude (kN)

# Problem type
feProblem= xc.FEProblem()
preprocessor=  feProblem.getPreprocessor   
nodes= preprocessor.getNodeHandler
modelSpace= predefined_spaces.StructuralMechanics3D(nodes)
nod1= nodes.newNodeXYZ(0,0.0,0.0)
nod2= nodes.newNodeXYZ(L,0.0,0.0)


# Constraints

modelSpace.fixNode000_000(nod1.tag)
linCrdTr=modelSpace.newLinearCrdTransf('linCrdTr',xzVector=xc.Vector([0,1,0]))
rr= modelSpace.setHugeBeamBetweenNodes(nod1.tag,nod2.tag,'linCrdTr')



# Loads definition
loadHandler= preprocessor.getLoadHandler

lPatterns= loadHandler.getLoadPatterns

#Load modulation.
ts= lPatterns.newTimeSeries("constant_ts","ts")
lPatterns.currentTimeSeries= "ts"
#Load case definition
lp0= lPatterns.newLoadPattern("default","0")
lp0.newNodalLoad(nod2.tag,xc.Vector([-F,F,-F,0,0,0]))
#We add the load case to domain.
lPatterns.addToDomain(lp0.name)

# Solution
analisis= predefined_solutions.simple_static_linear(feProblem)
result= analisis.analyze(1)


deltaX= nod2.getDisp[0]
deltaY= nod2.getDisp[1]
deltaZ= nod2.getDisp[2]  # Node 2 displacement


ratio1= math.sqrt(deltaX**2+deltaY**2+deltaZ**2)

''' 
print deltaX
print deltaY
print deltaZ
print ratio1
  '''

import os
from miscUtils import LogMessages as lmsg
fname= os.path.basename(__file__)
if ratio1<1e-8:
  print "test ",fname,": ok."
else:
  lmsg.error(fname+' ERROR.')
