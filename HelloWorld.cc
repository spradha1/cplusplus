#include <iostream> //allows program to output
using namespace std;

int main(){
    string reply;
    int num1, num2;
    cout << "Hello World! Reply to that!" << endl; //display
    cin >> reply; //takes in input
    cout << "Thanks for the reply! Now give me two numbers!" << endl;
    cin >> num1 >> num2;
    if (num1==num2){
        cout << num1 << " is equal to " << num2 << endl;
    }
    else{
        cout << num1 << " is not equal to " << num2 << endl;
    }
    cout << "Their sum = " << num1+num2 << endl;

    return 0; //program ended successfully
}
