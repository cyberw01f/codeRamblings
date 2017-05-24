// Copyright (c) 2017 Abhineet Dubey. All rights reserved.
// Use of this source code is governed by the GPLv3 license that can be
// found in the LICENSE file.
#include<iostream>
#include<stdio.h>
using namespace std;

void mergeSort(int [],int ,int ); //sorts the input array
void merge(int [],int,int ,int ); //performs the merge part of the merge sort algorithm

int main()
{
	//take the size of array as input
	int n;
	cin	>>	n;
	int a[n]; //input array, fetching input array values using for loop below
   	for(int i=1; i<=n; i++){
    	    cin >> a[i];
   		 }

	//call merge sort function (see below main)
	int p=1,r=n;
    mergeSort(a,p,r);

	//print the sorted array according to the output requirement
   	for(int i=1;i<=n;i++){
      		cout << a[i] << ';' ;
   		}
	cout << endl;
    return 0;
}

// the recurssive merge sort function following the algorithm mentioned in the lecture
void mergeSort(int a[],int p,int r){

     int q;
     if(p<r){
        q=(p+r)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        merge(a,p,q,r);
      }
}

void merge(int a[],int p,int q,int r){

      int n1=q-p+1, n2=r-q;
	  int L[n1+1], R[n2+1]; //L and R are left and right sub-arrays respectively
      //create left array
	  for(int i=1;i<=n1;i++){
         L[i]=a[p+i-1];
      }
	  //create right array
      for(int j=1;j<=n2;j++){
         R[j]=a[q+j];
      }
      L[n1+1]=9999; //instead of infinity as mentioned in book assigned 9999
      R[n2+1]=9999;

	  //perform the merging of arrays comparing the smallest and moving the pointer forward
      int i=1, j=1;
      for(int k=p; k<=r; k++){

         if(L[i] <= R[j]){
            a[k]=L[i];
            i=i+1;
          }
         else{
             a[k]=R[j];
             j=j+1;
         }
       }
}
