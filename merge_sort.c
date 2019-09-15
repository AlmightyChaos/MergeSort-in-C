#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 0x7FFFFFFF
#define LEN(x) (sizeof(x)/sizeof(typeof(x[0])))
#define mergeSort(x,y) (mergeSortEx(x,0,y-1))

void printSortedArray(int [], int);
void mergeSortEx(int [], int, int);
void merge(int [], int, int, int);


int main(void){
	int a[10] = {54,2,60,36,98,37,53,73,4,91};
	mergeSort(a, LEN(a));
	printSortedArray(a, LEN(a));
	return 0;
}

void mergeSortEx(int arr[], int front, int rear){
	int mid;
	if (front < rear){
		mid = (front + rear)/2;
		mergeSortEx(arr, front, mid);
		mergeSortEx(arr, mid + 1, rear);
		merge(arr, front, mid, rear);
	}
}

void merge(int arr[], int front, int mid, int rear){
	int left_size = mid - front + 2;
	int right_size = rear - mid + 1;
	int* left_arr = (int *)malloc(sizeof(int)*left_size);
	int* right_arr = (int *)malloc(sizeof(int)*right_size);
	int left_idx = 0;
	int right_idx = 0;

	memcpy(left_arr, &arr[front], sizeof(int)*(left_size-1));
	memcpy(right_arr, &arr[mid+1], sizeof(int)*right_size-1);

	left_arr[left_size-1] = MAX;
	right_arr[right_size-1] = MAX;

	for (int i = front;i <= rear;++i){
		if (left_arr[left_idx] < right_arr[right_idx])
			arr[i] = left_arr[left_idx++];
		else
			arr[i] = right_arr[right_idx++];
	}

	free(left_arr);
	free(right_arr);
}

void printSortedArray(int arr[], int size){
	for (int i = 0;i < size;++i)
		printf("%d\n", arr[i]);
}
