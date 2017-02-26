void computeLeft(const int n, const vector<int>& lcp, vector<int>& lft, stack<int>& stk)
{
    while(!stk.empty())
        stk.pop();
    lft.resize(n - 1);
    for(int i = 0; i < n - 1; ++i)
    {
        while(!stk.empty() && lcp[stk.top()] >= lcp[i])
            stk.pop();
        lft[i] = stk.empty() ? 0 : stk.top() + 1;
        stk.push(i);
    }
    while(!stk.empty())
        stk.pop();
}

void computeRight(const int n, const vector<int>& lcp, vector<int>& rght, stack<int>& stk)
{
    while(!stk.empty())
        stk.pop();
    rght.resize(n - 1);
    for(int i = n - 2; i >= 0; --i)
    {
        while(!stk.empty() && lcp[stk.top()] >= lcp[i])
            stk.pop();
        rght[i] = stk.empty() ? n : stk.top() + 1;
        stk.push(i);
    }
    while(!stk.empty())
        stk.pop();
}
