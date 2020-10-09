//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Gayal Hewakuruppu
// Email:            gayal.hewakuruppu07@gmail.com
// Course:           CMPS 4883 Programming Techniques
// Proffessor:       Dr Terry Griffin
//
// Description:      This program carries out 2 main operations.    
//                    1) Doante a certain amount 
//                    2) Display the total
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream infile;
  infile.open("input.txt");

  int T,total,amount;
  string command;
  total = 0;

  infile >> T;

  for(int i = 0; i < T; i++){
    infile >> command;

    if(command == "donate"){
      infile >> amount;
      total += amount;
    }
    
    else if(command == "report"){
      cout << total <<endl;
    }
  }
  infile.close();
}
