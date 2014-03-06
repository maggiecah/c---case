#include <map>
#include <iostream>
using namespace std;
int main()
{
    map <int,int> dictory;
    for(int i =1;i<6;i++)
        dictory.insert(make_pair(i,i));
    for (map<int,int>::iterator it = dictory.begin();it!=dictory.end();it++)
        if(it->first==3){
          // it--;
            dictory.erase(it);
          // it--;
        }
        else
        cout<<" "<<it->second;
       
}
