# -*- coding: utf-8 -*-

# Devuelve la posición del punto medio
def getPuntoMedio(iPntA, iPntB):
  pntA= mdlr.getCad.getPont(iPntA)
  pntB= mdlr.getCad.getPont(iPntB)
  posPntA= posA.getVectorPos
  posPntB= posB.getVectorPos
  return (posPntA+posPntB)/2

