
//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Gayal Hewakuruppu
// Email:            gayal.hewakuruppu07@gmail.com
// Course:           CMPS 4883 Programming Techniques
// Proffessor:       Dr Terry Griffin
// Description:      This program deals with a different type of queue called
//                   "team queue". It implements a team queue with the use of 
//                    traditional queues and vectors.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ifstream infile;  //Declare infile
    infile.open("input.txt");    //open input file
    int num_teams, teamSize, members, scenario, memID; //declare the variables
    string command;
    scenario= 1;

    infile>> num_teams; //read in the number of teams

    while(num_teams != 0){
        queue<int> teams; //Queue that stores the team number in order
        vector<queue<int>> teamMembers(1000); //Queue that stores team members in order
        vector <int> teamNum(1000000); //Queue to store each member's team number
        
    
        for(int i = 0; i <num_teams; i++){
            infile >> teamSize;  //read in the size of each team
            for(int j = 0; j <teamSize;j++){
                infile >> members;
                teamNum[members] = i;   //storing the team number in the vector
            }}

        cout << "Scenario #" << scenario++ << endl;
        infile >> command; //Begins reading the commands
        while (command != "STOP"){
            if(command == "ENQUEUE"){
                infile >> memID;
                if(teamMembers[teamNum[memID]].empty())
                    teams.push(teamNum[memID]);
                teamMembers[teamNum[memID]].push(memID);
            }

           if(command == "DEQUEUE"){
                cout<< teamMembers[teams.front()].front() << endl;
                teamMembers[teams.front()].pop();

                if(teamMembers[teams.front()].empty()){
                    teams.pop();
                }
            }
            infile >> command;
        }
        cout << endl;
        teamMembers.clear();
        teamNum.clear();
        infile>> num_teams;
    }
    infile.close(); //Close the output file
}
