/* exisop.f -- translated by f2c (version 20160102).
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
/* Subroutine */ int exisop_(integer *mxnd, real *xn, real *yn, integer *
	lnodes, real *angle, integer *n1, real *xnew, real *ynew)
{
    static integer n0, n2;

/* *********************************************************************** */
/*  SUBROUTINE EXISOP = CALCULATES A POSITION TO MAKE A PARALLELPIPED */
/* *********************************************************************** */
    /* Parameter adjustments */
    --angle;
    lnodes -= 8;
    --yn;
    --xn;

    /* Function Body */
    n0 = lnodes[*n1 * 7 + 2];
    n2 = lnodes[*n1 * 7 + 3];
    *xnew = xn[n0] + xn[n2] - xn[*n1];
    *ynew = yn[n0] + yn[n2] - yn[*n1];
    return 0;
} /* exisop_ */

#ifdef __cplusplus
	}
#endif
