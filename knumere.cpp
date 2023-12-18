#include <bits/stdc++.h>
using namespace std;

ifstream fin("knumere.in");
ofstream fout("knumere.out");

deque<int> dq;
int v[1000003], diferente[1000003];

int main()
{

    int sol = INT_MAX;
    int n, k;

    fin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        fin >> v[i];
        if (i > 1)
        {
            diferente[i - 1] = v[i] - v[i - 1];
        }
    }

    for (int i = 1; i < n; i++)
    {
        while (!dq.empty() && diferente[i] >= diferente[dq.back()])
            dq.pop_back();

        dq.push_back(i);

        if (!dq.empty() && dq.front() <= i - (n - k - 1))
            dq.pop_front();

        if (i >= n - k - 1)
            sol = min(sol, diferente[dq.front()]);
    }

    fout << sol;
}