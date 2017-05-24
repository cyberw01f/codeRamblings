// Copyright (c) 2017 Abhineet Dubey. All rights reserved.
// Use of this source code is governed by the GPLv3 license that can be
// found in the LICENSE file.
#include<iostream>
#include<stdio.h>

using namespace std;

int partition(int *,int,int);
void quickSort(int *, int,int);

int main(){

	int n; //size of array
	cin	>>	n;
	int A[n]; //input array, fetching input array values using for loop below
   	for(int i=1; i<=n; i++){
    	cin >> A[i];
   	}

   	quickSort(A,1,n); //primary method
    for(int i=1;i<=n;i++){ //printing array as required
      		cout << A[i] << ';' ;
   		}
	cout << endl;


}

void quickSort(int array[],int ps,int rs){
	if(ps<rs){
		int qs = partition(array,ps,rs);
		quickSort(array,ps,qs-1);
		quickSort(array,qs+1,rs);
	}
}

int partition(int arr[],int pst, int rst){
	int x=arr[rst];
	int i = pst-1;
	int temp;
	for(int j=pst;j<=rst-1;j++){
			if(arr[j]<=x){
				i = i+1;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
	}
	temp=arr[i+1];
	arr[i+1]=arr[rst];
	arr[rst]=temp;

	return i+1;
}
