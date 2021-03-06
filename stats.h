/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _STATS_H_RPCGEN
#define _STATS_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct DATA {
	int array[11];
	int arr[10];
};
typedef struct DATA DATA;

struct search_1_argument {
	DATA arg1;
	int arg2;
};
typedef struct search_1_argument search_1_argument;

struct zero_1_argument {
	DATA arg1;
	int arg2;
};
typedef struct zero_1_argument zero_1_argument;

#define STATSPROG 0x20083001
#define STATSVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define search 1
extern  int * search_1(DATA , int , CLIENT *);
extern  int * search_1_svc(DATA , int , struct svc_req *);
#define zero 2
extern  int * zero_1(DATA , int , CLIENT *);
extern  int * zero_1_svc(DATA , int , struct svc_req *);
#define sum 3
extern  int * sum_1(DATA , CLIENT *);
extern  int * sum_1_svc(DATA , struct svc_req *);
#define median 4
extern  int * median_1(DATA , CLIENT *);
extern  int * median_1_svc(DATA , struct svc_req *);
#define average 5
extern  int * average_1(DATA , CLIENT *);
extern  int * average_1_svc(DATA , struct svc_req *);
#define STDEV 6
extern  int * stdev_1(DATA , CLIENT *);
extern  int * stdev_1_svc(DATA , struct svc_req *);
extern int statsprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define search 1
extern  int * search_1();
extern  int * search_1_svc();
#define zero 2
extern  int * zero_1();
extern  int * zero_1_svc();
#define sum 3
extern  int * sum_1();
extern  int * sum_1_svc();
#define median 4
extern  int * median_1();
extern  int * median_1_svc();
#define average 5
extern  int * average_1();
extern  int * average_1_svc();
#define STDEV 6
extern  int * stdev_1();
extern  int * stdev_1_svc();
extern int statsprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_DATA (XDR *, DATA*);
extern  bool_t xdr_search_1_argument (XDR *, search_1_argument*);
extern  bool_t xdr_zero_1_argument (XDR *, zero_1_argument*);

#else /* K&R C */
extern bool_t xdr_DATA ();
extern bool_t xdr_search_1_argument ();
extern bool_t xdr_zero_1_argument ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_STATS_H_RPCGEN */
