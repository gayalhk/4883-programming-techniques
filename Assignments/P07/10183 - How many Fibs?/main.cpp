//Gayal Hewakuruppu
//10183 - How many Fibs?
//Programming techniques - Dr Terry Griffin

#include <iostream>
#include <vector>

using namespace std;

int main()
{   
  vector<int> Fibs;
  int next_fib;
  int num_fibs=0;
  int max = 1000000000;

  Fibs.push_back(1);
  Fibs.push_back(2);
  next_fib = Fibs[Fibs.size()-1] + Fibs[Fibs.size()-2];
  
  while(next_fib<=(max)){
    Fibs.push_back(next_fib);
    next_fib = Fibs[Fibs.size()-1] + Fibs[Fibs.size()-2]; 
  }

  int lower,upper;
  cin>>lower>>upper;

  while((lower!=0)&&(upper!=0)){
    for(int i=0;i<Fibs.size();i++){
      if((Fibs[i]>=lower)&&(Fibs[i]<=upper)){
        num_fibs++;
      }
      else if(Fibs[i]>upper){
        break;
      }
    }
    cout<<num_fibs<<endl;
    num_fibs=0;
  }

  return 0;
}
