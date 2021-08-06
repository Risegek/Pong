// Copyright 2021 tszechwa, dkedge, nmarylou
// I WANT TO PLAY WITH YOU
// YOUR FRIEND, AI
#include<stdio.h>

const int width = 80;
const int heigth = 25;

int count_team_1 = 0;
int count_team_2 = 0;

int pos_team_1 = 12;
int pos_team_2 = 12;

int ball_direction = 1;
int ball_direction_i = 0;

int ball_i = 12;
int ball_j = 40;

char map[heigth][width];

int keyboard_handler(int a);
void create_map();
void print();
void check(int i, int j);
void ball_move_j();
void ball_move_i();
void check_goal();
void score_printer();
void printer_team_1();

int main() {
	printf("\e[1;1H\e[2J");
	create_map();
    score_printer();
	print();
	int c = 0;
	while (count_team_1 != 21 || count_team_2 != 21) {
        if (keyboard_handler(getchar())) {
            continue;
        }
        ball_move_j();
        ball_move_i();
        check_goal();
		printf("\e[1;1H\e[2J");
		create_map();
        score_printer();
		print();
        if (count_team_1 == 21 || count_team_2 == 21) {
            break;
        }
	}
	return 0;
}

void printer_team_1() {
    switch (count_team_1) {
        case 0:  // отрисовка цифры 0 для команды 1
            map[5][35] = 'R';
            map[6][35] = 'R';
            map[7][35] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[7][37] = 'R';
            map[4][36] = 'R';
            map[8][36] = 'R';
            break;
        case 1:
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[5][36] = 'R';
            map[6][36] = 'R';
            map[7][36] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 2:
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[6][36] = 'R';
            map[6][35] = 'R';
            map[7][35] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 3:
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[6][36] = 'R';
            map[6][35] = 'R';
            map[7][37] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 4:
            map[4][35] = 'R';
            map[5][35] = 'R';
            map[6][35] = 'R';
            map[6][36] = 'R';
            map[4][37] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[7][37] = 'R';
            map[8][37] = 'R';
            break;
        case 5:
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][35] = 'R';
            map[6][37] = 'R';
            map[6][36] = 'R';
            map[6][35] = 'R';
            map[7][37] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 6:
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][35] = 'R';
            map[6][37] = 'R';
            map[6][36] = 'R';
            map[6][35] = 'R';
            map[7][37] = 'R';
            map[7][35] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 7:
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[7][37] = 'R';
            map[8][37] = 'R';
            break;
        case 8:
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][35] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[6][36] = 'R';
            map[6][35] = 'R';
            map[7][37] = 'R';
            map[7][35] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 9:
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][35] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[6][36] = 'R';
            map[6][35] = 'R';
            map[7][37] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 10:
            map[4][31] = 'R';
            map[4][32] = 'R';
            map[5][32] = 'R';
            map[6][32] = 'R';
            map[7][32] = 'R';
            map[8][31] = 'R';
            map[8][32] = 'R';
            map[8][33] = 'R';
            map[5][35] = 'R';
            map[6][35] = 'R';
            map[7][35] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[7][37] = 'R';
            map[4][36] = 'R';
            map[8][36] = 'R';
            break;
        case 11:
            map[4][31] = 'R';
            map[4][32] = 'R';
            map[5][32] = 'R';
            map[6][32] = 'R';
            map[7][32] = 'R';
            map[8][31] = 'R';
            map[8][32] = 'R';
            map[8][33] = 'R';
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[5][36] = 'R';
            map[6][36] = 'R';
            map[7][36] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 12:
            map[4][31] = 'R';
            map[4][32] = 'R';
            map[5][32] = 'R';
            map[6][32] = 'R';
            map[7][32] = 'R';
            map[8][31] = 'R';
            map[8][32] = 'R';
            map[8][33] = 'R';
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[6][36] = 'R';
            map[6][35] = 'R';
            map[7][35] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 13:
            map[4][31] = 'R';
            map[4][32] = 'R';
            map[5][32] = 'R';
            map[6][32] = 'R';
            map[7][32] = 'R';
            map[8][31] = 'R';
            map[8][32] = 'R';
            map[8][33] = 'R';
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[6][36] = 'R';
            map[6][35] = 'R';
            map[7][37] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 14:
            map[4][31] = 'R';
            map[4][32] = 'R';
            map[5][32] = 'R';
            map[6][32] = 'R';
            map[7][32] = 'R';
            map[8][31] = 'R';
            map[8][32] = 'R';
            map[8][33] = 'R';
            map[4][35] = 'R';
            map[5][35] = 'R';
            map[6][35] = 'R';
            map[6][36] = 'R';
            map[4][37] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[7][37] = 'R';
            map[8][37] = 'R';
            break;
        case 15:
            map[4][31] = 'R';
            map[4][32] = 'R';
            map[5][32] = 'R';
            map[6][32] = 'R';
            map[7][32] = 'R';
            map[8][31] = 'R';
            map[8][32] = 'R';
            map[8][33] = 'R';
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][35] = 'R';
            map[6][37] = 'R';
            map[6][36] = 'R';
            map[6][35] = 'R';
            map[7][37] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 16:
            map[4][31] = 'R';
            map[4][32] = 'R';
            map[5][32] = 'R';
            map[6][32] = 'R';
            map[7][32] = 'R';
            map[8][31] = 'R';
            map[8][32] = 'R';
            map[8][33] = 'R';
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][35] = 'R';
            map[6][37] = 'R';
            map[6][36] = 'R';
            map[6][35] = 'R';
            map[7][37] = 'R';
            map[7][35] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 17:
            map[4][31] = 'R';
            map[4][32] = 'R';
            map[5][32] = 'R';
            map[6][32] = 'R';
            map[7][32] = 'R';
            map[8][31] = 'R';
            map[8][32] = 'R';
            map[8][33] = 'R';
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[7][37] = 'R';
            map[8][37] = 'R';
            break;
        case 18:
            map[4][31] = 'R';
            map[4][32] = 'R';
            map[5][32] = 'R';
            map[6][32] = 'R';
            map[7][32] = 'R';
            map[8][31] = 'R';
            map[8][32] = 'R';
            map[8][33] = 'R';
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][35] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[6][36] = 'R';
            map[6][35] = 'R';
            map[7][37] = 'R';
            map[7][35] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 19:
            map[4][31] = 'R';
            map[4][32] = 'R';
            map[5][32] = 'R';
            map[6][32] = 'R';
            map[7][32] = 'R';
            map[8][31] = 'R';
            map[8][32] = 'R';
            map[8][33] = 'R';
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[4][37] = 'R';
            map[5][35] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[6][36] = 'R';
            map[6][35] = 'R';
            map[7][37] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            break;
        case 20:
            map[4][31] = 'R';
            map[4][32] = 'R';
            map[4][33] = 'R';
            map[5][33] = 'R';
            map[6][33] = 'R';
            map[6][32] = 'R';
            map[6][31] = 'R';
            map[7][31] = 'R';
            map[8][31] = 'R';
            map[8][32] = 'R';
            map[8][33] = 'R';
            map[5][35] = 'R';
            map[6][35] = 'R';
            map[7][35] = 'R';
            map[5][37] = 'R';
            map[6][37] = 'R';
            map[7][37] = 'R';
            map[4][36] = 'R';
            map[8][36] = 'R';
            break;
        case 21:  // отрисовка числа 21 и надписи победа для команды 2
            map[4][31] = 'R';
            map[4][32] = 'R';
            map[4][33] = 'R';
            map[5][33] = 'R';
            map[6][33] = 'R';
            map[6][32] = 'R';
            map[6][31] = 'R';
            map[7][31] = 'R';
            map[8][31] = 'R';
            map[8][32] = 'R';
            map[8][33] = 'R';
            map[4][35] = 'R';
            map[4][36] = 'R';
            map[5][36] = 'R';
            map[6][36] = 'R';
            map[7][36] = 'R';
            map[8][35] = 'R';
            map[8][36] = 'R';
            map[8][37] = 'R';
            //
            map[10][29] = 'R';
            map[10][30] = 'R';
            map[10][31] = 'R';
            map[10][32] = 'R';
            map[10][33] = 'R';
            map[11][31] = 'R';
            map[12][31] = 'R';
            map[13][31] = 'R';
            map[14][31] = 'R';
            map[10][35] = 'R';
            map[10][36] = 'R';
            map[10][37] = 'R';
            map[10][38] = 'R';
            map[11][35] = 'R';
            map[12][35] = 'R';
            map[13][35] = 'R';
            map[14][35] = 'R';
            map[12][36] = 'R';
            map[12][37] = 'R';
            map[12][38] = 'R';
            map[14][36] = 'R';
            map[14][37] = 'R';
            map[14][38] = 'R';
            map[10][44] = 'R';
            map[11][43] = 'R';
            map[11][45] = 'R';
            map[12][42] = 'R';
            map[12][46] = 'R';
            map[13][42] = 'R';
            map[13][46] = 'R';
            map[14][42] = 'R';
            map[14][46] = 'R';
            map[13][43] = 'R';
            map[13][44] = 'R';
            map[13][45] = 'R';
            map[10][48] = 'R';
            map[10][49] = 'R';
            map[11][50] = 'R';
            map[12][51] = 'R';
            map[11][52] = 'R';
            map[10][53] = 'R';
            map[10][54] = 'R';
            map[11][48] = 'R';
            map[12][48] = 'R';
            map[13][48] = 'R';
            map[14][48] = 'R';
            map[11][54] = 'R';
            map[12][54] = 'R';
            map[13][54] = 'R';
            map[14][54] = 'R';
            map[16][39] = 'R';
            map[16][40] = 'R';
            map[17][40] = 'R';
            map[18][40] = 'R';
            map[19][40] = 'R';
            map[20][39] = 'R';
            map[20][40] = 'R';
            map[20][41] = 'R';
            break;
        default:
            break;
    }
}

void score_printer() {  // отрисовка счета
    printer_team_1();
    switch (count_team_2) {
        case 0:  // отрисовка цифры 0 для команды 2
            map[5][43] = 'R';
            map[6][43] = 'R';
            map[7][43] = 'R';
            map[5][45] = 'R';
            map[6][45] = 'R';
            map[7][45] = 'R';
            map[4][44] = 'R';
            map[8][44] = 'R';
            break;
        case 1:  // отрисовка цифры 1 для команды 2
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[5][44] = 'R';
            map[6][44] = 'R';
            map[7][44] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            break;
        case 2:  // отрисовка цифры 2 для команды 2
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[4][45] = 'R';
            map[5][45] = 'R';
            map[6][45] = 'R';
            map[6][44] = 'R';
            map[6][43] = 'R';
            map[7][43] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            break;
        case 3:  // отрисовка цифры 3 для команды 2
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[4][45] = 'R';
            map[5][45] = 'R';
            map[6][45] = 'R';
            map[6][44] = 'R';
            map[6][43] = 'R';
            map[7][45] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            break;
        case 4:  // отрисовка цифры 4 для команды 2
            map[4][43] = 'R';
            map[5][43] = 'R';
            map[6][43] = 'R';
            map[6][44] = 'R';
            map[4][45] = 'R';
            map[5][45] = 'R';
            map[6][45] = 'R';
            map[7][45] = 'R';
            map[8][45] = 'R';
            break;
        case 5:  // отрисовка цифры 5 для команды 2
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[4][45] = 'R';
            map[5][43] = 'R';
            map[6][43] = 'R';
            map[6][44] = 'R';
            map[6][45] = 'R';
            map[7][45] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            break;
        case 6:  // отрисовка цифры 6 для команды 2
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[4][45] = 'R';
            map[5][43] = 'R';
            map[6][43] = 'R';
            map[6][44] = 'R';
            map[6][45] = 'R';
            map[7][45] = 'R';
            map[7][43] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            break;
        case 7:  // отрисовка цифры 7 для команды 2
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[4][45] = 'R';
            map[5][45] = 'R';
            map[6][45] = 'R';
            map[7][45] = 'R';
            map[8][45] = 'R';
            break;
        case 8:  // отрисовка цифры 8 для команды 2
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[4][45] = 'R';
            map[5][43] = 'R';
            map[5][45] = 'R';
            map[6][43] = 'R';
            map[6][44] = 'R';
            map[6][45] = 'R';
            map[7][45] = 'R';
            map[7][43] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            break;
        case 9:  // отрисовка цифры 9 для команды 2
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[4][45] = 'R';
            map[5][43] = 'R';
            map[5][45] = 'R';
            map[6][43] = 'R';
            map[6][44] = 'R';
            map[6][45] = 'R';
            map[7][45] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            break;
        case 10:  // отрисовка цифры 10 для команды 2
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[5][44] = 'R';
            map[6][44] = 'R';
            map[7][44] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            map[5][47] = 'R';
            map[6][47] = 'R';
            map[7][47] = 'R';
            map[5][49] = 'R';
            map[6][49] = 'R';
            map[7][49] = 'R';
            map[4][48] = 'R';
            map[8][48] = 'R';
            break;
        case 11:  // отрисовка цифры 0 для команды 2
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[5][44] = 'R';
            map[6][44] = 'R';
            map[7][44] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            map[4][47] = 'R';
            map[4][48] = 'R';
            map[5][48] = 'R';
            map[6][48] = 'R';
            map[7][48] = 'R';
            map[8][47] = 'R';
            map[8][48] = 'R';
            map[8][49] = 'R';
            break;
        case 12:
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[5][44] = 'R';
            map[6][44] = 'R';
            map[7][44] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            map[4][47] = 'R';
            map[4][48] = 'R';
            map[4][49] = 'R';
            map[5][49] = 'R';
            map[6][49] = 'R';
            map[6][48] = 'R';
            map[6][47] = 'R';
            map[7][47] = 'R';
            map[8][47] = 'R';
            map[8][48] = 'R';
            map[8][49] = 'R';
            break;
        case 13:
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[5][44] = 'R';
            map[6][44] = 'R';
            map[7][44] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            map[4][47] = 'R';
            map[4][48] = 'R';
            map[4][49] = 'R';
            map[5][49] = 'R';
            map[6][49] = 'R';
            map[6][48] = 'R';
            map[6][47] = 'R';
            map[7][49] = 'R';
            map[8][47] = 'R';
            map[8][48] = 'R';
            map[8][49] = 'R';
            break;
        case 14:
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[5][44] = 'R';
            map[6][44] = 'R';
            map[7][44] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            map[4][47] = 'R';
            map[5][47] = 'R';
            map[6][47] = 'R';
            map[6][48] = 'R';
            map[4][49] = 'R';
            map[5][49] = 'R';
            map[6][49] = 'R';
            map[7][49] = 'R';
            map[8][49] = 'R';
            break;
        case 15:
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[5][44] = 'R';
            map[6][44] = 'R';
            map[7][44] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            map[4][47] = 'R';
            map[4][48] = 'R';
            map[4][49] = 'R';
            map[5][47] = 'R';
            map[6][47] = 'R';
            map[6][48] = 'R';
            map[6][49] = 'R';
            map[7][49] = 'R';
            map[8][47] = 'R';
            map[8][48] = 'R';
            map[8][49] = 'R';
            break;
        case 16:
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[5][44] = 'R';
            map[6][44] = 'R';
            map[7][44] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            map[4][47] = 'R';
            map[4][48] = 'R';
            map[4][49] = 'R';
            map[5][47] = 'R';
            map[6][47] = 'R';
            map[6][48] = 'R';
            map[6][49] = 'R';
            map[7][49] = 'R';
            map[7][47] = 'R';
            map[8][47] = 'R';
            map[8][48] = 'R';
            map[8][49] = 'R';
            break;
        case 17:
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[5][44] = 'R';
            map[6][44] = 'R';
            map[7][44] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            map[4][47] = 'R';
            map[4][48] = 'R';
            map[4][49] = 'R';
            map[5][49] = 'R';
            map[6][49] = 'R';
            map[7][49] = 'R';
            map[8][49] = 'R';
            break;
        case 18:
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[5][44] = 'R';
            map[6][44] = 'R';
            map[7][44] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            map[4][47] = 'R';
            map[4][48] = 'R';
            map[4][49] = 'R';
            map[5][47] = 'R';
            map[5][49] = 'R';
            map[6][47] = 'R';
            map[6][48] = 'R';
            map[6][49] = 'R';
            map[7][49] = 'R';
            map[7][47] = 'R';
            map[8][47] = 'R';
            map[8][48] = 'R';
            map[8][49] = 'R';
            break;
        case 19:
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[5][44] = 'R';
            map[6][44] = 'R';
            map[7][44] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            map[4][47] = 'R';
            map[4][48] = 'R';
            map[4][49] = 'R';
            map[5][47] = 'R';
            map[5][49] = 'R';
            map[6][47] = 'R';
            map[6][48] = 'R';
            map[6][49] = 'R';
            map[7][49] = 'R';
            map[8][47] = 'R';
            map[8][48] = 'R';
            map[8][49] = 'R';
            break;
        case 20:
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[4][45] = 'R';
            map[5][45] = 'R';
            map[6][45] = 'R';
            map[6][44] = 'R';
            map[6][43] = 'R';
            map[7][43] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            map[5][47] = 'R';
            map[6][47] = 'R';
            map[7][47] = 'R';
            map[5][49] = 'R';
            map[6][49] = 'R';
            map[7][49] = 'R';
            map[4][48] = 'R';
            map[8][48] = 'R';
            break;
        case 21:  // отрисовка числа 21 и надписи победа для команды 2
            map[4][43] = 'R';
            map[4][44] = 'R';
            map[4][45] = 'R';
            map[5][45] = 'R';
            map[6][45] = 'R';
            map[6][44] = 'R';
            map[6][43] = 'R';
            map[7][43] = 'R';
            map[8][43] = 'R';
            map[8][44] = 'R';
            map[8][45] = 'R';
            map[4][47] = 'R';
            map[4][48] = 'R';
            map[5][48] = 'R';
            map[6][48] = 'R';
            map[7][48] = 'R';
            map[8][47] = 'R';
            map[8][48] = 'R';
            map[8][49] = 'R';
            //
            map[10][29] = 'R';
            map[10][30] = 'R';
            map[10][31] = 'R';
            map[10][32] = 'R';
            map[10][33] = 'R';
            map[11][31] = 'R';
            map[12][31] = 'R';
            map[13][31] = 'R';
            map[14][31] = 'R';
            map[10][35] = 'R';
            map[10][36] = 'R';
            map[10][37] = 'R';
            map[10][38] = 'R';
            map[11][35] = 'R';
            map[12][35] = 'R';
            map[13][35] = 'R';
            map[14][35] = 'R';
            map[12][36] = 'R';
            map[12][37] = 'R';
            map[12][38] = 'R';
            map[14][36] = 'R';
            map[14][37] = 'R';
            map[14][38] = 'R';
            map[10][44] = 'R';
            map[11][43] = 'R';
            map[11][45] = 'R';
            map[12][42] = 'R';
            map[12][46] = 'R';
            map[13][42] = 'R';
            map[13][46] = 'R';
            map[14][42] = 'R';
            map[14][46] = 'R';
            map[13][43] = 'R';
            map[13][44] = 'R';
            map[13][45] = 'R';
            map[10][48] = 'R';
            map[10][49] = 'R';
            map[11][50] = 'R';
            map[12][51] = 'R';
            map[11][52] = 'R';
            map[10][53] = 'R';
            map[10][54] = 'R';
            map[11][48] = 'R';
            map[12][48] = 'R';
            map[13][48] = 'R';
            map[14][48] = 'R';
            map[11][54] = 'R';
            map[12][54] = 'R';
            map[13][54] = 'R';
            map[14][54] = 'R';
            map[16][39] = 'R';
            map[16][40] = 'R';
            map[16][41] = 'R';
            map[17][41] = 'R';
            map[18][41] = 'R';
            map[18][40] = 'R';
            map[18][39] = 'R';
            map[19][39] = 'R';
            map[20][39] = 'R';
            map[20][40] = 'R';
            map[20][41] = 'R';
            break;
        default:
            break;
    }
}
void check_goal() {
    if (ball_j == 1) {  // проверка мяча у левой границы
            count_team_2++;
            ball_direction = 0;
            ball_i = 12;
            ball_j = 40;
        }
    if (ball_j == 78) {  // проверка мяча у правой границы
            count_team_1++;
            ball_direction = 1;
            ball_i = 12;
            ball_j = 40;
        }
}

void ball_move_i() {
    if (ball_direction_i == 1) {
        if (ball_i == 23) {
            ball_direction_i = -1;
            ball_i--;
        } else {
            ball_i++;
        }
    } else {
        if (ball_direction_i == -1) {
            if (ball_i == 1) {
                ball_direction_i = 1;
                ball_i++;
            } else {
                ball_i--;
            }
        }
    }
}

void ball_move_j() {
    if (ball_direction) {
        if (ball_j == 65 || ball_j == 66) {  // проверка мяча у ракетки
            if (ball_i == pos_team_2 - 1) {
                ball_direction_i = -1;
                ball_direction = 0;
                ball_j--;
            } else {
                if (ball_i == pos_team_2 + 1) {
                    ball_direction_i = 1;
                    ball_direction = 0;
                    ball_j--;
                } else {
                    if (ball_i == pos_team_2) {
                        ball_direction_i = 0;
                        ball_direction = 0;
                        ball_j--;
                    } else {
                        ball_j++;
                    }
                }
            }
        } else {
            ball_j++;
        }
    } else {
        if (ball_j == 14 || ball_j == 13) {
            if (ball_i == pos_team_1 - 1) {
                ball_direction_i = -1;
                ball_direction = 1;
                ball_j++;
            } else {
                if (ball_i == pos_team_1 + 1) {
                    ball_direction_i = 1;
                    ball_direction = 1;
                    ball_j++;
                } else {
                    if (ball_i == pos_team_1) {
                        ball_direction_i = 0;
                        ball_direction = 1;
                        ball_j++;
                    } else {
                        ball_j--;
                    }
                }
            }
        } else {
            ball_j--;
        }
    }
}

int keyboard_handler(int c) {
    if (c == 65 || c == 97) {  // 65 - а, 97 - A
        if (pos_team_1 - 1 == 1) {
        } else {
            pos_team_1--;
        }
    } else {
        if (c == 90 || c == 122) {  // 90 - Z, 122 - z
            if (pos_team_1 + 1 == 23) {
            } else {
                pos_team_1++;
            }
        } else {
            if (c == 75 || c == 107) {  // 75 - K, 107 - k
                if (pos_team_2 - 1 == 1) {
                } else {
                    pos_team_2--;
                }
            } else {
                 if (c == 77 || c == 109) {  // 77 - M, 109 - m
                     if (pos_team_2 + 1 == 23) {
                     } else {
                        pos_team_2++;
                    }
                } else {
                    if (c == 32) {  // 32 - пробел
                    } else {
                        printf("\e[1;1H\e[2J");
                        print();
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void create_map() {
	for (int i = 0; i < heigth; i++) {
		for(int j = 0; j < width; j++) {
            check(i, j);
		}
	}
}

void create_rocket() {
	map[pos_team_1][13] = 'R';
	map[pos_team_1 - 1][13] = 'R';
	map[pos_team_1 + 1][13] = 'R';
	map[pos_team_2][66] = 'R';
	map[pos_team_2 - 1][66] = 'R';
	map[pos_team_2 + 1][66] = 'R';
	map[ball_i][ball_j] = 'B';
}
void check(int i, int j) {
	if (i == 0 || i == 24) {
		map[i][j] = '-';
		return;
	}
	if (j == 0 || j == 79) {
		map[i][j] = '|';
		return;
	}
	if (j != 40) {
		map[i][j] = ' ';
	} else {
        map[i][j] = '|';
	}
	create_rocket();
}

void print() {
	for (int i = 0; i < heigth; i++) {
			for (int j = 0; j < width; j++) {
				if (map[i][j] == 'R') {
					printf("█");
					continue;
                }
				if (map[i][j] == 'G') {
					printf("━");
					continue;
				}
				if (map[i][j] == 'B') {
					printf("✱");
					continue;
				}
				printf("%c", map[i][j]);
			}
		printf("\n");
		}
}
