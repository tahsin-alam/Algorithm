
//Tahsin Alam
//CS 220
//Algorithm.


#include <stdio.h>
#include <stdlib.h>

int randomindex( int k )
{ return(  rand() % k );
}

int quickselect( int *A, int k, int n)
{
    long i, j1, j2, pivot, tmp;
    if(n>1)
    {  i = randomindex(n);
        pivot = A[i]; A[i] = A[n-1]; A[n-1] = pivot;
        j1 = 0; j2 = n-1;
        while(j1 < j2)
        {  for(; A[j1] < pivot ; j1++)
                ;
            for(; A[j2] >= pivot && j2 > j1 ; j2-- )
                ;
            if( j1 != j2 )
            {  tmp = A[j1]; A[j1] = A[j2]; A[j2] = tmp;
            }
        }
        //moves pivot element at correct place //
        A[n-1] = A[j1]; A[j1] = pivot;


        if(j1+1==k){
            return A[k-1];}

        else if(j1+1>k){
            quickselect(A,k,j1);
        }
        else
            quickselect(A+j1+1,k-j1-1,n-j1-1);


    }
    return A[k-1];

}

int main(void)
{
    long i;
    int *space; int tmp;
    space =  (int *) malloc( 1000000*sizeof(int));
    for( i=0; i< 500000; i++ )
    {  *(space + i) = ((139*i)%500000);
        *(space + i + 500000) = 1000000 + ((141*i)%500000);
    }
    if( (tmp = quickselect(  space, 500001, 1000000)) != 1000000 )
    {  printf(" Failed test 1. Returned %d instead of 1000000\n", tmp);
        fflush(stdout); exit(-1);
    }
    else printf("passed test1\n");
    for( i=0; i< 500000; i++ )
    {  *(space + i) = ((139*i)%500000);
        *(space + i + 500000) = 1000000 + ((141*i)%500000);
    }
    if( (tmp = quickselect(  space, 1, 1000000)) != 0 )
    {  printf(" Failed test 2. Returned %d instead of 0\n", tmp);
        fflush(stdout); exit(-1);
    }
    else printf("passed test2\n");
    for( i=0; i< 500000; i++ )
    {  *(space + i) = ((139*i)%500000);
        *(space + i + 500000) = 1000000 + ((141*i)%500000);
    }
    if( (tmp = quickselect(  space, 124, 1000000)) != 123 )
    {  printf(" Failed test 3. Returned %d instead of 123\n", tmp);
        fflush(stdout); exit(-1);
    }
    else printf("passed test3\n");



    printf("Quickselect successful\n");
    exit(0);
}