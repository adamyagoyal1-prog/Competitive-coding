#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if(n == 1){
            cout << s << "\n";
            continue;
        }

        int freq[26] = {0};
        for(char c : s) freq[c - 'a']++;

       
        int mx = 0;
        char best = 'a';
        for(int i = 0; i < 26; i++){
            if(freq[i] > mx){
                mx = freq[i];
                best = 'a' + i;
            }
        }

        
        for(int i = 0; i < n; i++){
            if(s[i] != best){
                s[i] = best;
                break;
            }
        }

        cout << s << "\n";
    }
    return 0;
}
