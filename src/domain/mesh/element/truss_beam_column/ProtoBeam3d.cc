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
//ProtoBeam3d.cc

#include "ProtoBeam3d.h"

#include "material/section/elastic_section/BaseElasticSection3d.h"
#include "xc_utils/src/geom/pos_vec/Vector2d.h"

//! @brief Asigna valores a los parámetros estáticos de la sección.
void XC::ProtoBeam3d::set_material(const Material *m)
  {
    if(m)
      {
        const BaseElasticSection3d *scc= dynamic_cast<const BaseElasticSection3d *>(m);
	
        if(scc)
          ctes_scc= scc->getCrossSectionProperties();
        else
          std::cerr << "ProtoBeam3d::ProtoBeam3d -- el material no es del tipo adecuado.\n";
      }
    else
      if(verborrea>0)
        std::cerr << "ProtoBeam3d::set_material; se pasó un puntero nulo." << std::endl;
  }

//! @brief Constructor por defecto.
XC::ProtoBeam3d::ProtoBeam3d(int tag,int class_tag,const Material *m)
  :Element1D(tag,class_tag,0,0)
  { set_material(m); }

//! @brief Constructor.
XC::ProtoBeam3d::ProtoBeam3d(int tag, int class_tag, int Nd1, int Nd2)
  :Element1D(tag,class_tag,Nd1,Nd2), ctes_scc() {}

//! @brief Constructor.
XC::ProtoBeam3d::ProtoBeam3d(int tag, int class_tag, double a, double e, double g, double jx, double iy, double iz,int Nd1, int Nd2)
  :Element1D(tag,class_tag,Nd1,Nd2), ctes_scc(e,a,iz,iy,g,jx) {}

int XC::ProtoBeam3d::getNumDOF(void) const
  { return 12; }

//! @brief Send members through the channel being passed as parameter.
int XC::ProtoBeam3d::sendData(CommParameters &cp)
  {
    DbTagData &dt= getDbTagData();
    int res= Element1D::sendData(cp);
    res+= cp.sendMovable(ctes_scc,dt,CommMetaData(7));
    return res;
  }

//! @brief Receives members through the channel being passed as parameter.
int XC::ProtoBeam3d::recvData(const CommParameters &cp)
  {
    int res= Element1D::recvData(cp);
    res+= cp.receiveMovable(ctes_scc,getDbTagData(),CommMetaData(7));
    return res;
  }

//! @brief Returns the direction vector of element strong axis
//! expressed in the local coordinate system.
XC::Vector XC::ProtoBeam3d::getVDirEjeFuerteLocales(void) const
  {
    const Vector2d ejeFuerteSeccion= ctes_scc.getVDirEjeFuerte();
    Vector eF(3); eF(0)= 0.0; eF(1)= ejeFuerteSeccion.x(); eF(2)= ejeFuerteSeccion.y();
    return eF;
  }

//! @brief Returns the direction vector of element weak axis
//! expressed in the local coordinate system.
XC::Vector XC::ProtoBeam3d::getVDirEjeDebilLocales(void) const
  {
    const Vector2d ejeDebilSeccion= ctes_scc.getVDirEjeDebil();
    Vector eD(3); eD(0)= 0.0; eD(1)= ejeDebilSeccion.x(); eD(2)= ejeDebilSeccion.y();
    return eD;
  }

//! @brief Returns the angle between element strong axis
//! and local XZ plane.
double XC::ProtoBeam3d::getAnguloEjeFuerte(void) const
  {
    Vector eF= getVDirEjeFuerteLocales();
    return atan2(eF(2),eF(1));
  }

//! @brief Returns the angle between element weak axis
//! and local XZ plane.
double XC::ProtoBeam3d::getAnguloEjeDebil(void) const
  {
    Vector eD= getVDirEjeDebilLocales();
    return atan2(eD(2),eD(1));
  }
