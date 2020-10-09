//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Gayal Hewakuruppu
// Email:            gayal.hewakuruppu07@gmail.com
// Course:           CMPS 4883 Programming Techniques
// Proffessor:       Dr Terry Griffin
//
// Description:      This program reads in coordinates from an input file and 
//                   determines its location compared to a given division point
//       
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;

int main(){

  int K,x,y, divPoint[2];

  cin>>K;
  while(K!=0){
    cin>> divPoint[0] >> divPoint[1];

    for(int i=0;i<K;i++){
        cin>> x >> y;

        if(x > divPoint[0])
      {
        if(y > divPoint[1])
          cout << "NE" << endl;
        else if(y < divPoint[1])
          cout << "SE" << endl;
        else 
          cout << "divisa" << endl;
      }
      else if(x < divPoint[0])
      {
        if(y > divPoint[1])
          cout << "NO" << endl;
        else if(y < divPoint[1])
          cout << "SO" << endl;
        else 
          cout << "divisa" << endl;
      }
      else
        cout << "divisa" << endl;
    }
    cin>>K;
  }
}
