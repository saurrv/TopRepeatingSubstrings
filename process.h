#include "suffix_array.h"
#include "lcp.h"
#include "stack.h"
#include "scoring.h"

vector<int> lcp, pos, lft, rght, suffixArray, bit;
vector<node> arr;
set<pair<long long, int>> scores;
stack<int> stk;
vector<vector<int>> last;

void process(const string& str, const int L, const int N, vector<pair<int, pair<int, int>>>& out)
{
    lcp.clear(), pos.clear(), lft.clear(), rght.clear(), suffixArray.clear(), bit.clear(), arr.clear(), scores.clear(), last.clear();

    int n = str.size();

    buildSuffixArray(n, str, pos, suffixArray, arr, last);
    buildLCP(n, str, suffixArray, pos, lcp);
    pos.clear();

    computeLeft(n, lcp, lft, stk);
    computeRight(n, lcp, rght, stk);

    updateScores(n, lft, rght, lcp, suffixArray, L, N, out, scores, bit);
    lcp.clear(), suffixArray.clear(), lft.clear(), rght.clear();
}
