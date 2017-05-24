// Copyright (c) 2017 Abhineet Dubey. All rights reserved.
// Use of this source code is governed by the GPLv3 license that can be
// found in the LICENSE file.
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

int main(int argc, char* argv[]) {
int counter=0;
char c;
ifstream iFile;
if (argc!=2){
 cout << "Error: No filename provided\nUsage: wordcounter <space> fileName\n";
 return 0;
 }
string fileName = argv[1];
iFile.open(fileName);
if(iFile.is_open()){ //if file is open
	while(iFile.peek()!=EOF){ //until we hit end of file
		if(iFile.get(c) && c!='\n' && c!=' ') counter++; //we have character not equal to newline or space
	}
}
iFile.close();
cout << "Number of characters in the file : " << counter << endl;
return 0;
}
