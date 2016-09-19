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
                                                                        
// $Revision: 1.10 $
// $Date: 2005/11/23 22:37:43 $
// $Source: /usr/local/cvs/OpenSees/SRC/matrix/IntPtrWrapper.cpp,v $
                                                                        
                                                                        
// Written: fmk 
// Revision: A
//
// Description: This file contains the class implementation for XC::IntPtrWrapper.
//
// What: "@(#) IntPtrWrapper.C, revA"

#include "IntPtrWrapper.h"
#include <cstdlib>


#include <boost/python/extract.hpp>

int XC::IntPtrWrapper::ID_NOT_VALID_ENTRY= 0;

void XC::IntPtrWrapper::libera(void)
  {
    if(data && (fromFree==0))
      {
        delete [] data;
        data= nullptr;
      }
  }

void XC::IntPtrWrapper::check_sizes(void)
  {
#ifdef _G3DEBUG
    if(sz<0)
      {
        std::cerr << "alloc - size " << size << " specified < 0\n";
        sz = 0;
      }
#endif
  }

//! @brief Standard constructor, sets size = 0;
XC::IntPtrWrapper::IntPtrWrapper(void)
  : sz(0), data(nullptr), fromFree(0) {}


// //! @brief Constructor used to allocate a IntPtrWrapper of size size.
// XC::IntPtrWrapper::IntPtrWrapper(int size)
//   : sz(size), data(nullptr), fromFree(0)
//   {
//     check_sizes();
//     alloc(arraySize);
//     // zero the data
//     for(int i=0; i<size; i++)
//       data[i] = 0;
//   }


// //! @brief Constructor used to allocate a XC::IntPtrWrapper of size size.
// XC::IntPtrWrapper::IntPtrWrapper(int size, int arraySz)
//   :sz(size), data(nullptr), arraySize(arraySz), fromFree(0)
//   {
//     check_sizes();
//     alloc(arraySize);
//     // zero the data
//     for(int i=0; i<arraySize; i++)
//       data[i] = 0;
//   }

XC::IntPtrWrapper::IntPtrWrapper(int *d, int size, bool cleanIt)
  :sz(size), data(d), fromFree(1)
  {
    if(!d)
      {
        std::cerr << "IntPtrWrapper; se pasó un puntero nulo." << std::endl;
        sz= 0;
        data= nullptr;
        fromFree = 0;

        // create the space
        if(size!=0)
          {
            std::cerr << "IntPtrWrapperWrapper; llama a malloc" << std::endl;
            data=  (int *)malloc(size*sizeof(int));
            if(!data)
              {
                std::cerr << "IntPtrWrapper(int*,int): ran out of memory with arraySize "
                          << size << std::endl;
                exit(-1);
              }
	    else
	      sz= size;
          }
        // zero the data
        for(int i=0; i<size; i++)
          data[i] = 0;
       }
    if(cleanIt==true)
      fromFree=0;
  }

// XC::IntPtrWrapper::IntPtrWrapper(const int *d, int size)
//   :sz(size), data(nullptr), arraySize(size), fromFree(0)
//   {
//     if(d)
//       {
//         check_sizes();
//         alloc(arraySize);
//         if(arraySize!=0)
//           {
//             for(int i=0; i<arraySize; i++)
//               data[i]= d[i];
//           }
//       }
//     else
//       {
//         sz= 0;
//         data= nullptr;
//         arraySize= 0;
//         fromFree= 0;
//       }
//   }

//! @brief Constructor de copia.
XC::IntPtrWrapper::IntPtrWrapper(const IntPtrWrapper &other)
  :sz(other.sz), data(other.data), fromFree(0)
  {
    std::cerr << "IntPtrWrapper object not intended to be copied." << std::endl;
  }        

// ~IntPtrWrapper():
//         destructor, deletes the [] data

XC::IntPtrWrapper::~IntPtrWrapper(void)
 { libera(); }

int XC::IntPtrWrapper::setData(int *newData, int size, bool cleanIt)
  {
    libera();
    sz = size;
    data = newData;
  
    if(cleanIt == false)
      fromFree= 1;
    else
      fromFree= 0;

    if(sz <= 0)
      {
        std::cerr << "IntPtrWrapper::IntPtrWrapper(int *, size) - size " << size << " specified <= 0\n";
        sz= 0;
      }
    return 0;
  }


void XC::IntPtrWrapper::Zero(void)
  {
    for(int i=0; i<sz; i++)
      data[i]=0;
  }

int XC::IntPtrWrapper::getLocation(int value) const
  {
    // search through IntPtrWrapper for the value
    for(int i=0; i<sz; i++)
      if(data[i] == value)
        return i;
    // if we get here the value is not in the array
    return -1;
  }


int XC::IntPtrWrapper::getLocationOrdered(int value) const
  {
    int middle = 0;
    int left = 0;
    int right = sz-1;
    if(sz!=0)
      {
        while(left <= right)
          {
            middle = (left + right)/2;
            double dataMiddle = data[middle];
            if(value == dataMiddle)
              return middle;   // already there
            else if(value>dataMiddle)
              left = middle + 1;
            else 
              right = middle-1;
          }
      }
    // if we get here the value is not in the array
    return -1;
  }


int XC::IntPtrWrapper::removeValue(int value)
  {
    int place = -1;
    for(int i=0; i<sz; i++)
    if(data[i] == value)
      {
        place = i;
        // copy the rest of the components down one in XC::IntPtrWrapper
        for(int j=i; j<sz-1; j++)
          data[j] = data[j+1];                
        sz--;
      }
    return place;
  }


//! @brief Devuelve el máximo de las componentes del vector.
const int &XC::IntPtrWrapper::max(void) const
  { return *std::max_element(data,data+Size()); }

//! @brief Devuelve el mínimo de las componentes del vector.
const int &XC::IntPtrWrapper::min(void) const
  { return *std::min_element(data,data+Size()); }

// IntPtrWrapper &operator=(const IntPtrWrapper  &V):
//        the assignment operator, This is assigned to be a copy of V. if sizes
//        are not compatable this.data [] is deleted. The data pointers will not
//        point to the same area in mem after the assignment.
//

XC::IntPtrWrapper &XC::IntPtrWrapper::operator=(const IntPtrWrapper &V) 
  {
    std::cerr << "IntPtrWrapper object not intended to be assigned." << std::endl;
    return *this;
  }





//! @brief A function is defined to allow user to print the IntPtrWrappers using streams.
std::ostream &XC::operator<<(std::ostream &s, const XC::IntPtrWrapper &V)
  {
    for(int i=0; i<V.Size();i++) 
      s << V(i) << " ";
    return s;
  }

// friend istream &operator>>(istream &s, IntPtrWrapper &V)
//        A function is defined to allow user to input the data into a XC::IntPtrWrapper which has already
//        been constructed with data, i.e. IntPtrWrapper(int) or XC::IntPtrWrapper(const XC::IntPtrWrapper &) constructors.

/*
istream &operator>>(istream &s, IntPtrWrapper &V)
{
    for(int i=0; i<V.Size(); i++) 
        s >> V(i);

    return s;
}
*/


//! @brief Convierte el vector en un std::vector<double>.
std::vector<int> XC::id_to_std_vector(const IntPtrWrapper &v)
  {
    const size_t sz= v.Size();
    std::vector<int> retval(sz,0);
    for(register size_t i=0;i<sz;i++)
      retval[i]= v(i);
    return retval;
  }

