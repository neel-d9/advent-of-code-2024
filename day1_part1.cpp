#include <set>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    multiset<int> v, u;
    int locations, count=0;
    cin >> locations;
    for(int i = 0; i < locations; i++) {
        int a, b;
        cin >> a >> b;
        v.insert(a);
        u.insert(b);
    }
    auto ut = u.begin();
    for(auto it = v.begin(); it != v.end(); ++it) {
        count+=abs((*ut)-(*it));
        ++ut;
    }
    cout << "******************" << endl << count << endl;

    return 0;
}