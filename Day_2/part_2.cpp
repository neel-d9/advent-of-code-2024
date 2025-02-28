#include<bits/stdc++.h>
using namespace std;

unordered_map<bool, unordered_set<int>> valid_diffs = {
    {true,  { 1,  2,  3}},
    {false, {-1, -2, -3}}
};

void dampener(list<int>& diff, int& numpos, int& numneg, int& numzero) {
    bool order = numpos>=numneg;
    for(auto it = diff.begin(); it != diff.end(); ++it) {
        if(*it == 0) {
            numzero--;
            diff.erase(it);
            break;
        }
        auto sel = it;
        if(it == diff.begin() || next(it) == diff.end()) {
            sel = (it == diff.begin() ? next(it) : prev(it));
            if(valid_diffs[order].count(*it))
                continue;
            if(valid_diffs[order].count(*sel)) {
                if(*it<0) numneg--;
                if(*it>0) numpos--;
                diff.erase(it);
                break;
            }
        }
        else {
            if(order==(*it<0))
                sel = ((*prev(it)>=*next(it))==(order) ? prev(it) : next(it));
            else continue;
        }
        int pr = *it;
        *it += *sel;
        int merger = (*it < 0 && pr > 0) ? 1 : ((*it > 0 && pr < 0) ? -1 : 0);
        numneg += merger - (*sel < 0);
        numpos += -merger - (*sel > 0);
        diff.erase(sel);
        break;
    }
}

int main() {
    ifstream input_file("input.txt");
    if (!input_file) {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }
    int safe=0;
    string line;
    while(getline(input_file, line)) {
        istringstream ss(line);
        vector<int> levels;
        list<int> diffs;
        bool is_safe = true;
        int n=0, diff=0, numpos=0, numneg=0, numzero=0;

        while(ss >> n)
            levels.push_back(n);

        for(auto level = levels.begin(); level != levels.end(); ++level) {
            if(level == levels.begin())
                continue;
            diff = (*level)-(*prev(level));
            diff == 0 ? numzero++ : (diff > 0 ? numpos++ : numneg++);
            diffs.push_back(diff);
        }

        dampener(diffs, numpos, numneg, numzero);

        if(numzero>0) continue;
        if((numpos==0)==(numneg==0)) continue;
        bool order = numpos>=numneg;
        for(int diff : diffs)
            if(!valid_diffs[order].count(diff))
                is_safe = false;
        if(is_safe) safe++;
    }
    cout << safe << endl;
    input_file.close();
    return 0;
}
