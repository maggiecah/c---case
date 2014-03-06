#include <stdlib.h>
#include <iostream>
#include <map>
using namespace std;
#define MAX 2147483647
typedef struct Node {
    int value;
    int preKey;
    int afterKey;
} Node;
typedef struct mapHead{

    int head;
    int capacity;
    int size;
    int tail;
}mapHead;

class LRUCache{
    public:
     LRUCache(int capacity) {
        
            head=(mapHead *) malloc(sizeof(mapHead));
            head->head = MAX;
            head->capacity =capacity;
            head->size =0;
            head->tail =MAX;
     }
                
     int get(int key) {
    
         map<int ,Node*>::iterator  l_it;
         l_it =cacheMap.find(key);
         if(l_it==cacheMap.end()||l_it->second==NULL)
         {
             cout<<-1<<endl;
             return -1;
         }
         else
         {
             if(head->head==key){
                cout<<cacheMap[key]->value<<endl;
                return cacheMap[key]->value;
             }

             Node * node =cacheMap[key];

             //node->value =value;
             int preKey =cacheMap[key]->preKey;
             int afterKey =cacheMap[key]->afterKey;
             if(afterKey!=MAX)
                 cacheMap[afterKey]->preKey = preKey;
                 cacheMap[preKey]->afterKey =cacheMap[key]->afterKey;
             if(node->afterKey ==MAX&&preKey!=MAX)
                 head->tail = preKey;
             cacheMap[head->head]->preKey =key;
             node->afterKey=head->head;
           node->preKey =MAX;
             head->head = key;
            cout<< node->value<<endl;
             return node->value;
         }
    }
    
     void set(int key, int value) {
         map<int ,Node* >::iterator l_it;; 
            l_it=cacheMap.find(key);
               if(l_it==cacheMap.end()||l_it->second ==NULL)
               {
                   //insert a new node
                   //
                   if(head->size ==head->capacity)
                   {
                     
                       int preKey =cacheMap[head->tail]->preKey;
                        if(preKey !=MAX)
                        cacheMap[preKey]->afterKey =MAX;
                        else
                            head->head=MAX;
                        Node * tail = cacheMap[head->tail];
                        free(tail);
                        cacheMap[head->tail]=NULL;
                        head->tail = preKey;
                        
                   }
               
                   Node * node =(Node *) malloc(sizeof(Node));
                   node->afterKey = head->head;
                   if(node->afterKey!=MAX){
                       Node * temp= cacheMap[head->head];
                   
                       temp->preKey =key;
                       //cout<<temp->preKey<<endl;
                   }


                   //cout<<cacheMap[head->head]->preKey<<endl;
                   node->preKey = MAX;
                   head->head = key;
                   if(head->size<head->capacity)
                   (head->size) ++;
                   if(head->tail ==MAX)
                       head->tail = key;
                   node ->value = value;
                   cacheMap[key]=node;
               }


               else
               {
                   //change the value
                   if(head->head == key){
                    cacheMap[key]->value=value;
                    return;
                   }
                   Node * node =cacheMap[key];
                    node->value =value;
                    int preKey =cacheMap[key]->preKey;
                    int afterKey = cacheMap[key]->afterKey;
                    if(afterKey!=MAX)
                        cacheMap[afterKey]->preKey = preKey;
                    else
                    {
                        head->tail = preKey;
                    }
                        cacheMap[preKey]->afterKey =cacheMap[key]->afterKey;
                    cacheMap[head->head]->preKey =key;
                    node->afterKey=head->head;
                    node->preKey =MAX;
                    head->head =key;


               }
    }
    private:
      mapHead *head;
     map<int ,Node*> cacheMap;
};
int main()
{
    LRUCache m(2);
   m.set(2,1);m.set(1,1);m.set(2,3);m.set(4,1);m.get(1);m.get(2);
//    m.set(2,1);m.set(1,1);cout<<m.get(2)<<endl;m.set(4,1);cout<<m.get(1)<<endl;cout<<m.get(2)<<endl;
    //m.set(1,1);m.set(2,2);m.set(3,3);m.set(4,4);m.get(4);m.get(3);m.get(2);m.get(1);m.set(5,5);m.get(1);m.get(2);m.get(3);m.get(4);m.get(5);
    /*m.set(1,5);
    m.set(2,6);
    m.set(3,7);
    m.set(4,8);
    m.set(5,9); 
    cout<<m.get(2)<<endl;
*/    return 1;
}
