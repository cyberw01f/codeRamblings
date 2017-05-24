// Copyright (c) 2017 Abhineet Dubey. All rights reserved.
// Use of this source code is governed by the GPLv3 license that can be
// found in the LICENSE file.
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int length;
	cin >> length;
	int arr[length], j, temp, i;
	for (i = 0; i < length; i++){
		cin >> arr[i];
		j=i;
		while (j>0 && arr[j]<arr[j-1]){
			temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
		if (i>0){
			for (int k=0; k<=i; k++){
				cout << arr[k] << ';';
			}
		cout << endl;
		}
	}
}
