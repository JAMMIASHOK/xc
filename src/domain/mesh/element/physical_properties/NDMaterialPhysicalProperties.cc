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
//NDMaterialPhysicalProperties.cc

#include "NDMaterialPhysicalProperties.h"
#include "utility/matrix/Matrix.h"

//! @brief Constructor.
XC::NDMaterialPhysicalProperties::NDMaterialPhysicalProperties(const size_t &nMat,const NDMaterial *ptr_mat)
  :PhysicalProperties<NDMaterial>(nMat,ptr_mat) {}

//! @brief Constructor.
XC::NDMaterialPhysicalProperties::NDMaterialPhysicalProperties(const size_t &nMat, NDMaterial &theMat,const std::string &type ) 
  : PhysicalProperties<NDMaterial>(nMat,nullptr)
  {
    if(check_material_type(type))
      theMaterial.setMaterial(&theMat,type);
  }

//! @brief Comprueba el tipo de material, DEBE redefinirse en las clases derivadas.
bool XC::NDMaterialPhysicalProperties::check_material_type(const std::string &type) const
  {
    std::cerr << "Error; se debe redefinir check_material_type en la clase: " << nombre_clase() << std::endl;
    return false;
  }

bool XC::NDMaterialPhysicalProperties::check_material_elast_plana(const std::string &type)
  {
    if((type!="PlaneStrain") && (type!="PlaneStress")
      && (type!="PlaneStrain2D") && (type!="PlaneStress2D"))
       {
         std::cerr << "XC::SolidMech2D::SolidMech2D -- improper material type " << type << " for XC::SolidMech2D\n";
         return false;
       }
    else
      return true;
  }

//! @brief devuelve los vectores con la deformación de cada uno de los
//! puntos de Gauss.
XC::Matrix XC::NDMaterialPhysicalProperties::getCommittedStrain(void) const
  {
    const size_t nfilas= theMaterial.size();
    std::vector<Vector> strains(nfilas);
    for(size_t i= 0;i<nfilas;i++)
      strains[i]= getCommittedStrain(i);
    const size_t ncols= strains[0].Size();
    Matrix retval(nfilas,ncols);
    for(size_t i= 0;i<nfilas;i++)
      for(size_t j= 0;j<ncols;j++)
        retval(i,j)= strains[i](j);
    return retval;
  }   

//! @brief devuelve los vectores con la deformación de cada uno de los
//! puntos de Gauss.
XC::Matrix XC::NDMaterialPhysicalProperties::getCommittedStress(void) const
  {
    const size_t nfilas= theMaterial.size();
    std::vector<Vector> stresses(nfilas);
    for(size_t i= 0;i<nfilas;i++)
      stresses[i]= getCommittedStress(i);
    const size_t ncols= stresses[0].Size();
    Matrix retval(nfilas,ncols);
    for(size_t i= 0;i<nfilas;i++)
      for(size_t j= 0;j<ncols;j++)
        retval(i,j)= stresses[i](j);
    return retval;
  }   


//! @brief Devuelve la tensión media en el elemento.
XC::Vector XC::NDMaterialPhysicalProperties::getCommittedAvgStress(void) const
  {
    const size_t numMaterials= theMaterial.size();
    Vector retval= theMaterial[0]->getCommittedStress();
    for(size_t i=1; i<numMaterials; i++)
      retval+= theMaterial[i]->getCommittedStress();
    retval/= numMaterials;
    return retval;
  }

//! @brief Devuelve la tensión media en el elemento.
XC::Vector XC::NDMaterialPhysicalProperties::getCommittedAvgStrain(void) const
  {
    const size_t numMaterials= theMaterial.size();
    Vector retval= theMaterial[0]->getCommittedStrain();
    for(size_t i=1; i<numMaterials; i++)
      retval+= theMaterial[i]->getCommittedStrain();
    retval/= numMaterials;
    return retval;
  }

//! @brief Devuelve la componente iComp de la tensión media en el elemento.
double XC::NDMaterialPhysicalProperties::getCommittedAvgStress(const size_t &iComp) const
  {
    const size_t numMaterials= theMaterial.size();
    double retval(0.0);
    for(size_t i=0; i<numMaterials; i++)
      retval+= theMaterial[i]->getCommittedStress()[iComp];
    retval/= numMaterials;
    return retval;
  }

//! @brief Devuelve la componente iComp de la deformación media en el elemento.
double XC::NDMaterialPhysicalProperties::getCommittedAvgStrain(const size_t &iComp) const
  {
    const size_t numMaterials= theMaterial.size();
    double retval(0.0);
    for(size_t i=0; i<numMaterials; i++)
      retval+= theMaterial[i]->getCommittedStrain()[iComp];
    retval/= numMaterials;
    return retval;
  }

// check to see if have mass
bool XC::NDMaterialPhysicalProperties::haveRho(void) const
  {
    const size_t numMaterials= theMaterial.size();
    bool retval= false;
    for(size_t i=0; i<numMaterials; i++)
      {
        if(theMaterial[i]->getRho() != 0.0)
	  {
	    retval= true;
            break;
          }
      }
    return retval;
  }

//! @brief Returns densities for each position.
XC::Vector XC::NDMaterialPhysicalProperties::getRhoi(const double &rhoDefault) const
  {
    const size_t numMaterials= theMaterial.size();
    Vector retval(numMaterials);
    for(size_t i=0; i<numMaterials; i++)
      {
        retval[i]= theMaterial[i]->getRho();
        if(retval[i] == 0.0)
          { retval[i] = rhoDefault; }
      }
    return retval;
  }
