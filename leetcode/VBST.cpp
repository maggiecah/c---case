#include<stdlib.h>
#include<iostream>
using namespace std;
 // Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
#define MAX 2147483647
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        pre= (int *)malloc(sizeof(int));
        *pre =MAX;
        return InorderTree(root);
        
    }
    bool InorderTree(TreeNode * root )
    {
        if(root==NULL)
            return true;
        if(root->left){
            bool temp=InorderTree(root->left);
            if(temp==false)
                return false;
        }
        //data
        //cout<<*pre<<endl;
        if(*pre ==MAX)
            *pre = root->val;
        else if(root->val<*pre ||root->val==*pre){
            return false;
        }
        else
            *pre=root->val;
        //right
        if(root->right){
            bool isValid=InorderTree(root->right);
            if(isValid == false)
                return false;
        }
        return true;
    }
    
private:
    int *pre;
};
