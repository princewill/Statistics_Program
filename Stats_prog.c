/**
README
Stats_prog.c
Created by: Princewill Ohuabunwa
 In this program each argument in the commands below is a size 11 array of integers except N and P which are single integers.
It asks the user to input data for the array and also to select the command desired to perform operation.
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max_array 10
#define max_array2 10

struct DATA {
    int array[11];
    int arr[10];
};
typedef struct DATA DATA;


int main (int argc, char *argv[])
{
    int i;
    int result;
    int value, option;
    int b=0;
    DATA a;
    
    /***
     * Checking for error in command line entry
     *
     *
     **/
    
    if (argc < 1)
    {
        fprintf(stderr, "usage: %s host message\n", argv[0]);
        exit(1);
    }

    /***
     * Prompt user to enter values
     **/
    
    printf("**************\nEnter number of desired command from options below, or '0' to quit:\n 1. Search(A,N) \n 2. Zero(A,N) \n 3. Sum(A) \n 4. Median(A) \n 5. Average(A) \n 6. STDEV(A) \n*************\n");
    
    /***
     ** Check to see if number entered is 1-6
     **/
    scanf("%i",&option);
    if (option!=1&&option!=2&&option!=3&&option!=4&&option!=5&&option!=6&&option!=0)
    {
        b=1;
    }
    
    /***
     ** Check for validity of option choosen
     **/
    
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
    
    switch (option)
    {
        case 0:
            exit(1);
            break;
        case 1:
            printf("Enter values for A array, must be 11 numbers:");
            for(i=0;i<max_array;++i)
            {
                scanf("%i",&a.array[i]);
            }
            
            printf("Enter N value:");
            scanf("%i",&value);
            search(a,value);
            break;
        case 2:
            printf("Enter values for A array, must be 11 numbers:");
            for(i=0;i<max_array;++i)
            {
                scanf("%i",&a.array[i]);
            }
            
            printf("Enter N value:");
            scanf("%i",&value);
            zero(a, value);
            break;
        case 3:
            printf("Enter values for A array, must be 11 numbers:");
            for(i=0;i<max_array;++i)
            {
                scanf("%i",&a.array[i]);
            }
            sum(a);
            break;
        case 4:
            printf("Enter values for A array, must be 11 numbers:");
            for(i=0;i<max_array;++i)
            {
                scanf("%i",&a.array[i]);
            }
            median(a);
            break;
        case 5:
            printf("Enter values for A array, must be 11 numbers:");
            for(i=0;i<max_array;++i)
            {
                scanf("%i",&a.array[i]);
            }
            average(a);
            break;
        case 6:
            printf("Enter values for A array, must be 10 numbers:");
            for(i=0;i<max_array-1;++i)
            {
                scanf("%i",&a.arr[i]);
            }
            stdev(a);
            break;
    }

    
}

/*
 * method for "search"
Search (A, N): In response to this command A-Processor returns P if A[P-1]=N where P-1 is the smallest index such that A[P-1]=N; otherwise, A-Processor returns -1. For example, let A=[12, 43, 8, 10, 6, 9, 13, 10, 21, 33, 1] and N=10. Then P=4.
 */

int search(DATA a, int value)
{
    static int result;
    int w = 0;
    int p;
    printf("Your array is = [");
    for(p=0;p<max_array;p++)
    {
        printf(" %i ", a.array[p]);
    }
    printf("]\n");
    int j;
    for(j=0;j<max_array;j++)
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
 * method for "zero"
 Zero (A, N): In response to this command A-Processor must replace every occurrence of N in A with 0 and return the resulting array. If A does not contain N, A-Processor returns a size 11 array where each entry contains -1. For example, let A=[12, 43, 8, 10, 6, 9, 13, 10, 21, 33, 1] and N=10. Then A-Processor returns [12, 43, 8, 0, 6, 9, 13, 0, 21, 33, 1].

 */

int zero(DATA a, int value){
    
    static int result;
    int count=0;
    int p;
    
    printf("Your array is = [");
    for(p=0;p<max_array;p++)
    {
        printf(" %i ", a.array[p]);
    }
    printf("]\n");
    
    int j;
    for(j=0;j<max_array;j++)
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
    if (count == max_array)
    {
        int c;
        printf("Your value of %i is not in the array therefore your new array is = [", value);
        for(c=0;c<max_array;c++)
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
        for(k=0;k<max_array;k++)
        {
            printf(" %i ", a.array[k]);
        }
        printf("]\n");
        result = 1;
        return (&result);
    }
    
}



/*
 * method for "sum"
 Sum (A): In response to this command, A-Processor returns the sum of the integers in A.

 */
int sum(DATA a){
    
    static int result;
    int accum = 0;
    int p;
    
    printf("Your array is = [");
    for(p=0;p<max_array;p++)
    {
        printf(" %i ", a.array[p]);
    }
    printf("]\n");
    
    int j;
    for(j=0;j<max_array;j++)
    {
        accum = accum + a.array[j];
        
    }
    
    printf("Sum of array: %d\n",accum);
    result = 1;
    return (&result);
    
}



/*
 * method for "median"
 Median (A): In response to this command, A-Processor returns the median of the integers in A.

 */
int median(DATA a){
    
    static int result;
    int temp = 0;
    int i;
    
    // 2D array used to sort the array in ascending order
    int k;
    int j;
    int p;
    
    printf("Your array is = [");
    for(p=0;p<max_array;p++)
    {
        printf(" %i ", a.array[p]);
    }
    printf("]\n");
    
    
    for(k = 0; k < max_array; k++)
    {
        for(j = k+1; j < max_array; j++)
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
    for(s=0;s<max_array;s++)
    {
        printf(" %i ", a.array[s]);
    }
    printf("]\n");
    
    if (max_array%2 == 0)
    {
        printf("Median of array: %i\n",(a.array[max_array / 2] + a.array[max_array/ 2 - 1]) / 2);
        result = 1;
        return (&result);
    }
    
    else
        printf("Median of array: %i\n",a.array[(max_array / 2)]);
    result = 1;
    return (&result);
    
    
    printf("Median of array: %i\n",a.array[5]);
    result = 1;
    return (&result);
    
}




/*
 * method for "average"
 Average (A): In response to this command, A-Processor returns the average of the integers in A.
 */
int average(DATA a){
    
    static int result;
    int temp = 0;
    float avg =0 ;

    
    int p;
    printf("Your array is = [");
    for(p=0;p<max_array;p++)
    {
        printf(" %i ", a.array[p]);
    }
    printf("]\n");
    int k;
    for (k = 0; k < max_array; k++)
    {temp = temp + a.array[k];}
    avg = temp/max_array;
    
    
    
    printf("Average of array: %f\n",avg);
    result = 1;
    return (&result);
    
}



/*
 * method for "stdev"
 STDEV (A): In response to this command, A-Processor returns the standard deviation of the integers in A. Assume that the numbers in A make up a sample from a population and use 10 (instead of 11) as the divisor in the square root formula for standard deviation.
 */
int stdev(DATA a){
    
    static int result;
    int temp = 0;
    float deviation,sqr, stddeviation,variance, avg = 0.0 ;
    float sumsqr = 0.0;
    
    int p;
    printf("Your array is = [");
    for(p=0;p<max_array2;p++)
    {
        printf(" %i ", a.arr[p]);
    }
    printf("]\n");
    int k;
    for (k = 0; k < max_array2; k++)
    {temp = temp + a.arr[k];}
    avg = temp/max_array2;
    
    int j;
    for (j = 0 ; j< max_array2; j++)
    {
        deviation = a.arr[j] - avg;
        
        sumsqr = sumsqr + (deviation * deviation);
        
    }
    variance = sumsqr/max_array2 ;
    
    stddeviation = sqrt(variance) ;                        
    
    printf("Standard deviation : %f\n", stddeviation);
    
    result = 1;
    return (&result);
    
}

    

