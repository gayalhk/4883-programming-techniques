//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Gayal Hewakuruppu
// Email:            gayal.hewakuruppu07@gmail.com
// Course:           CMPS 4883 Programming Techniques
// Proffessor:       Dr Terry Griffin
//
// Description:      This program takes 3 people's salaries and determines the  
//                   middle vaue of the 3 in order to decide which employee is 
//                   not to be layed off.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

using namespace std;

int main(){

  int T;
  int Salaries[3];

  cin >> T;

  for(int i = 0; i < T; i++){
    cin >> Salaries[0] >> Salaries[1] >> Salaries[2];
    for(int a = 0; a < 2; a++)
    {
      for(int b = 0; b < 2 - a; b++)
      {
        if(Salaries[b] > Salaries[b+1])
        {
          int temp = Salaries[b];
          Salaries[b] = Salaries[b+1];
          Salaries[b+1] = temp;
        }
      }
    }
    cout << "Case " << i+1 << ": " << Salaries[1] << endl;
  }
}
