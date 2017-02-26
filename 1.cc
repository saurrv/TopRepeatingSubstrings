#include<bits/stdc++.h>
using namespace std;

#define debug(X) cerr << " --> " << #X << " = " << X << endl

#include "process.h"

string str;
vector<pair<int, pair<int, int>>> out;

int main(int argc, char const *argv[])
{
	cin >> str;

	assert(argc == 4);

    int L = atoi(argv[1]), N = atoi(argv[2]);

    process(str, L, N, out);

    for(auto p : out)
    {
        printf("<%d, %d, %d>\n", p.first, p.second.first, p.second.second);
    }

    return 0;
}
