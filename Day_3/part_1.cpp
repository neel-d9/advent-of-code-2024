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
    regex instruction("mul\\((\\d+),(\\d+)\\)");
    long long int total=0;
    
    while(getline(cin, line)) {
        while(regex_search(line, matches, instruction)) {
            total += stoll(matches[1]) * stoll(matches[2]);
            line = matches.suffix().str();
        }
    }
    cout << total << endl;    
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

void parse_num(int& index, bool& goback) {
    char ch;
    int numind=0;
    pair<int, bool> number[] = {{0,false},{0,false}};
    while(cin.get(ch)) {
        if((ch-'0')>=0 && (ch-'0')<=9) {
            number[numind].first=number[numind].first*10+ch;
            // while(cin.get(ch)) {
            //     number[numind].first=number[numind].first*10+ch;
            //     if(ch==',') {
            //         numind++;
            //         break;
            //     }
            // }
            if(ch==',') {
                numind++;
                break;
            }
        }
        
        else if(ch=='m') {
            index=1;
            return;
        }
        else {
            goback=true;
            return;
        }
    }
}

int main() {
    if(!freopen("input.txt", "r", stdin)) {
        cerr << "Error: input.txt not found!\n";
        return 1;
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    char ch;
    int index=0;
    bool goback=false;
    string match="mul(";
    while(cin.get(ch)) {
        if(ch == 'm') {
            index=1;
            while(cin.get(ch) && !goback) {
                if(ch==match[index]) {
                    if(index<3) index++;
                    else {
                        parse_num(index, goback);
                        goback=true;
                    }
                }
                else if(ch==match[0]) index=1;
                else break;
            }
            // if(!cin.get(ch)) break;
            // if(ch == 'u') {
            //     if(!cin.get(ch)) break;
            //     if(ch == 'l') {

            //     }
            // }
        }
    }
    
    return 0;
}
*/
