//class example
#include <iostream>
#include <math.h>

using namespace std;

//class definition
class Calc{
    private:
        string name;

    public://you can define functions right here or just leave a prototype like the setName
        Calc();//public constructor
        int add(int x, int y){
            return x+y;
        }

        double sineOf(double degree){
            return sin(degree*3.1415/180.0);
        }

        void setName(string);

        void showName(){
            cout << name << endl;
        }
};

Calc::Calc(){
    name = "Sanjiv invented the Calculator!";
}
//the prototyped function can be defined here
void Calc::setName(string n){
    name = n; //don't use variable name as parametee, it mistakes for the class variable
}

int main(){
    Calc calc;           //Calc object
    Calc *calcP = &calc; //pointer to calc
    Calc &callie = calc; //ref to calc

    calc.showName();//default constructor sets name already

    calc.setName("I rule this world!");
    calc.showName();

    callie.setName("Callie!");
    calc.showName();
    //using arrow operator to use function from pointers
    cout << "Add function using 5 & 4 gives " << calcP->add(5,4) << " & " << "sine function for 46 degrees gives " << calcP->sineOf(46.0) << endl;
}
