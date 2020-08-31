//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Gayal Hewakuruppu
// Email:            gayal.hewakuruppu07@gmail.com
// Course:           CMPS 4883 Programming Techniques
// Proffessor:       Dr Terry Griffin
//
// Description:      This program takes 3 values (legth,width and height) and   
//                   checks if it fits a 20x20x20 suitcase.
//                   
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream infile;
  infile.open("input.txt");

  int T;
  int length,width,height;

  infile >> T;

  for(int i = 0; i < T; i++){
    infile >> length >> width >> height;

    if((length<=20) && (height<=20) && (height<=20)){
      cout << "Case " << i+1 << ": good" << endl;
    }
    
    else{
      cout << "Case " << i+1 << ": bad" << endl;
    }
  }
  infile.close();
}
