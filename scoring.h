#include "bit.h"

vector<pair<int, pair<int, int>>> updateScores(const int n, const vector<int>& lft, const vector<int>& rght, const vector<int>& lcp, const vector<int>& suffixArray, const int L, const int N)
{
    vector<pair<int, pair<int, int>>> output;

    set<pair<long long, int>> scores;

    for(int i = 0; i < n - 1; ++i)
    {
        scores.insert({(long long)(lft[i] - rght[i]) * lcp[i], i});
    }

    vector<int> bit(n + 5, 0);

    for(; output.size() < N && !scores.empty(); )
    {
        int i = scores.begin() -> second;
        scores.erase(scores.begin());

        if(lcp[i] < L || query(bit, i))
            continue;

        /*
        TODO: if ana is taken, na is also taken at later stage.

        bool add = true;
        for(auto p : output)
        {
            if(checkSubstring(str, p.first, p.second, suffixArray[i], lcp[i]))
            {
                add = false;
                break;
            }
        }
        if(!add)
            continue;*/
        output.push_back({suffixArray[i], {lcp[i], rght[i] - lft[i]}});

        int l = lft[i], r = rght[i];
        if(!l)
            ++l;
        update(bit, l, 1);
        update(bit, r, -1);
    }

    return output;
}
