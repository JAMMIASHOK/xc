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
//BrickBase.h
                                                                        
#ifndef BrickBase_h
#define BrickBase_h

#include <domain/mesh/element/ElemWithMaterial.h>
#include "domain/mesh/element/physical_properties/NDMaterialPhysicalProperties.h"

namespace XC {
class NDMaterial;

//! \ingroup Elem
//
//! @defgroup ElemVol Elementos para el análisis de sólidos.
//!
//! \ingroup ElemVol
//
//! @brief Clase base para los hexaedros.
class BrickBase : public ElemWithMaterial<8,NDMaterialPhysicalProperties>
  {
  protected:
    TritrizPtrElem coloca_en_malla(const TritrizPtrNod &,dir_mallado dm) const;
  public:
    BrickBase(int classTag);
    BrickBase(int tag,int classTag,const NDMaterialPhysicalProperties &);
    BrickBase(int tag, int classTag,int nd1, int nd2, int nd3, int nd4,int nd5,int nd6,int nd7,int nd8, const NDMaterialPhysicalProperties &);
    size_t getDimension(void) const;
  };

} // end of XC namespace
#endif
