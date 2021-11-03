 #include <stdio.h>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    int dfs(TreeNode* currentNode, int prevValue)
    {
        int curValue = prevValue*10 + currentNode->val;
        int sum = 0;
        bool isLeaf= 1;
        if(currentNode->left != nullptr)
        {
            sum += dfs(currentNode->left, curValue);
            isLeaf=0;
        }
        
        if(currentNode->right != nullptr)
        {
            sum += dfs(currentNode->right, curValue);
            isLeaf=0;
        }
        if(isLeaf)
        {
            sum += curValue;
            printf("%d %d\n", curValue, currentNode->val);
        }
        
        
        return sum;
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

int main()
{
    TreeNode A;
    TreeNode B;
    TreeNode C;
    A.val = 1;
    A.left = &B;
    A.right = &C;
    B.val = 2;
    C.val = 3;
    Solution s;
    int res = s.sumNumbers(&A);
    printf("ans = %d\n",res);
    return 0;
}