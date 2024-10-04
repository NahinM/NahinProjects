#include <iostream>

using namespace std;

char arr[9]= {'1','2','3','4','5','6','7','8','9'};

int wincomb[8][3] = {
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,4,8},
    {2,4,6}
};

void printGrid(){
    cout << "   |   |   \n";
    printf(" %c | %c | %c \n",arr[0],arr[1],arr[2]);
    cout << "   |   |   \n";
    cout << "###|###|###\n";
    cout << "   |   |   \n";   
     printf(" %c | %c | %c \n",arr[3],arr[4],arr[5]);
    cout << "   |   |   \n";
    cout << "###|###|###\n";
    cout << "   |   |   \n";
    printf(" %c | %c | %c \n",arr[6],arr[7],arr[8]);
    cout << "   |   |   \n";

}

void resetGrid(){
    for(int i=0;i<9;i++) arr[i]=' ';
}

bool win(){
    for(int i=0;i<8;i++){
        if(arr[wincomb[i][0]]==arr[wincomb[i][1]] && arr[wincomb[i][1]]==arr[wincomb[i][2]] && arr[wincomb[i][0]]!=' '){
            cout << "Congratulations\n";
            return true;
        }
    }
    return false;
}

int main(){
    cout << "Enter your names\n";
    string player1,player2;
    cout << "player1 : ";
    cin >> player1;
    cout << "player2 : ";
    cin >> player2;
    cout << "Welcome to tic-tac-toe "<< player1 << " and "<< player2 <<". Here is your game grid\n";

    printGrid();
    cout << "\nEnter the values of the boxes to place your move\nFirst move goes to " << player1 << '\n';
    resetGrid();


    bool turn = true;
    int place;
    for(int m=0;m<9;m++){
        cout << (turn?player1:player2) << ": ";
        cin >> place;
        if(!(1<= place && place<=9)) {
            cout << "place is out of the grid.Try again.";
            m--;
            continue;
        }
        arr[place-1] = turn?'X':'O';
        printGrid();
        if(win()){
            cout << (turn?player1:player2) << " won\n";
            return 0;
        }
        turn = !turn;
    }
    cout << "Match draw!!\n"; 

    return 0;
}