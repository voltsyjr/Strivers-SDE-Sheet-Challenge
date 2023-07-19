#include <bits/stdc++.h>
vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return {};
    queue<TreeNode<int> *> q;
    q.push(root);
    int rev = 0;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            temp.push_back(q.front()->data);
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        if (rev == 1)
            reverse(temp.begin(), temp.end());
        for (auto it : temp)
            ans.push_back(it);
        rev = rev == 0 ? 1 : 0;
    }
    return ans;
}