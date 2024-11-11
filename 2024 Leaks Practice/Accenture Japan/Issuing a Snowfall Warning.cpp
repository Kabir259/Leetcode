#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <cmath>

int main() {
    double X;
    cin >> X;

    // Calculate the smallest integer Y that triggers the alarm
    int Y = ceil(X - 1);

    cout << Y << std::endl;

    return 0;
}