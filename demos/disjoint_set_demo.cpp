#include <bits/stdc++.h>
#include "_utility.h"

using namespace std;

int main()
{
    cout << "========== DISJOINT SET DEMO ==========\n\n";

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    DisjointSet dsu(n);

    while(true)
    {
        cout << "\n";
        cout << "1. Union Sets\n";
        cout << "2. Find Parent\n";
        cout << "3. Check Connected\n";
        cout << "4. Exit\n";

        int choice;
        cin >> choice;

        if(choice == 1)
        {
            int u, v;

            cout << "Enter u and v: ";
            cin >> u >> v;

            dsu.union_sets(u,v);

            cout << "Union Completed.\n";
        }
        else if(choice == 2)
        {
            int node;

            cout << "Enter node: ";
            cin >> node;

            cout << "Parent: " << dsu.find(node) << endl;
        }
        else if(choice == 3)
        {
            int u, v;

            cout << "Enter u and v: ";
            cin >> u >> v;

            if(dsu.find(u) == dsu.find(v)){
                cout << "Connected\n";
            }
            else{
                cout << "Not Connected\n";
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}