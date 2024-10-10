#include <iostream>
#include <cmath>

using namespace std;

// Universal Variables
char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','8'}};
int row, column;
char token = 'x';
bool draw = false;
string name1 = " ";
string name2 = " ";

void function()
{
// Tic Tac Toe Structure
    cout<<"   |   |   "<<endl;
    cout<<" "<<space[0][0]<<" | "<<space[0][1]<<" | "<<space[0][2]<<endl;
    cout<<"___|___|___"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<space[1][0]<<" | "<<space[1][1]<<" | "<<space[1][2]<<endl;
    cout<<"___|___|___"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<space[2][0]<<" | "<<space[2][1]<<" | "<<space[2][2]<<endl;
    cout<<"   |   |   "<<endl;
}

void functiontwo(){
// Users Input
    int digit;
    if(token == 'x'){
        cout<<name1<<" please Enter:"<<endl;
        cin>>digit;
    } else {
        cout<<name2<<" please Enter:"<<endl;
        cin>>digit;
    }
    
// Accessing Users Input in Memory
    if(digit == 1){
        row = 0; column = 0;
    } else if(digit == 2){
        row = 0; column = 1;
    } else if(digit == 3){
        row = 0; column = 2;
    } else if(digit == 4){
        row = 1; column = 0;
    } else if(digit == 5){
        row = 1; column = 1;
    } else if(digit == 6){
        row = 1; column = 2;
    } else if(digit == 7){
        row = 2; column = 0;
    } else if(digit == 8){
        row = 2; column = 1;
    } else if(digit == 9){
        row = 2; column = 2;
    } else {
        cout<<"INVALID NUMBER"<<endl;
        return;
    }

// This is written to ensure that no one try to play at the same place again and again.
    if(token == 'x' && space[row][column] != 'x' && space[row][column] != '0'){
        space[row][column] = 'x';
        token = '0';
    } else if(token == '0' && space[row][column] != 'x' && space[row][column] != '0'){
        space[row][column] = '0';
        token = 'x';
    } else {
        cout<<"There are no EMPTY spaces"<<endl;
        functiontwo();
    }
    function();
}

bool functionthree(){

// Identify Winning Pattern
    for(int i = 0; i < 3; i++){
        if(space[i][0] == space[i][1] && space[i][0] == space[i][2] || 
           space[0][i] == space[1][i] && space[0][i] == space[2][i]){
            return true;
        }
    }

    if(space[0][0] == space[1][1] && space[0][0] == space[2][2] || 
       space[0][2] == space[1][1] && space[0][2] == space[2][0]){
        return true;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(space[i][j] != 'x' && space[i][j] != '0'){
                return false;
            }
        }
    }
    
    draw = true;
    return false;
}

int main(){
    cout<<"Enter name of Player one:"<<endl;
    getline(cin,name1);
    cout<<"Enter name of Player two:"<<endl;
    getline(cin,name2);
    
    cout<<name1<<" will play First"<<endl;
    cout<<name2<<" will play Second"<<endl;
    
    while(functionthree() == false){
        function();
        functiontwo();
    }
    
    if (!draw) {
        if (token == 'x') {
            cout<<name2<< " WINS!!"<<endl;
        } else {
            cout<<name1<< " WINS!!"<<endl;
        }
    } else {
        cout<< "It's a DRAW!!"<<endl;
    }
}
