#include<bits/stdc++.h>
using namespace std;

#define debug(X) cerr << " --> " << #X << " = " << X << endl

#include "process.h"

vector<pair<int, pair<int, int>>> out, current_output;

bool comp(const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b)
{
    return (long long)b.second.second * b.second.first < (long long)a.second.first * a.second.second;
}

string str;

int main(int argc, char const *argv[])
{
    cin >> str;

    assert(argc == 4);

    int L = atoi(argv[1]), N = atoi(argv[2]);
    double p = atof(argv[3]);

    int small = ceil(exp(0.5 * (p + 1.000000) * log(str.size())));
    for(int cnt = 0; cnt * small < str.size(); ++cnt)
    {
        process(str.substr(cnt * small, small), L, N, current_output);
        for(auto current : current_output)
            out.push_back(current);
    }

    sort(out.begin(), out.end(), comp);

    for(auto p : out)
    {
        printf("<%d, %d, %d>\n", p.first, p.second.first, p.second.second);
    }

    return 0;
}
