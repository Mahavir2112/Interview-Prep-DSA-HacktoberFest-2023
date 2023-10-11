class Solution
{
    public:
    
    pair<bool, int> check(Node *root)
    {
        pair<bool, int> ans;
        if(root->left==NULL && root->right==NULL)
        {
            ans.first=1;
            ans.second=root->data;
            return ans;
        }
        
        pair<bool, int> x;
        pair<bool,int> y;
        
        if(root->left!=NULL)
            x=check(root->left);
            
        else
        {
            x.first=1;
            x.second=0;
        }
            
        if(root->right!=NULL)
            y=check(root->right);
            
        else
        {
            y.first=1;
            y.second=0;
        }
            
        if(root->data==x.second+y.second)
        {
            if(x.first==1 && y.first==1)
            ans.first=1;
            
            else
            ans.first=0;
            
            ans.second=x.second+y.second+root->data;
            return ans;
        }
        
        else
        {
            ans.first=0;
            ans.second=x.second+y.second+root->data;
            return ans;
        }
    }
    
    bool isSumTree(Node* root)
    {
        pair<bool, int> haha=check(root);
        return haha.first;
    }
};
