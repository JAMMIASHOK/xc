# -*- coding: utf-8 -*-
''' Properties of Plywood structural panels taken from:
    http://www.pfsteco.com/techtips/pdf/tt_plywooddesigncapacities
    table C.

    Oriented strand board panels according to document:
    "Panel design specification" Form No. D510C/Revised May 2012/0300

    Properties of LSL beams and headers taken from:
    LP SolidStart LSL Beam & Header Technical Guide

    Properties of LVL beams and headers taken from:
    LP SolidStart LVL Beam & Header Technical Guide
'''

from __future__ import division
from __future__ import print_function

from materials.awc_nds import AWCNDS_materials as mat
from AWCNDS_materials import in2meter
from AWCNDS_materials import pound2N
from AWCNDS_materials import foot2meter
from AWCNDS_materials import pound2kg

__author__= "Luis C. Pérez Tato (LCPT) , Ana Ortega (AO_O) "
__copyright__= "Copyright 2020, LCPT, AO_O"
__license__= "GPL"
__version__= "3.0"
__email__= "l.pereztato@ciccp.es, ana.ortega@ciccp.es "

PlywoodPanelSections= dict()

PlywoodPanelSections['3/8']= mat.PlywoodPanelSection('3/8',b= 1.0, h= 0.375*in2meter, shear_constant= 3.00) #,  'CrossSectionalArea':4.500, 'MomentOfInertia':0.053, 'SectionModulus':0.281, 'StaticalMoment':0.211
PlywoodPanelSections['7/16']= mat.PlywoodPanelSection('7/16',b= 1.0, h= 0.437*in2meter, shear_constant= 3.50) #,  'CrossSectionalArea':5.250, 'MomentOfInertia':0.084, 'SectionModulus':0.383, 'StaticalMoment':0.287
PlywoodPanelSections['15/32']= mat.PlywoodPanelSection('15/32',b= 1.0, h= 0.469*in2meter, shear_constant= 3.75) #,  'CrossSectionalArea':5.625, 'MomentOfInertia':0.103, 'SectionModulus':0.440, 'StaticalMoment':0.330
PlywoodPanelSections['1/2']= mat.PlywoodPanelSection('1/2',b= 1.0, h= 0.500*in2meter, shear_constant= 4.00) #,  'CrossSectionalArea':6.000, 'MomentOfInertia':0.125, 'SectionModulus':0.500, 'StaticalMoment':0.375
PlywoodPanelSections['19/32']= mat.PlywoodPanelSection('19/32',b= 1.0, h= 0.594*in2meter, shear_constant= 4.75) #,  'CrossSectionalArea':7.125, 'MomentOfInertia':0.209, 'SectionModulus':0.705, 'StaticalMoment':0.529
PlywoodPanelSections['5/8']= mat.PlywoodPanelSection('5/8',b= 1.0, h= 0.625*in2meter, shear_constant= 5.00) #,  'CrossSectionalArea':7.500, 'MomentOfInertia':0.244, 'SectionModulus':0.781, 'StaticalMoment':0.586
PlywoodPanelSections['23/32']= mat.PlywoodPanelSection('23/32',b= 1.0, h= 0.719*in2meter, shear_constant= 5.75) #,  'CrossSectionalArea':8.625, 'MomentOfInertia':0.371, 'SectionModulus':1.033, 'StaticalMoment':0.775
PlywoodPanelSections['3/4']= mat.PlywoodPanelSection('3/4',b= 1.0, h= 0.750*in2meter, shear_constant= 6.00) #,  'CrossSectionalArea':9.000, 'MomentOfInertia':0.422, 'SectionModulus':1.125, 'StaticalMoment':0.844
PlywoodPanelSections['7/8']= mat.PlywoodPanelSection('7/8',b= 1.0, h= 0.875*in2meter, shear_constant= 7.00) #, 'CrossSectionalArea':10.500, 'MomentOfInertia':0.670, 'SectionModulus':1.531, 'StaticalMoment':1.148
PlywoodPanelSections['1']= mat.PlywoodPanelSection('1',b= 1.0, h= 1.000*in2meter, shear_constant= 8.00) #,  'CrossSectionalArea':12.000, 'MomentOfInertia':1.000, 'SectionModulus':2.000, 'StaticalMoment':1.500
PlywoodPanelSections['1-1/8']= mat.PlywoodPanelSection('1-1/8',b= 1.0, h= 1.125*in2meter, shear_constant= 9.00) #,  'CrossSectionalArea':13.500, 'MomentOfInertia':1.424, 'SectionModulus':2.531, 'StaticalMoment':1.898

OSBPanelSections= dict()

OSBPanelSections['3/8']= mat.OSBPanelSection('3/8',b= 1.0, h= 0.375*in2meter, shear_constant= 3.00)
OSBPanelSections['7/16']= mat.OSBPanelSection('7/16',b= 1.0, h= 0.437*in2meter, shear_constant= 3.50)
OSBPanelSections['15/32']= mat.OSBPanelSection('15/32',b= 1.0, h= 0.469*in2meter, shear_constant= 3.75)
OSBPanelSections['1/2']= mat.OSBPanelSection('1/2',b= 1.0, h= 0.500*in2meter, shear_constant= 4.00)
OSBPanelSections['19/32']= mat.OSBPanelSection('19/32',b= 1.0, h= 0.594*in2meter, shear_constant= 4.75)
OSBPanelSections['5/8']= mat.OSBPanelSection('5/8',b= 1.0, h= 0.625*in2meter, shear_constant= 5.00)
OSBPanelSections['23/32']= mat.OSBPanelSection('23/32',b= 1.0, h= 0.719*in2meter, shear_constant= 5.75)
OSBPanelSections['3/4']= mat.OSBPanelSection('3/4',b= 1.0, h= 0.750*in2meter, shear_constant= 6.00)
OSBPanelSections['7/8']= mat.OSBPanelSection('7/8',b= 1.0, h= 0.875*in2meter, shear_constant= 7.00)
OSBPanelSections['1']= mat.OSBPanelSection('1',b= 1.0, h= 1.000*in2meter, shear_constant= 8.00)
OSBPanelSections['1-1/8']= mat.OSBPanelSection('1-1/8',b= 1.0, h= 1.125*in2meter, shear_constant= 9.00)

LSL135HeaderSections= dict()

LSL135HeaderSections['3.5x4-3/8']= mat.LSL_135E_HeaderSection('3.5x4-3/8',b= 3.5*in2meter, h= (4+3/8.0)*in2meter, Ms= 1817*pound2N*foot2meter, Vs= 4185*pound2N, linearDensity= 4.7*pound2kg)
LSL135HeaderSections['1.5x5-1/2']= mat.LSL_135E_HeaderSection('1.5x5-1/2',b= 1.5*in2meter, h= 5.5*in2meter, Ms= 1197*pound2N*foot2meter, Vs= 2255*pound2N, linearDensity= 2.6*pound2kg)
LSL135HeaderSections['3.5x5-1/2']= mat.LSL_135E_HeaderSection('3.5x5-1/2',b= 3.5*in2meter, h= 5.5*in2meter, Ms= 2794*pound2N*foot2meter, Vs= 5262*pound2N, linearDensity= 5.9*pound2kg)
LSL135HeaderSections['1.5x7-1/4']= mat.LSL_135E_HeaderSection('1.5x7-1/4',b= 1.5*in2meter, h= 7.25*in2meter, Ms= 2013*pound2N*foot2meter, Vs= 2972*pound2N, linearDensity= 3.4*pound2kg)
LSL135HeaderSections['3.5x7-1/4']= mat.LSL_135E_HeaderSection('3.5x7-1/4',b= 3.5*in2meter, h= 7.25*in2meter, Ms= 4696*pound2N*foot2meter, Vs= 6936*pound2N, linearDensity= 7.8*pound2kg)

LSL155HeaderSections= dict()

LSL155HeaderSections['1.5x5-1/2']= mat.LSL_155E_HeaderSection('1.5x5-1/2', b= 1.5*in2meter, h= 5.5*in2meter, Ms= 1633*pound2N*foot2meter, Vs= 2255*pound2N, linearDensity= 2.6*pound2kg)
LSL155HeaderSections['1.5x7-1/4']= mat.LSL_155E_HeaderSection('1.5x7-1/4', b= 1.5*in2meter, h= 7.25*in2meter, Ms= 2745*pound2N*foot2meter, Vs= 2973*pound2N, linearDensity= 3.5*pound2kg)
LSL155HeaderSections['1.5x9-1/4']= mat.LSL_155E_HeaderSection('1.5x9-1/4', b= 1.5*in2meter, h= 9.25*in2meter, Ms= 4340*pound2N*foot2meter, Vs= 3793*pound2N, linearDensity= 4.4*pound2kg)
LSL155HeaderSections['1.5x9-1/2']= mat.LSL_155E_HeaderSection('1.5x9-1/2', b= 1.5*in2meter, h= 9.5*in2meter, Ms= 4563*pound2N*foot2meter, Vs= 3895*pound2N, linearDensity= 4.6*pound2kg)
LSL155HeaderSections['1.5x11-1/4']= mat.LSL_155E_HeaderSection('1.5x11-1/4', b= 1.5*in2meter, h= 11.25*in2meter, Ms= 6271*pound2N*foot2meter, Vs= 4613*pound2N, linearDensity= 5.4*pound2kg)
LSL155HeaderSections['1.5x11-7/8']= mat.LSL_155E_HeaderSection('1.5x11-7/8', b= 1.5*in2meter, h= 11.875*in2meter, Ms= 6942*pound2N*foot2meter, Vs= 4869*pound2N, linearDensity= 5.7*pound2kg)

LSL155HeaderSections['1.75x5-1/2']= mat.LSL_155E_HeaderSection('1.75x5-1/2', b= 1.75*in2meter, h= 5.5*in2meter, Ms= 1905*pound2N*foot2meter, Vs= 2631*pound2N, linearDensity= 3.1*pound2kg)
LSL155HeaderSections['1.75x7-1/4']= mat.LSL_155E_HeaderSection('1.75x7-1/4', b= 1.75*in2meter, h= 7.25*in2meter, Ms= 3203*pound2N*foot2meter, Vs= 3468*pound2N, linearDensity= 4.1*pound2kg)
LSL155HeaderSections['1.75x9-1/4']= mat.LSL_155E_HeaderSection('1.75x9-1/4', b= 1.75*in2meter, h= 9.25*in2meter, Ms= 5064*pound2N*foot2meter, Vs= 4425*pound2N, linearDensity= 5.2*pound2kg)
LSL155HeaderSections['1.75x9-1/2']= mat.LSL_155E_HeaderSection('1.75x9-1/2', b= 1.75*in2meter, h= 9.5*in2meter, Ms= 5324*pound2N*foot2meter, Vs= 4544*pound2N, linearDensity= 5.3*pound2kg)

LSL155HeaderSections['1.75x11-7/8']= mat.LSL_155E_HeaderSection('1.75x11-7/8', b= 1.75*in2meter, h= 11.875*in2meter, Ms= 8099*pound2N*foot2meter, Vs= 5680*pound2N, linearDensity= 6.6*pound2kg)
LSL155HeaderSections['1.75x14']= mat.LSL_155E_HeaderSection('1.75x14', b= 1.75*in2meter, h= 14*in2meter, Ms= 11037*pound2N*foot2meter, Vs= 6697*pound2N, linearDensity= 7.8*pound2kg)
LSL155HeaderSections['1.75x16']= mat.LSL_155E_HeaderSection('1.75x16', b= 1.75*in2meter, h= 16*in2meter, Ms= 14186*pound2N*foot2meter, Vs= 7653*pound2N, linearDensity= 8.9*pound2kg)
LSL155HeaderSections['1.75x18']= mat.LSL_155E_HeaderSection('1.75x18', b= 1.75*in2meter, h= 18*in2meter, Ms= 17702*pound2N*foot2meter, Vs= 8610*pound2N, linearDensity= 10.1*pound2kg)

LSL155HeaderSections['3.5x5-1/2']= mat.LSL_155E_HeaderSection('3.5x5-1/2', b= 3.5*in2meter, h= 5.5*in2meter, Ms= 3811*pound2N*foot2meter, Vs= 5262*pound2N, linearDensity= 6.1*pound2kg)
LSL155HeaderSections['3.5x7-1/4']= mat.LSL_155E_HeaderSection('3.5x7-1/4', b= 3.5*in2meter, h= 7.25*in2meter, Ms= 6406*pound2N*foot2meter, Vs= 6936*pound2N, linearDensity= 8.1*pound2kg)
LSL155HeaderSections['3.5x9-1/4']= mat.LSL_155E_HeaderSection('3.5x9-1/4', b= 3.5*in2meter, h= 9.25*in2meter, Ms= 10127*pound2N*foot2meter, Vs= 8849*pound2N, linearDensity= 10.3*pound2kg)
LSL155HeaderSections['3.5x9-1/2']= mat.LSL_155E_HeaderSection('3.5x9-1/2', b= 3.5*in2meter, h= 9.5*in2meter, Ms= 10648*pound2N*foot2meter, Vs= 9088*pound2N, linearDensity= 10.6*pound2kg)

LSL155HeaderSections['3.5x11-7/8']= mat.LSL_155E_HeaderSection('3.5x11-7/8', b= 3.5*in2meter, h= 11.875*in2meter, Ms= 16198*pound2N*foot2meter, Vs= 11360*pound2N, linearDensity= 13.3*pound2kg)
LSL155HeaderSections['3.5x14']= mat.LSL_155E_HeaderSection('3.5x14', b= 3.5*in2meter, h= 14*in2meter, Ms= 22073*pound2N*foot2meter, Vs= 13393*pound2N, linearDensity= 15.7*pound2kg)
LSL155HeaderSections['3.5x16']= mat.LSL_155E_HeaderSection('3.5x16', b= 3.5*in2meter, h= 16*in2meter, Ms= 28372*pound2N*foot2meter, Vs= 15307*pound2N, linearDensity= 17.9*pound2kg)
LSL155HeaderSections['3.5x18']= mat.LSL_155E_HeaderSection('3.5x18', b= 3.5*in2meter, h= 18*in2meter, Ms= 35405*pound2N*foot2meter, Vs= 17220*pound2N, linearDensity= 20.1*pound2kg)

LSL155HeaderSections['5.25x5-1/2']= mat.LSL_155E_HeaderSection('5.25x5-1/2', b= 5.25*in2meter, h= 5.5*in2meter, Ms= 5716*pound2N*foot2meter, Vs= 7893*pound2N, linearDensity= 9.2*pound2kg)
LSL155HeaderSections['5.25x7-1/4']= mat.LSL_155E_HeaderSection('5.25x7-1/4', b= 5.25*in2meter, h= 7.25*in2meter, Ms= 9609*pound2N*foot2meter, Vs= 10404*pound2N, linearDensity= 12.2*pound2kg)
LSL155HeaderSections['5.25x9-1/4']= mat.LSL_155E_HeaderSection('5.25x9-1/4', b= 5.25*in2meter, h= 9.25*in2meter, Ms= 15191*pound2N*foot2meter, Vs= 13274*pound2N, linearDensity= 15.5*pound2kg)
LSL155HeaderSections['5.25x9-1/2']= mat.LSL_155E_HeaderSection('5.25x9-1/2', b= 5.25*in2meter, h= 9.5*in2meter, Ms= 15972*pound2N*foot2meter, Vs= 13633*pound2N, linearDensity= 15.9*pound2kg)

LSL155HeaderSections['5.25x11-7/8']= mat.LSL_155E_HeaderSection('5.25x11-7/8', b= 5.25*in2meter, h= 11.875*in2meter, Ms= 24297*pound2N*foot2meter, Vs= 17041*pound2N, linearDensity= 19.9*pound2kg)
LSL155HeaderSections['5.25x14']= mat.LSL_155E_HeaderSection('5.25x14', b= 5.25*in2meter, h= 14*in2meter, Ms= 33110*pound2N*foot2meter, Vs= 20090*pound2N, linearDensity= 23.5*pound2kg)
LSL155HeaderSections['5.25x16']= mat.LSL_155E_HeaderSection('5.25x16', b= 5.25*in2meter, h= 16*in2meter, Ms= 42558*pound2N*foot2meter, Vs= 22960*pound2N, linearDensity= 26.8*pound2kg)
LSL155HeaderSections['5.25x18']= mat.LSL_155E_HeaderSection('5.25x18', b= 5.25*in2meter, h= 18*in2meter, Ms= 53107*pound2N*foot2meter, Vs= 25830*pound2N, linearDensity= 30.2*pound2kg)

LVLHeaderSections= dict()

LVLHeaderSections['1.75x7-1/4']= mat.LVL_2900Fb2E_HeaderSection('1.75x7-1/4', b= 1.75*in2meter, h= 7.25*in2meter, Ms= 3918*pound2N*foot2meter, Vs= 2411*pound2N, linearDensity= 3.6*pound2kg)
LVLHeaderSections['1.75x9-1/4']= mat.LVL_2900Fb2E_HeaderSection('1.75x9-1/4', b= 1.75*in2meter, h= 9.25*in2meter, Ms= 6208*pound2N*foot2meter, Vs= 3076*pound2N, linearDensity= 4.6*pound2kg)
LVLHeaderSections['1.75x9-1/2']= mat.LVL_2900Fb2E_HeaderSection('1.75x9-1/2', b= 1.75*in2meter, h= 9.5*in2meter, Ms= 6529*pound2N*foot2meter, Vs= 3159*pound2N, linearDensity= 4.8*pound2kg)
LVLHeaderSections['1.75x11-1/4']= mat.LVL_2900Fb2E_HeaderSection('1.75x11-1/4', b= 1.75*in2meter, h= 11.25*in2meter, Ms= 8985*pound2N*foot2meter, Vs= 3741*pound2N, linearDensity= 5.6*pound2kg)
LVLHeaderSections['1.75x11-7/8']= mat.LVL_2900Fb2E_HeaderSection('1.75x11-7/8', b= 1.75*in2meter, h= 11.875*in2meter, Ms= 9951*pound2N*foot2meter, Vs= 3948*pound2N, linearDensity= 5.9*pound2kg)
LVLHeaderSections['1.75x14']= mat.LVL_2900Fb2E_HeaderSection('1.75x14', b= 1.75*in2meter, h= 14*in2meter, Ms= 13514*pound2N*foot2meter, Vs= 4655*pound2N, linearDensity= 7*pound2kg)
LVLHeaderSections['1.75x16']= mat.LVL_2900Fb2E_HeaderSection('1.75x16', b= 1.75*in2meter, h= 16*in2meter, Ms= 17318*pound2N*foot2meter, Vs= 5320*pound2N, linearDensity= 8*pound2kg)
LVLHeaderSections['1.75x18']= mat.LVL_2900Fb2E_HeaderSection('1.75x18', b= 1.75*in2meter, h= 18*in2meter, Ms= 21552*pound2N*foot2meter, Vs= 5985*pound2N, linearDensity= 9*pound2kg)

LVLHeaderSections['3.5x7-1/4']= mat.LVL_2900Fb2E_HeaderSection('3.5x7-1/4', b= 3.5*in2meter, h= 7.25*in2meter, Ms= 7837*pound2N*foot2meter, Vs= 4821*pound2N, linearDensity= 7.3*pound2kg)
LVLHeaderSections['3.5x9-1/4']= mat.LVL_2900Fb2E_HeaderSection('3.5x9-1/4', b= 3.5*in2meter, h= 9.25*in2meter, Ms= 12416*pound2N*foot2meter, Vs= 6151*pound2N, linearDensity= 9.3*pound2kg)
LVLHeaderSections['3.5x9-1/2']= mat.LVL_2900Fb2E_HeaderSection('3.5x9-1/2', b= 3.5*in2meter, h= 9.5*in2meter, Ms= 13057*pound2N*foot2meter, Vs= 6318*pound2N, linearDensity= 9.5*pound2kg)
LVLHeaderSections['3.5x11-1/4']= mat.LVL_2900Fb2E_HeaderSection('3.5x11-1/4', b= 3.5*in2meter, h= 11.25*in2meter, Ms= 17970*pound2N*foot2meter, Vs= 7481*pound2N, linearDensity= 11.3*pound2kg)
LVLHeaderSections['3.5x11-7/8']= mat.LVL_2900Fb2E_HeaderSection('3.5x11-7/8', b= 3.5*in2meter, h= 11.875*in2meter, Ms= 19902*pound2N*foot2meter, Vs= 7897*pound2N, linearDensity= 11.9*pound2kg)
LVLHeaderSections['3.5x14']= mat.LVL_2900Fb2E_HeaderSection('3.5x14', b= 3.5*in2meter, h= 14*in2meter, Ms= 27029*pound2N*foot2meter, Vs= 9310*pound2N, linearDensity= 14*pound2kg)
LVLHeaderSections['3.5x16']= mat.LVL_2900Fb2E_HeaderSection('3.5x16', b= 3.5*in2meter, h= 16*in2meter, Ms= 34636*pound2N*foot2meter, Vs= 10640*pound2N, linearDensity= 16*pound2kg)
LVLHeaderSections['3.5x18']= mat.LVL_2900Fb2E_HeaderSection('3.5x18', b= 3.5*in2meter, h= 18*in2meter, Ms= 43105*pound2N*foot2meter, Vs= 11970*pound2N, linearDensity= 18*pound2kg)

LVLHeaderSections['5.25x7-1/4']= mat.LVL_2900Fb2E_HeaderSection('5.25x7-1/4', b= 5.25*in2meter, h= 7.25*in2meter, Ms= 11755*pound2N*foot2meter, Vs= 7232*pound2N, linearDensity= 10.9*pound2kg)
LVLHeaderSections['5.25x9-1/4']= mat.LVL_2900Fb2E_HeaderSection('5.25x9-1/4', b= 5.25*in2meter, h= 9.25*in2meter, Ms= 18624*pound2N*foot2meter, Vs= 9227*pound2N, linearDensity= 13.9*pound2kg)
LVLHeaderSections['5.25x9-1/2']= mat.LVL_2900Fb2E_HeaderSection('5.25x9-1/2', b= 5.25*in2meter, h= 9.5*in2meter, Ms= 19586*pound2N*foot2meter, Vs= 9476*pound2N, linearDensity= 14.3*pound2kg)
LVLHeaderSections['5.25x11-1/4']= mat.LVL_2900Fb2E_HeaderSection('5.25x11-1/4', b= 5.25*in2meter, h= 11.25*in2meter, Ms= 26955*pound2N*foot2meter, Vs= 11222*pound2N, linearDensity= 16.9*pound2kg)
LVLHeaderSections['5.25x11-7/8']= mat.LVL_2900Fb2E_HeaderSection('5.25x11-7/8', b= 5.25*in2meter, h= 11.875*in2meter, Ms= 29854*pound2N*foot2meter, Vs= 11845*pound2N, linearDensity= 17.8*pound2kg)
LVLHeaderSections['5.25x14']= mat.LVL_2900Fb2E_HeaderSection('5.25x14', b= 5.25*in2meter, h= 14*in2meter, Ms= 40543*pound2N*foot2meter, Vs= 13965*pound2N, linearDensity= 21*pound2kg)
LVLHeaderSections['5.25x16']= mat.LVL_2900Fb2E_HeaderSection('5.25x16', b= 5.25*in2meter, h= 16*in2meter, Ms= 51954*pound2N*foot2meter, Vs= 15960*pound2N, linearDensity= 24*pound2kg)
LVLHeaderSections['5.25x18']= mat.LVL_2900Fb2E_HeaderSection('5.25x18', b= 5.25*in2meter, h= 18*in2meter, Ms= 64657*pound2N*foot2meter, Vs= 17955*pound2N, linearDensity= 27*pound2kg)

LVLHeaderSections['7x7-1/4']= mat.LVL_2900Fb2E_HeaderSection('7x7-1/4', b= 7*in2meter, h= 7.25*in2meter, Ms= 15673*pound2N*foot2meter, Vs= 9643*pound2N, linearDensity= 14.5*pound2kg)
LVLHeaderSections['7x9-1/4']= mat.LVL_2900Fb2E_HeaderSection('7x9-1/4', b= 7*in2meter, h= 9.25*in2meter, Ms= 24832*pound2N*foot2meter, Vs= 12303*pound2N, linearDensity= 18.5*pound2kg)
LVLHeaderSections['7x9-1/2']= mat.LVL_2900Fb2E_HeaderSection('7x9-1/2', b= 7*in2meter, h= 9.5*in2meter, Ms= 26115*pound2N*foot2meter, Vs= 12635*pound2N, linearDensity= 19*pound2kg)
LVLHeaderSections['7x11-1/4']= mat.LVL_2900Fb2E_HeaderSection('7x11-1/4', b= 7*in2meter, h= 11.25*in2meter, Ms= 35940*pound2N*foot2meter, Vs= 14963*pound2N, linearDensity= 22.5*pound2kg)
LVLHeaderSections['7x11-7/8']= mat.LVL_2900Fb2E_HeaderSection('7x11-7/8', b= 7*in2meter, h= 11.875*in2meter, Ms= 39805*pound2N*foot2meter, Vs= 15794*pound2N, linearDensity= 23.8*pound2kg)
LVLHeaderSections['7x14']= mat.LVL_2900Fb2E_HeaderSection('7x14', b= 7*in2meter, h= 14*in2meter, Ms= 54057*pound2N*foot2meter, Vs= 18620*pound2N, linearDensity= 28*pound2kg)
LVLHeaderSections['7x16']= mat.LVL_2900Fb2E_HeaderSection('7x16', b= 7*in2meter, h= 16*in2meter, Ms= 69272*pound2N*foot2meter, Vs= 21280*pound2N, linearDensity= 32*pound2kg)
LVLHeaderSections['7x18']= mat.LVL_2900Fb2E_HeaderSection('7x18', b= 7*in2meter, h= 18*in2meter, Ms= 86209*pound2N*foot2meter, Vs= 23940*pound2N, linearDensity= 36.1*pound2kg)
