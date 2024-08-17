//tic tac toe, the games is in portuguese.
#include <iostream>
#include <algorithm>

using namespace std;

char playerChoice(); // Function that return the player Input Choice (O or X);
 
int checkWin(char * arrPt, size_t size); //check if there is some winner, and reurn an int

void flushArray(char * arr, size_t size); // restart the array to normal

int main() {
        
    char playerInput; //save the player input
    
    int tries = 9; //the maximum tries, if it equals to 0, cat's game

    char player; // it just defines who is the player

    bool value = true; //I added it just to save if the value entered by the player was valid

    bool gameMode=true; // it defines the game state (running, or not), would be more iteresting if it was used in a do while
    
    char array[] = " 1 | 2 | 3 \n"
                   " 4 | 5 | 6 \n"
                   " 7 | 8 | 9 \n"; // this char array contains the game "graphical" basis
    
    char*p; // a pointer used in the find() function from the algorithm library to found the correct character
    
    size_t size=sizeof array/1; // used to specify the size of the array, dividing it by one just to remind me that the size of char = 1 byte

    player=playerChoice();

    while(gameMode){

        if (!tries) {
            cout << "\nVelha!\n"  
                 << "deseja sair? (s/n): ";

            cin >> playerInput;

            flushArray(array, size);

            (playerInput == 's') ? gameMode = 0 : gameMode=1;
        }
        
        for (int  i=0; i<size; i++) {
            cout << array[i];
        }

        cout << player << " joga agora, escolha um numero: ";
        cin >> playerInput;

        if (playerInput == 'O' || playerInput == 'X' || playerInput == '|') 
            playerInput = '#';
        
        p=find(array, array+size, playerInput);

        if(p!=array+size) {
            *p=player;
            value = true;
        } else {
            cout << "insira um valor valido";
            value = false;
            tries++;
        }
                
        if (checkWin(array,size)) {            
            cout << "\n" << player << " Venceu!\n"
                 << "deseja sair? (s/n): ";
            cin >> playerInput;
            
            flushArray(array, size);
            
            tries = 9;
            
            (playerInput == 's') ? gameMode = 0 : gameMode=1;
        } else if (playerInput >= 49 && playerInput <=57 && value) { // Dec ASCII table
            (player=='X') ? player = 'O': player ='X';
        }
        
        cout << "\n";
    
        tries--;
    }
    return 0;
}

char playerChoice() {
    char playerInput;
    
    for(;;){ 

        cout << "Quem jogara primeiro?\n"
             << "Escolha 1 para O ou 2 para X: ";
        
        cin >> playerInput;

        if (playerInput == '1') {
            return 'O';
        } else if (playerInput == '2') {
            return 'X';
        } else {
            cout << "Insira um valor valido\n\n";
        }
    }
}

int checkWin (char *arrPt, size_t size) {
    
    char array[100];

    for (int i=0;i<size; i++) {
        array[i] = *arrPt++;
    }
    
    if ( array[1] == array[5] && array[5] == array[9]) {
        return 1;
    } else if (array [13] == array[17] && array[17] == array[21])  { 
        return 1;
    } else if (array [25] == array[29] && array[29] == array[33])  {
        return 1;
    } else if (array [1] == array[13] && array[13] == array[25])  {
        return 1;
    } else if (array [5] == array[17] && array[17] == array[29])  {
        return 1;
    } else if (array [9] == array[21] && array[21] == array[33])  {
        return 1;
    } else if (array [1] == array[17] && array[17] == array[33])  {
        return 1;
    } else if (array [9] == array[17] && array[17] == array[25])  {
        return 1;
    } else {
        return 0;
    }
}

void flushArray(char * arr, size_t size) {
    char fArray[]= " 1 | 2 | 3 \n"
                   " 4 | 5 | 6 \n"
                   " 7 | 8 | 9 \n";
    
    for (int i=0; i<size; i++) {
        *arr++ = fArray[i];
    }
}