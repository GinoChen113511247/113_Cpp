#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int squares_in_circle(int r, int a) {
    vector<pair<int, int>> result;
    int limit;

    if (r < 1 || r > 100 || a < 1 || a > 100) {
        return -1;
    }

    if (a == 0) {
        return -1; // Handling zero division case
    }

    limit = r / a ; //+ 1;
    for (int i = -limit; i <= limit; ++i) {
        for (int j = -limit; j <= limit; ++j) {
            int x = i * a;
            int y = j * a;
            if (sqrt(x * x + y * y) + (a * sqrt(2)) / 2 <= r) {
                result.push_back({x, y});
            }
        }
    }

    sort(result.begin(), result.end(), compare);

    if (!result.empty()) {
        for (auto &p : result) {
            cout << p.first << ", " << p.second << endl;
        }
    } else {
        cout << "No squares can fit!" << endl;
    }
    return 0;
}

int main() {
    int r, a;

    cin >> r;
    cin >> a;
    squares_in_circle(r, a);

    //system("pause");
    return 0;
}
