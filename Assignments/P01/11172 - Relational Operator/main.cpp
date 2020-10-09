//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Gayal Hewakuruppu
// Email:            gayal.hewakuruppu07@gmail.com
// Course:           CMPS 4883 Programming Techniques
// Proffessor:       Dr Terry Griffin
//
// Description:      This program takes two values from an input file, compares them
//                   and outputs the relational operator that relates to them.
//       
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  int num, first, second;

  cin>>num;

  for(int i = 0; i < num; i++)
  {
    cin >> first >> second;
    if (first > second)
      cout << ">" <<endl;
    else if(first < second)
      cout << "<" << endl;
    else 
      cout << "=" << endl;
  }

}
