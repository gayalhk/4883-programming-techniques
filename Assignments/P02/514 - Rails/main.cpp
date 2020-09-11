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
#include <vector>
#include <stack>

using namespace std;

int main(){
    ifstream infile;
    infile.open("input.txt");

    vector <int> Train;
    int index, N, C_id;
    stack <int> s;
    bool YES;
    
    infile>>N;

    while(N!=0){
        infile>>C_id;
        while(C_id!=0){
          Train.push_back(C_id);
        
            while(!s.empty())
            s.pop();
            index =1;
            YES = true;

            for(int x = 1; x<N;x++){
            infile>> C_id;
            Train.push_back(C_id);}
          
            for(int y=0;y<N;y++){
                if(Train[y]>index){ 
                    while(Train[y]!=index){
                        s.push(index);
                        index++;}
                    index++;
                  }

                else if(Train[y]<index){
                    if(s.size()>0){
                        if(s.top()==Train[y]){
                            s.pop();
                        }
                    }
                    YES =false;
                    break;
                } 
                
                else if(Train[y]==index){
                    index++;
                    }       
            }
            if(YES){
                cout << "Yes\n";}
            
            else{
                cout << "No\n";}

            infile>>C_id;
            }

        cout << endl;
        Train.clear();
        infile>>N;
    }
    infile.close();
}
