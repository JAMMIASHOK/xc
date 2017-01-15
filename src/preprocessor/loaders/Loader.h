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
//Loader.h

#ifndef LOADER_H
#define LOADER_H

#include "xc_utils/src/nucleo/EntCmd.h"
#include "utility/actor/actor/MovableObject.h"
#include <map>

namespace XC {
class Domain;
class Preprocessor;
class Channel;
class FEM_ObjectBroker;

//! \ingroup Preprocessor
//
//! @defgroup Ldrs Definición del modelo.
//
//! \ingroup Ldrs
//! 
//! @brief Objetos encargado de agregar al dominio los nodos,
//! elementos, cargas, etc. leídos desde archivo.
class Loader: public EntCmd,public MovableObject
  {
  protected:
    Preprocessor *preprocessor; //!< Puntero al preprocesador.

    friend class Preprocessor;    
    void set_preprocessor(Preprocessor *preprocessor);
  public:
    Loader(Preprocessor *owr);
    ~Loader(void);
    Domain *getDomain(void) const;

    virtual int sendSelf(CommParameters &);
    virtual int recvSelf(const CommParameters &);
  };

} // end of XC namespace

#endif
