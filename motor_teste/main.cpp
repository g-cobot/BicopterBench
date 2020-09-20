#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>

#include "MOTOR.hpp"

#define P9_42 "P9.42"  // pwmchip7 pwm0 pin P8.19
#define P9_22 "P9.22"  // pwmchip7 pwm1 pin P8.13

#define dt 0.02  //seconds
using namespace std;

int input{1};

int main()
{
	int i{0};
	int j{0};
	float ti = clock();
	float tf{0.0};
	float t{0.0};

	cout << "Enter with 0 to turn on motor: " << endl;

	while(input!=0){
		cin>>input;
	}

	Motor motor1(P9_42);

	cout << "Enter with 1 to accelerate motor: " << endl;

	while(input!=1){
		cin>>input;
	}

	motor1.setForceinNewton(1.5);

	cout << "Enter with 0 to deaccelerate motor: " << endl;

	while(input!=0){
		cin>>input;
	}

	motor1.setForceinNewton(1.4);

	cout << "Enter with 0 to end test: " << endl;

	while(input!=0){
		cin>>input;
	}


    // Desativação do Motor
    motor1.deactivate();

    return 0; 
}
