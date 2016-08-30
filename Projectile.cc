//depicts a projectile by displaying its position by updating its velocity every certain time interval

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void updatePosition(double[], double[]);
void updateVelocity(double[], double[]);
double timeInterval = 0.01;
double rad = 3.1415/180;

int main(){
    double muzzleVelocity = 50;
    double position[2] = {0,0};
    double acceleration[2] = {0, -9.81};
    double time = 0;
    double angle;

    cout << "Enter elevation angle for the projection: ";
    cin >> angle;

    double initialXvel = muzzleVelocity*cos(angle*rad);
    double initialYvel = muzzleVelocity*sin(angle*rad);
    double velocity[2] = {initialXvel, initialYvel};

    do{
        time += timeInterval;
        updatePosition(position, velocity);
        updateVelocity(velocity, acceleration);

        cout << "Time = " << setprecision(2) << time << " Horizontal Range = " << setprecision(3) << fixed << position[0] << " Height = " << setprecision(3) << fixed << position[1] << endl;
    }while(position[1]>0);
}

void updatePosition(double position[], double velocity[]){
    for(int i=0; i<2; i++){
        position[i] += velocity[i]*timeInterval;
    }
}

void updateVelocity(double velocity[], double acceleration[]){
    for(int i=0; i<2; i++){
        velocity[i] += timeInterval*acceleration[i];
    }
}
