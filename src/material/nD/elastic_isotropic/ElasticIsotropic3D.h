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
//===============================================================================
//# COPYRIGHT (C): Woody's license (by BJ):
//                 ``This    source  code is Copyrighted in
//                 U.S.,  for  an  indefinite  period,  and anybody
//                 caught  using it without our permission, will be
//                 mighty good friends of ourn, cause we don't give
//                 a  darn.  Hack it. Compile it. Debug it. Run it.
//                 Yodel  it.  Enjoy it. We wrote it, that's all we
//                 wanted to do.''
//
//# PROJECT:           Object Oriented Finite Element Program
//# PURPOSE:           Elastic Isotropic Material implementation:
//# CLASS:             ElasticIsotropic3D
//#
//# VERSION:           0.61803398874989 (golden section)
//# LANGUAGE:          C++
//# TARGET OS:         all...
//# DESIGN:            Zhaohui Yang, Boris Jeremic (jeremic@ucdavis.edu)
//# PROGRAMMER(S):     Zhaohui Yang, Boris Jeremic
//#
//#
//# DATE:              10Oct2000
//# UPDATE HISTORY:    22Nov2002 small fixes 
//#
//#
//===============================================================================
                                                                        
                                                                        
#ifndef ElasticIsotropic3D_h
#define ElasticIsotropic3D_h
	 
#include <material/nD/ElasticIsotropicMaterial.h>

#include <utility/matrix/nDarray/straint.h>
#include <utility/matrix/nDarray/stresst.h>
#include <utility/matrix/nDarray/Tensor.h>


namespace XC {
//! @ingroup NDMat
//
//! @brief Material elásticos e isótropos para problemas tridimensionales.
class ElasticIsotropic3D : public ElasticIsotropicMaterial
  {
  private:
    static Vector sigma;        // Stress vector
    static Matrix D;            // Elastic constantsVector sigma;

    mutable Tensor *Dt;			// Elastic constants tensor
    static stresstensor Stress;	// Stress tensor    
    straintensor Strain;	// Strain tensor    
  public:
    ElasticIsotropic3D(int tag, double E, double nu, double rho);
    ElasticIsotropic3D(int tag);
    ElasticIsotropic3D(void);
    ~ElasticIsotropic3D(void);

    int setTrialStrainIncr(const Vector &v);
    int setTrialStrainIncr(const Vector &v, const Vector &r);
    const Matrix &getTangent(void) const;
    const Matrix &getInitialTangent(void) const;

    const Vector &getStress(void) const;
    
    int setTrialStrain(const Tensor &v);
    int setTrialStrain(const Tensor &v, const Tensor &r);
    int setTrialStrainIncr(const Tensor &v);
    int setTrialStrainIncr(const Tensor &v, const Tensor &r);
    const Tensor &getTangentTensor (void) const;
    const stresstensor &getStressTensor(void) const;
    const straintensor &getStrainTensor(void) const;
    const straintensor &getPlasticStrainTensor(void) const;

    int commitState (void);
    int revertToLastCommit (void);
    int revertToStart (void);
    
    NDMaterial *getCopy(void) const;
    const std::string &getType(void) const;
    int getOrder(void) const;

    void Print(std::ostream &s, int flag =0);
    void setInitElasticStiffness(void) const;
  };
} // end of XC namespace


#endif


