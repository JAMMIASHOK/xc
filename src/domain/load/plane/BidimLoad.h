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
//BidimLoad.h
                                                                        
#ifndef BidimLoad_h
#define BidimLoad_h


#include <domain/load/ElementBodyLoad.h>

namespace XC {

//! @ingroup ElemLoads
//
//! @brief Carga sobre elementos bidimensionales.
class BidimLoad : public ElementBodyLoad
  {
  protected:
    bool procesa_comando(CmdStatus &status);
  public:
    BidimLoad(int tag, int classTag,const ID &theElementTags);
    BidimLoad(int tag, int classTag);

    virtual std::string Categoria(void) const;

    void Print(std::ostream &s, int flag =0) const;
    any_const_ptr GetProp(const std::string &cod) const;
  };
} // end of XC namespace

#endif

