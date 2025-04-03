#include<iostream>
// #include<iomanip> //* for two pressison point
// #include<unistd.h> // for usleep()
#include<time.h>

using namespace std;

void create_board( char *red, char *blue, char *yellow, char *green);

inline void player1_dice( char *red, char *blue, char *yellow, char *green, char player11, int num, bool running, int no, int &loc11, int &loc12, int &loc13, int &loc14, int &player1);
inline void player2_dice( char *red, char *blue, char *yellow, char *green, char player21, int num, bool running, int no, int &loc21, int &loc22, int &loc23, int &loc24, int &player2);
inline void player3_dice( char *red, char *blue, char *yellow, char *green, char player31, int num, bool running, int no, int &loc31, int &loc32, int &loc33, int &loc34, int &player3);
inline void player4_dice( char *red, char *blue, char *yellow, char *green, char player41, int num, bool running, int no, int &loc41, int &loc42, int &loc43, int &loc44, int &player4);

inline void revive1( char *red, char *blue, char *yellow, char *green, char player11, bool running, int num, int no, int &loc11, int &loc12 , int &loc13, int &loc14, int &player1);
inline void revive2( char *red, char *blue, char *yellow, char *green, char player21, bool running, int num, int no, int &loc11, int &loc22 , int &loc23, int &loc24, int &player2);
inline void revive3( char *red, char *blue, char *yellow, char *green, char player31, bool running, int num, int no, int &loc11, int &loc32 , int &loc33, int &loc34, int &player3);
inline void revive4( char *red, char *blue, char *yellow, char *green, char player41, bool running, int num, int no, int &loc11, int &loc42 , int &loc43, int &loc44, int &player4);

inline void dot1_move( char *red, char *blue, char *yellow, char *green, char player11, int no, int &loc11, int &loc12, int &loc13, int &loc14, bool running, int num);
inline void dot2_move( char *red, char *blue, char *yellow, char *green, char player21, int no, int &loc21, int &loc22, int &loc23, int &loc24, bool running, int num);
inline void dot3_move( char *red, char *blue, char *yellow, char *green, char player31, int no, int &loc31, int &loc32, int &loc33, int &loc34, bool running, int num);
inline void dot4_move( char *red, char *blue, char *yellow, char *green, char player41, int no, int &loc41, int &loc42, int &loc43, int &loc44, bool running, int num);

inline void last1_move( char *red, char *blue, char *yellow, char *green, char player11, int no, int &loc11, int &loc12, int &loc13, int &loc14, bool running, int num,int &player1);
inline void last2_move( char *red, char *blue, char *yellow, char *green, char player21, int no, int &loc21, int &loc22, int &loc23, int &loc24, bool running, int num,int &player2);
inline void last3_move( char *red, char *blue, char *yellow, char *green, char player31, int no, int &loc31, int &loc32, int &loc33, int &loc34, bool running, int num,int &player3);
inline void last4_move( char *red, char *blue, char *yellow, char *green, char player41, int no, int &loc41, int &loc42, int &loc43, int &loc44, bool running, int num,int &player4);

inline void valid_kill1( char *red, char *blue, char *yellow, char *green, char player11, char player21, char player31, char player41, int &loc11, int &loc12, int &loc13, int &loc14, int &loc21, int &loc22, int &loc23, int &loc24, int &loc31, int &loc32, int &loc33, int &loc34, int &loc41, int &loc42, int &loc43, int &loc44);
inline void valid_kill2( char *red, char *blue, char *yellow, char *green, char player11, char player21, char player31, char player41, int &loc11, int &loc12, int &loc13, int &loc14, int &loc21, int &loc22, int &loc23, int &loc24, int &loc31, int &loc32, int &loc33, int &loc34, int &loc41, int &loc42, int &loc43, int &loc44);
inline void valid_kill3( char *red, char *blue, char *yellow, char *green, char player11, char player21, char player31, char player41, int &loc11, int &loc12, int &loc13, int &loc14, int &loc21, int &loc22, int &loc23, int &loc24, int &loc31, int &loc32, int &loc33, int &loc34, int &loc41, int &loc42, int &loc43, int &loc44);
inline void valid_kill4( char *red, char *blue, char *yellow, char *green, char player11, char player21, char player31, char player41, int &loc11, int &loc12, int &loc13, int &loc14, int &loc21, int &loc22, int &loc23, int &loc24, int &loc31, int &loc32, int &loc33, int &loc34, int &loc41, int &loc42, int &loc43, int &loc44);

void check_winner( char *red, char *blue, char *yellow, char *green, int player1, int player2, int player3, int player4);

int roll();

int main()
{
    char red[90]={ ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char green[90]={ ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char yellow[90]={ ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char blue[90]={ ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

    int player1 = 0;
    int player2 = 0;
    int player3 = 0;
    int player4 = 0;

    char player11 = (char)227;
    char player21 = (char)224;
    char player31 = (char)234;
    char player41 = (char)225;

    //player is used for dot type
    red[77] = player11; red[78] = player11; red[79] = player11; red[80] = player11; 
    green[77] = player21; green[78] = player21; green[79] = player21; green[80] = player21; 
    yellow[77] = player31; yellow[78] = player31; yellow[79] = player31; yellow[80] = player31; 
    blue[77] = player41; blue[78] = player41; blue[79] = player41; blue[80] = player41; 
    
    //loc is used for dot move
    int loc11 = 77; int loc12 = 78; int loc13 = 79; int loc14 = 80;
    int loc21 = 77; int loc22 = 78; int loc23 = 79; int loc24 = 80;
    int loc31 = 77; int loc32 = 78; int loc33 = 79; int loc34 = 80;
    int loc41 = 77; int loc42 = 78; int loc43 = 79; int loc44 = 80;

    bool running = true;
    bool winner = true;
    int no, number, num;

    create_board( red, blue, yellow, green);
    while (winner == true )
    {
        // cin.clear();    //* most imp. ex- enter pizza without this = infinity loop
        // fflush(stdin);  //* most imp. ex- enter pizza without this = infinity loop

        player1_dice( red, blue, yellow, green, player11, running, num, no, loc11, loc12, loc13, loc14, player1);
            valid_kill1( red, blue, yellow, green, player11, player21, player31, player41, loc11, loc12, loc13, loc14, loc21, loc22, loc23, loc24, loc31, loc32, loc33, loc34, loc41, loc42, loc43, loc44);
            check_winner( red, blue, yellow, green, player1, player2, player3, player4);
            create_board(  red, blue, yellow, green);
        
        player2_dice( red, blue, yellow, green, player21, running, num, no, loc21, loc22, loc23, loc24, player2);
            valid_kill2( red, blue, yellow, green, player11, player21, player31, player41, loc11, loc12, loc13, loc14, loc21, loc22, loc23, loc24, loc31, loc32, loc33, loc34, loc41, loc42, loc43, loc44);
            check_winner( red, blue, yellow, green, player1, player2, player3, player4);
            create_board(  red, blue, yellow, green);
        
        player3_dice( red, blue, yellow, green, player31, running, num, no, loc31, loc32, loc33, loc34, player3);
            valid_kill3( red, blue, yellow, green, player11, player21, player31, player41, loc11, loc12, loc13, loc14, loc21, loc22, loc23, loc24, loc31, loc32, loc33, loc34, loc41, loc42, loc43, loc44);
            check_winner( red, blue, yellow, green, player1, player2, player3, player4);
            create_board(  red, blue, yellow, green);

        player4_dice( red, blue, yellow, green, player41, running, num, no, loc41, loc42, loc43, loc44, player4);
            valid_kill4( red, blue, yellow, green, player11, player21, player31, player41, loc11, loc12, loc13, loc14, loc21, loc22, loc23, loc24, loc31, loc32, loc33, loc34, loc41, loc42, loc43, loc44);
            check_winner( red, blue, yellow, green, player1, player2, player3, player4);
           create_board(  red, blue, yellow, green);
    }

    return 0;
}

// void clearScreen()
// {
//     std::cout << "\033[2J\033[1;1H"; // Clear screen and move cursor to home position
// }

int roll()
{
    srand(time(0));
    int number,num;
    cin >> number;
    num = (rand() +number) % 6;
    num++;
    cout << "Your dice is - " << num << endl;
    return num;
    
}

void player1_dice( char *red, char *blue, char *yellow, char *green, char player11, int num, bool running, int no, int &loc11, int &loc12, int &loc13, int &loc14, int &player1)
{
    do
    {
        cout << "Player 1 role dice - ";
        num = roll();

        if (num == 6 && (loc11 == 77 || loc12 == 78 || loc13 == 79 || loc14 == 80))
        {
            revive1( red, blue, yellow, green, player11, num, running, no, loc11, loc12, loc13, loc14, player1);
        }
        else if ((num <= 5) && (loc11 < 60 || loc12 < 60 || loc13 < 60 || loc14 < 60))
        {
            dot1_move( red, blue, yellow, green, player11, no, loc11, loc12, loc13, loc14, running, num);
        }
        else if ((num <= 5) && ( (loc11 >= 60) && (loc11 <= 65) || (loc12 >= 60) && (loc12 <= 65) || (loc13 >= 60) && (loc13 <= 65) || (loc14 >= 60) && (loc14 <= 65) ))
        {
            last1_move( red, blue, yellow, green, player11, no, loc11, loc12, loc13, loc14, running, num, player1);
        }
    } while (!num >=1);   
}

void player2_dice( char *red, char *blue, char *yellow, char *green, char player21, int num, bool running, int no, int &loc21, int &loc22, int &loc23,  int &loc24, int &player2)
{
    do
    {
        cout << "Player 2 role dice - ";
        num = roll();

        if (num == 6 && (loc21 == 77 || loc22 == 78 || loc23 == 79 || loc24 == 80))
        {
            revive2( red, blue, yellow, green, player21, running, num, no, loc21, loc22, loc23, loc24, player2);
        }else if (num <= 5 && (loc21 < 70 || loc22 < 70 || loc23 < 70 || loc24 < 70))
        {
            dot2_move( red, blue, yellow, green, player21, no, loc21, loc22, loc23, loc24, running, num);
        }
        else if ((num <= 5) && ( (loc21 >= 60) && (loc21 <= 65) || (loc22 >= 60) && (loc22 <= 65) || (loc23 >= 60) && (loc23 <= 65) || (loc24 >= 60) && (loc24 <= 65) ))
        {
            last2_move( red, blue, yellow, green, player21, no, loc21, loc22, loc23, loc24, running, num, player2);
        }
    } while (!num >=1);   
}

void player3_dice( char *red, char *blue, char *yellow, char *green, char player31, int num, bool running, int no, int &loc31, int &loc32, int &loc33,  int &loc34, int &player3)
{
    do
    {
        cout << "Player 3 role dice - ";
        num = roll();

        if (num == 6 && (loc31 == 77 || loc32 == 78 || loc33 == 79 || loc34 == 80))
        {
            revive3( red, blue, yellow, green, player31, running, num, no, loc31, loc32, loc33, loc34, player3);
        }else if (num <= 5 && (loc31 < 70 || loc32 < 70 || loc33 < 70 || loc34 < 70))
        {
            dot3_move( red, blue, yellow, green, player31, no, loc31, loc32, loc33, loc34, running, num);   
        }
        else if ((num <= 5) && ( (loc31 >= 60) && (loc31 <= 65) || (loc32 >= 60) && (loc32 <= 65) || (loc33 >= 60) && (loc33 <= 65) || (loc34 >= 60) && (loc34 <= 65) ))
        {
            last3_move( red, blue, yellow, green, player31, no, loc31, loc32, loc33, loc34, running, num, player3);
        }
    } while (!num >=1);   
}

void player4_dice( char *red, char *blue, char *yellow, char *green, char player41, int num, bool running, int no, int &loc41, int &loc42, int &loc43,  int &loc44, int &player4)
{
    do
    {
        cout << "Player 4 role dice - ";
        num = roll();

        if (num == 6 && (loc41 == 77 || loc42 == 78 || loc43 == 79 || loc44 == 80))
        {
            revive4( red, blue, yellow, green, player41, running, num, no, loc41, loc42, loc43, loc44, player4);
        }else if (num <= 5 && (loc41 < 70 || loc42 < 70 || loc43 < 70 || loc44 < 70))
        {
            dot4_move( red, blue, yellow, green, player41, no, loc41, loc42, loc43, loc44, running, num);
        }
        else if ((num <= 5) && ( (loc41 >= 60) && (loc41 <= 65) || (loc42 >= 60) && (loc42 <= 65) || (loc43 >= 60) && (loc43 <= 65) || (loc44 >= 60) && (loc44 <= 65) ))
        {
            last4_move( red, blue, yellow, green, player41, no, loc41, loc42, loc43, loc44, running, num, player4);
        }
    } while (!num >= 1);   
}

void revive1( char *red, char *blue, char *yellow, char *green, char player11,  bool running, int num, int no, int &loc11, int &loc12, int &loc13, int &loc14,int &player1)
{
    if (player11 == red[77] || player11 == red[78] || player11 == red[79] || player11 == red[80])
    {
        int no;
        cout << "Choose a dice to alive otherwise choose 0 -";
        cin >> no;
        if(no == 1 && red[77] == player11)
        {
            red[77] = ' ';
            red[2] = player11;
            loc11 = 2;
            player1_dice( red, blue, yellow, green, player11, running, num, no, loc11, loc12, loc13, loc14, player1);
        }else if (no == 1 && red[77] != player11)
        {
            red[loc11] = ' ';
            loc11 = loc11 + num;
            red[loc11] = player11;
            player1_dice( red, blue, yellow, green, player11, running, num, no, loc11, loc12, loc13, loc14, player1);
        }
        else if(no == 2 && red[78] == player11)
        {
            red[78] = ' ';
            red[3] = player11;
            loc12 = 3;
            player1_dice( red, blue, yellow, green, player11, running, num, no, loc11, loc12, loc13, loc14, player1);
        }else if (no == 2 && red[78] != player11)
        {
            red[loc12] = ' ';
            loc12 = loc12 + num;
            red[loc12] = player11;
            player1_dice( red, blue, yellow, green, player11, running, num, no, loc11, loc12, loc13, loc14, player1);
        }
        else if(no == 3 && red[79] == player11)
        {
            red[79] = ' ';
            red[4] = player11;
            loc13 = 4;
            player1_dice( red, blue, yellow, green, player11, running, num, no, loc11, loc12, loc13, loc14, player1);
        }else if (no == 3 && red[79] != player11)
        {
            red[loc13] = ' ';
            loc13 = loc13 + num;
            red[loc13] = player11;
            player1_dice( red, blue, yellow, green, player11, running, num, no, loc11, loc12, loc13, loc14, player1);
        }
        else if(no == 4 && red[80] == player11)
        {
            red[80] = ' ';
            red[5] = player11;
            loc14 = 5;
            player1_dice( red, blue, yellow, green, player11, running, num, no, loc11, loc12, loc13, loc14, player1);
        }else if (no == 4 && red[80] != player11)
        {
            red[loc14] = ' ';
            loc14 = loc14 + num;
            red[loc14] = player11;
            player1_dice( red, blue, yellow, green, player11, running, num, no, loc11, loc12, loc13, loc14, player1);
        }
    }
}

void revive2( char *red, char *blue, char *yellow, char *green, char player21,  bool running, int num, int no, int &loc21, int &loc22, int &loc23, int &loc24,int &player2)
{
    if (player21 == green[77] || player21 == green[78] || player21 == green[79] || player21 == green[80])
    {
        int no;
        cout << "Choose a dice to alive otherwise choose 0 -";
        cin >> no;
        if(no == 1 && green[77] == player21)
        {
            green[77] = ' ';
            green[2] = player21;
            loc21 = 2;
            player2_dice( red, blue, yellow, green, player21, running, num, no, loc21, loc22, loc23, loc24, player2);
        }else if (no == 1 && green[77] != player21)
        {
            green[loc21] = ' ';
            loc21 = loc21 + num;
            green[loc21] = player21;
            player2_dice( red, blue, yellow, green, player21, running, num, no, loc21, loc22, loc23, loc24, player2);
        }
        else if(no == 2 && green[78] == player21)
        {
            green[78] = ' ';
            green[3] = player21;
            loc22 = 3;
            player2_dice( red, blue, yellow, green, player21, running, num, no, loc21, loc22, loc23, loc24, player2);
        }else if (no == 2 && green[78] != player21)
        {
            green[loc22] = ' ';
            loc22 = loc22 + num;
            green[loc22] = player21;
            player2_dice( red, blue, yellow, green, player21, running, num, no, loc21, loc22, loc23, loc24, player2);
        }
        else if(no == 3 && green[79] == player21)
        {
            green[79] = ' ';
            green[4] = player21;
            loc23 = 4;
            player2_dice( red, blue, yellow, green, player21, running, num, no, loc21, loc22, loc23, loc24, player2);
        }else if (no == 3 && green[79] != player21)
        {
            green[loc23] = ' ';
            loc23 = loc23 + num;
            green[loc23] = player21;
            player2_dice( red, blue, yellow, green, player21, running, num, no, loc21, loc22, loc23, loc24, player2);
        }
        else if(no == 4 && green[80] == player21)
        {
            green[80] = ' ';
            green[5] = player21;
            loc24 = 5;
            player2_dice( red, blue, yellow, green, player21, running, num, no, loc21, loc22, loc23, loc24, player2);
        }else if (no == 4 && green[80] != player21)
        {
            green[loc24] = ' ';
            loc24 = loc24 + num;
            green[loc24] = player21;
            player2_dice( red, blue, yellow, green, player21, running, num, no, loc21, loc22, loc23, loc24, player2);
        }
    }
}

void revive3( char *red, char *blue, char *yellow, char *green, char player31,  bool running, int num, int no, int &loc31, int &loc32, int &loc33, int &loc34, int &player3)
{
    if (player31 == yellow[77] || player31 == yellow[78] || player31 == yellow[79] || player31 == yellow[80])
    {
        int no;
        cout << "Choose a dice to alive otherwise choose 0 -";
        cin >> no;
        if(no == 1 && yellow[77] == player31)
        {
            yellow[77] = ' ';
            yellow[2] = player31;
            loc31 = 2;
            player3_dice( red, blue, yellow, green, player31, running, num, no, loc31, loc32, loc33, loc34, player3);
        }else if(no == 1 && yellow[77] != player31)
        {
            yellow[loc31] = ' ';
            loc31 = loc31 + num;
            yellow[loc31] = player31;
            player3_dice( red, blue, yellow, green, player31, running, num, no, loc31, loc32, loc33, loc34, player3);
        }
        else if(no == 2 && yellow[78] == player31)
        {
            yellow[78] = ' ';
            yellow[3] = player31;
            loc32 = 3;
            player3_dice( red, blue, yellow, green, player31, running, num, no, loc31, loc32, loc33, loc34, player3);
        }else if(no == 1 && yellow[77] != player31)
        {
            yellow[loc32] = ' ';
            loc32 = loc32 + num;
            yellow[loc32] = player31;
            player3_dice( red, blue, yellow, green, player31, running, num, no, loc31, loc32, loc33, loc34, player3);
        }
        else if(no == 3 && yellow[79] == player31)
        {
            yellow[79] = ' ';
            yellow[4] = player31;
            loc33 = 4;
            player3_dice( red, blue, yellow, green, player31, running, num, no, loc31, loc32, loc33, loc34, player3);
        }else if (no == 1 && yellow[77] != player31)
        {
            yellow[loc33] = ' ';
            loc33 = loc33 + num;
            yellow[loc33] = player31;
            player3_dice( red, blue, yellow, green, player31, running, num, no, loc31, loc32, loc33, loc34, player3);
        }
        else if(no == 4 && yellow[80] == player31)
        {
            yellow[80] = ' ';
            yellow[5] = player31;
            loc34 = 5;
            player4_dice( red, blue, yellow, green, player31, running, num, no, loc31, loc32, loc33, loc34, player3);
        }else if(no == 1 && yellow[77] != player31)
        {
            yellow[loc34] = ' ';
            loc34 = loc34 + num;
            yellow[loc34] = player31;
            player3_dice( red, blue, yellow, green, player31, running, num, no, loc31, loc32, loc33, loc34, player3);
        }
    }
}

void revive4( char *red, char *blue, char *yellow, char *green, char player41,  bool running, int num, int no, int &loc41, int &loc42, int &loc43, int &loc44,int &player4)
{
    if (player41 == blue[77] || player41 == blue[78] || player41 == blue[79] || player41 == blue[80])
    {
        int no;
        cout << "Choose a dice to alive otherwise choose 0 -";
        cin >> no;
        if(no == 1 && blue[77] == player41)
        {
            blue[77] = ' ';
            blue[2] = player41;
            loc41 = 2;
            player4_dice( red, blue, yellow, green, player41, running, num, no, loc41, loc42, loc43, loc44, player4);
        }else if (no == 1 && blue[77] != player41)
        {
            blue[loc41] = ' ';
            loc41 = loc41 + num;
            blue[loc41] = player41;
            player4_dice( red, blue, yellow, green, player41, running, num, no, loc41, loc42, loc43, loc44, player4);
        }
        else if(no == 2 && blue[78] == player41)
        {
            blue[78] = ' ';
            blue[3] = player41;
            loc42 =3;
            player4_dice( red, blue, yellow, green, player41, running, num, no, loc41, loc42, loc43, loc44, player4);
        }else if(no == 2 && blue[78] != player41)
        {
            blue[loc42] = ' ';
            loc42 = loc42 + num;
            blue[loc42] = player41;
            player4_dice( red, blue, yellow, green, player41, running, num, no, loc41, loc42, loc43, loc44, player4);
        }
        else if(no == 3 && blue[79] == player41)
        {
            blue[79] = ' ';
            blue[4] = player41;
            loc43 = 4;
            player4_dice( red, blue, yellow, green, player41, running, num, no, loc41, loc42, loc43, loc44, player4);
        }else if(no == 3 && blue[79] != player41)
        {
            blue[loc43] = ' ';
            loc43 = loc43 + num;
            blue[loc43] = player41;
            player4_dice( red, blue, yellow, green, player41, running, num, no, loc41, loc42, loc43, loc44, player4);
        }
        else if(no == 4 && blue[80] == player41)
        {
            blue[80] = ' ';
            blue[5] = player41;
            loc44 = 5;
            player4_dice( red, blue, yellow, green, player41, running, num, no, loc41, loc42, loc43, loc44, player4);
        }else if(no == 4 && blue[80] != player41)
        {
            blue[loc44] = ' ';
            loc44 = loc44 + num;
            blue[loc44] = player41;
            player4_dice( red, blue, yellow, green, player41, running, num, no, loc41, loc42, loc43, loc44, player4);
        }
    }
}

void dot1_move( char *red, char *blue, char *yellow, char *green, char player11,  int no, int &loc11, int &loc12, int &loc13, int &loc14, bool running, int num)
{
    cout << "Choose a dice to move - ";
    cin >> no;
    if(no == 1)
    {
        if (loc11 == 2)
        {
            red[loc11] = ' ';
            loc11 = loc11 + 3;
            loc11 = loc11 + num;
            red[loc11] = player11;
        }
        else if (loc11 > 5 && loc11<70)
        {
            red[loc11] = ' ';
            loc11 = loc11 + num;
            red[loc11] = player11;
        }
    }
    else if(no == 2)
    {
        if (loc12 == 3)
        {
            red[loc12] = ' ';
            loc12 = loc12 + 2;
            loc12 = loc12 + num;
            red[loc12] = player11;
        }
        else if (loc12 > 5 && loc12<70)
        {
            red[loc12] = ' ';
            loc12 = loc12 + num;
            red[loc12] = player11;
        }
    }
    else if(no == 3)
    {
        if (loc13 == 4)
        {
            red[loc13] = ' ';
            loc13 = loc13 + 1;
            loc13 = loc13 + num;
            red[loc13] = player11;
        }
        else if (loc13 > 5 && loc13<70)
        {
            red[loc13] = ' ';
            loc13 = loc13 + num;
            red[loc13] = player11;
        }
    }
    else if(no == 4)
    {
        if (loc14 >= 5)
        {
            red[loc14] = ' ';
            loc14 = loc14 + num;
            red[loc14] = player11;
        }
    }        
}

void dot2_move( char *red, char *blue, char *yellow, char *green, char player21,  int no, int &loc21, int &loc22, int &loc23, int &loc24, bool running, int num)
{
    cout << "Choose a dice to move";
    cin >> no;
    if(no == 1)
    {
        if (loc21 == 2)
        {
            green[loc21] = ' ';
            loc21 = loc21 + 3;
            loc21 = loc21 + num;
            green[loc21] = player21;
        }
        else if (loc21 > 5 && loc21<70)
        {
            green[loc21] = ' ';
            loc21 = loc21 + num;
            green[loc21] = player21;
        }
    }
    else if(no == 2)
    {
        if (loc22 == 3)
        {
            green[loc22] = ' ';
            loc22 = loc22 + 2;
            loc22 = loc22 + num;
            green[loc22] = player21;
        }
        else if (loc22 > 5 && loc22<70)
        {
            green[loc22] = ' ';
            loc22 = loc22 + num;
            green[loc22] = player21;
        }
    }
    else if(no == 3)
    {
        if (loc23 == 4)
        {
            green[loc23] = ' ';
            loc23 = loc23 + 1;
            loc23 = loc23 + num;
            green[loc23] = player21;
        }
        else if (loc23 > 5 && loc23<70)
        {
            green[loc23] = ' ';
            loc23 = loc23 + num;
            green[loc23] = player21;
        }
    }
    else if(no == 4)
    {
        if (loc24 >= 5)
        {
            green[loc24] = ' ';
            loc24 = loc24 + num;
            green[loc24] = player21;
        }
    }
}

void dot3_move( char *red, char *blue, char *yellow, char *green, char player31,  int no, int &loc31, int &loc32, int &loc33, int &loc34, bool running, int num)
{
    cout << "Choose a dice to move";
    cin >> no;
    if(no == 1)
    {
        if (loc31 == 2)
        {
            yellow[loc31] = ' ';
            loc31 = loc31 + 3;
            loc31 = loc31 + num;
            yellow[loc31] = player31;
        }
        else if (loc31 > 5 && loc31<70)
        {
            yellow[loc31] = ' ';
            loc31 = loc31 + num;
            yellow[loc31] = player31;
        }
    }
    else if(no == 2)
    {
        if (loc32 == 3)
        {
            yellow[loc32] = ' ';
            loc32 = loc32 + 2;
            loc32 = loc32 + num;
            yellow[loc32] = player31;
        }
        else if (loc32 > 5 && loc32<70)
        {
            yellow[loc32] = ' ';
            loc32 = loc32 + num;
            yellow[loc32] = player31;
        }
    }
    else if(no == 3)
    {
        if (loc33 == 4)
        {
            yellow[loc33] = ' ';
            loc33 = loc33 + 1;
            loc33 = loc33 + num;
            yellow[loc33] = player31;
        }
        else if (loc33 > 5 && loc33<70)
        {
            yellow[loc33] = ' ';
            loc33 = loc33 + num;
            yellow[loc33] = player31;
        }
    }
    else if(no == 4)
    {
        if (loc34 >= 5)
        {
            yellow[loc34] = ' ';
            loc34 = loc34 + num;
            yellow[loc34] = player31;
        }
    }
}

void dot4_move( char *red, char *blue, char *yellow, char *green, char player41,  int no, int &loc41, int &loc42, int &loc43, int &loc44, bool running, int num)
{
    cout << "Choose a dice to move";
    cin >> no;
    if(no == 1)
    {
        if (loc41 == 2)
        {
            blue[loc41] = ' ';
            loc41 = loc41 + 3;
            loc41 = loc41 + num;
            blue[loc41] = player41;
        }
        else if (loc41 > 5 && loc41<70)
        {
            blue[loc41] = ' ';
            loc41 = loc41 + num;
            blue[loc41] = player41;
        }
    }
    else if(no == 2)
    {
        if (loc42 == 3)
        {
            blue[loc42] = ' ';
            loc42 = loc42 + 2;
            loc42 = loc42 + num;
            blue[loc42] = player41;
        }
        else if (loc42 > 5 && loc42<70)
        {
            blue[loc42] = ' ';
            loc42 = loc42 + num;
            blue[loc42] = player41;
        }
    }
    else if(no == 3)
    {
        if (loc43 == 4)
        {
            blue[loc43] = ' ';
            loc43 = loc43 + 1;
            loc43 = loc43 + num;
            blue[loc43] = player41;
        }
        else if (loc43 > 5 && loc43<70)
        {
            blue[loc43] = ' ';
            loc43 = loc43 + num;
            blue[loc43] = player41;
        }
    }
    else if(no == 4)
    {
        if (loc44 >= 5)
        {
            blue[loc44] = ' ';
            loc44 = loc44 + num;
            blue[loc44] = player41;
        }
    }
}

void last1_move( char *red, char *blue, char *yellow, char *green, char player11, int no, int &loc11, int &loc12, int &loc13, int &loc14, bool running, int num,int &player1)
{
    cout << "Choose a dice to move - ";
    cin >> no;
    if(no == 1)
    {
        if (loc11 >= 60 && loc11 <= 65)
        {
            red[loc11] = ' ';
            loc11 = loc11 + num;
            red[loc11] = player11;
            if (loc11 > 65)
            {
                red[loc11] = ' ';
                loc11 = loc11 - num;
                red[loc11] = player11; 
            }
            else if (loc11 == 65)
            {
                loc11 == 0;
                player1 ++;
            }
        }
    }
    else if(no == 2)
    {
        if (loc12 >= 60 && loc12 <= 65)
        {
            red[loc12] = ' ';
            loc12 = loc12 + num;
            red[loc12] = player11;
            if (loc12 > 65)
            {
                red[loc12] = ' ';
                loc12 = loc12 - num;
                red[loc12] = player11; 
            }
            else if (loc12 == 65)
            {
                loc12 = 0;
                player1 ++;
            }
        }
    }
    else if(no == 3)
    {
        if (loc13 >= 60 && loc13 <= 65)
        {
            red[loc13] = ' ';
            loc13 = loc13 + num;
            red[loc13] = player11;
            if (loc13 > 65)
            {
                red[loc13] = ' ';
                loc13 = loc13 - num;
                red[loc13] = player11; 
            }
            else if (loc13 == 65)
            {
                loc13 == 0;
                player1 ++;
            }
        }
    }
    else if(no == 4)
    {
        if (loc14 >= 60 && loc14 <= 65)
        {
            red[loc14] = ' ';
            loc14 = loc14 + num;
            red[loc14] = player11;
            if (loc14 > 65)
            {
                red[loc14] = ' ';
                loc14 = loc14 - num;
                red[loc14] = player11; 
            }
            else if (loc14 == 65)
            {
                loc14 == 0;
                player1 ++;
            }
        }
    }
}

void last2_move( char *red, char *blue, char *yellow, char *green, char player21, int no, int &loc21, int &loc22, int &loc23, int &loc24, bool running, int num,int &player2)
{
    cout << "Choose a dice to move - ";
    cin >> no;
    if(no == 1)
    {
        if (loc21 >= 60 && loc21 <= 65)
        {
            green[loc21] = ' ';
            loc21 = loc21 + num;
            green[loc21] = player21;
            if (loc21 > 65)
            {
                green[loc21] = ' ';
                loc21 = loc21 - num;
                green[loc21] = player21; 
            }
            else if (loc21 == 65)
            {
                loc21 == 0;
                player2 ++;
            }
        }
    }
    else if(no == 2)
    {
        if (loc22 >= 60 && loc22 <= 65)
        {
            green[loc22] = ' ';
            loc22 = loc22 + num;
            green[loc22] = player21;
            if (loc22 > 65)
            {
                green[loc22] = ' ';
                loc22 = loc22 - num;
                green[loc22] = player21; 
            }
            else if (loc22 == 65)
            {
                loc22 == 0;
                player2 ++;
            }
        }
    }
    else if(no == 3)
    {
        if (loc23 >= 60 && loc23 <=  65)
        {
            green[loc23] = ' ';
            loc23 = loc23 + num;
            green[loc23] = player21;if (loc21 > 65)
            {
                green[loc23] = ' ';
                loc23 = loc23 - num;
                green[loc23] = player21; 
            }
            else if (loc23 == 65)
            {
                loc23 == 0;
                player2 ++;
            }
        }
    }
    else if(no == 4)
    {
        if (loc24 >= 60 && loc24 <= 65)
        {
            green[loc24] = ' ';
            loc24 = loc24 + num;
            green[loc24] = player21;
            if (loc24 > 65)
            {
                green[loc24] = ' ';
                loc24 = loc24 - num;
                green[loc24] = player21; 
            }
            else if (loc24 == 65)
            {
                loc24 == 0;
                player2 ++;
            }
        }
    }
}

void last3_move( char *red, char *blue, char *yellow, char *green, char player31, int no, int &loc31, int &loc32, int &loc33, int &loc34, bool running, int num,int &player3)
{
    cout << "Choose a dice to move - ";
    cin >> no;
    if(no == 1)
    {
        if (loc31 >= 60 && loc31 <= 65)
        {
            yellow[loc31] = ' ';
            loc31 = loc31 + num;
            yellow[loc31] = player31;
            if (loc31 > 65)
            {
                yellow[loc31] = ' ';
                loc31 = loc31 - num;
                yellow[loc31] = player31; 
            }
            else if (loc31 == 65)
            {
                loc31 == 0;
                player3 ++;
            }
        }
    }
    else if(no == 2)
    {
        if (loc32 >= 60 && loc32 <= 65)
        {
            yellow[loc32] = ' ';
            loc32 = loc32 + num;
            yellow[loc32] = player31;
            if (loc32 > 65)
            {
                yellow[loc32] = ' ';
                loc32 = loc32 - num;
                yellow[loc32] = player31; 
            }
            else if (loc32 == 65)
            {
                loc32 == 0;
                player3 ++;
            }
        }
    }
    else if(no == 3)
    {
        if (loc33 >= 60 && loc33 <= 65)
        {
            yellow[loc33] = ' ';
            loc33 = loc33 + num;
            yellow[loc33] = player31;
            if (loc33 > 65)
            {
                yellow[loc33] = ' ';
                loc33 = loc33 - num;
                yellow[loc33] = player31; 
            }
            else if (loc33 == 65)
            {
                loc33 == 0;
                player3 ++;
            }
        }
    }
    else if(no == 4)
    {
        if (loc34 >= 60 && loc34 <= 65)
        {
            yellow[loc34] = ' ';
            loc34 = loc34 + num;
            yellow[loc34] = player31;
            if (loc34 > 65)
            {
                yellow[loc34] = ' ';
                loc34 = loc34 - num;
                yellow[loc34] = player31; 
            }
            else if (loc34 == 65)
            {
                loc34 == 0;
                player3 ++;
            }
        }
    }
}

void last4_move( char *red, char *blue, char *yellow, char *green, char player41, int no, int &loc41, int &loc42, int &loc43, int &loc44, bool running, int num,int &player4)
{
    cout << "Choose a dice to move - ";
    cin >> no;
    if(no == 1)
    {
        if (loc41 >= 60 && loc41 <= 65)
        {
            blue[loc41] = ' ';
            loc41 = loc41 + num;
            blue[loc41] = player41;
            if (loc41 > 65)
            {
                blue[loc41] = ' ';
                loc41 = loc41 - num;
                blue[loc41] = player41; 
            }
            else if (loc41 == 65)
            {
                loc41 == 0;
                player4 ++;
            }
        }
    }
    else if(no == 2)
    {
        if (loc42 >= 60 && loc42 <= 65)
        {
            blue[loc42] = ' ';
            loc42 = loc42 + num;
            blue[loc42] = player41;
            if (loc42 > 65)
            {
                blue[loc42] = ' ';
                loc42 = loc42 - num;
                blue[loc42] = player41; 
            }
            else if (loc42 == 65)
            {
                loc42 == 0;
                player4 ++;
            }
        }
    }
    else if(no == 3)
    {
        if (loc43 >= 60 && loc43 <= 65)
        {
            blue[loc43] = ' ';
            loc43 = loc43 + num;
            blue[loc43] = player41;
            if (loc43 > 65)
            {
                blue[loc43] = ' ';
                loc43 = loc43 - num;
                blue[loc43] = player41; 
            }
            else if (loc43 == 65)
            {
                loc43 == 0;
                player4 ++;
            }
        }
    }
    else if(no == 4)
    {
        if (loc44 >= 60 && loc44 <= 65)
        {
            blue[loc44] = ' ';
            loc44 = loc44 + num;
            blue[loc44] = player41;
            if (loc44 > 65)
            {
                blue[loc44] = ' ';
                loc44 = loc44 - num;
                blue[loc44] = player41; 
            }
            else if (loc44 == 65)
            {
                loc44 == 0;
                player4 ++;
            }
        }
    }
}

void valid_kill1( char *red, char *blue, char *yellow, char *green, char player11, char player21, char player31, char player41, int &loc11, int &loc12, int &loc13, int &loc14, int &loc21, int &loc22, int &loc23, int &loc24, int &loc31, int &loc32, int &loc33, int &loc34, int &loc41, int &loc42, int &loc43, int &loc44)
{
    if (loc21 >= 20 && loc21 <= 59)
    {
        if(loc11 == loc21+14 || loc12 == loc21+14 || loc13 == loc21+14 || loc14 == loc21+14 )
        {
            green[loc21] = ' ';
            loc21 = 77;
            green[loc21] = player21;
        }
    }else if (loc21 >= 6 && loc21 <= 17)
    {
        if(loc11 == loc21-42 || loc12 == loc21-42 || loc13 == loc21-42 || loc14 == loc21-42 )
        {
            green[loc21] = ' ';
            loc21 = 77;
            green[loc21] = player21;
        }
    }
    if (loc22 >= 20 && loc22 <= 59)
    {
        if(loc11 == loc22+14 || loc12 == loc22+14 || loc13 == loc22+14 || loc14 == loc22+14)
        {
            green[loc22] = ' ';
            loc22 = 78;
            green[loc22] = player21;
        }
    }else if (loc22 >= 6 && loc22 <= 17)
    {
        if(loc11 == loc22-42 || loc12 == loc22-42 || loc13 == loc22-42 || loc14 == loc22-42)
        {
            green[loc22] = ' ';
            loc22 = 78;
            green[loc22] = player21;
        }
    }
    if (loc23 >= 20 && loc23 <= 59)
    {
        if(loc11 == loc23+14 || loc12 == loc23+14 || loc13 == loc23+14 || loc14 == loc23+14)
        {
            green[loc23] = ' ';
            loc23 = 79;
            green[loc23] = player21;
        }
    }else if (loc23 >= 6 && loc23 <= 17)
    {
        if(loc11 == loc23-42 || loc12 == loc23-42 || loc13 == loc23-42 || loc14 == loc23-42)
        {
            green[loc23] = ' ';
            loc23 = 79;
            green[loc23] = player21;
        }
    }
    if (loc24 >= 20 && loc24 <= 59)
    {
        if(loc11 == loc24+14 || loc12 == loc24+14 || loc13 == loc24+14 || loc14 == loc24+14)
        {
            green[loc24] = ' ';
            loc24 = 80;
            green[loc24] = player21;
        }
    }else if (loc24 >= 6 && loc24 <= 17)
    {
        if(loc11 == loc24-42 || loc12 == loc24-42 || loc13 == loc24-42 || loc14 == loc24-42)
        {
            green[loc24] = ' ';
            loc24 = 80;
            green[loc24] = player21;
        }
    }
    
    if (loc31 >= 34 && loc31 <= 59)
    {
        if(loc11 == loc31+28 || loc12 == loc31+28 || loc13 == loc31+28 || loc14 == loc31+28)
        {
            yellow[loc31] = ' ';
            loc31 = 77;
            yellow[loc31] = player31;
        }
    }else if (loc31 >= 6 && loc31 <= 31)
    {
        if(loc11 == loc31-28 || loc12 == loc31-28 || loc13 == loc31-28 || loc14 == loc31-28)
        {
            yellow[loc31] = ' ';
            loc31 = 77;
            yellow[loc31] = player31;
        }
    }
    if (loc32 >= 34 && loc32 <= 59)
    {
        if(loc11 == loc32+28 || loc12 == loc32+28 || loc13 == loc32+28 || loc14 == loc32+28)
        {
            yellow[loc32] = ' ';
            loc32 = 78;
            yellow[loc32] = player31;
        }
    }else if (loc32 >= 6 && loc32 <= 31)
    {
        if(loc11 == loc32-28 || loc12 == loc32-28 || loc13 == loc32-28 || loc14 == loc32-28)
        {
            yellow[loc32] = ' ';
            loc32 = 78;
            yellow[loc32] = player31;
        }
    }
    if (loc33 >= 34 && loc33 <= 59)
    {
        if(loc11 == loc33+28 || loc12 == loc33+28 || loc13 == loc33+28 || loc14 == loc33+28)
        {
            yellow[loc33] = ' ';
            loc33 = 79;
            yellow[loc33] = player31;
        }
    }else if (loc33 >= 6 && loc33 <= 31)
    {
        if(loc11 == loc33-28 || loc12 == loc33-28 || loc13 == loc33-28 || loc14 == loc33-28)
        {
            yellow[loc33] = ' ';
            loc33 = 79;
            yellow[loc33] = player31;
        }
    }
    if (loc34 >= 34 && loc34 <= 59)
    {
        if(loc11 == loc34+28 || loc12 == loc34+28 || loc13 == loc34+28 || loc14 == loc34+28)
        {
            yellow[loc34] = ' ';
            loc34 = 80;
            yellow[loc34] = player31;
        }
    }else if (loc34 >= 6 && loc34 <= 31)
    {
        if(loc11 == loc34-28 || loc12 == loc34-28 || loc13 == loc34-28 || loc14 == loc34-28)
        {
            yellow[loc34] = ' ';
            loc34 = 80;
            yellow[loc34] = player31;
        }
    }
    
    if (loc41 >= 48 && loc41 <= 59)
    {
        if(loc11 == loc41+42 || loc12 == loc41+42 || loc13 == loc41+42 || loc14 == loc41+42)
        {
            blue[loc41] = ' ';
            loc41 = 77;
            blue[loc41] = player41;
        }
    }else if (loc41 >= 6 && loc41 <= 45)
    {
        if(loc11 == loc41-14 || loc12 == loc41-14 || loc13 == loc41-14 || loc14 == loc41-14)
        {
            blue[loc41] = ' ';
            loc41 = 77;
            blue[loc41] = player41;
        }
    }
    if (loc42 >= 48 && loc42 <= 59)
    {
        if(loc11 == loc42+42 || loc12 == loc42+42 || loc13 == loc42+42 || loc14 == loc42+42)
        {
            blue[loc42] = ' ';
            loc42 = 78;
            blue[loc42] = player41;
        }
    }else if (loc42 >= 6 && loc42 <= 45)
    {
        if(loc11 == loc42-14 || loc12 == loc42-14 || loc13 == loc42-14 || loc14 == loc42-14)
        {
            blue[loc42] = ' ';
            loc42 = 78;
            blue[loc42] = player41;
        }
    }
    if (loc43 >= 48 && loc43 <= 59)
    {
        if(loc11 == loc43+42 || loc12 == loc43+42 || loc13 == loc43+42 || loc14 == loc43+42)
        {
            blue[loc43] = ' ';
            loc43 = 79;
            blue[loc43] = player41;
        }
    }else if (loc43 >= 6 && loc43 <= 45)
    {
        if(loc11 == loc43-14 || loc12 == loc43-14 || loc13 == loc43-14 || loc14 == loc43-14)
        {
            blue[loc43] = ' ';
            loc43 = 79;
            blue[loc43] = player41;
        }
    }
    if (loc44 >= 48 && loc44 <= 59)
    {
        if(loc11 == loc44+42 || loc12 == loc44+42 || loc13 == loc44+42 || loc14 == loc44+42)
        {
            blue[loc44] = ' ';
            loc44 = 80;
            blue[loc44] = player41;
        }
    }else if (loc44 >= 6 && loc44 <= 45)
    {
        if(loc11 == loc44-14 || loc12 == loc44-14 || loc13 == loc44-14 || loc14 == loc44-14)
        {
            blue[loc44] = ' ';
            loc44 = 80;
            blue[loc44] = player41;
        }
    }
}

void valid_kill2( char *red, char *blue, char *yellow, char *green, char player11, char player21, char player31, char player41, int &loc11, int &loc12, int &loc13, int &loc14, int &loc21, int &loc22, int &loc23, int &loc24, int &loc31, int &loc32, int &loc33, int &loc34, int &loc41, int &loc42, int &loc43, int &loc44)
{
    if (loc11 >= 48 && loc11 <= 59)
    {
        if(loc21 == loc11+42 || loc22 == loc11+42 || loc23 == loc11+42 || loc24 == loc11+42 )
        {
            red[loc11] = ' ';
            loc11 = 77;
            red[loc11] = player11;
        }
    }else if (loc11 >= 6 && loc11 <= 45)
    {
        if(loc21 == loc11-14 || loc22 == loc11-14 || loc23 == loc11-14 || loc24 == loc11-14 )
        {
            red[loc11] = ' ';
            loc11 = 77;
            red[loc11] = player11;
        }
    }
    if (loc12 >= 48 && loc12 <= 59)
    {
        if(loc21 == loc12+42 || loc22 == loc12+42 || loc23 == loc12+42 || loc24 == loc12+42)
        {
            red[loc12] = ' ';
            loc12 = 78;
            red[loc12] = player11;
        }
    }else if (loc12 >= 6 && loc12 <= 45)
    {
        if(loc21 == loc12-14 || loc22 == loc12-14 || loc23 == loc12-14 || loc24 == loc12-14)
        {
            red[loc12] = ' ';
            loc12 = 78;
            red[loc12] = player11;
        }
    }
    if (loc13 >= 48 && loc13 <= 59)
    {
        if(loc21 == loc13+42 || loc22 == loc13+42 || loc23 == loc13+42 || loc24 == loc13+42)
        {
            red[loc13] = ' ';
            loc13 = 79;
            red[loc13] = player11;
        }
    }else if (loc13 >= 6 && loc13 <= 45)
    {
        if(loc21 == loc13-14 || loc22 == loc13-14 || loc23 == loc13-14 || loc24 == loc13-14)
        {
            red[loc13] = ' ';
            loc13 = 79;
            red[loc13] = player11;
        }
    }
    if (loc14 >= 48 && loc14 <= 59)
    {
        if(loc21 == loc14+42 || loc22 == loc14+42 || loc23 == loc14+42 || loc24 == loc14+42)
        {
            red[loc14] = ' ';
            loc14 = 80;
            red[loc14] = player11;
        }
    }else if (loc14 >= 6 && loc14 <= 45)
    {
        if(loc21 == loc14-14 || loc22 == loc14-14 || loc23 == loc14-14 || loc24 == loc14-14)
        {
            red[loc14] = ' ';
            loc14 = 80;
            red[loc14] = player11;
        }
    }
    
    if (loc31 >= 20 && loc31 <= 59)
    {
        if(loc21 == loc31+14 || loc22 == loc31+14 || loc23 == loc31+14 || loc24 == loc31+14)
        {
            yellow[loc31] = ' ';
            loc31 = 77;
            yellow[loc31] = player31;
        }
    }else if (loc31 >= 6 && loc31 <= 17)
    {
        if(loc21 == loc31-42 || loc22 == loc31-42 || loc23 == loc31-42 || loc24 == loc31-42)
        {
            yellow[loc31] = ' ';
            loc31 = 77;
            yellow[loc31] = player31;
        }
    }
    if (loc32 >= 20 && loc32 <= 59)
    {
        if(loc21 == loc32+14 || loc22 == loc32+14 || loc23 == loc32+14 || loc24 == loc32+14)
        {
            yellow[loc32] = ' ';
            loc32 = 78;
            yellow[loc32] = player31;
        }
    }else if (loc32 >= 6 && loc32 <= 17)
    {
        if(loc21 == loc32-42 || loc22 == loc32-42 || loc23 == loc32-42 || loc24 == loc32-42)
        {
            yellow[loc32] = ' ';
            loc32 = 78;
            yellow[loc32] = player31;
        }
    }
    if (loc33 >= 20 && loc33 <= 59)
    {
        if(loc21 == loc33+14 || loc22 == loc33+14 || loc23 == loc33+14 || loc24 == loc33+14)
        {
            yellow[loc33] = ' ';
            loc33 = 79;
            yellow[loc33] = player31;
        }
    }else if (loc33 >= 6 && loc33 <= 17)
    {
        if(loc21 == loc33-42 || loc22 == loc33-42 || loc23 == loc33-42 || loc24 == loc33-42)
        {
            yellow[loc33] = ' ';
            loc33 = 79;
            yellow[loc33] = player31;
        }
    }
    if (loc34 >= 20 && loc34 <= 59)
    {
        if(loc21 == loc34+14 || loc22 == loc34+14 || loc23 == loc34+14 || loc24 == loc34+14)
        {
            yellow[loc34] = ' ';
            loc34 = 80;
            yellow[loc34] = player31;
        }
    }else if (loc34 >= 6 && loc34 <= 17)
    {
        if(loc21 == loc34-42 || loc22 == loc34-42 || loc23 == loc34-42 || loc24 == loc34-42)
        {
            yellow[loc34] = ' ';
            loc34 = 80;
            yellow[loc34] = player31;
        }
    }
    
    if (loc41 >= 34 && loc41 <= 59)
    {
        if(loc21 == loc41+28 || loc22 == loc41+28 || loc23 == loc41+28 || loc24 == loc41+28)
        {
            blue[loc41] = ' ';
            loc41 = 77;
            blue[loc41] = player41;
        }
    }else if (loc41 >= 6 && loc41 <= 31)
    {
        if(loc21 == loc41-28 || loc22 == loc41-28 || loc23 == loc41-28 || loc24 == loc41-28)
        {
            blue[loc41] = ' ';
            loc41 = 77;
            blue[loc41] = player41;
        }
    }
    if (loc42 >= 34 && loc42 <= 59)
    {
        if(loc11 == loc42+28 || loc12 == loc42+28 || loc13 == loc42+28 || loc14 == loc42+28)
        {
            blue[loc42] = ' ';
            loc42 = 78;
            blue[loc42] = player41;
        }
    }else if (loc42 >= 6 && loc42 <= 31)
    {
        if(loc11 == loc42-28 || loc12 == loc42-28 || loc13 == loc42-28 || loc14 == loc42-28)
        {
            blue[loc42] = ' ';
            loc42 = 78;
            blue[loc42] = player41;
        }
    }
    if (loc43 >= 34 && loc43 <= 59)
    {
        if(loc11 == loc43+28 || loc12 == loc43+28 || loc13 == loc43+28 || loc14 == loc43+28)
        {
            blue[loc43] = ' ';
            loc43 = 79;
            blue[loc43] = player41;
        }
    }else if (loc43 >= 6 && loc43 <= 31)
    {
        if(loc11 == loc43-28 || loc12 == loc43-28 || loc13 == loc43-28 || loc14 == loc43-28)
        {
            blue[loc43] = ' ';
            loc43 = 79;
            blue[loc43] = player41;
        }
    }
    if (loc44 >= 34 && loc44 <= 59)
    {
        if(loc11 == loc44+28 || loc12 == loc44+28 || loc13 == loc44+28 || loc14 == loc44+28)
        {
            blue[loc44] = ' ';
            loc44 = 80;
            blue[loc44] = player41;
        }
    }else if (loc44 >= 6 && loc44 <= 31)
    {
        if(loc11 == loc44-28 || loc12 == loc44-28 || loc13 == loc44-28 || loc14 == loc44-28)
        {
            blue[loc44] = ' ';
            loc44 = 80;
            blue[loc44] = player41;
        }
    }
}

void valid_kill3( char *red, char *blue, char *yellow, char *green, char player11, char player21, char player31, char player41, int &loc11, int &loc12, int &loc13, int &loc14, int &loc21, int &loc22, int &loc23, int &loc24, int &loc31, int &loc32, int &loc33, int &loc34, int &loc41, int &loc42, int &loc43, int &loc44)
{ 
    if (loc11 >= 34 && loc11 <= 59)
    {
        if(loc31 == loc11+28 || loc32 == loc11+28 || loc33 == loc11+28 || loc34 == loc11+28 )
        {
            red[loc11] = ' ';
            loc11 = 77;
            red[loc11] = player11;
        }
    }else if (loc11 >= 6 && loc11 <= 31)
    {
        if(loc31 == loc11-28 || loc32 == loc11-28 || loc33 == loc11-28 || loc34 == loc11-28 )
        {
            red[loc11] = ' ';
            loc11 = 77;
            red[loc11] = player11;
        }
    }
    if (loc12 >= 34 && loc12 <= 59)
    {
        if(loc31 == loc12+28 || loc32 == loc12+28 || loc33 == loc12+28 || loc34 == loc12+28)
        {
            red[loc12] = ' ';
            loc12 = 78;
            red[loc12] = player11;
        }
    }else if (loc12 >= 6 && loc12 <= 31)
    {
        if(loc31 == loc12-28 || loc32 == loc12-28 || loc33 == loc12-28 || loc34 == loc12-28)
        {
            red[loc12] = ' ';
            loc12 = 78;
            red[loc12] = player11;
        }
    }
    if (loc13 >= 34 && loc13 <= 59)
    {
        if(loc31 == loc13+28 || loc32 == loc13+28 || loc33 == loc13+28 || loc34 == loc13+28)
        {
            red[loc13] = ' ';
            loc13 = 79;
            red[loc13] = player11;
        }
    }else if (loc13 >= 6 && loc13 <= 31)
    {
        if(loc31 == loc13-28 || loc32 == loc13-28 || loc33 == loc13-28 || loc34 == loc13-28)
        {
            red[loc13] = ' ';
            loc13 = 79;
            red[loc13] = player11;
        }
    }
    if (loc14 >= 34 && loc14 <= 59)
    {
        if(loc31 == loc14+28 || loc32 == loc14+28 || loc33 == loc14+28 || loc34 == loc14+28)
        {
            red[loc14] = ' ';
            loc14 = 80;
            red[loc14] = player11;
        }
    }else if (loc14 >= 6 && loc14 <= 31)
    {
        if(loc31 == loc14-28 || loc32 == loc14-28 || loc33 == loc14-28 || loc34 == loc14-28)
        {
            red[loc14] = ' ';
            loc14 = 80;
            red[loc14] = player11;
        }
    }
    
    if (loc21 >= 48 && loc21 <= 59)
    {
        if(loc31 == loc21+42 || loc32 == loc21+42 || loc33 == loc21+42 || loc34 == loc21+42)
        {
            green[loc21] = ' ';
            loc21 = 77;
            green[loc21] = player21;
        }
    }else if (loc21 >= 6 && loc21 <= 45)
    {
        if(loc31 == loc21-14 || loc32 == loc21-14 || loc33 == loc21-14 || loc34 == loc21-14)
        {
            green[loc21] = ' ';
            loc21 = 77;
            green[loc21] = player21;
        }
    }
    if (loc22 >= 48 && loc22 <= 59)
    {
        if(loc31 == loc22+42 || loc32 == loc22+42 || loc33 == loc22+42 || loc34 == loc22+42)
        {
            green[loc22] = ' ';
            loc22 = 78;
            green[loc22] = player21;
        }
    }else if (loc22 >= 6 && loc22 <= 45)
    {
        if(loc31 == loc22-14 || loc32 == loc22-14 || loc33 == loc22-14 || loc34 == loc22-14)
        {
            green[loc22] = ' ';
            loc22 = 78;
            green[loc22] = player21;
        }
    }
    if (loc23 >= 48 && loc23 <= 59)
    {
        if(loc31 == loc23+42 || loc32 == loc23+42 || loc33 == loc23+42 || loc34 == loc23+42)
        {
            green[loc23] = ' ';
            loc23 = 79;
            green[loc23] = player21;
        }
    }else if (loc23 >= 6 && loc23 <= 45)
    {
        if(loc31 == loc23-14 || loc32 == loc23-14 || loc33 == loc23-14 || loc34 == loc23-14)
        {
            green[loc23] = ' ';
            loc23 = 79;
            green[loc23] = player21;
        }
    }
    if (loc24 >= 48 && loc24 <= 59)
    {
        if(loc31 == loc24+42 || loc32 == loc24+42 || loc33 == loc24+42 || loc34 == loc24+42)
        {
            green[loc24] = ' ';
            loc24 = 80;
            green[loc24] = player21;
        }
    }else if (loc24 >= 6 && loc24 <= 45)
    {
        if(loc31 == loc24-14 || loc32 == loc24-14 || loc33 == loc24-14 || loc34 == loc24-14)
        {
            green[loc24] = ' ';
            loc24 = 80;
            green[loc24] = player21;
        }
    }
    
    if (loc41 >= 20 && loc31 <= 59)
    {
        if(loc31 == loc41+14 || loc32 == loc41+14 || loc33 == loc41+14 || loc34 == loc41+14)
        {
            blue[loc41] = ' ';
            loc41 = 77;
            blue[loc41] = player41;
        }
    }else if (loc41 >= 6 && loc41 <= 17)
    {
        if(loc31 == loc41-42 || loc32 == loc41-42 || loc33 == loc41-42 || loc34 == loc41-42)
        {
            blue[loc41] = ' ';
            loc41 = 77;
            blue[loc41] = player41;
        }
    }
    if (loc42 >= 20 && loc42 <= 59)
    {
        if(loc31 == loc42+14 || loc32 == loc42+14 || loc33 == loc42+14 || loc34 == loc42+14)
        {
            blue[loc42] = ' ';
            loc42 = 78;
            blue[loc42] = player41;
        }
    }else if (loc42 >= 6 && loc42 <= 17)
    {
        if(loc31 == loc42-42 || loc32 == loc42-42 || loc33 == loc42-42 || loc34 == loc42-42)
        {
            blue[loc42] = ' ';
            loc42 = 78;
            blue[loc42] = player41;
        }
    }
    if (loc43 >= 20 && loc43 <= 59)
    {
        if(loc31 == loc43+14 || loc32 == loc43+14 || loc33 == loc43+14 || loc34 == loc43+14)
        {
            blue[loc43] = ' ';
            loc43 = 79;
            blue[loc43] = player41;
        }
    }else if (loc43 >= 6 && loc43 <= 17)
    {
        if(loc31 == loc43-42 || loc32 == loc43-42 || loc33 == loc43-42 || loc34 == loc43-42)
        {
            blue[loc43] = ' ';
            loc43 = 79;
            blue[loc43] = player41;
        }
    }
    if (loc44 >= 20 && loc44 <= 59)
    {
        if(loc31 == loc44+14 || loc32 == loc44+14 || loc33 == loc44+14 || loc34 == loc44+14)
        {
            blue[loc44] = ' ';
            loc44 = 80;
            blue[loc44] = player41;
        }
    }else if (loc44 >= 6 && loc44 <= 17)
    {
        if(loc31 == loc44-42 || loc32 == loc44-42 || loc33 == loc44-42 || loc34 == loc44-42)
        {
            blue[loc44] = ' ';
            loc44 = 80;
            blue[loc44] = player41;
        }
    }
}

void valid_kill4( char *red, char *blue, char *yellow, char *green, char player11, char player21, char player31, char player41, int &loc11, int &loc12, int &loc13, int &loc14, int &loc21, int &loc22, int &loc23, int &loc24, int &loc31, int &loc32, int &loc33, int &loc34, int &loc41, int &loc42, int &loc43, int &loc44)
{
    if (loc11 >= 20 && loc11 <= 59)
    { 
        if(loc41 == loc11+14 || loc42 == loc11+14 || loc43 == loc11+14 || loc44 == loc11+14 )
        {
            red[loc11] = ' ';
            loc11 = 77;
            red[loc11] = player21;
        }
    }
    else if (loc11 >= 6 && loc11 <= 17)
    {
        if(loc41 == loc11-42 || loc42 == loc11-42 || loc43 == loc11-42 || loc44 == loc11-42 )
        {
            red[loc11] = ' ';
            loc11 = 77;
            red[loc11] = player21;
        }
    }
    if (loc12 >= 20 && loc12 <= 59)
    {
        if(loc41 == loc12+14 || loc42 == loc12+14 || loc43 == loc12+14 || loc44 == loc12+14)
        {
            red[loc12] = ' ';
            loc12 = 78;
            red[loc12] = player21;
        }
    }else if (loc12 >= 6 && loc12 <= 17)
    {
        if(loc41 == loc12-42 || loc42 == loc12-42 || loc43 == loc12-42 || loc44 == loc12-42)
        {
            red[loc12] = ' ';
            loc12 = 78;
            red[loc12] = player21;
        }
    }
    if (loc13 >= 20 && loc13 <= 59)
    {
        if(loc41 == loc13+14 || loc42 == loc13+14 || loc43 == loc13+14 || loc44 == loc13+14)
        {
            red[loc13] = ' ';
            loc13 = 79;
            red[loc13] = player21;
        }
    }else if (loc13 >= 6 && loc13 <= 17)
    {
        if(loc41 == loc13-42 || loc42 == loc13-42 || loc43 == loc13-42 || loc44 == loc13-42)
        {
            red[loc13] = ' ';
            loc13 = 79;
            red[loc13] = player21;
        }
    }
    if (loc14 >= 20 && loc14 <= 59)
    {
        if(loc41 == loc14+14 || loc42 == loc14+14 || loc43 == loc14+14 || loc44 == loc14+14)
        {
            red[loc14] = ' ';
            loc14 = 80;
            red[loc14] = player21;
        }
    }else if (loc14 >= 6 && loc14 <= 17)
    {
        if(loc41 == loc14-42 || loc42 == loc14-42 || loc43 == loc14-42 || loc44 == loc14-42)
        {
            red[loc14] = ' ';
            loc14 = 80;
            red[loc14] = player21;
        }
    }
    
    if (loc21 >= 34 && loc21 <= 59)
    {
        if(loc41 == loc21+28 || loc42 == loc21+28 || loc43 == loc21+28 || loc44 == loc21+28)
        {
            green[loc21] = ' ';
            loc21 = 77;
            green[loc21] = player21;
        }
    }else if (loc21 >= 6 && loc21 <= 31)
    {
        if(loc41 == loc21-28 || loc42 == loc21-28 || loc43 == loc21-28 || loc44 == loc21-28)
        {
            green[loc21] = ' ';
            loc21 = 77;
            green[loc21] = player21;
        }
    }
    if (loc22 >= 34 && loc22 <= 59)
    {
        if(loc41 == loc22+28 || loc42 == loc22+28 || loc43 == loc22+28 || loc44 == loc22+28)
        {
            green[loc22] = ' ';
            loc22 = 78;
            green[loc22] = player21;
        }
    }else if (loc22 >= 6 && loc22 <= 31)
    {
        if(loc41 == loc22-28 || loc42 == loc22-28 || loc43 == loc22-28 || loc44 == loc22-28)
        {
            green[loc22] = ' ';
            loc22 = 78;
            green[loc22] = player21;
        }
    }
    if (loc23 >= 34 && loc23 <= 59)
    {
        if(loc41 == loc23+28 || loc42 == loc23+28 || loc43 == loc23+28 || loc44 == loc23+28)
        {
            green[loc23] = ' ';
            loc23 = 79;
            green[loc23] = player21;
        }
    }else if (loc23 >= 6 && loc23 <= 31)
    {
        if(loc41 == loc23-28 || loc42 == loc23-28 || loc43 == loc23-28 || loc44 == loc23-28)
        {
            green[loc23] = ' ';
            loc23 = 79;
            green[loc23] = player21;
        }
    }
    if (loc24 >= 34 && loc24 <= 59)
    {
        if(loc41 == loc24+28 || loc42 == loc24+28 || loc43 == loc24+28 || loc44 == loc24+28)
        {
            green[loc24] = ' ';
            loc24 = 80;
            green[loc24] = player21;
        }
    }else if (loc24 >= 6 && loc24 <= 31)
    {
        if(loc41 == loc24-28 || loc42 == loc24-28 || loc43 == loc24-28 || loc44 == loc24-28)
        {
            green[loc24] = ' ';
            loc24 = 80;
            green[loc24] = player21;
        }
    }
    
    if (loc31 >= 48 && loc31 <= 59)
    {
        if(loc41 == loc31+42 || loc42 == loc31+42 || loc43 == loc31+42 || loc44 == loc31+42)
        {
            yellow[loc31] = ' ';
            loc31 = 77;
            yellow[loc31] = player31;
        }
    }else if (loc31 >= 6 && loc31 <= 45)
    {
        if(loc41 == loc31-14 || loc42 == loc31-14 || loc43 == loc31-14 || loc44 == loc31-14)
        {
            yellow[loc31] = ' ';
            loc31 = 77;
            yellow[loc31] = player31;
        }
    }
    if (loc32 >= 48 && loc32 <= 59)
    {
        if(loc41 == loc32+42 || loc42 == loc32+42 || loc43 == loc32+42 || loc44 == loc32+42)
        {
            yellow[loc32] = ' ';
            loc32 = 78;
            yellow[loc32] = player31;
        }
    }else if (loc32 >= 6 && loc32 <= 45)
    {
        if(loc41 == loc32-14 || loc42 == loc32-14 || loc43 == loc32-14 || loc44 == loc32-14)
        {
            yellow[loc32] = ' ';
            loc32 = 78;
            yellow[loc32] = player31;
        }
    }
    if (loc33 >= 48 && loc33 <= 59)
    {
        if(loc41 == loc33+42 || loc42 == loc33+42 || loc43 == loc33+42 || loc44 == loc33+42)
        {
            yellow[loc33] = ' ';
            loc33 = 79;
            yellow[loc33] = player31;
        }
    }else if (loc33 >= 6 && loc33 <= 45)
    {
        if(loc41 == loc33-14 || loc42 == loc33-14 || loc43 == loc33-14 || loc44 == loc33-14)
        {
            yellow[loc33] = ' ';
            loc33 = 79;
            yellow[loc33] = player31;
        }
    }
    if (loc34 >= 48 && loc34 <= 59)
    {
        if(loc41 == loc34+42 || loc42 == loc34+42 || loc43 == loc34+42 || loc44 == loc34+42)
        {
            yellow[loc34] = ' ';
            loc34 = 80;
            yellow[loc34] = player31;
        }
    }else if (loc34 >= 6 && loc34 <= 45)
    {
        if(loc41 == loc34-14 || loc42 == loc34-14 || loc43 == loc34-14 || loc44 == loc34-14)
        {
            yellow[loc34] = ' ';
            loc34 = 80;
            yellow[loc34] = player31;
        }
    }
}

void check_winner( char *red, char *blue, char *yellow, char *green, int player1, int player2, int player3, int player4)
{
    if (player1 == 4)
    {
        cout << "player1 win";
    }
    else if (player2 == 4)
    {
        cout << "player2 win";
    }
    else if (player3 == 4)
    {
        cout << "player3 win";
    }
    else if (player4 == 4)
    {
        cout << "player4 win";
    }
}

void create_board( char *red, char *blue, char *yellow, char *green)
{
    cout << endl;
    cout << "\t       ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______" << endl;
    cout << "\t      |                                         |  "  << red[58] <<   "" << green[16] << "  |  "  << red[59] <<   "" << green[17] << "  |  " << green[18] << "   |                                         |" << endl;
    cout << "\t      |                                         |  " << yellow[30] << "" << blue[44] << "  |  " << yellow[31] << "" << blue[45] << "  |  " << yellow[32] << "" << blue[46] << "  |                                         |" << endl;
    cout << "\t      |                                         |______|______|______|                                         |" << endl;

    cout << "\t      |                                         |  "  << red[57] <<   "" << green[15] <<                "  |      | "                << red[2] <<  "" << green[19] << ""  << red[3] <<  "  |                                         |" << endl;
    cout << "\t      |                                         |  " << yellow[29] << "" << blue[43] << "  |   "  << red[60] <<   "  |  " << yellow[33] << "*" << blue[47] << " |                                         |" << endl;
    cout << "\t      |           " << green[79] << "                  " << green[80] << "          |______|______|__"  << red[4] <<  ""  << red[5] <<  "__|         "  << red[77] <<   "                   "  << red[78] <<   "           |" << endl;

    cout << "\t      |                                         |  "  << red[56] <<   "" << green[14] <<                "  |      |  "                << red[6] <<  "" << green[20] << "  |                                         |" << endl;
    cout << "\t      |                                         |  " << yellow[28] << "" << blue[42] << "  |   "  << red[61] <<   "  |  " << yellow[34] << "" << blue[48] << "  |                                         |" << endl;
    cout << "\t      |                                         |______|______|______|                                         |" << endl;

    cout << "\t      |                                         |  "  << red[55] <<   "" << green[13] <<                "  |      |  "                << red[7] <<  "" << green[21] << "  |                                         |" << endl;
    cout << "\t      |                                         |  " << yellow[27] << "" << blue[41] << "  |   "  << red[62] <<   "  |  " << yellow[35] << "" << blue[49] << "  |                                         |" << endl;
    cout << "\t      |                                         |______|______|______|                                         |" << endl;

    cout << "\t      |           " << green[77] << "                  " << green[78] << "          |  "  << red[54] <<   "" << green[12] <<                "  |      |  "                << red[8] <<  "" << green[22] << "  |         "  << red[79] <<   "                   "  << red[80] << "           |" << endl;
    cout << "\t      |                                         |  " << yellow[26] << "" << blue[40] << "  |   "  << red[63] <<   "  |  " << yellow[36] << "" << blue[50] << "  |                                         |" << endl;
    cout << "\t      |                                         |______|______|______|                                         |" << endl;
    
    cout << "\t      |                                         |  "  << red[53] <<   "" << green[11] <<                "  |      |  "                << red[9] <<  "" << green[23] << "  |                                         |" << endl;
    cout << "\t      |                                         |  " << yellow[25] << "" << blue[39] << "  |   "  << red[64] <<   "  |  " << yellow[37] << "" << blue[51] << "  |                                         |" << endl;
    cout << "\t      |______ ______ ______ ______ ______ ______|______|______|______|______ ______ ______ ______ ______ ______|" << endl;
    
    cout << "\t      |   "                << red[46] <<                  "  | " << green[4] << ""  << red[47] <<   "" << green[5] << "  |  "   << red[48] <<   ""  << green[6] << "  |  "   << red[49] <<   ""  << green[7] << "  |  "   << red[50] <<   ""  << green[8] << "  |  "   << red[51] <<   ""  << green[9] << "  |  "   << red[52] <<   ""  << green[10] <<                 "  |      |  "                    << red[10] <<   ""  << green[24] << "  |  "   << red[11] <<  "" << green[25] << "  |  "   << red[12] <<  "" << green[26] << "  |  "   << red[13] <<  "" << green[27] << "  |  "   << red[14] <<  "" << green[28] << "  |  "   << red[15] <<  "" << green[29] << "  |  "   << red[16] <<  "" << green[30] << "  |" << endl;
    cout << "\t      |  " << yellow[18] << "" << blue[32] << "  |  "              << yellow[19] << "*" << blue[33] <<              " |  " << yellow[20] << "" << blue[34] << "  |  " << yellow[21] << "" << blue[35] << "  |  " << yellow[22] << "" << blue[36] << "  |  " << yellow[23] << "" << blue[37] << "  |  " << yellow[24] << "" << blue[38] << "  |   "        << red[65] <<          "  |  " << yellow[38] << "" << blue[52] << "  |  " << yellow[39] << "" << blue[53] << "  |  " << yellow[40] << "" << blue[54] << "  |  " << yellow[41] << "" << blue[55] << "  |  " << yellow[42] << "" << blue[56] << "  |  " << yellow[43] << "" << blue[57] << "  |  " << yellow[44] << "" << blue[58] << "  |" << endl;
    cout << "\t      |______|__" << green[2] << "" << green[3] << "__|______|______|______|______|______|______|______|______|______|______|______|______|______|" << endl;
    
    cout << "\t      |  "  << red[45] <<   "" << green[59] <<                                                                                                                                                                          "  |      |      |      |      |      |      |      |      |      |      |      |      |      |  "                                                                                                                                                                       << red[17] <<   "" << green[31] << "  |" << endl;
    cout << "\t      |  " << yellow[17] << "" << blue[31] << "  |   " << green[60] << "  |  " << green[61] << "   |  " << green[62] << "   |   " << green[63] << "  |  " << green[64] << "   |   " << green[65] << "  |      |   " << blue[65] << "  |   " << blue[64] << "  |   " << blue[63] << "  |   " << blue[62] << "  |   " << blue[61] << "  |   " << blue[60] << "  |  " << yellow[45] << "" << blue[59] << "  |" << endl;
    cout << "\t      |______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|" << endl;
    
    cout << "\t      |  "  << red[44] <<   "" << green[58] << "  |  "  << red[43] <<   "" << green[57] << "  |  "  << red[42] <<   "" << green[56] << "  |  "  << red[41] <<   "" << green[55] << "  |  "  << red[40] <<   "" << green[54] << "  |  "  << red[39] <<   "" << green[53] << "  |  "<< red[38] <<   "" << green[52] <<                   "  |      |  "                       << red[24] <<  "" << green[38] << "  |  " << red[23] <<  "" << green[37] << "  |  " << red[22] <<  "" << green[36] << "  |  " << red[21] <<  "" << green[35] << "  |  " << red[20] <<  "" << green[34] << "  |  " << red[19] <<  "" << green[33] << "" << blue[5] << " |  " << red[18] <<  "" << green[32] << "  |" << endl;
    cout << "\t      |  " << yellow[16] << "" << blue[30] << "  |  " << yellow[15] << "" << blue[29] << "  |  " << yellow[14] << "" << blue[28] << "  |  " << yellow[13] << "" << blue[27] << "  |  " << yellow[12] << "" << blue[26] << "  |  " << yellow[11] << "" << blue[25] << "  |  " << yellow[10] << "" << blue[24] << "  |  "       << yellow[65] <<       "   |  " << yellow[52] << "" << blue[10] << "  |  " << yellow[51] << "" << blue[9] << "  |  " << yellow[50] << "" << blue[8] << "  |  " << yellow[49] << "" << blue[7] << "  |  " << yellow[48] << "" << blue[6] << "  |  "                 << yellow[47] << "*" << blue[4] <<               " |   "             << yellow[46] <<              "  |" << endl;
    cout << "\t      |______|______|______|______|______|______|______|______|______|______|______|______|______|__" << blue[3] << "" << blue[2] << "__|______|" << endl;
    
    cout << "\t      |                                         |  "  << red[37] <<   "" << green[51] <<             "  |      |  "                 << red[25] <<   "" << green[39] << "  |                                         |" << endl;
    cout << "\t      |                                         |  " << yellow[9] << "" << blue[23] << "  |  " << yellow[64] << "   |  " << yellow[53] << "" << blue[11] << "  |                                         |" << endl;
    cout << "\t      |                                         |______|______|______|                                         |" << endl;

    cout << "\t      |                                         |  "  << red[36] <<   "" << green[50] <<             "  |      |  "                 << red[26] <<   "" << green[40] << "  |                                         |" << endl;
    cout << "\t      |                                         |  " << yellow[8] << "" << blue[22] << "  |  " << yellow[63] << "   |  " << yellow[54] << "" << blue[12] << "  |                                         |" << endl;
    cout << "\t      |          " << yellow[79] << "                    " << yellow[80] << "         |______|______|______|           " << blue[77] << "                " << blue[78] << "            |" << endl;

    cout << "\t      |                                         |  "  << red[35] <<   "" << green[49] <<             "  |      |  "                 << red[27] <<   "" << green[41] << "  |                                         |" << endl;
    cout << "\t      |                                         |  " << yellow[7] << "" << blue[21] << "  |  " << yellow[62] << "   |  " << yellow[55] << "" << blue[13] << "  |                                         |" << endl;
    cout << "\t      |                                         |______|______|______|                                         |" << endl;

    cout << "\t      |                                         |  "  << red[34] <<   "" << green[48] <<             "  |      |  "                 << red[28] <<   "" << green[42] << "  |                                         |" << endl;
    cout << "\t      |                                         |  " << yellow[6] << "" << blue[20] << "  |  " << yellow[61] << "   |  " << yellow[56] << "" << blue[14] << "  |                                         |" << endl;
    cout << "\t      |                                         |______|______|______|                                         |" << endl;

    cout << "\t      |          " << yellow[77] << "                    " << yellow[78] << "         |  "  << red[33] <<   "" << green[47] << "" << yellow[3] <<             " |      |  "                 << red[29] <<   "" << green[43] << "  |           " << blue[79] << "                " << blue[80] << "            |" << endl;
    cout << "\t      |                                         |  " << yellow[2] << "*" << blue[19] << " |  " << yellow[60] << "   |  " << yellow[57] << "" << blue[15] << "  |                                         |" << endl;
    cout << "\t      |                                         |__" << yellow[5] << "" << yellow[4] << "__|______|______|                                         |" << endl;
    
    cout << "\t      |                                         |  "  << red[32] <<   "" << green[46] << "  |  "  << red[31] <<   "" << green[45] << "  |  "  << red[30] <<   "" << green[44] << "  |                                         |" << endl;
    cout << "\t      |                                         |  "               << blue[18] <<                  "   |  " << yellow[59] << "" << blue[17] << "  |  " << yellow[58] << "" << blue[16] << "  |                                         |" << endl;
    cout << "\t      |______ ______ ______ ______ ______ ______|______|______|______|______ ______ ______ ______ ______ ______|" << endl;

    cout << endl;
}