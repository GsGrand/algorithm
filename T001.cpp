#include<iostream>
#include<vector>
#define MAX 3
using namespace std;
vector<int> a(MAX, 0), book(MAX, 0);
void dfs(int step){
    if(step==MAX){
        for(int i:a)
            cout << i << " ";
        cout<<endl;
        return;
    }

    for (int i = 0; i < MAX;i++){
        if(book[i]==0){
            a[step] = i;
            book[i] = 1;
            dfs(step + 1);
            book[i] = 0;
        }
    }
}
int main(){
    dfs(0);
    return 0;
}