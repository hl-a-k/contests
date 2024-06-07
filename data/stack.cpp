#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    for (int i=0; i<10; i++) {
        st.push(i);
    }

    while (!st.empty())
    {
        int t = st.top();
        st.pop();
        
        cout << t << " ";
    }
    cout << endl;
    return 0;
    
}