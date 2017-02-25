#include<bits/stdc++.h>
using namespace std;

#define debug(X) cerr << " --> " << #X << " = " << X << endl

#include "process.h"

int main(int argc, char const *argv[])
{
    string str = "bananabanana";
	cin >> str;

	assert(argc == 4);

    int L = atoi(argv[1]), N = atoi(argv[2]);

    vector<pair<int, pair<int, int>>> out = process(str, L, N);

    for(auto p : out)
    {
        printf("<%d, %d, %d>\n", p.first, p.second.first, p.second.second);
    }

    return 0;
}
