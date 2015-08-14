README
In this program each argument in the commands below is a size 11 array of integers except N and P which are single integers.

THE CLIENT PROGRAM
Creates RPC handle for server, it asks the user to input data for the array and also to select the command desired to perform operation. The RPC handle is passed to client stubs.

THE SERVER PROGRAM
Used to provide the actual remote procedures that do the work.

Search (A, N): In response to this command A-Processor returns P if A[P-1]=N where P-1 is the smallest index such that A[P-1]=N; otherwise, A-Processor returns -1. For example, let A=[12, 43, 8, 10, 6, 9, 13, 10, 21, 33, 1] and N=10. Then P=4.

Zero (A, N): In response to this command A-Processor must replace every occurrence of N in A with 0 and return the resulting array. If A does not contain N, A-Processor returns a size 11 array where each entry contains -1. For example, let A=[12, 43, 8, 10, 6, 9, 13, 10, 21, 33, 1] and N=10. Then A-Processor returns [12, 43, 8, 0, 6, 9, 13, 0, 21, 33, 1].

Sum (A): In response to this command, A-Processor returns the sum of the integers in A.

Median (A): In response to this command, A-Processor returns the median of the integers in A.

Average (A): In response to this command, A-Processor returns the average of the integers in A.

STDEV (A): In response to this command, A-Processor returns the standard deviation of the integers in A. Assume that the numbers in A make up a sample from a population and use 10 (instead of 11) as the divisor in the square root formula for standard deviation.

COMPILING
Compiling the protocol definition: rpcgen -N stats.x
Compiling the client program: gcc rstatsprog.c stats_clnt.c stats_xdr.c -o client
Compiling the server program: gcc stats_proc.c stats_svc.c stats_xdr.c -o server -lm

RUNNING
On the server machine, run the server: ./server
On the client machine, run the client program ./client 127.0.0.1

****************************************************************
OR

gcc stats_prog.c
./a.out
