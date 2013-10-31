#include <map>
#include <iostream>
using namespace std;
int main()
{
    map <int,int> dictory;
    for(int i =0;i<5;i++)
        dictory.insert(make_pair(i,i));
    for (map<int,int>::iterator it = dictory.begin();it!=dictory.end();it++)
        if(it->first==1)
             dictory.erase(it--);
        else
        cout<<" "<<it->second;
       
}
