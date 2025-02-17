#include<iostream>
#include<unordered_map>
#include<vector>    
using namespace std;

int main() {
    int locations, count=0;
    cin >> locations;
    unordered_map<int, int> m;
    vector<int> v;  
    for(int i = 0; i < locations; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(a);
        m[b] += 1;
    }
    for(auto val : v) {
        int sim = m.find(val) == m.end() ? 0 : m[val];
        count += val*sim;
    }
    cout << "******************" << endl << count << endl;
    return 0;
}