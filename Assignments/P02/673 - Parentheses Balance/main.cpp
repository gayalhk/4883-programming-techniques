
//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Gayal Hewakuruppu
// Email:            gayal.hewakuruppu07@gmail.com
// Course:           CMPS 4883 Programming Techniques
// Proffessor:       Dr Terry Griffin
// Description:      This program takes a string containing paranthesis
//                   and checks if they are balanced.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ifstream infile;
  infile.open("input.txt");
  int n;
  stack <char> S;
  string paranthesis;
  
  infile >> n;
  getline(infile,paranthesis);
  for(int i=0; i < n; i++){
    bool balanced = false;
    getline(infile, paranthesis);
    if (paranthesis == ""){
      balanced = true;
      cout << "Yes"<<endl;  
    }
    for(int j=0; j < paranthesis.size() && balanced == false; j++){
        if(paranthesis[j]=='('){
          S.push(paranthesis[j]);
          break;}

        else if(paranthesis[j]=='['){
          S.push(paranthesis[j]);
          break;}

        else if(paranthesis[j]==')'){
          if(!S.empty()){
            if (S.top()=='(')
              S.pop();
            else{
              balanced = true;
              cout << "No"<<endl;
            }
          }
          else{
            balanced = true;
            cout << "No"<<endl;
          }
          break;
        }

        else if(paranthesis[j]==']'){
          if(!S.empty()){
            if (S.top()=='[')
              S.pop();
            else{
              balanced = true;
              cout << "No"<<endl;
            }
          }
          else{
            balanced = true;
            cout << "No"<<endl;
          }
          break;}
          
        else if(paranthesis[j]==' '){
          break;
        }
    }
    
    if(balanced == false){
      if(S.empty())
        cout << "Yes\n";
      else{
        cout << "No\n";
      }
    }
    
    while(!S.empty()){
      S.pop();
    }
  }
  infile.close();
}
