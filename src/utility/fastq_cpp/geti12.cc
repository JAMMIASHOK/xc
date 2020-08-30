/* geti12.f -- translated by f2c (version 20160102).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#ifdef __cplusplus
extern "C" {
#endif
#include "fastq_cpp.h"

/*    Copyright(C) 1999-2020 National Technology & Engineering Solutions */
/*    of Sandia, LLC (NTESS).  Under the terms of Contract DE-NA0003525 with */
/*    NTESS, the U.S. Government retains certain rights in this software. */

/*    See packages/seacas/LICENSE for details */
/* Subroutine */ int geti12_(integer *mcom, integer *icom, integer *jcom, 
	char *cin, integer *iin, integer *kin, integer *i1, integer *i2, 
	integer *ifound, ftnlen cin_len)
{
/* *********************************************************************** */
/*  SUBROUTINE GETI12 = GETS TWO INTEGERS */
/* *********************************************************************** */
    /* Parameter adjustments */
    --kin;
    --iin;
    cin -= 72;

    /* Function Body */
    if (*icom > *jcom || *(unsigned char *)&cin[*icom * 72] == ' ') {
	*ifound = 0;
	++(*icom);
	*i1 = 0;
	*i2 = 0;
    } else {
	*i1 = iin[*icom];
	++(*icom);
	if (*icom <= *jcom && kin[*icom] > 0) {
	    *i2 = iin[*icom];
	    ++(*icom);
	    *ifound = 2;
	} else {
	    *i2 = 0;
	    *ifound = 1;
	}
    }
    return 0;
} /* geti12_ */

#ifdef __cplusplus
	}
#endif
