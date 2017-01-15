//----------------------------------------------------------------------------
//  XC program; finite element analysis code
//  for structural analysis and design.
//
//  Copyright (C)  Luis Claudio Pérez Tato
//
//  This program derives from OpenSees <http://opensees.berkeley.edu>
//  developed by the  «Pacific earthquake engineering research center».
//
//  Except for the restrictions that may arise from the copyright
//  of the original program (see copyright_opensees.txt)
//  XC is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or 
//  (at your option) any later version.
//
//  This software is distributed in the hope that it will be useful, but 
//  WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details. 
//
//
// You should have received a copy of the GNU General Public License 
// along with this program.
// If not, see <http://www.gnu.org/licenses/>.
//----------------------------------------------------------------------------
/* ****************************************************************** **
**    OpenSees - Open System for Earthquake Engineering Simulation    **
**          Pacific Earthquake Engineering Research Center            **
**                                                                    **
**                                                                    **
** (C) Copyright 1999, The Regents of the University of California    **
** All Rights Reserved.                                               **
**                                                                    **
** Commercial use of this program without express permission of the   **
** University of California, Berkeley, is strictly prohibited.  See   **
** file 'COPYRIGHT'  in main directory for information on usage and   **
** redistribution,  and for a DISCLAIMER OF ALL WARRANTIES.           **
**                                                                    **
** Developed by:                                                      **
**   Frank McKenna (fmckenna@ce.berkeley.edu)                         **
**   Gregory L. Fenves (fenves@ce.berkeley.edu)                       **
**   Filip C. Filippou (filippou@ce.berkeley.edu)                     **
**                                                                    **
** ****************************************************************** */
                                                                        
// $Revision: 1.1 $
// $Date: 2002/10/29 20:26:23 $
// $Source: /usr/local/cvs/OpenSees/SRC/material/nD/feap/FeapMaterial03.cpp,v $
                                                                      
// Written: MHS
// Created: June 2001
//
// Description: This file contains the class definition for 
// FeapMaterial03.

#include <material/nD/feap/FeapMaterial03.h>
#include <utility/matrix/Vector.h>

XC::FeapMaterial03::FeapMaterial03(int tag,
			       double K, double G, double sigY, double Hiso):
  // 7 history variables and 4 material parameters
    FeapMaterial(tag, ND_TAG_FeapMaterial03, 7, 4)
{
  ud[0] = K;
  ud[1] = G;
  ud[2] = sigY;
  ud[3] = Hiso;
}

XC::FeapMaterial03::FeapMaterial03(void):
  FeapMaterial(0, ND_TAG_FeapMaterial03, 7, 4)
{
  // Does nothing
}

int
XC::FeapMaterial03::fillDArray(void)
{
  // Look in FEAP programmer's manual
  
  return 0;
}
