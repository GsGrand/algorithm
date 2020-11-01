#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string,::size_t> word_cnt;
    string word;
    while(cin>>word)
        word_cnt[word]++;
    for(const auto &i:word_cnt)
        cout << i.first <<" "<<i.second<< endl;
    return 0;
}