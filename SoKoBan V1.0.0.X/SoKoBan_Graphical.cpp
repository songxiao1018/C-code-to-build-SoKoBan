﻿//// SoKoBan.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 本项目采用C/C++语法
// 推箱子
// 更据地图，绘制地图、采用不同的标记来反应不同元素
// 地图用二维数组
#include<iostream>
#include<stdlib.h>
#include<conio.h>      // 关于按键控制
#include<graphics.h>   // 第三方图形库 easyx
#include<easyx.h>      // easy.h 头文件

using namespace std;
int m, n;              // 定义循环变量
int flag = 0;          // 定义关卡数
const int FLOOR = 0;   // 空地————————"  "
const int WALL = 1;    // 墙——————————"*  "
const int BOX = 2;     // 箱子————————"□"
const int EMPTY = 3;   // 目的地———————"+ "
const int PLAYER = 4;  // 人——————————"@ "
const int FULL = 5;    // 箱子+目的地——"X "
const int ON = 7;      // 人+目的地————"$ "

// 创建图片对象
IMAGE imgFLOOR  ;  // 空地————————"  "
IMAGE imgWALL   ;  // 墙——————————"* "
IMAGE imgBOX    ;  // 箱子————————"□"
IMAGE imgEMPTY  ;  // 目的地———————"+ "
IMAGE imgPLAYER ;  // 人——————————"@ "
IMAGE imgFULL   ;  // 箱子+目的地——"X "
IMAGE imgON     ;  // 人+目的地————"$ "

// 定义地图数组
int map[3][10][10] = {
    // 1
    0,0,0,0,0,0,0,0,0,0,
    0,1,1,1,1,1,1,1,1,0,
    0,1,0,0,0,0,0,0,1,0,
    0,1,0,3,0,2,3,0,1,0,
    0,1,0,2,0,0,0,0,1,0,
    0,1,0,0,0,4,2,0,1,0,
    0,1,0,3,2,0,3,0,1,0,
    0,1,0,0,0,0,0,0,1,0,
    0,1,1,1,1,1,1,1,1,0,
    0,0,0,0,0,0,0,0,0,0,
    // 2
    0,0,0,0,0,0,0,0,0,0,
    0,1,1,1,1,1,1,1,1,0,
    0,1,0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,0,0,1,0,
    0,1,2,2,2,0,2,0,1,0,
    0,1,0,0,0,0,0,0,1,0,
    0,1,0,4,0,0,2,2,1,0,
    0,1,3,3,3,3,3,3,1,0,
    0,1,1,1,1,1,1,1,1,0,
    0,0,0,0,0,0,0,0,0,0,
    // 3
    0,0,0,0,0,0,0,0,0,0,
    0,1,1,1,1,1,1,1,1,0,
    0,1,3,0,0,0,0,0,1,0,
    0,1,0,2,0,0,0,0,1,0,
    0,1,3,0,0,2,0,0,1,0,
    0,1,0,2,0,0,0,0,1,0,
    0,1,3,0,0,0,4,0,1,0,
    0,1,0,0,0,0,0,0,1,0,
    0,1,1,1,1,1,1,1,1,0,
    0,0,0,0,0,0,0,0,0,0
};

// 定义游戏地图
int GameMap[10][10] = { 0 };    // 游戏地图
int LastRound[10][10] = { 0 };  // 上一轮地图

// 读取地图函数
void ReadMap(int flag) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            GameMap[i][j] = map[flag][i][j];
        }
    }
}

// 复制地图函数
void CopyMap() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            LastRound[i][j] = GameMap[i][j];
        }
    }
}

// 返回上一步
void ReturnMap() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            GameMap[i][j] = LastRound[i][j];
        }
    }
}

// 定义输出地图函数  空地0  墙1  箱子2  目的地3   人4   箱子+目的地5  人+目的地7
void show_map() {
    loadimage(&imgFLOOR   , _T("0.jpg"), 64, 64);
    loadimage(&imgWALL    , _T("1.jpg"), 64, 64);
    loadimage(&imgBOX     , _T("2.jpg"), 64, 64);
    loadimage(&imgEMPTY   , _T("3.jpg"), 64, 64);
    loadimage(&imgPLAYER  , _T("4.jpg"), 64, 64);
    loadimage(&imgFULL    , _T("5.jpg"), 64, 64);
    loadimage(&imgON      , _T("7.jpg"), 64, 64);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            switch (GameMap[i][j]) {
            case FLOOR:
                cout << "  ";
                putimage(j * 64, i * 64, &imgFLOOR);
                break;
            case WALL:
                cout << "* ";
                putimage(j * 64, i * 64, &imgWALL);
                break;
            case BOX:
                cout << "□";
                putimage(j * 64, i * 64, &imgBOX);
                break;
            case EMPTY:
                cout << "+ ";
                putimage(j * 64, i * 64, &imgEMPTY);
                break;
            case PLAYER:
                cout << "@ ";
                putimage(j * 64, i * 64, &imgPLAYER);
                break;
            case FULL:
                cout << "X ";
                putimage(j * 64, i * 64, &imgFULL);
                break;
            case ON:
                cout << "$ ";
                putimage(j * 64, i * 64, &imgON);
                break;
            }
        }
        cout << endl;
    }
}

// 找人
void findPlayer() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (GameMap[i][j] == PLAYER || GameMap[i][j] == ON) {
                m = i;
                n = j;
                goto xyz;
            }
        }
    }
xyz:;
}

// 玩游戏
void playGame() {
    // 捕获用户按键
    char ch = ' ';

    ch = _getch();

    switch (ch)
    {
    case 'W':// 前面时空地或者目的地可以走
    case 'w':
    case 72:    //对于当前位置-PLAYER 前面 +PLAYER
        // 空地上走
        /*if (map[flag][m - 1][n] == FLOOR || map[flag][m - 1][n] == EMPTY) {
            map[flag][m - 1][n] += PLAYER;
            map[flag][m][n] -= PLAYER;
        }

        // 推箱子
        if ((map[flag][m - 1][n] == BOX || map[flag][m - 1][n] == FULL) && (map[flag][m - 2][n] != WALL)&&(map[flag][m - 2][n] != BOX)) {
            map[flag][m][n] -= PLAYER;
            map[flag][m - 1][n] += (PLAYER - BOX);
            map[flag][m - 2][n] += BOX;
        }*/
        if (GameMap[m - 1][n] == FLOOR || GameMap[m - 1][n] == EMPTY) {
            GameMap[m - 1][n] += PLAYER;
            GameMap[m][n] -= PLAYER;
        }
        else if ((GameMap[m - 1][n] == BOX || GameMap[m - 1][n] == FULL) && (GameMap[m - 2][n] == FLOOR || GameMap[m - 2][n] == EMPTY)) {
            GameMap[m][n] -= PLAYER;
            GameMap[m - 1][n] += (PLAYER - BOX);
            GameMap[m - 2][n] += BOX;
        }
        break;

    case 'A':
    case 'a':
    case 75:
        // 空地走
        /*if (map[flag][m][n - 1] == 0 || map[flag][m][n - 1] == 3) {
            map[flag][m][n - 1] += PLAYER;
            map[flag][m][n] -= PLAYER;
        }

        // 推箱子
        if ((map[flag][m][n - 1] == BOX || map[flag][m][n - 1] == FULL) && map[flag][m][n - 2] != WALL && (map[flag][m][n - 2] != BOX)) {
            map[flag][m][n] -= PLAYER;
            map[flag][m][n - 1] += (PLAYER - BOX);
            map[flag][m][n - 2] += BOX;
        }*/
        if (GameMap[m][n - 1] == FLOOR || GameMap[m][n - 1] == EMPTY) {
            GameMap[m][n - 1] += PLAYER;
            GameMap[m][n] -= PLAYER;
        }
        else if ((GameMap[m][n - 1] == BOX || GameMap[m][n - 1] == FULL) && (GameMap[m][n - 2] == FLOOR || GameMap[m][n - 2] == EMPTY)) {
            GameMap[m][n] -= PLAYER;
            GameMap[m][n - 1] += (PLAYER - BOX);
            GameMap[m][n - 2] += BOX;
        }
        break;

    case 'S':
    case 's':
    case 80:
        // 空地走
        /*if (map[flag][m + 1][n] == 0 || map[flag][m + 1][n] == 3) {
            map[flag][m + 1][n] += PLAYER;
            map[flag][m][n] -= PLAYER;
        }

        // 推箱子
        if ((map[flag][m + 1][n] == BOX || map[flag][m + 1][n] == FULL) && map[flag][m + 2][n] != WALL && (map[flag][m + 2][n] != BOX)) {
            map[flag][m][n] -= PLAYER;
            map[flag][m + 1][n] += (PLAYER - BOX);
            map[flag][m + 2][n] += BOX;
        }*/
        if (GameMap[m + 1][n] == FLOOR || GameMap[m + 1][n] == EMPTY) {
            GameMap[m + 1][n] += PLAYER;
            GameMap[m][n] -= PLAYER;
        }
        else if ((GameMap[m + 1][n] == BOX || GameMap[m + 1][n] == FULL) && (GameMap[m + 2][n] == FLOOR || GameMap[m + 2][n] == EMPTY)) {
            GameMap[m][n] -= PLAYER;
            GameMap[m + 1][n] += (PLAYER - BOX);
            GameMap[m + 2][n] += BOX;
        }
        break;

    case 'D':
    case 'd':
    case 77:
        // 空地走
        /*if (map[flag][m][n + 1] == 0 || map[flag][m][n + 1] == 3) {
            map[flag][m][n + 1] += PLAYER;
            map[flag][m][n] -= PLAYER;
        }

        // 推箱子
        if ((map[flag][m][n + 1] == BOX || map[flag][m][n + 1] == FULL) && map[flag][m][n + 2] != WALL && (map[flag][m][n + 2] != BOX)) {
            map[flag][m][n] -= PLAYER;
            map[flag][m][n + 1] += (PLAYER - BOX);
            map[flag][m][n + 2] += BOX;
        }*/
        if (GameMap[m][n + 1] == FLOOR || GameMap[m][n + 1] == EMPTY) {
            GameMap[m][n + 1] += PLAYER;
            GameMap[m][n] -= PLAYER;
        }
        else if ((GameMap[m][n + 1] == BOX || GameMap[m][n + 1] == FULL) && (GameMap[m][n + 2] == FLOOR || GameMap[m][n + 2] == EMPTY)) {
            GameMap[m][n] -= PLAYER;
            GameMap[m][n + 1] += (PLAYER - BOX);
            GameMap[m][n + 2] += BOX;
        }
        break;

    case 'Z':
    case 'z':
        ReturnMap();
        
        break;

    default:
        break;
    }

}

// 判断结束
bool gameEND() {
    bool f = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (GameMap[i][j] == BOX) {
                f = 1;
                goto yza;
            }
        }
    }
yza:
    return f;
}

int main() {
    // 初始化窗口
    initgraph(640, 640, EW_SHOWCONSOLE | EW_DBLCLKS);
    //initgraph(640, 640);

    flag = 0;
    while (1) {
        // 读取地图
        ReadMap(flag);
        
        while (gameEND()) {
            // 打印地图
            show_map();
            CopyMap();
            // 开始游戏
            findPlayer();
            playGame();
            

            // 刷新屏幕
            system("cls");
            cleardevice();
        }
        // 判断游戏结束
        if (!gameEND()) {
            system("cls");
            show_map();

            if (flag == 2) {
                //cout << "you win !";
                //break;
                flag = 0;
            }
            else {
                flag++;
            }

        }
    }
    

    // 关闭图形化窗口
    closegraph();
    return 0;
}

