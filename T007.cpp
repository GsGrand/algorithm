/**
 * Author:Gzking
 * Date  :2020-10-29
 * Task  :±¶µ∫ÃΩœ’
*/

#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

struct position{
    int x;
    int y;
} que[101];

int areas = 0;
int map[11][11];
int book[11][11];
int det[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
void color(int x,int y){
    map[x][y] = -1;
}
int main(){
    int n, m;
    int sx,sy,tx, ty;
    ifstream sin("seas.in", ios::in);
    sin >> n >> m>> sx >> sy;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m;j++){
            sin >> map[i][j];
            book[i][j] = 0;
        } 
    int head=1;
    int tail = 1;
    que[tail].x = sx;
    que[tail].y = sy;
    tail++;
    color(sx, sy);
    areas++;

    while(head<tail){
        for (int k = 0; k < 4;k++){
            tx = que[head].x + det[k][0];
            ty = que[head].y + det[k][1];

            if(tx<1||tx>n||ty<1||ty>m)
                continue;
            
            if(map[tx][ty]>0&&book[tx][ty]==0){
                color(tx, ty);
                areas++;
                que[tail].x = tx;
                que[tail].y = ty;
                tail++;
            }
        }
        head++;
    }

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cout <<setfill(' ')<<setw(2)<< map[i][j]<<" ";
        }
        cout << endl;
    }
    cout << "∫£µ∫√Êª˝: " << areas << endl;
    system("pause");
    return 0;
}

/*
10 10 6 8
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
*/