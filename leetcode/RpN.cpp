#include <string>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
// transfer sting into number 
// push the number 
// comucate the number ,and into the deque
//return the result
int transformToNumber(string number,int & number_data)
{
      const char* temp = number.c_str();
    /*char * copy = new char [strlen(temp)+1];
    strcpy(copy,temp);
    int number_str = atoi(copy);*/
    cout<<"the number is "<< temp;
      int flag =0;
    number_data=0;
    for (int i=0;i<strlen(temp);i++)
    {
        if(temp[i]>'9'||temp[i]<'0')
        {
            if(flag==0)
            {
                if(temp[i]=='-')
                    flag =1;
                else if(temp[i]=='+')
                    flag =2;
                else 
                    return -1;
            }
            else 
                return -1;
        }
        else
        {
            if(flag ==0)
                flag =2;
            number_data =number_data *10 +(temp[i]-'0');
        }
    }
   if(flag == 1)
       number_data =0-number_data;
cout<< "number_data is "<<number_data;
//    return number_str;
}
int evalRPN(vector<string> &tokens) {
    deque<int> deque;
    vector<string>::iterator it = tokens.begin();
    for(;it!=tokens.end();it++)
    {
        cout<<"the string is "<<*it<<endl;
        if((*it =="+")||(*it=="-")||(*it=="*")||(*it=="/"))
        {
            if(deque.size()<2)
            {
                cout<<"the expression is error"<<endl;
                return -1;
            }
            int t1 =deque.front();
            deque.pop_front();
            int t2 =deque.front();
            deque.pop_front();
            if(*it=="+")
                t1=t1+t2;
            else if(*it=="-")
                t1=t2-t1;
            else if(*it=="*")
                t1=t1*t2;
            else
                t1= t2/t1;
            deque.push_front(t1);
        }
        else
        {
            int data=0;
            int temp =transformToNumber(*it,data);
            if(temp==-1){
                cout<<"the expression  is error";
                return -1;
            }
            deque.push_front(data);
            cout<<"push" << data<<endl;
        }
    }
    if(deque.size()>1||deque.empty())
        return -1;
    return deque.front();

 }
int main()
{
   // string temp ="-i23";
    //cout << transformToNumber(temp)<<endl;
    string array[]={"-4", "13", "5", "/", "+"};
    vector<string> vec(5);
//    array.assign(array,array+4);
  int i =0;
    for (vector<string>::iterator it=vec.begin();i<5;it++,i++)
    {      //cout<<*it <<endl;
    *it=*(array+i);
    cout<<*it<<endl;
    }cout<<evalRPN(vec)<<endl;
    return 1;
}
