#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream input_file("input.txt");
    if (!input_file) {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }
    string line;
    int count=0, a, b;
    multiset<int> v, u;
    
    while(getline(input_file, line)) {
        stringstream ss(line);
        ss >> a >> b;
        v.insert(a);
        u.insert(b);
    }
        
    auto ut = u.begin();
    for(auto it = v.begin(); it != v.end(); ++it) {
        count+=abs((*ut)-(*it));
        ++ut;
    }
    input_file.close();
    cout << count << endl;
    return 0;
}
