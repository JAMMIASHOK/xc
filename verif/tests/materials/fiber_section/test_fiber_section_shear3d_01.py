# -*- coding: utf-8 -*-
# Test de funcionamiento de una sección metálica rectangular de fibras de elastoplástico.
#    elaborado a partir de Nociones de cálculo plástico. C. Benito Hernández.
#    página 26 y siguientes.

from materials import sccRectg
from materials.ehe import auxEHE
from misc import banco_pruebas_scc3d
from solution import predefined_solutions


from materials.ehe import hormigonesEHE
from materials.ehe import EHE_reinforcing_steel
from materials.ehe import comprobVEHE08
from materials.ehe import cortanteEHE
import xc_base
import geom
import xc
from solution import predefined_solutions
from model import predefined_spaces
from model import fix_node_6dof
from materials import typical_materials


# Definición de la sección rectangular
scc10x20= sccRectg.sccRectang()
scc10x20.b= 10 # Ancho de la sección expresado en cm.
scc10x20.h= 20 # Canto de la sección expresado en cm.
scc10x20.nDivIJ= 32
scc10x20.nDivJK= 32

import os
pth= os.path.dirname(__file__)
if(not pth):
  pth= "."
#print "pth= ", pth
execfile(pth+"/macros_test_fiber_section.py")


fy= 2600 # Tensión de cedencia del material expresada en kp/cm2.
E= 2.1e6 # Módulo de Young del material en kp/cm2.

prueba= xc.ProblemaEF()
prueba.logFileName= "/tmp/borrar.log" # Para no imprimir mensajes de advertencia.
mdlr= prueba.getModelador
# Materials definition
epp= typical_materials.defElasticPPMaterial(mdlr,"epp",E,fy,-fy) 
respT= typical_materials.defElasticMaterial(mdlr,"respT",1e10) # Respuesta de la sección a torsión.
respVy= typical_materials.defElasticMaterial(mdlr,"respVy",1e6) # Respuesta de la sección a cortante según y.
respVz= typical_materials.defElasticMaterial(mdlr,"respVz",1e3) # Respuesta de la sección a cortante según y.
# Secciones
geomRectang= mdlr.getMaterialLoader.newSectionGeometry("geomRectang")
reg= scc10x20.discretization(geomRectang,"epp")
sa= mdlr.getMaterialLoader.newMaterial("fiberSectionShear3d","sa")
fiberSectionRepr= sa.getFiberSectionRepr()
fiberSectionRepr.setGeomNamed("geomRectang")
sa.setupFibers()
extraeParamSccFibras(sa,scc10x20)
sa.setRespVyByName("respVy")
sa.setRespVzByName("respVz")
sa.setRespTByName("respT")

banco_pruebas_scc3d.modeloSecc3d(mdlr,"sa")

# Constraints
coacciones= mdlr.getConstraintLoader

fix_node_6dof.fixNode6DOF(coacciones,1)

# Loads definition
cargas= mdlr.getLoadLoader

casos= cargas.getLoadPatterns

#Load modulation.
ts= casos.newTimeSeries("constant_ts","ts")
casos.currentTimeSeries= "ts"
#Load case definition
lp0= casos.newLoadPattern("default","0")
#casos.currentLoadPattern= "0"
loadVy= 2e4
loadVz= 3e4
loadMx= 1e3
loadMz= 0.999*scc10x20.Mp1(fy)
lp0.newNodalLoad(2,xc.Vector([0,loadVy,loadVz,loadMx,0,loadMz]))

#We add the load case to domain.
casos.addToDomain("0")


# Procedimiento de solución
analisis= predefined_solutions.simple_newton_raphson(prueba)
analOk= analisis.analyze(1)
if(analOk!=0):
  print "Error!; failed to converge."
  exit()



nodos= mdlr.getNodeLoader
nodos.calculateNodalReactions(True)
n1= nodos.getNode(1)
RVy= n1.getReaction[1] 
RVz= n1.getReaction[2] 
RMx= n1.getReaction[3] 
RMz= n1.getReaction[5] 

elementos= mdlr.getElementLoader
ele1= elementos.getElement(1)
scc= ele1.getSection()
esfVy= scc.getStressResultantComponent("Vy")
esfVz= scc.getStressResultantComponent("Vz")
esfMx= scc.getStressResultantComponent("T")
esfMz= scc.getStressResultantComponent("Mz")



yCdgTeor= 0.0
zCdgTeor= 0.0
ratio1= (sumAreas-scc10x20.area())/scc10x20.area()
ratio2= yCdg-yCdgTeor
ratio3= zCdg-zCdgTeor
ratio4= (I1-scc10x20.I1())/scc10x20.I1()
ratio5= (I2-scc10x20.I2())/scc10x20.I2()
ratio6= (i1-scc10x20.i1())/scc10x20.i1()
ratio7= (i2-scc10x20.i2())/scc10x20.i2()
ratio8= (Me1-scc10x20.Me1(fy))/scc10x20.Me1(fy)
ratio9= (Me2-scc10x20.Me2(fy))/scc10x20.Me2(fy)
ratio10= (SzPosG-scc10x20.S1PosG())/scc10x20.S1PosG()
ratio11= (SyPosG-scc10x20.S2PosG())/scc10x20.S2PosG()
ratio12= (RMz+loadMz)/loadMz
ratio13= (esfMz-loadMz)/loadMz

ratio14= (RMx+loadMx)/loadMx
ratio15= (esfMx-loadMx)/loadMx

ratio16= (RVy+loadVy)/loadVy
ratio17= (esfVy-loadVy)/loadVy

ratio18= (RVz+loadVz)/loadVz
ratio19= (esfVz-loadVz)/loadVz

''' 
    print "RVy= ",(RVy)
    print "esfVy= ",(esfVy)
    print "loadVy= ",(loadVy)

    print "RVz= ",(RVz)
    print "esfVz= ",(esfVz)
    print "loadVz= ",(loadVz)

    print "RMx= ",(RMx)
    print "esfMx= ",(esfMx)
    print "loadMx= ",(loadMx)

    print "RMz= ",(RMz)
    print "esfMz= ",(esfMz)
    print "loadMz= ",(loadMz)
   '''

fname= os.path.basename(__file__)
if (abs(ratio1)<1e-5) & (abs(ratio2)<1e-5) & (abs(ratio3)<1e-5) & (abs(ratio4)<1e-3) & (abs(ratio5)<1e-2) & (abs(ratio6)<1e-3) & (abs(ratio7)<1e-2) & (abs(ratio8)<1e-3) & (abs(ratio9)<1e-3) & (abs(ratio10)<1e-5) & (abs(ratio11)<1e-5) & (abs(ratio12)<1e-5) & (abs(ratio13)<1e-5) & (abs(ratio14)<1e-5) & (abs(ratio15)<1e-5) & (abs(ratio16)<1e-5) & (abs(ratio17)<1e-5) & (abs(ratio18)<1e-5) & (abs(ratio19)<1e-5) & (analOk == 0.0) :
  print "test ",fname,": ok."
else:
  print "test ",fname,": ERROR."
