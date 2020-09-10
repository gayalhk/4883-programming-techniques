//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Gayal Hewakuruppu
// Email:            gayal.hewakuruppu07@gmail.com
// Course:           CMPS 4883 Programming Techniques
// Proffessor:       Dr Terry Griffin
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main(){
  ifstream infile;
  infile.open("input.txt");

  vector<stack<string>> DeckOfCards(52);
  bool running = true;
  string Card;

  while (running){                     
        for (int i = 0; i < DeckOfCards.size(); i++){
          infile >> Card;
          if (Card == "#"){
                i = 100;
                running = false;}
          else
                DeckOfCards[i].push(Card);
         }
    
  if (!running)
            break;

  for (int i = 1; i < DeckOfCards.size(); i++){
            if (i >= 3 && 
            (DeckOfCards[i].top().at(0) == DeckOfCards[i - 3].top().at(0) 
            || DeckOfCards[i].top().at(1) == DeckOfCards[i - 3].top().at(1))){

                DeckOfCards[i - 3].push(DeckOfCards[i].top());
                DeckOfCards[i].pop();

                if (DeckOfCards[i].empty()){
                    DeckOfCards.erase(DeckOfCards.begin() + i, DeckOfCards.begin()+(i + 1));
                }
                i -= 4;                                         
            }
            if (i >= 1 && 
            (DeckOfCards[i].top().at(0) == DeckOfCards[i - 1].top().at(0) 
            || DeckOfCards[i].top().at(1) == DeckOfCards[i - 1].top().at(1))){

                DeckOfCards[i - 1].push(DeckOfCards[i].top());
                DeckOfCards[i].pop();

                if (DeckOfCards[i].empty()){
                    DeckOfCards.erase(DeckOfCards.begin() + i, DeckOfCards.begin()+(i + 1));                               }
                i -= 2;}
        }

        if(DeckOfCards.size() == 1)
            cout << DeckOfCards.size() << " pile remaining: ";
        else
            cout << DeckOfCards.size() << " piles remaining: ";
        
        for (int i = 0; i < DeckOfCards.size(); i++){
            cout << DeckOfCards[i].size();

            if(i != DeckOfCards.size() - 1)
                cout << ' ';  
        }
        cout << endl;
    }
    infile.close();
}
