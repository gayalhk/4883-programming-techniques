//Gayal Hewakuruppu
//10226 - Hardwood Species
//Programming techniques - Dr Terry Griffin

#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

int main()
{   
    string tree_name;
    int cases;
    cin >> cases;

    for(int i=0;i<cases;i++)
    {   
        //Create map to track trees
        map <string, int> trees_list;  
        int num_trees = 0;
        cin>>tree_name;
        while(tree_name!="")
        {
            num_trees++;
            //Add tree to map
            trees_list[tree_name]++;
            cin>>tree_name;
        }
        
        //Traverse map and print out the tree name and percentage
        map <string , int> :: iterator j = trees_list.begin();
        while(j != trees_list.end()){
          cout << j->first << ' ' << fixed << setprecision(4) << j->second * (100.0/num_trees) << endl;
          j++;
        }
 
        cout<<endl;
    }

    return 0;
}
