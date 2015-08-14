/*
* rstatsprog.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <rpc/rpc.h>
#include "stats.h" 


int main(int argc, char *argv[])
{


	CLIENT* cl;
	int* result;
	char* server;
	int value, option;
    DATA a;
    int b=0;
	


	if (argc < 2)
	 {
		fprintf(stderr, "usage: %s host message\n", argv[0]);
		exit(1);
	}
    
    /*
     * Save values of command line arguments
     */

	server = argv[1];
    
    printf("**************\nEnter number of desired command from options below, or '0' to quit:\n 1. Search(A,N) \n 2. Zero(A,N) \n 3. Sum(A) \n 4. Median(A) \n 5. Average(A) \n 6. STDEV(A) \n*************\n");
    scanf("%i",&option);
    if (option!=1&&option!=2&&option!=3&&option!=4&&option!=5&&option!=6&&option!=0) //Check to see if number entered is 1-6
    {
       b=1;
    }
    
    //While loop to confirm is correct entry is entered for the command
    while(b>0)
    {
        if (option == 0){exit(1);} //handle quit command.
        printf("Please enter a valid number, between 1-6 inclusive, to select desired command from options below.\n");
        printf("**************\nEnter number of desired command,or '0' to quit:\n 1. Search(A,N) \n 2. Zero(A,N) \n 3. Sum(A) \n 4. Median(A) \n 5. Average(A) \n 6. STDEV(A) \n*************\n");
        scanf("%i",&option);
        if (option!=1&&option!=2&&option!=3&&option!=4&&option!=5&&option!=6&&option!=0)
        {
            b=1;
        }
        
        if (option==1||option==2||option==3||option==4||option==5||option==6||option == 0)
        {
            b=0;
            break;
        }
        
    }
    
    if (option == 0){exit(1);} //handle quit command.


    // Handle for the search procedure
	if (option == 1)
	{
		printf("Enter values for A array, must be 11 numbers:");
		int i;
  		for(i=0;i<11;++i)
		{
        		scanf("%i",(a.array+i));
		}

		printf("Enter N value:");
		scanf("%i",&value);
        
        /*
         * Create client "handle" used for calling STATSPROG on the
         * server designated on the command line. We tell the RPC package
         * to use the "tcp" protocol when contacting the server.
         */

		cl = clnt_create(server, STATSPROG, STATSVERS, "tcp");

		if (cl == NULL)
            
		{
            /*
             * Couldn't establish connection with server.
             * Print error message and die.
             */
			clnt_pcreateerror(server);
			exit(1);
		}
	
        /*
         * Call the remote procedure "search" on the server
         */
		result = search_1(a,value, cl);
	
	
		if (result== NULL)
		{
            /*
             * An error occurred while calling the server.
             * Print error message and die.
             */
			clnt_perror(cl, server);
			exit(1);
		}

		if (*result == 0)
	 	{
            /*
             * Server was unable to print our message.
             * Print error message and die.
             */
			fprintf(stderr, "%s: %s couldn't print your message\n",
			argv[0], server);
			exit(1);
		}

        /*
         * The message was output on the server
         */
		printf("Message delivered to %s!\n", server);
	
		return 0;
	}
    
    
    // Handle for the search procedure
    if (option == 2)
	{
		printf("Enter values for A array, must be 11 numbers:");
		int i;
  		for(i=0;i<11;++i)
		{
        		scanf("%i",(a.array+i));
		}

		printf("Enter N value:");
		scanf("%i",&value);
        /*
         * Create client "handle" used for calling STATSPROG on the
         * server designated on the command line. We tell the RPC package
         * to use the "tcp" protocol when contacting the server.
         */

		cl = clnt_create(server, STATSPROG, STATSVERS, "tcp");

		if (cl == NULL)
		{
            /*
             * Couldn't establish connection with server.
             * Print error message and die.
             */
			clnt_pcreateerror(server);
			exit(1);
		}
	
	
        /*
         * Call the remote procedure "zero" on the server
         */
		result = zero_1(a, value,cl);
	
	
		if (result== NULL)
		{
           
            /*
             * An error occurred while calling the server.
             * Print error message and die.
             */

			clnt_perror(cl, server);
			exit(1);
		}

		if (*result == 0)
	 	{
            /*
             * Server was unable to print our message.
             * Print error message and die.
             */
			fprintf(stderr, "%s: %s couldn't print your message\n",
			argv[0], server);
			exit(1);
		}
        /*
         * The message was output on the server
         */

		printf("Message delivered to %s!\n", server);
	
		return 0;
	}

	if (option == 3)
	{
		printf("Enter values for A array, must be 11 numbers:");
		int i;
  		for(i=0;i<11;++i)
		{
        		scanf("%i",(a.array+i));
		}

		cl = clnt_create(server, STATSPROG, STATSVERS, "tcp");

		if (cl == NULL)
		{
			clnt_pcreateerror(server);
			exit(1);
		}
	
	
		result = sum_1(a,cl);
	
	
		if (result == NULL)
		{
			clnt_perror(cl, server);
			exit(1);
		}

		if (*result == 0)
	 	{
			fprintf(stderr, "%s: %s couldn't print your message\n",
			argv[0], server);
			exit(1);
		}

		printf("Message delivered to %s!\n", server);
	
		return 0;
	}

	
	if (option == 4)
	{
		printf("Enter values for A array, must be 11 numbers:");
		int i;
  		for(i=0;i<11;++i)
		{
        		scanf("%i",(a.array+i));
		}

		cl = clnt_create(server, STATSPROG, STATSVERS, "tcp");

		if (cl == NULL)
		{
			clnt_pcreateerror(server);
			exit(1);
		}
	
	
		result = median_1(a,cl);
	
	
		if (result == NULL)
		{
			clnt_perror(cl, server);
			exit(1);
		}

		if (*result == 0)
	 	{
			fprintf(stderr, "%s: %s couldn't print your message\n",
			argv[0], server);
			exit(1);
		}

		printf("Message delivered to %s!\n", server);
	
		return 0;
	}




	if (option == 5)
	{
		printf("Enter values for A array, must be 11 numbers:");
		int i;
  		for(i=0;i<11;++i)
		{
        		scanf("%i",(a.array+i));
		}

		cl = clnt_create(server, STATSPROG, STATSVERS, "tcp");

		if (cl == NULL)
		{
			clnt_pcreateerror(server);
			exit(1);
		}
	
	
		result = average_1(a,cl);
	
	
		if (result == NULL)
		{
			clnt_perror(cl, server);
			exit(1);
		}

		if (*result == 0)
	 	{
			fprintf(stderr, "%s: %s couldn't print your message\n",
			argv[0], server);
			exit(1);
		}

		printf("Message delivered to %s!\n", server);
	
		return 0;
	}



	if (option == 6)
	{
		printf("Enter values for A array, must be 10 numbers:");
		int i;
  		for(i=0;i<10;++i)
		{
        		scanf("%i",(a.arr+i));
		}

		cl = clnt_create(server, STATSPROG, STATSVERS, "tcp");

		if (cl == NULL)
		{
			clnt_pcreateerror(server);
			exit(1);
		}
	
	
		result = stdev_1(a,cl);
	
	
		if (result == NULL)
		{
			clnt_perror(cl, server);
			exit(1);
		}

		if (*result == 0)
	 	{
			fprintf(stderr, "%s: %s couldn't print your message\n",
			argv[0], server);
			exit(1);
		}

		printf("Message delivered to %s!\n", server);
	
		return 0;
	}



}
