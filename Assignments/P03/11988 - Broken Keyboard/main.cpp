//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Gayal Hewakuruppu
// Email:            gayal.hewakuruppu07@gmail.com
// Course:           CMPS 4883 Programming Techniques
// Proffessor:       Dr Terry Griffin
// Description:      This program reads in a jumbled sentence with randomly placed brackets
//                   and outputs the correct sentence with the use of queues and stacks
//                    
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main(){
  string sentence; //Input string
  stack<string> S; //stack
  queue<char> characters; //queue to store characters in order
  

  while(getline(cin,sentence)){
    string ind, temp; //String to indicate charactor and temporary string
    ind = "F"; 
    temp = "";

    while(!S.empty()){ //Clears the stack if it isnt empty
      S.pop(); 
    }
    while(!characters.empty()){ //Clears the queue if it isnt empty
      characters.pop();
    }
     
    for(int i = 0; i < sentence.length();i++){
        if(sentence.at(i)=='[')
            ind = "H";  
       
        if(ind == "H"){
            if(sentence.at(i)==']'){
                if(temp !="")
                    S.push(temp);
                temp = "";
                ind="F";
            }
           
            else{
                if(sentence.at(i) == '['){
                    if(temp != "")
                      S.push(temp);
                temp= "";
                ind= "H";
                }
                else 
                    temp += sentence.at(i);
            }
        } 
        else{
            if(sentence.at(i)!= '[' && sentence.at(i) != ']')
                characters.push(sentence.at(i));
            }
    }
    if(ind=="H")
        S.push(temp);
    temp = "";

    while(!S.empty()){
        cout << S.top(); //print the beiju texts
        S.pop();
    }
  
    while(!characters.empty()){
        cout << characters.front(); 
        characters.pop();
    }
    cout << endl;
    temp= "";
}
}
