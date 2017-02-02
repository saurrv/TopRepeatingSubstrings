void update(vector<int> bit, int i, int v)
{
    while(i < bit.size())
    {
        bit[i] += v;
        i += (i & (-i));
    }
}

int query(vector<int> bit, int i)
{
    int r = 0;
    while(i > 0)
    {
        r += bit[i];
        i -= (i & (-i));
    }
    return r;
}
