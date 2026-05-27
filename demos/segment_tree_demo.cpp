#include <bits/stdc++.h>
#include "_utility.h"

using namespace std;

int main()
{
    cout << "========== SEGMENT TREE DEMO ==========\n\n";

    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Segment_Tree* sum_root = sum_tree(arr);

    while(true)
    {
        cout << "\n";
        cout << "1. Range Sum Query\n";
        cout << "2. Point Update\n";
        cout << "3. Exit\n";

        int choice;
        cin >> choice;

        if(choice == 1)
        {
            int l, r;

            cout << "Enter left and right index: ";
            cin >> l >> r;

            cout << "Sum: "
                 << sum_query(sum_root,l,r)
                 << endl;
        }
        else if(choice == 2)
        {
            int index, value;

            cout << "Enter index and new value: ";
            cin >> index >> value;

            sum_update(sum_root,index,value);

            cout << "Updated.\n";
        }
        else
        {
            break;
        }
    }

    delete sum_root;

    return 0;
}