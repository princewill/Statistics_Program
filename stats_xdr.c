/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "stats.h"

bool_t
xdr_DATA (XDR *xdrs, DATA *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, ( 11  + 10 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->array, 11,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->arr, 10,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->array;
					i < 11; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			{
				register int *genp;

				for (i = 0, genp = objp->arr;
					i < 10; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, ( 11  + 10 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->array, 11,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->arr, 10,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->array;
					i < 11; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			{
				register int *genp;

				for (i = 0, genp = objp->arr;
					i < 10; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
		}
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->array, 11,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->arr, 10,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_search_1_argument (XDR *xdrs, search_1_argument *objp)
{
	 if (!xdr_DATA (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_zero_1_argument (XDR *xdrs, zero_1_argument *objp)
{
	 if (!xdr_DATA (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}
