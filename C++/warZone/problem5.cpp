// Copyright (c) 2017 Abhineet Dubey. All rights reserved.
// Use of this source code is governed by the GPLv3 license that can be
// found in the LICENSE file.
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

using namespace std;

void Hello(){
  cout << "Welcome to the warzone !" << endl;
  cout << "We are being attacked by enemy tanks" << endl;
  cout << "You have one tank, which you can shoot at any angle" << endl;
  cout << "You only get 10 shots to destroy a target" << endl;
}

bool tank(){
  float dist,angle;
  int shots=0;
  bool hit = false;
  float Velocity = 350.0; // initial velocity of 200 ft/sec
  float Gravity = 32.2; // gravity for distance calculation
  srand(time(NULL));
  dist=rand()%500+1;
  cout << "Enemy tank spotted at a distance of " << dist << " feet" << endl;
  while(!hit){
    cout << "At what angle do you want to shoot?" << endl;
    cin >> angle;
    int rangle = (angle*3.14)/180;
    shots++; if(shots>=10) break;
    float timeTaken = (2.0*Velocity*sin(rangle))/Gravity;
    float distance = round((Velocity*cos(rangle))*timeTaken);
    if(distance==dist){
      cout << "Hit confirmed!" << endl; hit=true;
      cout << "You took " << shots << " shots to destroy target" << endl;
      break;
    }
    else if(distance>dist) cout << "Overshot by " << distance-dist << endl;
    else if(distance<dist) cout << "Undershot by " << dist-distance << endl;
  }
  if(hit==true) return true;
  else return false;
  return false;
}


int main(){
  Hello();
  int killed = 0;
  char done;
  do {
    bool res = tank();
    if(res==true) {
      killed++;
      cout << "New enemy tank spotted, shoot again? (y/n) " << endl;
      cin >> done;
    }
    else if(res==false){
      cout << "You used up your 10 shots !" << endl;
      cout << "Would you like to target another enemy? (y/n) " << endl;
      cin >> done;
    }
  } while (done != 'n');
  cout << "You eliminated " << killed << " tanks of the enemy." << endl;
return 0;
}
