/**
 * Author:Gzking
 * Date  :2020-10-26
 * Task  :DFS解决用1~9摆出成立的加法式子,将结果式子保存在T002.dat中，并输出这样的式子个数
*/
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

vector<int> a(10, 0);      //***+***=***式子中的数字
vector<int> book(10, 0);   //记录1~9的使用情况

ofstream out("T002.dat", ios::out);

int ans=0;
//***+***=***中第step个数字的解决
void dfs(int step){
    //如果式子数字齐了
    if(step==10){
        //如果这个式子数学上成立，打印
        if((a[1]*100 + a[2] * 10 + a[3]  + a[4]* 100 + a[5] * 10 + a[6] ) == (a[7]* 100 + a[8] * 10 + a[9] )){
            out << a[1] << a[2] << a[3] << "+"
                 << a[4] << a[5] << a[6] << "="
                 << a[7] << a[8] << a[9] << endl;
        }
        ans++;
        return;
    }

    
    for (int i=1; i < 10;i++){
        if(book[i]==0){
            a[step] = i;
            book[i] = 1;  //标记book[i]
            
            dfs(step + 1);//解决step+1位的数字
            book[i] = 0;  //复原book[i]
        }
    }
}


int main(){
    ans = 0;
    dfs(1);
    cout << ans / 2 << endl;
}
