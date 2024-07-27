#include<iostream>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void player2game(int &p1, int &p2);

void gotoRowCol(int rpos, int cpos)
{
	int xpos=cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void sleep(int m)
{
        for(int j=0;j<m*21000;j++)
        {

        }
}

void print_box(int r, int c, int num, int p1, int p2)
{
    gotoRowCol(r + 3, c + 2);
    cout << num;
    if(p1 != p2)
        {
        if(num == p1){
            gotoRowCol(r + 1, c);
            cout << "#";
        }
        if(num == p2){
            gotoRowCol(r + 1, c);
            cout << "$";
        }
    }
    else if(p1 == p2)
    {
        if(num == p1){
            gotoRowCol(r + 1, c);
            cout << "#";
        }
        if(num == p2){
            gotoRowCol(r + 1, c + 2);
            cout << "$";
        }
    }
    for(int i = 1; i<=6; i++)
    {
        gotoRowCol(r, c);
        cout << char(219);
        c++;
    }

    for (int i = 1; i <= 5; i++)
    {
        gotoRowCol(r, c);
        cout << char(219);
        r++;
    }
}
int roll_Dice()
{
    int a;
    a=rand()%5+2;
   return a;
   }

void side_print()
{
    for(int x=0;x<=69;x++)
    {gotoRowCol(0,x);
    cout<<char(219);}
    for(int y=0;y<=49;y++)
    {gotoRowCol(y,0);
    cout<<char(219);}
    for(int z=0;z<=69;z++)
    {gotoRowCol(49,z);
    cout<<char(219);}
    }

void print_board(int &p1, int &p2)
{
    side_print();
    int num = 100;
    for(int i = 0; i <= 45; i+=5)
    {
        for(int j = 0; j <= 63; j+=7)
        {
            print_box(i,j, num, p1, p2);
            num--;
        }
    }
}

void clearScreen(){
    for(int i = 0; i <= 75; i++){
        for(int j = 0; j <= 75; j++){
            gotoRowCol(i, j);
            cout << " ";
        }
    }
}

void player1game(int &p1, int &p2){
    int random_number=0;
    gotoRowCol(5, 90);
    cout << "P1 Turn: ";
    _getch();
    while (true)
        {
        if (_kbhit())
         {
            random_number = roll_Dice();
            cout << "The dice rolled: " << random_number << std::endl;
            if(p1 == 0 && random_number != 6){
                player2game(p1, p2);
            }
            else if(p1== 0 && random_number == 6){
                p1 = 1;
                clearScreen();
                print_board(p1, p2);
                player1game(p1, p2);
            }
            else if(p1> 0 && random_number == 6){
                if(p1 + random_number <= 100)
                    p1+= 6;
                else{
                    player2game(p1, p2);
                }
                if(p1== 2)
                    p1 = 23;
                else if(p1== 37)
                    p1 = 56;
                else if(p1 == 64)
                    p1 = 82;
                else if(p1 == 98)
                    p1 = 17;
                else if(p1 == 36)
                    p1 = 14;
                else if(p1 == 69)
                    p1= 46;
                clearScreen();
                print_board(p1, p2);
                player1game(p1, p2);
            }
            if(p1+ random_number <= 100)
                p1 += random_number;
            if(p1 == 2)
                p1 = 23;
            else if(p1 == 37)
                p1 = 56;
            else if(p1 == 64)
                p1 = 82;
            else if(p1 == 98)
                p1 = 17;
            else if(p1 == 36)
                p1 = 14;
            else if(p1 == 69)
                p1= 46;
            clearScreen();
            if(p1 <= 100)
                print_board(p1, p2);
            break;
        }
    }
    if(p1 == 100){
        gotoRowCol(7, 75);
        cout << "P1 in WINNER!";
        return;
    }
    if(p1 > 100){
        clearScreen();
        print_board(p1, p2);
        player2game(p1, p2);
    }
    if(true){
        player2game(p1, p2);
    }
}
void player2game(int &p1, int &p2){
    int random_number, a = 0;
    gotoRowCol(5, 75);
    cout << "P2 Turn: ";
    _getch();
    while (true)
        {
        if (_kbhit())
         {
            random_number = roll_Dice();
            cout << "The dice rolled: " << random_number << std::endl;
            if(p2 == 0 && random_number != 6){
                player2game(p1, p2);
            }
            else if(p2== 0 && random_number == 6){
                p2 = 1;
                clearScreen();
                print_board(p1, p2);
                player2game(p1, p2);
            }
            else if(p2> 0 && random_number == 6){//snakes and ladders for six
                if(p2 + random_number <= 100)
                    p2+= 6;
                else{
                    player1game(p1, p2);
                }
                if(p2== 2)
                    p2 = 23;
                else if(p2== 37)
                    p2 = 56;
                else if(p2 == 64)
                    p2 = 82;
                else if(p2 == 98)
                    p2 = 17;
                else if(p2 == 36)
                    p2 = 14;
                else if(p2 == 69)
                    p2= 46;
                clearScreen();
                print_board(p1, p2);
                player2game(p1, p2);
            }
            if(p2+ random_number <= 100)//snakes and ladders check
                p2 += random_number;
            if(p2 == 2)
                p2 = 23;
            else if(p2 == 37)
                p2 = 56;
            else if(p2 == 64)
                p2 = 82;
            else if(p2 == 98)
                p2 = 17;
            else if(p2 == 36)
                p2 = 14;
            else if(p2 == 69)
                p2= 46;
            clearScreen();
            if(p2 <= 100)
                print_board(p1, p2);
            break;
        }
    }
    if(p2 == 100){//condition for checking winner
        gotoRowCol(7, 75);
        cout << "P2 in WINNER!";
        return;
    }
    if(p2 > 100){
        clearScreen();
        print_board(p1, p2);
        player1game(p1, p2);
    }
    if(true){
        player1game(p1, p2);
    }
}
void infomation(){
    gotoRowCol(9, 110);
    cout << "P1------> !";
    gotoRowCol(10, 110);
    cout << "P2------> @";
    gotoRowCol(11, 110);
    cout << "**************" << endl;
    gotoRowCol(12, 110);
    cout << "Snakes:" << endl;
    gotoRowCol(13, 110);
    cout << "98------->17" << endl;
    gotoRowCol(14, 110);
    cout << "69------->46" << endl;
    gotoRowCol(15, 110);
    cout << "36----->14" << endl;
    gotoRowCol(16, 110);
    cout << "Ladders:" << endl;
    gotoRowCol(17, 110);
    cout << "2------->23" << endl;
    gotoRowCol(18, 110);
    cout << "37------->56" << endl;
    gotoRowCol(19, 110);
    cout << "64----->82" << endl;
}

int main()
{
    _getch();
    infomation();
    int p1= 0, p2 = 0;
    print_board(p1, p2);
    player1game(p1, p2);
    _getch();
    return 0;
}
