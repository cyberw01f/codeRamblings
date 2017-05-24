/*
Tested on gcc version 6.3.1 20161221 (Red Hat 6.3.1-1) (GCC)
*/
#include<iostream>
#include<stdio.h>
//#include<array>
using namespace std;

int maxHeapify(int [], int, int);
int buildMaxHeap(int [],int);
int heapSort(int [], int);

int main(){
	
	int n; //size of array
	cin	>>	n;
	int A[n]; //input array, fetching input array values using for loop below
   	for(int i=1; i<=n; i++){
    	cin >> A[i];
   	}
   	int hSize=n; 
   	heapSort(A,hSize); //primary method
    for(int i=1;i<=n;i++){ //printing array as required
      		cout << A[i] << ';' ;
   		}
	cout << endl;

return 0;

}


int maxHeapify(int Array[], int index, int heapSize){ //recursive method called on a particular heap node which is at index
	int l,r,largest,temp;
	l=2*index; //LEFT(i)
	r=2*index+1; //RIGHT(i)
	
	if(l<=heapSize && Array[l]>Array[index])
		largest=l;
	else
		largest=index;
	if(r<=heapSize && Array[r]>Array[largest])
		largest=r;
	if(largest!=index){
		temp=Array[index];
		Array[index]=Array[largest];
		Array[largest]=temp;
		maxHeapify(Array,largest,heapSize);
	}
}

int buildMaxHeap(int arr[],int hS){ // makes max heap by calling max heapify
	//int size = ARRAY_SIZE(arr);
	for(int i = hS/2;i>=1;i--){
		maxHeapify(arr,i,hS);
	}
	
}


int heapSort(int a[], int hpSize){
	
	int temp;
	buildMaxHeap(a,hpSize);
	for(int i=hpSize;i>=2;i--){
		temp=a[i];
		a[i]=a[1];
		a[1]=temp;
		//hpSize = hpSize - 1;
		maxHeapify(a,1,i-1);
	}
	
}
