//copied from https://github.com/saurv4u/Algorithm-Library

void buildLCP(const int n, const string& str, const vector<int>& suffixArray, const vector<int>& pos, vector<int>& lcp)
{
    lcp.resize(n - 1);
    for(int i = 0, k = 0; i < n; ++i)
    {
        if(pos[i] == n - 1)
        {
            k = 0;
            continue;
        }
        int j = suffixArray[pos[i] + 1];
        while(i + k < n && j + k < n && str[i + k] == str[j + k])
            ++k;
        lcp[pos[i]] = k;
        (k > 0) ? --k : 0;
    }
}
