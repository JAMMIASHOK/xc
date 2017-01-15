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
//SetFilaI.h

#ifndef SETFILAI_H
#define SETFILAI_H

#include "SetFila.h"
#include "preprocessor/cad/matrices/TritrizPtrNod.h"
#include "preprocessor/cad/matrices/TritrizPtrElem.h"

class RangoIndice;

namespace XC {

class EntMdlr;

//!  \ingroup Set
//! 
//!  \brief Conjunto de objetos.
//! 
//!  Un objeto SetFilaI contiene un conjunto de 0 o más:
//!  - Nodos.
//!  - Elementos finitos.
//!  que corresponden a una fila_i de un objeto EntMdlr.
class SetFilaI: public SetFila<TritrizPtrNod::var_ref_fila_i,TritrizPtrElem::var_ref_fila_i>
  {
  public:
    typedef TritrizPtrNod::var_ref_fila_i tfilanod;
    typedef TritrizPtrElem::var_ref_fila_i tfilaelem;
    SetFilaI(EntMdlr &e,const size_t &f=1,const size_t &c=1,const std::string &nmb="",Preprocessor *preprocessor= NULL);
    SetFilaI(EntMdlr &e,const RangoIndice &rango_capas,const size_t &f,const size_t &c,const std::string &nmb="",Preprocessor *preprocessor= NULL);
  };
} //end of XC namespace
#endif
