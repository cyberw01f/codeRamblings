// Copyright (c) 2017 Abhineet Dubey. All rights reserved.
// Use of this source code is governed by the GPLv3 license that can be
// found in the LICENSE file.
#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main(){
  int hPrice,dPrice,cPrice,hCount,dCount,cCount,tCost,tAnimals,snum=0;
  cout << "Input price of a Horse: "; cin >> hPrice;
  cout << "Input price of a Dog: "; cin >> dPrice;
  cout << "Input price of a cat: "; cin >> cPrice;
  cout << "Input total payement made: "; cin >> tCost;
  cout << "Input total number of animals bought: "; cin >> tAnimals;
  for(hCount=0;hCount<tAnimals;hCount++){
    for(dCount=0;dCount<tAnimals;dCount++){
      for(cCount=0;cCount<tAnimals;cCount++){
        if((hCount+dCount+cCount)==tAnimals){
          if(((hPrice*hCount)+(dPrice*dCount)+(cPrice*cCount))==tCost){
            snum++;
            cout << "Probable solution " << snum << "\n\tHorses = " << hCount << "\n\tDogs = " << dCount << "\n\tCats = " << cCount << endl;
          }
        }
      }
    }
  }
return 0;
}
