#include<bits/stdc++.h>
using namespace std;

char v[5] = {'a', 'e', 'i', 'o', 'u'}; // 모음 배열
string long_vowels[2] = {"ee", "oo"}; // 긴 모음
stack<char> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str; // string 변수 선언
    char ch[str.length()]; // char 배열 선언

    getline(cin, str);
    strcpy(ch, str.c_str());


    for (int i = 0; i < str.length(); i++) {
        if (s.empty()) {
            s.push(ch[i]);
        }


    }


    return 0;
}
