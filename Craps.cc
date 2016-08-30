//This program is intended to calculate win percentages of sets of cycles of the craps game

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int roll(); //function prototype: no parameters and int return type
bool craps();

int main(){
    srand(time(0));//makes distinctive possibilities from rand()
    int t = 10;
    while(t<=10000000){

        double wins = 0;
        for(int i=0; i<t; i++){
            bool result = craps();
            if(result){
                ++wins;
            }
        }
        wins = (wins/t)*100;
        cout << "Win percentage for " << setprecision(3) << fixed << t << " cycles is: " << wins << endl;
        t*=10;
    }
}

bool craps(){
    enum Status{AGAIN, WIN, LOSS}; //all caps constants for values that new type Status can hold
    int point;
    Status game;

    int sum = roll();

    switch (sum){
        case 7:
        case 11:
            game = WIN;
            break;
        case 2:
        case 3:
        case 12:
            game = LOSS;
            break;
        default:
            game = AGAIN;
            point = sum;
            break;
    }

    while(game == AGAIN){
        sum = roll();
        if(sum == point){
            game = WIN;
        }
        else{
            if(sum == 7){
                game = LOSS;
            }
        }
    }

    if(game == WIN){
        return true;
    }
    else{
        return false;
    }
}

int roll(){
    int d1 = 1 + rand()%6;
    int d2 = 1 + rand()%6;
    int sum = d1 + d2;
    return sum;
}


