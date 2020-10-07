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

class_<XC::J2Plasticity, bases<XC::NDMaterial>, boost::noncopyable >("J2Plasticity", no_init)
  ;

class_<XC::J2AxiSymm, bases<XC::J2Plasticity>, boost::noncopyable >("J2AxiSymm", no_init)
  ;

class_<XC::J2PlaneStrain , bases<XC::J2Plasticity>, boost::noncopyable >("J2PlaneStrain", no_init)
  ;

class_<XC::J2PlaneStress, bases<XC::J2Plasticity>, boost::noncopyable >("J2PlaneStress", no_init);

class_<XC::J2PlateFiber , bases<XC::J2Plasticity>, boost::noncopyable >("J2PlateFiber", no_init);

class_<XC::J2ThreeDimensional , bases<XC::J2Plasticity>, boost::noncopyable >("J2ThreeDimensional", no_init);
