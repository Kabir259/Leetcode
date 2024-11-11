#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x;
    cin >> n >> x;

    vector<int> ages(n);
    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }

    auto it = find_if(ages.begin(), ages.end(), [&](int age) { return age < x; });
    bool has_minor = it != ages.end();

    if (has_minor) {
        cout << "Soft Drink" << endl;
    } else {
        cout << "Alcoholic Beverages" << endl;
    }

    return 0;
}