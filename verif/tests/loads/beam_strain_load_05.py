# -*- coding: utf-8 -*-
from __future__ import print_function
''' home made test
    Reference:  Cálculo de estructuras por el método de los elemen-
    tos finitos. 1991. E. Oñate, page 165, example 5.3

    isbn={9788487867002}
    url={https://books.google.ch/books?id=lV1GSQAACAAJ}

'''
import xc_base
import geom
import xc
from solution import predefined_solutions
from model import predefined_spaces
from materials import typical_materials

__author__= "Luis C. Pérez Tato (LCPT) and Ana Ortega (AOO)"
__copyright__= "Copyright 2015, LCPT and AOO"
__license__= "GPL"
__version__= "3.0"
__email__= "l.pereztato@gmail.com"

L= 1.0 # Bar length (m)
E= 2.1e6*9.81/1e-4 # Elastic modulus
nu= 0.3 # Poisson's ratio
G= E/(2*(1+nu)) # Shear modulus
alpha= 1.2e-5 # Thermal expansion coefficient of the steel
A= 4e-4 # bar area expressed in square meters
Iy= 80.1e-8 # Cross section moment of inertia (m4)
Iz= 8.49e-8 # Cross section moment of inertia (m4)
J= 0.721e-8 # Cross section torsion constant (m4)
AT= 10 # Temperature increment (Celsius degrees)

# Problem type
feProblem= xc.FEProblem()
preprocessor=  feProblem.getPreprocessor
nodes= preprocessor.getNodeHandler
modelSpace= predefined_spaces.StructuralMechanics2D(nodes)

nodes.defaultTag= 1 #First node number.
nod= nodes.newNodeXY(0.0,0.0)
nod= nodes.newNodeXY(L/2,0.0)
nod= nodes.newNodeXY(L,0.0)


# Geometric transformation(s)
lin= modelSpace.newLinearCrdTransf("lin")
# Materials definition
section= typical_materials.defElasticShearSection2d(preprocessor, "section",A,E,G,Iz,1.0)

# Elements definition
elements= preprocessor.getElementHandler
elements.defaultTransformation= lin.name # Coordinate transformation for the new elements
elements.defaultMaterial= "section"
elements.defaultTag= 1
beam1= elements.newElement("ForceBeamColumn2d",xc.ID([1,2]))
beam2= elements.newElement("ForceBeamColumn2d",xc.ID([2,3]))

    
# Constraints
constraints= preprocessor.getBoundaryCondHandler
modelSpace.fixNode000(1)
modelSpace.fixNode000(3)

# Loads definition
loadHandler= preprocessor.getLoadHandler
lPatterns= loadHandler.getLoadPatterns
ts= lPatterns.newTimeSeries("linear_ts","ts")
lPatterns.currentTimeSeries= "ts"
#Load case definition
lp0= lPatterns.newLoadPattern("default","0")
#lPatterns.currentLoadPattern= "0"
eleLoad= lp0.newElementalLoad("beam_strain_load")
eleLoad.elementTags= xc.ID([1])
thermalDeformation= xc.DeformationPlane(alpha*AT)
eleLoad.backEndDeformationPlane= thermalDeformation
eleLoad.frontEndDeformationPlane= thermalDeformation

#We add the load case to domain.
lPatterns.addToDomain(lp0.name)

# Solution procedure
analysis= predefined_solutions.simple_static_modified_newton(feProblem)
result= analysis.analyze(1)


nod2= nodes.getNode(2)
dX= nod2.getDisp[0] 
dY= nod2.getDisp[1]   

elem1= elements.getElement(1)
elem1.getResistingForce()
scc0= elem1.getSections()[0]

axil= scc0.getStressResultantComponent("N")
moment= scc0.getStressResultantComponent("Mz")
shear= scc0.getStressResultantComponent("Vy")



N= (-E*A*alpha*AT)
ratio= ((axil-N)/N)

''' 
print("dX= ",dX)
print("dY= ",dY)
print("N= ",N)
print("axil= ",axil)
print("ratio= ",ratio)
print("moment= ",moment)
print("shear= ",shear)
   '''

import os
from misc_utils import log_messages as lmsg
fname= os.path.basename(__file__)
if (abs(dX)<1e-10) & (abs(ratio)<1e-10) & (abs(moment)<1e-10) & (abs(shear)<1e-10) :
  print("test ",fname,": ok.")
else:
  lmsg.error(fname+' ERROR.')
