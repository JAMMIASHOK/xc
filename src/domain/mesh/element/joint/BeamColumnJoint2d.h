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
/* ****************************************************************** **
**    OpenSees - Open System for Earthquake Engineering Simulation    **
**          Pacific Earthquake Engineering Research Center            **
**                                                                    **
**                                                                    **
** (C) Copyright 1999, The Regents of the University of California    **
** All Rights Reserved.                                               **
**                                                                    **
** Commercial use of this program without express permission of the   **
** University of California, Berkeley, is strictly prohibited.  See   **
** file 'COPYRIGHT'  in main directory for information on usage and   **
** redistribution,  and for a DISCLAIMER OF ALL WARRANTIES.           **
**                                                                    **
** Developed by:                                                      **
**   Frank McKenna (fmckenna@ce.berkeley.edu)                         **
**   Gregory L. Fenves (fenves@ce.berkeley.edu)                       **
**   Filip C. Filippou (filippou@ce.berkeley.edu)                     **
**                                                                    **
** ****************************************************************** */
                                                                        
// $Revision: 1.2 $
// $Date: 2004/10/06 19:21:45 $
// $Source: /usr/local/cvs/OpenSees/SRC/element/joint/BeamColumnJoint2d.h,v $
                                                                        
// Written: NM (nmitra@u.washington.edu)
// Created: April 2002
// Revised: August 2004
//
// Description: This file contains the class defination for beam-column joint.
// This element is a 4 noded 12 dof (3 dof at each node) finite area super-element introduced by
// Prof. Lowes and Arash. The element takes in 13 different material types in order to simulate
// the inelastic action observed in a reinforced beam column joint.
// Updates: Several concerning Joint formulation (presently a revised formulation for joints)
                                                                        
#ifndef BeamColumnJoint2d_h
#define BeamColumnJoint2d_h

#include <domain/mesh/element/ElemWithMaterial.h>
#include "domain/mesh/element/physical_properties/BeamColumnJointPhysicalProperties.h"
#include <utility/matrix/Matrix.h>
#include <utility/matrix/Vector.h>

namespace XC {
class Node;
class Channel;
class FEM_ObjectBroker;
class Response;
class Renderer;
class UniaxialMaterial;

//! \ingroup ElemJoint
//
//! @brief Elemento conexión viga-columna, para probleas bidimensionales.
class BeamColumnJoint2d : public ElemWithMaterial<4,BeamColumnJointPhysicalProperties>
  {
  private:
  
    // private methods
    void getGlobalDispls(Vector&) ;
    void getBCJoint(void);
    void getdg_df(void);
    void getdDef_du(void);
    void matDiag(Vector, Matrix&);
    void getMatResponse(Vector, Vector&, Vector&);
    void formR(Vector);
    void formK(Vector);
    double getStepSize(double,double,Vector,Vector,Vector,Vector,double);
  
    int nodeDbTag, dofDbTag;
  
    // various other element parameters
    double elemActHeight;
    double elemActWidth;
    double elemWidth;
    double elemHeight;
    double HgtFac; //!< distance in between the tension compression couple in the height direction 
    double WdtFac; //!< distance in between the tension compression couple in the width direction      
  
    Vector Uecommit; //!< vector of external commited displacements
    Vector UeIntcommit; //!< vector of internal commited displacements   
    Vector UeprCommit; //!< vector of previous external committed displacements
    Vector UeprIntCommit; //!< vector of previous internal committed displacements  
    Matrix BCJoint; //!< matrix describing relation between the component deformations and the external and internal deformations
    Matrix dg_df; //!< matrix of derivative of internal equilibrium 
    Matrix dDef_du; //!< matrix of a portion of BCJoint reqd. for static condensation
  
    mutable Matrix K; //!< element stiffness matrix
    mutable Vector R; //!< element residual matrix  
  public:
    // default constructor
    BeamColumnJoint2d(void); 
    // defined constructor
    BeamColumnJoint2d(int tag,int Nd1, int Nd2, int Nd3, int Nd4, const UniaxialMaterial &theMat1, const UniaxialMaterial &theMat2, const UniaxialMaterial &theMat3, const UniaxialMaterial &theMat4, const UniaxialMaterial &theMat5, const UniaxialMaterial &theMat6, const UniaxialMaterial &theMat7, const UniaxialMaterial &theMat8, const UniaxialMaterial &theMat9, const UniaxialMaterial &theMat10, const UniaxialMaterial &theMat11, const UniaxialMaterial &theMat12, const UniaxialMaterial &theMat13);
  
    BeamColumnJoint2d(int tag,int Nd1, int Nd2, int Nd3, int Nd4, const UniaxialMaterial &theMat1, const UniaxialMaterial &theMat2, const UniaxialMaterial &theMat3, const UniaxialMaterial &theMat4, const UniaxialMaterial &theMat5, const UniaxialMaterial &theMat6, const UniaxialMaterial &theMat7, const UniaxialMaterial &theMat8, const UniaxialMaterial &theMat9, const UniaxialMaterial &theMat10, const UniaxialMaterial &theMat11, const UniaxialMaterial &theMat12, const UniaxialMaterial &theMat13, double Hgtfac, double Wdtfac);
    Element *getCopy(void) const;

  ////////////// public methods to obtain information about dof & connectivity    
  bool	isSubdomain(void) { return false; } ;
  
  // return number of DOFs
  int getNumDOF(void) const;	
  
  // set domain performs check on dof and associativity with node
  void setDomain(Domain *theDomain);
  
  //////////////////////////// public methods to set the state of the element    
  
  // commit state
  int commitState(void);
  
  // revert to last commit
  int revertToLastCommit(void);        
  
  // revert to start
  int revertToStart(void);        
  
  // determine current strain and set strain in material
  int update(void);
  
  //////////////////////// public methods to obtain stiffness, mass, damping and 
  ////////////////////////////////////// residual information    
  
  // returns converged tangent stiffness matrix
  const Matrix &getTangentStiff(void) const;
  const Matrix &getInitialStiff(void) const;   
  
  // not required for this element formulation
  const Matrix &getDamp(void) const;
  const Matrix &getMass(void) const;
  
  // not required for this element formulation
  int addLoad(ElementalLoad *theLoad, double loadFactor);
  int addInertiaLoadToUnbalance(const Vector &accel);
  
  // get converged residual
  const Vector &getResistingForce(void) const;
  
  // get converged residual with inertia terms
  const Vector &getResistingForceIncInertia(void) const;            
  
  // public methods for element output for parallel and database processing
  int sendSelf(CommParameters &);
  int recvSelf(const CommParameters &);
  
  // print out element data
  void Print(std::ostream &s, int flag =0);    
  
  // implemented to print into file
  Response *setResponse(const std::vector<std::string> &argv, Information &eleInfo);
  int getResponse(int responseID, Information &eleInformation);
  
  int setParameter(const std::vector<std::string> &argv, Parameter &param);
  int updateParameter (int parameterID, Information &info);
  
  
};
} // end of XC namespace

#endif
