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

  int T,total,amount;
  string command;
  total = 0;

  cin >> T;

  for(int i = 0; i < T; i++){
    cin >> command;

    if(command == "donate"){
      cin >> amount;
      total += amount;
    }
    
    else if(command == "report"){
      cout << total <<endl;
    }
  }
}
