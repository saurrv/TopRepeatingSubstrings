//copied from https://github.com/saurv4u/Algorithm-Library

struct node
{
    int index;
    int first, second;
    bool operator < (const node b) const
    {
        return (first == b.first) ? (second < b.second) : (first < b.first);
    }
    bool operator == (node b)
    {
        return (first == b.first && second == b.second);
    }
};

vector<int> buildSuffixArray(const int n, const string& str, vector<int>& pos)
{
    vector<vector<int>> last(22, vector<int> (n));
    vector<node> arr(n);
    vector<int> suffixArray(n);

    for(int i = 0; i < n; ++i)
        last[0][i] = str[i] -'a';
    for(int step = 1, done = 1; done < n; done <<= 1, ++step)
    {
        for(int i = 0; i < n; ++i)
        {
            arr[i].index = i;
            arr[i].first = last[step - 1][i];
            arr[i].second = ((i + done < n) ? last[step - 1][i + done] : -1);
        }

        sort(arr.begin(), arr.end());

        for(int i = 0; i < n; ++i)
        {
            if(i > 0 && arr[i] == arr[i - 1])
                last[step][arr[i].index] = last[step][arr[i - 1].index];
            else
                last[step][arr[i].index] = i;
        }
    }

    int step = ceil(log2(n));

    for(int i = 0; i < n; ++i)
    {
        suffixArray[last[step][i]] = i;
        pos[i] = last[step][i];
    }
    return suffixArray;
}
