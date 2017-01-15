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
//MapUniformGrids.cc

#include "MapUniformGrids.h"
#include "preprocessor/Preprocessor.h"
#include "domain/mesh/node/Node.h"
#include "domain/mesh/element/Element.h"

#include "preprocessor/cad/entidades/Pnt.h"
#include "preprocessor/cad/entidades/UniformGrid.h"
#include "preprocessor/cad/entidades/SupCuadrilatera.h"
#include "preprocessor/set_mgmt/Set.h"



//! @brief Constructor.
XC::MapUniformGrids::MapUniformGrids(Cad *cad)
  : MapEnt<UniformGrid>(cad) {}

//! @brief Inserta la nueva linea en el conjunto total y los conjuntos abiertos.
void XC::MapUniformGrids::UpdateSets(UniformGrid *nuevo_unif_grid) const
  {
    Preprocessor *preprocessor= const_cast<Preprocessor *>(getPreprocessor());
    preprocessor->get_sets().get_set_total()->GetUniformGrids().push_back(nuevo_unif_grid);
    preprocessor->get_sets().inserta_ent_mdlr(nuevo_unif_grid);
    MapSet::map_sets &abiertos= preprocessor->get_sets().get_sets_abiertos();
    for(MapSet::map_sets::iterator i= abiertos.begin();i!= abiertos.end();i++)
      {
        Set *ptr_set= dynamic_cast<Set *>((*i).second);
        assert(ptr_set);
        ptr_set->GetUniformGrids().push_back(nuevo_unif_grid);
      }
  }

//! @brief Crea una nueva malla uniforme.
XC::UniformGrid *XC::MapUniformGrids::Nueva(void)
  {
    UniformGrid *retval= busca(getTag());
    if(!retval) //La malla es nueva.
      {
        Preprocessor *preprocessor= getPreprocessor();
        retval= new UniformGrid(preprocessor);
        (*this)[getTag()]= retval;
        UpdateSets(retval);
        tag++;
      }
    return retval;
  }
