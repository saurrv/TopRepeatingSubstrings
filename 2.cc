#include<bits/stdc++.h>
using namespace std;

#define debug(X) cerr << " --> " << #X << " = " << X << endl

#include "process.h"

int main(int argc, char const *argv[])
{
    string str = "bananabanana";

    assert(argc == 3);

    int L = atoi(argv[1]), N = atoi(argv[2]);

    int small = ceil(exp(0.5 * (p + 1.000000) * log(n)));
    for(int cnt = 0; cnt * small < str.size(); ++cnt)
    {
        output[cnt] = process(str.substr(cnt * small, small), L, N);
    }

    return 0;
}
