#include <stdlib.h>
#include <iostream>
using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
            ListNode *sortList(ListNode *head) {
                
                //get the length
                if(head==NULL||head->next==NULL)
                    return head;
                ListNode * before =head->next;
                ListNode * after =head;
                ListNode * l1=head;
                ListNode * l2;
                for(;before!=NULL;){
                     if(before->next==NULL)
                         break;
                    before=before->next->next;
                    after =after->next;
                }
                l2=after->next;
                after->next =NULL;
               before= sortList(l1);
                after = sortList(l2);
                return mergeList(before,after);
                    
                //
                        
     }

        ListNode*  mergeList(ListNode * head1,ListNode * head2){
                ListNode * l1=head1;
                ListNode * l2= head2;
                ListNode * head;
                int flag =0;
                if(l2==NULL)
                 return l1;
                else if (l1==NULL)
                    return l2;
                ListNode * pre =NULL;
                ListNode * after =NULL;
                while(l2&&l1)
                {
                    if(l1->val < l2->val){
                        pre =l1;
                        l1=l1->next;
                    }
                    else{
                      if(pre){
                          pre->next =l2;
                
                      }
                     

                    after = l2->next;
                    l2->next =l1;
                    pre =l2;
                    l2=after ;
                    }
                    if(flag ==0){
                        flag =1;
                        head =pre;
                    }

                
            }
                if(l1==NULL)
                  pre->next =l2;
                return head;
            }
};
int main()
{
    ListNode * pre =NULL;
    ListNode * head;
//     for (int i =0;i<10;i++)
  //   {
         ListNode * temp= (ListNode *)malloc(sizeof(ListNode));
         temp->val =4;
         temp->next =pre;
         pre =temp;
    
    temp= (ListNode *)malloc(sizeof(ListNode));
    temp->val =5; 
    temp->next =pre;
    pre =temp;
     temp= (ListNode *)malloc(sizeof(ListNode));
    temp->val =6;
    temp->next =pre;
    pre =temp;
    // }
     head =pre;
     Solution s;
     ListNode * result =s.sortList(NULL);
     for (;result;result =result->next)
         cout<<result->val<<endl;
  return 1;
}
