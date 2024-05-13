#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv)
{
    int d, s, n, idx;
    vector<vector<int>> vs;
    priority_queue<int> pq;
    sort(vs.begin(), vs.end());
    while (idx < n && s >= vs[idx][0])
    {
        pq.push(vs[idx][1]);
        idx++;
    }

    while (d-- && !pq.empty())
    {
        s += pq.top();
        pq.pop();
        while (idx < n && s >= vs[idx][0])
        {
            pq.push(vs[idx][1]);
            idx++;
        }
    }
    return s;
}