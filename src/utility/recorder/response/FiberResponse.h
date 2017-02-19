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
                                                                        
// $Revision: 1.3 $
// $Date: 2001/07/31 18:26:59 $
// $Source: /usr/local/cvs/OpenSees/SRC/recorder/response/FiberResponse.h,v $
                                                                        
// Written: MHS 
// Created: Oct 2000
//
// Description: This file contains the FiberResponse class interface

#ifndef FiberResponse_h
#define FiberResponse_h

#include <utility/recorder/response/Response.h>

namespace XC {
class Fiber;

//! @ingroup Recorder
//
//! @brief Recorder for fiber response.
class FiberResponse : public Response
  {
  private:
   Fiber *theFiber;
   int responseID;
public:
	FiberResponse(Fiber *fib, int id);
	FiberResponse(Fiber *fib, int id, int val);
	FiberResponse(Fiber *fib, int id, double val);
	FiberResponse(Fiber *fib, int id, const ID &val);
	FiberResponse(Fiber *fib, int id, const Vector &val);
	FiberResponse(Fiber *fib, int id, const Matrix &val);
	FiberResponse(Fiber *fib, int id, const BJtensor &val);
    int getResponse(void);
  };
} // end of XC namespace

#endif
