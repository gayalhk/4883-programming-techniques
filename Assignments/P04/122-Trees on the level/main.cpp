//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Gayal Hewakuruppu
// Email:            gayal.hewakuruppu07@gmail.com
// Course:           CMPS 4883 Programming Techniques
// Proffessor:       Dr Terry Griffin
//
//
///////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*L=nullptr;
    Node*R=nullptr;
    bool assigned=false;// Is a node assigned?
};

bool f = true;

 void insert(int data, string s, Node *root){
    for (auto c : s) // Traverse the string 
        if (c == 'L'){
            if (root->L == nullptr)
                root->L = new Node();
            root = root->L;
        }
        else{
            if (root->R == nullptr)
                root->R = new Node();
            root = root->R;
        }
    if (root->assigned) //If the node is assigned
        f = false;   //The node is repeatedly assigned
    root->data = data;
    root->assigned = true; //Update the bool
}
bool levelTraversal(Node *root, vector<int> &level){
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
        root = q.front();
        q.pop();
        if (!root->assigned)
            return false;
            level.push_back(root->data);
        if (root->L != nullptr)
            q.push(root->L);
        if (root->R != nullptr)
            q.push(root->R);
    }
    return true;
}
int main(){
    string input;
    Node *root = new Node();
    while (cin >> input){
        if (input == "()"){ 
            vector<int> level;
             if (f && levelTraversal(root, level)){
                for (int i = 0; i < level.size(); ++i)
                    printf("%s%d", i > 0 ? " " : "", level[i]);
            }
            root = new Node();
            f = true;
        }
        else{
            int i = input.find(',');
            insert(stoi(input.substr(1, i - 1)), input.substr(i + 1, input.size() - 2 - i), root);
        }
    }
}
