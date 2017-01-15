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
                                                                        
// $Revision: 1.1.1.1 $
// $Date: 2000/09/15 08:23:19 $
// $Source: /usr/local/cvs/OpenSees/SRC/domain/load/Load.h,v $
                                                                        
                                                                        
#ifndef Load_h
#define Load_h

// File: ~/domain/load/Load.h
//
// Written: fmk 
// Created: 11/96
// Revision: A
//
// Purpose: This file contains the class definition for Load.
// Load is an abstract class. A Load object is used to add load
// to the model. 
//
// What: "@(#) Load.h, revA"

#include <domain/component/DomainComponent.h>

namespace XC {

//! \ingroup Dom
//!
//!
//! @defgroup Loads Condiciones de contorno en fuerzas.
//
//! @ingroup Loads
//
//! @brief Carga sobre nodos o elementos (clase base abstracta).
class Load: public DomainComponent
  {
  private:
    int loadPatternTag; //!< Identificador de la hipótesis a la que pertenece la carga.
  protected:
    int sendData(CommParameters &cp);
    int recvData(const CommParameters &cp);

  public:
    Load(int tag, int classTag);

    // pure virtual functions
    virtual void applyLoad(double loadfactor) =0;
    
    virtual void setLoadPatternTag(int loadPaternTag);
    virtual int  getLoadPatternTag(void) const;

  };
} // end of XC namespace

#endif
