//----------------------------------------------------------------------------
//  programa XC; cálculo mediante el método de los elementos finitos orientado
//  a la solución de problemas estructurales.
//
//  Copyright (C)  Luis Claudio Pérez Tato
//
//  El programa deriva del denominado OpenSees <http://opensees.berkeley.edu>
//  desarrollado por el «Pacific earthquake engineering research center».
//
//  Salvo las restricciones que puedan derivarse del copyright del
//  programa original (ver archivo copyright_opensees.txt) este
//  software es libre: usted puede redistribuirlo y/o modificarlo 
//  bajo los términos de la Licencia Pública General GNU publicada 
//  por la Fundación para el Software Libre, ya sea la versión 3 
//  de la Licencia, o (a su elección) cualquier versión posterior.
//
//  Este software se distribuye con la esperanza de que sea útil, pero 
//  SIN GARANTÍA ALGUNA; ni siquiera la garantía implícita
//  MERCANTIL o de APTITUD PARA UN PROPÓSITO DETERMINADO. 
//  Consulte los detalles de la Licencia Pública General GNU para obtener 
//  una información más detallada. 
//
// Debería haber recibido una copia de la Licencia Pública General GNU 
// junto a este programa. 
// En caso contrario, consulte <http://www.gnu.org/licenses/>.
//----------------------------------------------------------------------------
//SetFilaK.h

#ifndef SETFILAK_H
#define SETFILAK_H

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
//!  Un objeto SetFilaK contiene un conjunto de 0 o más:
//!  - Nodos.
//!  - Elementos finitos.
//!  que corresponden a una fila_k de un objeto EntMdlr.
class SetFilaK: public SetFila<TritrizPtrNod::var_ref_fila_k,TritrizPtrElem::var_ref_fila_k>
  {
  public:
    typedef TritrizPtrNod::var_ref_fila_k tfilanod;
    typedef TritrizPtrElem::var_ref_fila_k tfilaelem;
    SetFilaK(EntMdlr &e,const size_t &f=1,const size_t &c=1,const std::string &nmb="",Preprocessor *preprocessor= NULL);
    SetFilaK(EntMdlr &e,const size_t &capa,const size_t &f,const RangoIndice &,const std::string &nmb="",Preprocessor *preprocessor=NULL);
  };
} //end of XC namespace
#endif
