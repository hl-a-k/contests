#include <iostream>
#include <unordered_map>
using namespace std;

// Driver code
int main()
{
    unordered_map<string, int> umap;

    // inserting values by using [] operator
    umap["GeeksforGeeks"] = 10;
    umap["Practice"] = 20;
    umap["Contribute"] = 30;

    // Traversing an unordered map
    for (auto x : umap)
        cout << x.first << " " << x.second << endl;

    cout << umap["test"] << endl;

    auto k = umap.find("test");
    cout << (k == umap.end()) << endl;
    if (k != umap.end()) {
        cout << k->first << " " << k->second << endl;
    }

    k = umap.find("test1");
    cout << (k == umap.end()) << endl;
}
