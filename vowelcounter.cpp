#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;
int main() {
string input;
int aCount=0,eCount=0,iCount=0,oCount=0,uCount=0;
while(true){
 	cout << "\nenter your word \nenter exit to exit VowelCounter\n";
 	cin  >> input;
 	//int slen = strlen(input.c_str());
 	if(!(input.compare("exit"))) return 0;
 	else {
 		for(int i=0;i<input.length();i++){
 				if(input[i]=='a') aCount++;
 				else if(input[i]=='e') eCount++;
 				else if(input[i]=='i') iCount++;
 				else if(input[i]=='o') oCount++;
 				else if(input[i]=='u') uCount++;		
 		}
 	}
 cout << "Number of vowels:\n";
 cout << "\ta : " << aCount << endl;
 cout << "\te : " << eCount << endl;
 cout << "\ti : " << iCount << endl;
 cout << "\to : " << oCount << endl;
 cout << "\tu : " << uCount << endl;
 aCount=0,eCount=0,iCount=0,oCount=0,uCount=0;
 }
return 0;
}
