#include<bits/stdc++.h>
using namespace std;

int main() {
    if(!freopen("input.txt", "r", stdin)) {
        cerr << "Error: input.txt not found!\n";
        return 1;
    }
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    smatch matches;
    regex instruction("do\\(\\)|don't\\(\\)|mul\\((\\d+),(\\d+)\\)");
    long long int total=0;
    bool do_flag = true;

    while(getline(cin, line)) {
        while(regex_search(line, matches, instruction)) {
            switch(matches[0].str()[0]) {
                case 'd':
                    do_flag = matches[0].str()[2]=='n' ? false : true;
                    break;
                case 'm':
                    if(do_flag)
                        total += stoll(matches[1]) * stoll(matches[2]);
            }
            line = matches.suffix().str();
        }
    }
    cout << total << endl;
    return 0;
}