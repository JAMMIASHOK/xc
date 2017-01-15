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
//SisRefSccCartesianas2d.h
//Sistema de coordenadas cartesianas.

#ifndef SISREFSCCCARTESIANAS2D_H
#define SISREFSCCCARTESIANAS2D_H

#include "SisRefScc.h"
#include "xc_utils/src/geom/sis_ref/Ref2d2d.h"

namespace XC {

//! @ingroup MATSCCEntGeom
//
//! @brief Sistema de referencia bidimensional para una sección.
class SisRefSccCartesianas2d: public SisRefScc
  {
    Ref2d2d ref;//!< Sistema de referencia.
  protected:

  public:
    //! @brief Constructor.
    SisRefSccCartesianas2d(GeomSection *m)
      : SisRefScc(m) {}
    SisRefSccCartesianas2d(const std::string &nombre= "",GeomSection *m= NULL)
      : SisRefScc(nombre,m) {}

    Vector2d GetVDirEje(const size_t &,const Pos2d &) const;


    Pos2d GetPosGlobal(const Pos2d &p) const;
    Vector2d GetCooGlobales(const Vector2d &v) const;
    Pos2d GetPosLocal(const Pos2d &p) const;
    Vector2d GetCooLocales(const Vector2d &v) const;


  };

} //end of XC namespace

#endif
