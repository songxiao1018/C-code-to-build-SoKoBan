//// SoKoBan.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
// ����Ŀ����C/C++�﷨
// ������
// ���ݵ�ͼ�����Ƶ�ͼ�����ò�ͬ�ı������Ӧ��ͬԪ��
// ��ͼ�ö�ά����
#include<iostream>
#include<stdlib.h>
#include<conio.h>      // ���ڰ�������
#include<graphics.h>   // ������ͼ�ο� easyx
using namespace std;
int m, n;              // ����ѭ������
int flag = 0;          // ����ؿ���
const int FLOOR = 0;   // �յء���������������"  "
const int WALL = 1;    // ǽ��������������������"* "
const int BOX = 2;     // ���ӡ���������������"��"
const int EMPTY = 3;   // Ŀ�ĵء�������������"+ "
const int PLAYER = 4;  // �ˡ�������������������"@ "
const int FULL = 5;    // ����+Ŀ�ĵء���"X "
const int ON = 7;      // ��+Ŀ�ĵء�������"$ "

// ����ͼƬ����
IMAGE imgFLOOR  (50,50);  // �յء���������������"  "
IMAGE imgWALL   ;  // ǽ��������������������"* "
IMAGE imgBOX    ;  // ���ӡ���������������"��"
IMAGE imgEMPTY  ;  // Ŀ�ĵء�������������"+ "
IMAGE imgPLAYER ;  // �ˡ�������������������"@ "
IMAGE imgFULL   ;  // ����+Ŀ�ĵء���"X "
IMAGE imgON     ;  // ��+Ŀ�ĵء�������"$ "



// �����ͼ����
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

// ���������ͼ����  �յ�0  ǽ1  ����2  Ŀ�ĵ�3   ��4   ����+Ŀ�ĵ�5  ��+Ŀ�ĵ�7
void show_map() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            switch (map[flag][i][j]) {
            case FLOOR:
                cout << "  ";
                break;
            case WALL:
                cout << "* ";
                break;
            case BOX:
                cout << "��";
                break;
            case EMPTY:
                cout << "+ ";
                break;
            case PLAYER:
                cout << "@ ";
                break;
            case FULL:
                cout << "X ";
                break;
            case ON:
                cout << "$ ";
                break;
            }
        }
        cout << endl;
    }
}

// ����
void findPlayer() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[flag][i][j] == PLAYER || map[flag][i][j] == ON) {
                m = i;
                n = j;
                goto xyz;
            }
        }
    }
xyz:;
}

// ����Ϸ
void playGame() {
    // �����û�����
    char ch = ' ';

    ch = _getch();

    switch (ch)
    {
    case 'W':// ǰ��ʱ�յػ���Ŀ�ĵؿ�����
    case 'w':
    case 72:    //���ڵ�ǰλ��-PLAYER ǰ�� +PLAYER
        // �յ�����
        if (map[flag][m - 1][n] == FLOOR || map[flag][m - 1][n] == EMPTY) {
            map[flag][m - 1][n] += PLAYER;
            map[flag][m][n] -= PLAYER;
        }

        // ������
        if ((map[flag][m - 1][n] == BOX || map[flag][m - 1][n] == FULL) && map[flag][m - 2][n] != WALL) {
            map[flag][m][n] -= PLAYER;
            map[flag][m - 1][n] += (PLAYER - BOX);
            map[flag][m - 2][n] += BOX;
        }
        break;

    case 'A':
    case 'a':
    case 75:
        // �յ���
        if (map[flag][m][n - 1] == 0 || map[flag][m][n - 1] == 3) {
            map[flag][m][n - 1] += PLAYER;
            map[flag][m][n] -= PLAYER;
        }

        // ������
        if ((map[flag][m][n - 1] == BOX || map[flag][m][n - 1] == FULL) && map[flag][m][n - 2] != WALL) {
            map[flag][m][n] -= PLAYER;
            map[flag][m][n - 1] += (PLAYER - BOX);
            map[flag][m][n - 2] += BOX;
        }
        break;

    case 'S':
    case 's':
    case 80:
        // �յ���
        if (map[flag][m + 1][n] == 0 || map[flag][m + 1][n] == 3) {
            map[flag][m + 1][n] += PLAYER;
            map[flag][m][n] -= PLAYER;
        }

        // ������
        if ((map[flag][m + 1][n] == BOX || map[flag][m + 1][n] == FULL) && map[flag][m + 2][n] != WALL) {
            map[flag][m][n] -= PLAYER;
            map[flag][m + 1][n] += (PLAYER - BOX);
            map[flag][m + 2][n] += BOX;
        }
        break;

    case 'D':
    case 'd':
    case 77:
        // �յ���
        if (map[flag][m][n + 1] == 0 || map[flag][m][n + 1] == 3) {
            map[flag][m][n + 1] += PLAYER;
            map[flag][m][n] -= PLAYER;
        }

        // ������
        if ((map[flag][m][n + 1] == BOX || map[flag][m][n + 1] == FULL) && map[flag][m][n + 2] != WALL) {
            map[flag][m][n] -= PLAYER;
            map[flag][m][n + 1] += (PLAYER - BOX);
            map[flag][m][n + 2] += BOX;
        }
        break;

    default:
        break;
    }

}
// �жϽ���
bool gameEND() {
    bool f = 1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[flag][i][j] == BOX) {
                f = 0;
                goto yza;
            }
        }
    }
yza:
    return f;
}

int main() {
    // ��ʼ������
    initgraph(640, 640);

    // ���ô��ڱ���
    SetConsoleTitle("123");
    // ���û�ͼ������ɫΪ��ɫ
    setbkcolor(RGB(158, 168, 220));

    //

 /*   while (1) {
        // ��ӡ��ͼ
        show_map();

        // ��ʼ��Ϸ
        findPlayer();
        playGame();

        // �ж���Ϸ����
        if (gameEND()) {
            system("cls");
            show_map();

            if (flag == 2) {
                cout << "you win !";
                break;
            }
            else {
                flag++;
            }

        }

        // ˢ����Ļ
        system("cls");
    }*/

    _getch();

    // �ر�ͼ�λ�����
    closegraph();
    return 0;
}

