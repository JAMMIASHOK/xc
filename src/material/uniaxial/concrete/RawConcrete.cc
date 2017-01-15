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
//RawConcrete.cpp

#include <material/uniaxial/concrete/RawConcrete.h>
#include <utility/matrix/Vector.h>
#include <utility/matrix/Matrix.h>

#include <domain/mesh/element/Information.h>
#include <cmath>
#include <cfloat>


//! @brief Constructor.
XC::RawConcrete::RawConcrete(int tag, int classTag, double FPC, double EPSC0, double EPSCU)
  :UniaxialMaterial(tag, classTag), fpc(FPC), epsc0(EPSC0), epscu(EPSCU) {}

//! @brief Constructor
XC::RawConcrete::RawConcrete(int tag, int classTag)
  :UniaxialMaterial(tag, classTag), fpc(0.0), epsc0(0.0), epscu(0.0) {}

void XC::RawConcrete::setFpc(const double &d)
  {
    fpc= d;
    if(fpc > 0.0)
      {
        fpc= -fpc;
        std::clog << "!Ojo!, los parámetros del hormigón deben ser negativos." << std::endl;
      }
    setup_parameters();
  }

double XC::RawConcrete::getFpc(void) const
  { return fpc; }

void XC::RawConcrete::setEpsc0(const double &d)
  {
    epsc0= d;
    if(epsc0 > 0.0)
      {
        epsc0= -epsc0;
        std::clog << "!Ojo!, los parámetros del hormigón deben ser negativos." << std::endl;
      }
    setup_parameters();
  }

double XC::RawConcrete::getEpsc0(void) const
  { return epsc0; }

void XC::RawConcrete::setEpscu(const double &d)
  {
    epscu= d;
    if(epscu > 0.0)
      {
        epscu= -epscu;
        std::clog << "!Ojo!, los parámetros del hormigón deben ser negativos." << std::endl;
      }
  }

double XC::RawConcrete::getEpscu(void) const
  { return epscu; }

