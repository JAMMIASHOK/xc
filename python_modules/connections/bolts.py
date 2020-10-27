# -*- coding: utf-8 -*-
''' Naive gusset plate model.'''

from __future__ import division
from __future__ import print_function

__author__= "Luis C. Pérez Tato (LCPT) , Ana Ortega (AO_O) "
__copyright__= "Copyright 2020, LCPT, AO_O"
__license__= "GPL"
__version__= "3.0"
__email__= "l.pereztato@ciccp.es, ana.ortega@ciccp.es "

import math
import xc_base
import geom
from import_export import block_topology_entities as bte

class BoltBase(object):
    ''' Base class for bolts.

    :ivar diameter: bolt diameter
    :ivar pos3d: bolt position.
    '''
    def __init__(self, diameter, pos3d= None):
       ''' Constructor.

       :param diameter: bolt diameter.
       :param pos3d: bolt position.
       '''
       self.diameter= diameter
       if(pos3d):
           self.pos3d= pos3d
       else:
           self.pos3d= None
           
    def getMinDistanceBetweenCenters(self):
        ''' Return the minimum distance between centers.'''
        raise NotImplementedError()
    
    def getRecommendedDistanceBetweenCenters(self):
        ''' Return the recommended distance between centers.'''
        raise NotImplementedError()
           
    def getMinimumEdgeDistance(self):
        ''' Return the minimum edge distance from center of standard 
            hole to edge of connected part.'''
        raise NotImplementedError()
    
    def getName(self):
        return 'M'+str(self.diameter*1e3)[0:2]

    def getArea(self):
        ''' Return the area of the bolt.
        '''
        return math.pi*(self.diameter/2.0)**2
    
    def getDict(self):
        ''' Put member values in a dictionary.'''
        retval= {'diameter':self.diameter}
        xyz= None
        if(self.pos3d):
            xyz= (self.pos3d.x, self.pos3d.y, self.pos3d.z)
        retval.update({'pos3d': xyz})
        return retval

    def setFromDict(self,dct):
        ''' Read member values from a dictionary.'''
        self.diameter= dct['diameter']
        self.pos3d= None
        if('pos3d' in dct):
            xyz= dct['pos3d']
            if(xyz):
                self.pos3d= geom.Pos3d(xyz[0], xyz[1], xyz[2])

    def getHole(self, refSys= geom.Ref3d3d()):
        ''' Return a circle in the hole position.'''
        pLocal= geom.Pos2d(self.pos3d.x, self.pos3d.y)
        holeDiameter= self.getNominalHoleDiameter()
        circle2d= geom.Circle2d(pLocal,holeDiameter/2.0)
        return geom.Circle3d(refSys, circle2d)

    def getHoleAsPolygon(self, refSys= geom.Ref3d3d(), nSides= 8):
        ''' Return a polygon inscribed in the hole.'''
        hole= self.getHole(refSys)
        retval= hole.getInscribedPolygon(8,0.0)
        return retval
        
    def getHoleBlock(self, refSys= geom.Ref3d3d(), labels= []):
        ''' Return and octagon inscribed in the hole.'''
        retval= bte.BlockData()
        # Hole vertices.
        octagon= self.getHoleAsPolygon(refSys, nSides= 8).getVertexList()
        blk= retval.blockFromPoints(octagon,labels)
        # Hole center.
        ownerId= 'hole_center_owr_f'+str(blk.id) # Hole center owner.
        diameterLabel= 'diam_'+str(self.diameter)
        materialLabel= 'mat_'+str(self.steelType.name)
        centerLabelsB= labels+['hole_centers', diameterLabel, materialLabel]
        centerLabelsA= centerLabelsB+[ownerId]
        center3d= refSys.getPosGlobal(self.pos3d)
        pA= retval.appendPoint(-1, center3d.x, center3d.y, center3d.z, labels= centerLabelsA)        
        pB= retval.appendPoint(-1, center3d.x, center3d.y, center3d.z-1*self.diameter, labels= centerLabelsB)  #testing
        boltBlk= bte.BlockRecord(id= -1, typ= 'line', kPoints= [pA, pB])
        id= retval.appendBlock(boltBlk)       
        return retval
    
    def report(self, outputFile):
        ''' Reports bolt design values.'''
        outputFile.write('      diameter: '+str(self.diameter*1000)+' mm\n')
