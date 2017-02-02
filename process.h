#include "suffix_array.h"
#include "lcp.h"
#include "stack.h"
#include "scoring.h"

vector<pair<int, pair<int, int>>> process(const string& str, const int L, const int N)
{
    int n = str.size();
    vector<int> pos(n), lft(n - 1), rght(n - 1);
    vector<int> suffixArray = buildSuffixArray(n, str, pos);
    vector<int> lcp = buildLCP(n, str, suffixArray, pos);

    computeLeft(n, lcp, lft);
    computeRight(n, lcp, rght);

    return updateScores(n, lft, rght, lcp, suffixArray, L, N);
}
