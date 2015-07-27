#include <stdio.h>
#include <stdlib.h>

#define NUM 999999

void merge_sort(int* add, int n);

int
main(void)
{
    int array[NUM];

    //initialize the array with random numbers
    for(int i = 0; i < NUM; i++){
	array[i] = rand();
    }

    //print the array
    for(int i = 0; i < NUM; i++) {
    	printf("array[%4d]= %d\n", i, array[i]);
    }

	printf("sorting ...\n");

    //sort
    merge_sort(array, NUM);

    //print sorted array
	printf("sorted!\n");
    for(int i = 0; i < NUM; i++) {
    	printf("array[%4d]= %d\n", i, array[i]);
    }


}

//merge sort function
void
merge_sort(int* add, int n)
{
    if(n < 2) {
	return;
    } 
	else { 

		//sort the left part 
		int left_n = n/2;
		int right_n = n - n/2;

		int* left = add;
		int* right = add + left_n;
		merge_sort(left, left_n);
		//sort the right part
		merge_sort(right, right_n);
		//merge
		int* tmp_array;
		tmp_array =  malloc( n*sizeof(int) );
		//tmp_array = (int*) malloc( n*sizeof(int) );
		for(int j = 0, i = 0, l = 0; l < n; l++ ){
			if( j < right_n && i < left_n){
	   		 	if( right[j] < left[i]) {
					tmp_array[l] = right[j]; 
					j++;
	    		}
				else {
					tmp_array[l] = left[i];
					i++;
				}
			}
			else {
				if( j == right_n){
				    tmp_array[l] = left[i];
					i++;
				}
				else {
					tmp_array[l] = right[j];
					j++;
				}

			}
	    }

		//copy
		for(int i = 0; i < n; i++){
			add[i] = tmp_array[i];
		}

		free(tmp_array);
		tmp_array = NULL;

		//check
		printf("merge %d elements!\n",n);
        for(int i = 0; i < n; i++) {
        	printf("add[%3d]= %d\n", i, add[i]);
        }
		
	}
}
    
