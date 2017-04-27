//----------------------------------------------------------------------------
//  XC program; finite element analysis code
//  for structural analysis and design.
//
//  Copyright (C)  Luis Claudio Pérez Tato
//
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
//python_interface.tcc

class_<XC::ConstraintHandler, bases<XC::MovableObject,EntCmd>, boost::noncopyable >("ConstraintHandler", "ConstraintHandlers enforce the single and multi freedom constraints that exist in the domain by creating the appropriate FE_Element and DOF_Group objects.",no_init)
    ;

class_<XC::FactorsConstraintHandler, bases<XC::ConstraintHandler>, boost::noncopyable >("FactorsConstraintHandler", no_init)
    .add_property("alphaSP", &XC::FactorsConstraintHandler::getAlphaSP, &XC::FactorsConstraintHandler::setAlphaSP)
    .add_property("alphaMP", &XC::FactorsConstraintHandler::getAlphaMP, &XC::FactorsConstraintHandler::setAlphaMP)
    ;

class_<XC::PenaltyConstraintHandler, bases<XC::FactorsConstraintHandler>, boost::noncopyable >("PenaltyConstraintHandler", no_init)
    ;

class_<XC::LagrangeConstraintHandler , bases<XC::FactorsConstraintHandler>, boost::noncopyable >("LagrangeConstraintHandler", no_init);

class_<XC::PlainHandler , bases<XC::ConstraintHandler>, boost::noncopyable >("PlainHandler", no_init);

class_<XC::TransformationConstraintHandler , bases<XC::ConstraintHandler>, boost::noncopyable >("TransformationConstraintHandler", no_init);

