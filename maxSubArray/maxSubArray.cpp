// Copyright (c) 2017 Abhineet Dubey. All rights reserved.
// Use of this source code is governed by the GPLv3 license that can be
// found in the LICENSE file.
#include<iostream>
#include<stdio.h>
#include<limits.h> //http://www.cplusplus.com/reference/climits/ used for INT_MIN
using namespace std;

int findMaxSubArray(int [], int, int);
int findMaxCrossingSubArray(int [], int, int, int);

int main(){
	int n; //size of array
	cin	>>	n;
	int A[n]; //input array, fetching input array values using for loop below
   	for(int i=1; i<=n; i++){
    	cin >> A[i];
   	}
   	int finalResult = findMaxSubArray(A,1,n);
    cout << finalResult << endl;

return 0;
}


int findMaxSubArray(int A[],int low,int high){
	int mid,leftSum,rightSum,crossSum;
	if(high==low) //only one element in array
		return A[low];
	else{
		mid=(high+low)/2; //divide array at mid, using int so floor function not required
		leftSum =	findMaxSubArray(A,low,mid);
		rightSum =	findMaxSubArray(A,mid+1,high);
		crossSum =	findMaxCrossingSubArray(A,low,mid,high);
	//if else statements below return the maximum of left array sum,right array sum and array crossing the mid
	if( (leftSum >= rightSum) && (leftSum>=crossSum) )
		return leftSum;
	else if ((rightSum >= leftSum) && (rightSum >= crossSum) )
		return rightSum;
	else
		return crossSum;
	}
}


int findMaxCrossingSubArray(int A[],int low, int mid, int high){
	int leftSum,sum,rightSum;
	leftSum=INT_MIN; //used instead of infinity
	sum=0;
	for(int i=mid;i>=low;i--){
		sum=sum+A[i];
		if(sum>leftSum) leftSum=sum;
	}
	rightSum=INT_MIN; //used instead of infinity
	sum=0;
	for(int j=mid+1;j<=high;j++){
		sum=sum+A[j];
		if(sum>rightSum) rightSum=sum;
	}
	return leftSum+rightSum; //returns sum of elements on left and right side of mid
}
