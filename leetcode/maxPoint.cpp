#include<vector>
#include <map>
#include <iostream>
#define MAX -999999
using namespace std;
//  Definition for a point.
    struct Point {
          int x;
           int y;
            Point() : x(0), y(0) {}
             Point(int a, int b) : x(a), y(b) {}
          };
          
class Solution {
    public:
            int maxPoints(vector<Point> &points) {
     //calculate the xielv
     int max =0;
     int currentmax =0;
     vector<Point>::size_type it=points.size();
     if(it==0) return max;
     int i =0;
     int flag =0;
     for(;i<it;i++)
     {   
         map<float,int> record;
         int j =i+1;
         flag =0;
         currentmax =0;
         //cout<<i<<j<<it<<endl;
         for(;j<it;j++)
         {
            if(points[i].x==points[j].x&&points[j].y==points[i].y)
            {  flag++; 
             
                continue;
            }
                cout << "a is  "<<" " << points[i].x <<","<<points[i].y<<"; b is "<<" "<< points[j].x<<","<<points[j].y<<endl;
             float k =getK(points[i],points[j]);
            cout<<"k is"<<k<<endl;
             map<float,int>::iterator  it3=record.find(k);
            if(it3==record.end())
                 record[k]=1;                      // cout<<"we do not find 112"<<endl;
             else{ 
                 record[k]=it3->second+1;
             }
             if(record[k]>currentmax){
                currentmax =record[k];
             }

         }
         if(flag>0)
             currentmax=currentmax+flag;
         if(currentmax>max)
             max =currentmax;
     }
     //get the number of appearence
     return max+1;
}
   float getK(Point& a,Point& b)
   {
       if(b.x==a.x)
           return MAX;
       else
       return (float) (b.y-a.y)/(float)(b.x-a.x);
   }
};

int main()
{
    Solution s;
    Point a1 (0,0);
    Point a2 (0,0);
    Point a3 (0,2);
    Point a4 (4,5);
    vector<Point>points;
    points.push_back(a1);
    points.push_back(a2);
    points.push_back(a3);
    points.push_back(a4);
    vector<Point>::iterator it =points.begin();
    for(;it!=points.end();it++)
       cout << it->x <<" "<< it->y <<endl;
    cout<<s.maxPoints(points)<<endl;
    return 1;
}
