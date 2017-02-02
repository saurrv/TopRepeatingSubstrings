void computeLeft(const int n, const vector<int>& lcp, vector<int>& lft)
{
    stack<int> stk;
    for(int i = 0; i < n - 1; ++i)
    {
        while(!stk.empty() && lcp[stk.top()] >= lcp[i])
            stk.pop();
        lft[i] = stk.empty() ? 0 : stk.top() + 1;
        stk.push(i);
    }
}

void computeRight(const int n, const vector<int>& lcp, vector<int>& rght)
{
    stack<int> stk;
    for(int i = n - 2; i >= 0; --i)
    {
        while(!stk.empty() && lcp[stk.top()] >= lcp[i])
            stk.pop();
        rght[i] = stk.empty() ? n : stk.top() + 1;
        stk.push(i);
    }
}
