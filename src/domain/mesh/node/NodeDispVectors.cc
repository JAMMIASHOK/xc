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
//NodeDispVectors.cpp

#include <domain/mesh/node/NodeDispVectors.h>
#include <utility/tagged/TaggedObject.h>
#include <utility/matrix/Vector.h>



void XC::NodeDispVectors::libera(void)
  {
    NodeVectors::libera();
    // delete anything that we created with new
    if(incrDisp) delete incrDisp;
    incrDisp= nullptr;
    if(incrDeltaDisp) delete incrDeltaDisp;
    incrDeltaDisp= nullptr;
  }

//! @brief Constructor.
XC::NodeDispVectors::NodeDispVectors(void)
  :NodeVectors(4),incrDisp(nullptr),incrDeltaDisp(nullptr) {}


//! @brief Constructor de copia.
XC::NodeDispVectors::NodeDispVectors(const NodeDispVectors &otro)
  : NodeVectors(otro), incrDisp(nullptr), incrDeltaDisp(nullptr)
  { copia(otro); }

XC::NodeDispVectors &XC::NodeDispVectors::operator=(const NodeDispVectors &otro)
  {
    NodeVectors::operator=(otro);
    return *this;
  }

//! @brief destructor
XC::NodeDispVectors::~NodeDispVectors(void)
  { libera(); }


const XC::Vector &XC::NodeDispVectors::getIncrDisp(const size_t &nDOF) const
  {
    if(!incrDisp)
      {
        NodeDispVectors *this_no_const= const_cast<NodeDispVectors *>(this);
        if(this_no_const->createDisp(nDOF) < 0)
          {
            std::cerr << "FATAL NodeDispVectors::getTrialDisp() -- ran out of memory\n";
            exit(-1);
          }
      }
    return *incrDisp;
  }

const XC::Vector &XC::NodeDispVectors::getIncrDeltaDisp(const size_t &nDOF) const
  {
    if(!incrDeltaDisp)
      {
        NodeDispVectors *this_no_const= const_cast<NodeDispVectors *>(this);
        if(this_no_const->createDisp(nDOF) < 0)
          {
            std::cerr << "FATAL NodeDispVectors::getTrialDisp() -- ran out of memory\n";
            exit(-1);
          }
      }
    return *incrDeltaDisp;
  }


int XC::NodeDispVectors::setTrialDispComponent(const size_t &nDOF,const double &value,const size_t &dof)
  {
    // check vector arg is of correct size
    if(dof < 0 || dof >= nDOF)
      {
        std::cerr << "WARNING NodeDispVectors::setTrialDispComponent() - incompatible sizes\n";
        return -2;
      }

    // construct memory and Vectors for trial and committed
    // accel on first call to this method, getTrialDisp(),
    // getDisp(), or incrTrialDisp()
    if(!trialData)
      {
        if(this->createDisp(nDOF) < 0)
          {
            std::cerr << "FATAL NodeDispVectors::setTrialDispComponent() - ran out of memory\n";
            exit(-1);
          }
      }

    // perform the assignment .. we dont't go through Vector interface
    // as we are sure of size and this way is quicker
    const double tDisp = value;
    data[dof+2*nDOF]= tDisp - data[dof+nDOF];
    data[dof+3*nDOF]= tDisp - data[dof];
    data[dof]= tDisp;

    return 0;
  }

int XC::NodeDispVectors::setTrialDisp(const size_t &nDOF,const Vector &newTrialDisp)
  {
    // check vector arg is of correct size
    if(size_t(newTrialDisp.Size()) != nDOF)
      {
        std::cerr << "WARNING NodeDispVectors::setTrialDisp() - incompatible sizes\n";
        return -2;
      }

    // construct memory and Vectors for trial and committed
    // accel on first call to this method, getTrialDisp(),
    // getDisp(), or incrTrialDisp()
    if(!trialData)
      {
        if(this->createDisp(nDOF) < 0)
          {
            std::cerr << "FATAL NodeDispVectors::setTrialDisp() - ran out of memory\n";
            exit(-1);
          }
      }

    // perform the assignment .. we dont't go through Vector interface
    // as we are sure of size and this way is quicker
    for(size_t i=0;i<nDOF;i++)
      {
        const double tDisp = newTrialDisp(i);
        data[i+2*nDOF]= tDisp - data[i+nDOF];
        data[i+3*nDOF]= tDisp - data[i];
        data[i] = tDisp;
      }
    return 0;
  }


int XC::NodeDispVectors::incrTrialDisp(const size_t &nDOF,const XC::Vector &incrDispl)
  {
    // check vector arg is of correct size
    if(size_t(incrDispl.Size()) != nDOF)
      {
        std::cerr << "WARNING NodeDispVectors::incrTrialDisp() - incompatable sizes\n";
        return -2;
      }

    // create a copy if no trial exists andd add committed
    if(!trialData)
      {
        if(this->createDisp(nDOF) < 0)
          {
            std::cerr << "FATAL NodeDispVectors::incrTrialDisp() - ran out of memory\n";
            exit(-1);
          }
        for(size_t i=0;i<nDOF;i++)
          {
            double incrDispI = incrDispl(i);
            data[i]= incrDispI;
            data[i+2*nDOF]= incrDispI;
            data[i+3*nDOF]= incrDispI;
          }
        return 0;
      }

    // otherwise set trial = incr + trial
    for(size_t i= 0;i<nDOF;i++)
      {
        double incrDispI = incrDispl(i);
        data[i]+= incrDispI;
        data[i+2*nDOF]+= incrDispI;
        data[i+3*nDOF]= incrDispI;
      }
    return 0;
  }

int XC::NodeDispVectors::commitState(const size_t &nDOF)
  {
    // check disp exists, if does set commit = trial, incr = 0.0
    if(trialData)
      {
        for(size_t i=0; i<nDOF; i++)
          {
            data[i+nDOF]= data[i];
            data[i+2*nDOF]= 0.0;
            data[i+3*nDOF]= 0.0;
          }
      }
    return 0;
  }

//! @brief Devuelve los vectores al estado correspondiente al último commit.
int XC::NodeDispVectors::revertToLastCommit(const size_t &nDOF)
  {
    // check disp exists, if does set trial = last commit, incr = 0
    if(data)
      {
        for(size_t i=0;i<nDOF;i++)
          {
            data[i] = data[i+nDOF];
            data[i+2*nDOF]= 0.0;
            data[i+3*nDOF]= 0.0;
          }
      }
    return 0;
  }

void XC::NodeDispVectors::Print(std::ostream &s,int flag)
  {
    if(commitData)
      s << "\tcommitDisps: " << *trialData;
    s << "\n";
  }

//! @brief private method to create the arrays to hold the disp
//! values and the Vector objects for the committed and trial quantaties.
int XC::NodeDispVectors::createDisp(const size_t &nDOF)
  {
    // trial , committed, incr = (committed-trial)
    NodeVectors::createData(nDOF);

    incrDisp = new Vector(&data[2*nDOF], nDOF);
    incrDeltaDisp = new Vector(&data[3*nDOF], nDOF);

    if(incrDisp == nullptr || incrDeltaDisp == nullptr)
      {
        std::cerr << "WARNING - NodeDispVectors::createDisp() "
                  << "ran out of memory creating Vectors(double *,int)";
        return -2;
      }
    return 0;
  }
