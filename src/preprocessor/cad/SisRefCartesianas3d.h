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
//SisRefCartesianas3d.h
//Sistema de coordenadas cartesianas.

#ifndef SISREFCARTESIANAS3D_H
#define SISREFCARTESIANAS3D_H

#include "SisRef.h"
#include "xc_utils/src/geom/sis_ref/Ref3d3d.h"

namespace XC {

//! @ingroup CadSR
//!
//! @brief Sistema de coordenadas cartesianas tridimensional.
class SisRefCartesianas3d: public SisRef
  {
    Ref3d3d ref;//!< Sistema de referencia.
  protected:

  public:
    //! @brief Constructor.
    SisRefCartesianas3d(Preprocessor *m)
      : SisRef(m) {}
    SisRefCartesianas3d(const std::string &nombre= "",Preprocessor *m= NULL)
      : SisRef(nombre,m) {}

    Vector3d GetVDirEje(const size_t &,const Pos3d &) const;

    Pos3d getOrg(void) const;
    void setOrg(const Pos3d &);
    void TresPuntos(const Pos3d &,const Pos3d &, const Pos3d &);

    Pos3d GetPosGlobal(const Pos3d &p) const;
    Vector3d GetCooGlobales(const Vector3d &v) const;
    Pos3d GetPosLocal(const Pos3d &p) const;
    Vector3d GetCooLocales(const Vector3d &v) const;


  };

} //end of XC namespace

#endif
