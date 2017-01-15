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
//LoadLoaderMember.h

#ifndef LOADLOADERMEMBER_H
#define LOADLOADERMEMBER_H

#include "xc_utils/src/nucleo/EntCmd.h"
#include "utility/actor/actor/MovableObject.h"

namespace XC {
class LoadLoader;
class Domain;

//! \ingroup Ldrs
//! 
//! @brief ??.
class LoadLoaderMember: public EntCmd, public MovableObject
  {
  public:
    LoadLoaderMember(LoadLoader *owr);
    const LoadLoader *getLoadLoader(void) const;
    LoadLoader *getLoadLoader(void);
    Domain *getDomain(void) const;
    int &getTagLP(void);
    const int &getTagLP(void) const;
  };



} // end of XC namespace

#endif
