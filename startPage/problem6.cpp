// Copyright (c) 2017 Abhineet Dubey. All rights reserved.
// Use of this source code is governed by the GPLv3 license that can be
// found in the LICENSE file.
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>

using namespace std;

struct webData{
  string name;
  string link;
};

void getInput(int&,vector<webData>&);
bool buildPage(vector<webData>&);

int main(){

  int totalIndex; vector<webData> siteList;
  cout << "Welcome to Firefox start page builder" << endl;
  cout << "please enter the number of websites you want in the start page" << endl;
  cin >> totalIndex;
  getInput(totalIndex,siteList);
  bool ret = buildPage(siteList);
  if(ret) cout << "Start Page generated succesfuly\n";
  else cout << "There was an error writing the file startpage.html\n";
  return 0;
}

void getInput(int& ti, vector<webData>& sl){
  string input1,input2;
  cout << "Enter your choice: websiteName <space> websiteLink\n";
  for(int i=1; i<=ti;i++){
    cout << "Enter your choice number: "  << i << endl;
    cin >> input1 >> input2;
    webData wd;
    wd.name = input1;
    wd.link = input2;
    sl.push_back(wd);
    //wd.clear(); input1=input2="";
  }
}

bool buildPage(vector<webData>& w){
  ofstream of;
  string fileName = "startpage.html";
  of.open(fileName,ios::out|ios::trunc);
  if(of.is_open()){
    //start the webpage structure
    of << "<html>" << endl << "<head>" << "<link rel=\"stylesheet\" href=\"stylepage.css\">"
      << endl << "<title>startpage</title>"<< endl << "</head>" << endl << "<body>" << endl;
    //table structure
    of << "<table class=\"box\"  border=\"1px\"><tr><th></th><th></th></tr>" << endl;
    //adding all site name and link into table
    for(int j=0;j<w.size();j++){
      of << "<tr><td>" << w[j].name << "</td><td>" << "<a href=\"http://www." << w[j].link << "\">" << w[j].link  << "</a></td></tr>" << endl;
    }
    //close off table, body and document
    of << "</table>" << endl << "</body>" << endl << "</html>" << endl;
  }
  else return false;
  of.close();
  return true;
}
