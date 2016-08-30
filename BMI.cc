#include <iostream>
#include <iomanip> //stream manipulator library
using namespace std;

int main(){
    double h, w;
    double bmi;
    string result;

    cout << "Enter your height(inches) and weight(lbs): ";
    cin >> h >> w;
    bmi = w*703/(h*h);

    if(bmi<=18.5){
        result = "Underweight";
    }
    else if(bmi>18.5 && bmi<=25){
        result = "Normal";
    }
    else if(bmi>25 && bmi<=30){
        result = "Overweight";
    }
    else if(bmi>30){
        result = "Obese";
    }
    /*setprecision decides the number of digits after the decimal point and fixed prevents scientific notation
    & forces trailing zeros to print to meet setprecisions conditions*/
    cout << "BMI = " << setprecision(3) << fixed << bmi << " " << result << endl;
}
