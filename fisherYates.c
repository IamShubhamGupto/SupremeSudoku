#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
  
//function to swap to integers 
void swap (int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

//function to print grid 
void printArray (int arr[9][9], int n){ 
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n;j++){
			printf("%d ", arr[i][j]); 
		}
		printf("\n"); 
	}    
} 
  
// A function to generate a random permutation of arr[] 
void randomize ( int arr[], int n, int x ){ 
    // Use a different seed value so that we don't get same 
    srand ( time(NULL)+x ); 
  
    // Start from the last element and swap one by one. We don't 
    // need to run for the first element that's why i > 0 
    for (int i = n-1; i > 0; i--) 
    { 
        // Pick a random index from 0 to i 
        int j = rand() % (i+1); 
  
        // Swap arr[i] with the element at random index 
        swap(&arr[i], &arr[j]); 
    } 
} 
//function to remove duplicates from grid
void checkArray(int arr[9][9], int n){
	//int c=0;
	
	for(int i = n-1; i>-1 ;i--){
		//int d = arr[c][i];
		for(int j = n-1; j > -1;j--){
			int d = arr[i][j];
			for(int k = j-1; k > -1; k--){
				//check vertically
				if(arr[j][i] != 0 && arr[j][i] == arr[k][i]){
					arr[k][i] = 0;
				}
				//check horizontally
				if(arr[i][j] != 0 && arr[i][j] == arr[i][k]){
					arr[i][k] = 0;
				}

			}
		}
	}
	
} 
//fill grid
void makeGrid(int grid[9][9],int arr[9],int is,int ie,int js, int je){
	int c = 0;
	for(int i = is; i<= ie; i++){
		for(int j = js; j <= je; j++){
			grid[i][j] = arr[c];
			c++;
		}
	}
} 
//make random element of array 0
void popArray(int arr[],int i){
	arr[arr[0]] = 0;
	arr[i] = 0;
	
	
	srand(time(NULL));
	int pos = rand()%(i+1);
	//printf("pos = %d \n",pos);
	//for(int j = 0; j < 2; j++){
	arr[pos] = 0;	
	//}
	
	
} 
void main(){ 
	int grid[9][9];
	//int arr[] = {1, 2, 3, 4, 5, 6, 7, 8,9};
	for(int i = 0; i < 9; i++){
		//
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8,9};
		//int n = sizeof(arr)/ sizeof(arr[0]);
		randomize (arr, 9,i);
		popArray(arr,i);
		/*
		printf("before popping\n");
		for(int j = 0; j < 9; j++){
			printf("%d ",arr[j]);
		}
		
		for(int j = 0; j < 9; j++){
			printf("%d ",arr[j]);
		}
		printf("\n");
		*/
		switch(i){
		case 8:	makeGrid(grid,arr,0,2,0,2);
			break;
		case 7: makeGrid(grid,arr,0,2,3,5);
			break;
		case 6: makeGrid(grid,arr,0,2,6,8);
			break;
		case 5: makeGrid(grid,arr,3,5,0,2);
			break;
		case 4: makeGrid(grid,arr,3,5,3,5);
			break;		
		case 3: makeGrid(grid,arr,3,5,6,8);
			break;
		case 2: makeGrid(grid,arr,6,8,0,2);
			break;
		case 1: makeGrid(grid,arr,6,8,3,5);
			break;
		case 0: makeGrid(grid,arr,6,8,6,8);
			break;
		default: printf("\nError\n");
			exit(1);			
		}

		
/* 
		for(int j = 0; j < 9; j++){
			grid[i][j] = arr[j];
		}
*/
	}
	printArray(grid,9);
	printf("\n");
	checkArray(grid, 9); 
	printArray(grid,9);
} 

