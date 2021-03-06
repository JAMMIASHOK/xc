/* cornp.f -- translated by f2c (version 20160102).
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
#include "paving.h"

/*    Copyright(C) 1999-2020 National Technology & Engineering Solutions */
/*    of Sandia, LLC (NTESS).  Under the terms of Contract DE-NA0003525 with */
/*    NTESS, the U.S. Government retains certain rights in this software. */

/*    See packages/seacas/LICENSE for details */
logical cornp_(xc_float *angle)
{
    /* Initialized data */

    static xc_float eps = (xc_float).62;

    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static xc_float pi;

/* *********************************************************************** */
/*  FUNCTION CORNP = LOGICAL FUNCTION THAT RETURNS TRUE IF THE ANGLE IS */
/*                   WITHIN THE CURRENT DEFINITION OF A CORNER */
/* *********************************************************************** */
    pi = M_PI;
    if (*angle < pi - eps) {
	ret_val = TRUE_;
    } else {
	ret_val = FALSE_;
    }
    return ret_val;
} /* cornp_ */

#ifdef __cplusplus
	}
#endif
