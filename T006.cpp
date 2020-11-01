/**
 * Author:Gzking
 * Date  :2020-10-29
 * Task  :DFS解炸弹人
*/

#include<iostream>

using namespace std;
char map[21][21];
int book[21][21];

int n, m;
int tx, ty;
int fx, fy;
int _max = -1;
int det[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int getnum(int x,int y){
    int i, j;
    int sum = 0;
    for (i = x; i < n;i++){
        if(map[i][y]=='#'){
            break;
        }else if(map[i][y]=='G'){
            sum++;
        }
    }
    for (i = x; i >=1 ;i--){
        if(map[i][y]=='#'){
            break;
        }else if(map[i][y]=='G'){
            sum++;
        }
    }
    for (j = y; j < m;j++){
        if(map[x][j]=='#'){
            break;
        }else if(map[x][j]=='G'){
            sum++;
        }
    }
    for (j = y; j >=1;j--){
        if(map[x][j]=='#'){
            break;
        }else if(map[x][j]=='G'){
            sum++;
        }
    }

    return sum;
}

void dfs(int x,int y){
    int tmp = getnum(x,y);
    if(tmp>_max){
        _max = tmp;
        fx = x;
        fy = y;
    }
    for (int k = 0; k < 4;k++){
        tx = x + det[k][0];
        ty = y + det[k][1];
        if(tx<1||tx>n||ty<1||ty>m)
            continue;
        if(map[tx][ty]=='.'&&book[tx][ty]==0){
            book[tx][ty] = 1;
            dfs(tx, ty);
        }
    }
}

int main(){
    int flag = 0;
    int sx, sy;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <=  m;j++){
            cin >> map[i][j];
            book[i][j] = 0;
            if(flag==0&&map[i][j]=='.'){
                sx = i;
                sy = j;
                flag = 1;
            }
        }
    dfs(sx, sy);
    cout << _max << endl;
    cout << "(" << fx << "," << fy <<")" << endl;
}
/*
13 13
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.###
##G..G......#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
*/