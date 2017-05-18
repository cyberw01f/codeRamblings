// Copyright (c) 2017 Abhineet Dubey. All rights reserved.
// Use of this source code is governed by the GPLv3 license that can be
// found in the LICENSE file.
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main(){
  int guess,rNum;
  srand(time(NULL));
  rNum=rand()%100+1;
  cout << "Take a guess ! The number is between 1 and 100\nTo give up enter 0\n";
  while(true){
    cin >> guess;
    if(guess==0){
      cout << "Coward !, the number was: " << rNum << endl;
      return 0;
    }
    else if(guess>rNum) cout << "that's too high\n";
    else if(guess<rNum) cout << "that's too low\n";
    else if(guess==rNum){
      cout << "Congratulations you guessed it right, the number was: " << rNum << endl;
      return 0;
    }
  }
  return 0;
}
