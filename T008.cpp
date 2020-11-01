/**
 * Author:Gzking
 * Date  :2020-10-29
 * Task  :宝岛探险2
*/

#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

int n, m;
int tx, ty;
int map[11][11];
int book[11][11];
int det[4][2]{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

void dfs(int x,int y,int color){
    map[x][y] = color;
    book[x][y] = 1;
    for (int k = 0; k < 4;k++){
        tx = x + det[k][0];
        ty = y + det[k][1];

        if(tx<1||tx>n||ty<1||ty>m)
            continue;
        
        if(book[tx][ty]==0&&map[tx][ty]>0){
            dfs(tx, ty, color);
        }
    }
}

int main(){
    int color = 1;
    int sx, sy;
    ifstream sin("seas.in", ios::in);
    sin >> n >> m>>sx>>sy;
    for (int i =1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            sin >> map[i][j];
            book[i][j] = 0;
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(map[i][j]>0&&book[i][j]==0){
                dfs(i, j, color);
                color++;
            }
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cout <<map[i][j] << " ";
        }
        cout << endl;
    }
    cout << "当前海域存在的小岛数量为: " << color-1 << endl;
    system("pause");
    return 0;
}