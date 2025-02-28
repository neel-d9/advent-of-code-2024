#include<bits/stdc++.h>  
using namespace std;

int main() {
    ifstream input_file("input.txt");
    if (!input_file) {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }
    string line;
    int count=0, a, b;
    unordered_map<int, int> m;
    vector<int> v;  

    while(getline(input_file, line)) {
        stringstream ss(line);
        ss >> a >> b;
        v.push_back(a);
        m[b] += 1;
    }

    for(auto val : v) {
        int sim = m.find(val) == m.end() ? 0 : m[val];
        count += val*sim;
    }
    input_file.close();
    cout << count << endl;
    return 0;
}
