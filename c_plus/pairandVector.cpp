#include <vector>
#include <utility>
#include <iostream>
using namespace std;
int main()
{
    //pair<string,int> data;
    string key;
    int value;
    vector< pair<string,int> > temp;
    while(cin>>key>>value)
    {
        pair<string,int> data(key,value);
        temp.push_back(data);
    }
    vector< pair<string,int>  >::iterator  it = temp.begin();
    for(;it!=temp.end();it++)
    {
        cout<< " " << (*it).first <<","<< (*it).second << endl;
    }
    return 1;
}
