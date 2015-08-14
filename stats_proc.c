/*
* stats_proc.c
*/

#include <stdio.h>
#include <math.h>
#include <rpc/rpc.h>
#include "stats.h" 

/*
 * Remote verson of "search"
 */

#define ARRAY_SIZE1 11
#define ARRAY_SIZE2 10

int *search_1_svc(DATA a, int value, struct svc_req *rqstp)
{
	static int result;
	int w = 0;
	/**int i;

	for(i=0;i<ARRAY_SIZE1;i++)
	{

		if (a.array[i] == NULL) 
		{
			result = 0;
			return (&result);
		}

	}**/
    int p;
    printf("Your array is = [");
    for(p=0;p<ARRAY_SIZE1;p++)
    {
        printf(" %i ", a.array[p]);
    }
    printf("]\n");
	int j;
	for(j=0;j<ARRAY_SIZE1;j++)
	{
	
		if (a.array[j] == value)
		 {
			w = j+1;
			printf("Your value is in position: %i and index: array[%i]\n", w,w-1);
			result = 1;
			return (&result);
			
		} 
		
	}
			printf("Your value, %i, is not in the arrary, therefore P = -1\n",value);
			result = 1;
			return (&result);
}

/*
 * Remote verson of "zero"
 */

int *zero_1_svc(DATA a, int value, struct svc_req *rqstp){

	static int result;
	int count=0;

	/**int i;
	for(i=0;i<ARRAY_SIZE1;i++)
	{

		if (a.array[i] == NULL) 
		{
			result = 0;
			return (&result);
		}

	}**/
    
    
    /**
     * Replacing all the entries in array that is equal to the desired value with 0
     *
     **/
    int p;
    printf("Your array is = [");
    for(p=0;p<ARRAY_SIZE1;p++)
    {
        printf(" %i ", a.array[p]);
    }
    printf("]\n");

	int j;
	for(j=0;j<ARRAY_SIZE1;j++)
	{
		if (a.array[j] == value)
		 {
			a.array[j] = 0;
		}
        /**
         * if value not in array, then count counts up to 11
         *
         **/
		else { count ++; }
		
	}
    
    
    //Replacing all the entries in array with -1 if the desired value is not in the array
    if (count == ARRAY_SIZE1)
	{
		int c;
		printf("Your value of %i is not in the array therefore your new array is = [", value);
		for(c=0;c<ARRAY_SIZE1;c++)
		{			
			a.array[c] = -1;		
			printf(" %i ", a.array[c]);
		}
		printf("]\n");
		result = 1;
		return (&result); 
	}
			
	else 
	{
		int k;
		printf("Your new array is = [");
		for(k=0;k<ARRAY_SIZE1;k++)
		{			
			printf(" %i ", a.array[k]);
		}
		printf("]\n");
		result = 1;
		return (&result);
	}

}



/*
 * Remote verson of "sum"
 */
int *sum_1_svc(DATA a, struct svc_req *rqstp){

	static int result;
	int accum = 0;
    
    
    /**int i;
     
     for(i=0;i<ARRAY_SIZE1;i++)
     {
     
     if (a.array[i] == NULL)
     {
     result = 0;
     return (&result);
     }
     
     }**/
	
    int p;
    printf("Your array is = [");
    for(p=0;p<ARRAY_SIZE1;p++)
    {
        printf(" %i ", a.array[p]);
    }
    printf("]\n");

	int j;
	for(j=0;j<ARRAY_SIZE1;j++)
	{
		accum = accum + a.array[j];
		
	}
			
	printf("Sum of array: %d\n",accum);
	result = 1;
	return (&result);

}



/*
 * Remote verson of "median"
 */
int *median_1_svc(DATA a, struct svc_req *rqstp){

	static int result;
	int temp = 0;
	int i;
    
    /**int i;
     
     for(i=0;i<ARRAY_SIZE1;i++)
     {
     
     if (a.array[i] == NULL)
     {
     result = 0;
     return (&result);
     }
     
     }**/
	
    
// 2D array used to sort the array in ascending order
	int k;
	int j;
    int p;
    printf("Your array is = [");
    for(p=0;p<ARRAY_SIZE1;p++)
    {
        printf(" %i ", a.array[p]);
    }
    printf("]\n");
    

	for(k = 0; k < ARRAY_SIZE1; k++)
	{
	      for(j = k+1; j < ARRAY_SIZE1; j++)
	      {
	               if(a.array[j] < a.array[k])
	               {
	                   temp = a.array[k];
	                   a.array[k] = a.array[j];
	                   a.array[j] = temp;
	                }
	       }
	}
    
    int s;
    printf("Your new sorted array is = [");
    for(s=0;s<ARRAY_SIZE1;s++)
    {
        printf(" %i ", a.array[s]);
    }
    printf("]\n");
    
    if (ARRAY_SIZE1%2 == 0)
    {
        printf("Median of array: %i\n",(a.array[ARRAY_SIZE1 / 2] + a.array[ARRAY_SIZE1/ 2 - 1]) / 2);
        result = 1;
        return (&result);
    }

    else
        printf("Median of array: %i\n",a.array[(ARRAY_SIZE1 / 2)]);
        result = 1;
        return (&result);
    
			
	printf("Median of array: %i\n",a.array[5]);
	result = 1;
	return (&result);

}




/*
 * Remote verson of "average"
 */
int *average_1_svc(DATA a, struct svc_req *rqstp){

	static int result;
	int temp = 0;
	float avg =0 ;
    
    /**int i;
     
     for(i=0;i<ARRAY_SIZE1;i++)
     {
     
     if (a.array[i] == NULL)
     {
     result = 0;
     return (&result);
     }
     
     }**/
	
    int p;
    printf("Your array is = [");
    for(p=0;p<ARRAY_SIZE1;p++)
    {
        printf(" %i ", a.array[p]);
    }
    printf("]\n");
	int k;
	for (k = 0; k < ARRAY_SIZE1; k++)
		{temp = temp + a.array[k];}
	avg = temp/ARRAY_SIZE1;

	
			
	printf("Average of array: %f\n",avg);
	result = 1;
	return (&result);

}



/*
 * Remote verson of "stdev"
 */
int *stdev_1_svc(DATA a, struct svc_req *rqstp){

	static int result;
	int temp = 0;
	float deviation,sqr, stddeviation,variance, avg = 0.0 ;
    float sumsqr = 0.0;
    
    /**int i;
     
     for(i=0;i<ARRAY_SIZE1;i++)
     {
     
     if (a.array[i] == NULL)
     {
     result = 0;
     return (&result);
     }
     
     }**/
    
    
    int p;
    printf("Your array is = [");
    for(p=0;p<ARRAY_SIZE2;p++)
    {
        printf(" %i ", a.arr[p]);
    }
    printf("]\n");
    int k;
	for (k = 0; k < ARRAY_SIZE2; k++)
		{temp = temp + a.arr[k];}
	avg = temp/ARRAY_SIZE2;
                        
        int j;                                                    
        for (j = 0 ; j< ARRAY_SIZE2; j++)                               
        {                                                      
            deviation = a.arr[j] - avg;  
		                     
            sumsqr = sumsqr + (deviation * deviation);
		                    
        }                                                      
        variance = sumsqr/ARRAY_SIZE2 ;
                         
        stddeviation = sqrt(variance) ;                        
                                                               
        printf("Standard deviation : %f\n", stddeviation);
	
	result = 1;
	return (&result);

}
