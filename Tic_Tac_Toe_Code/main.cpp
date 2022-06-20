#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

char board[3][3] = { {'1' ,'2' ,'3'} , {'4' ,'5' ,'6'} , {'7' ,'8' ,'9'} };
char current_marker;
int current_player;
// here we creating drawboard of 3x3 matrix
void drawBoard()

{
    //Row 1
    cout << " "<< board[0][0] <<  " | " << board[0][1] <<  " | " << board[0][2] << endl;
    cout << "----------\n";

    //Row 2
    cout << " "<< board[1][0] <<  " | " << board[1][1] <<  " | " << board[1][2] << endl;
    cout << "----------\n";

    //Row 3
    cout << " "<< board[2][0] <<  " | " << board[2][1] <<  " | " << board[2][2] << endl;

}

bool placeMarker(int slot)
{

    int row= slot / 3;
    int col;
    if( slot % 3 == 0)
    {
       row = row - 1;
       col = 2;
    }
    else
      col= (slot % 3) - 1 ;

    if(board[row][col]!= 'X' && board[row][col] != 'O')
    {
         board[row][col] = current_marker;
         return true;
    }
    else
        return false;
}
int  winner()
{
    for(int i=0; i < 3; i++)
    {

        //row
        if(board[i][0]== board[i][1] && board[i][1]== board[i][2])
           return current_player;
        //columns
         if(board[0][i]== board[1][i] && board[1][i]== board[2][i])
           return current_player;

    }
    if(board[0][0]== board[1][1] && board[1][1]== board[2][2])
       return current_player;

    if(board[0][2]== board[1][1] && board[1][1]== board[2][0])
       return current_player;

    return 0;

}
// In this swap function we are checking if player 1 have marker X then player 2 automatically have O and same as here if player get number 1 then other will
// get number 2
void swap_player_and_marker()
{
    if(current_marker == 'X')
        current_marker= 'O';
    else
        current_marker='X';

    if(current_player == 1){
        current_player = 2;
    }
    else{
        current_player=1;
    }


}


void game()
{
    cout<< "Player one , choose your marker : ";
    char  marker_p1;
    cin >> marker_p1;
   // here we initializing player 1 and then player chooses marker X or O
      current_player = 1;
    current_marker = marker_p1;

    drawBoard();

    int player_won;

    for(int i =0; i< 9; i++)
    {
        cout << "its Player " << current_player << "'s turn. Enter  your slot : ";
         int slot;
         cin>> slot;

         if(slot < 1 || slot > 9)
         {
             cout<< "That slot is invalid! Try another slot!";
             i--;
             continue;
         }

         if(!placeMarker(slot))
         {
             cout<< "That slot occupied! Try another slot!";
             i--;
             continue;
         }

         drawBoard();

         player_won = winner();

         if(player_won == 1){
            cout<< "Player one won! Congratulation!!";
            break;
         }

         if(player_won == 2){
            cout<< "Player Two won! Congratulation!!";
            break;
         }

         swap_player_and_marker();


    }
    if(player_won == 0)
    {
        cout<< " That is a tie Game! ";
    }
}

int main()
{
    game();
    //srand(time(NULL));
   // cout<< (rand() % (10 - 1 + 1)) + 1;

    // to generate random numbers between range we use below mentioned formulae
   // [u , l) = (rand() % (10 - 1 + 1)) + 1;
}
