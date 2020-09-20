#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>

#include "SERVO.hpp"

#define P8_19 "P8.19"  // pwmchip7 pwm0 pin P8.19
#define P8_13 "P8.13"  // pwmchip7 pwm1 pin P8.13
#define dt 0.02  //seconds
using namespace std;


int main()
{
	int i{0};
	int j{0};
	float ti = clock();
	float tf{0.0};
	float t{0.0};

	Servo servo1(P8_19);
	servo1.setAngleRange(35, 0);
	servo1.setAngleinDeg(10.0);

	for(i=0; i < 3 ;i++){
		for(j=0;j<180;j++){
			servo1.setAngleinDeg(j);
			cout << "Setting Angle :" << j <<endl;
			while (t < dt*1000000){
				tf = clock();
				t = (tf-ti);
			}
			t=0.0;
			ti=clock();
		}
		j=0;
	}

    // Desativação dos Servos
    servo1.deactivate();

    return 0; 
}

void printData(){

	const int field1 {10};
	const int field2 {10};
	const int field3 {10};
	const int field4 {10};
	const int field5 {10};

	//cout<< setprecision(3)<<fixed;
	//cout<< setw(field1)<<left<< Falpha(2,0) <<setw(field2)<<left<< armaSV(cont_while2,0) <<setw(field3)<<left<< armaSV(cont_while2,1) << setw(field4)<<left<< armaSV(cont_while2,2) << endl;
	//cout<< setw(field1)<<left<< Falpha(0,0) <<setw(field2)<<left<< Falpha(1,0) <<setw(field3)<<left<< Falpha(2,0) << setw(field4)<<left<< Falpha(3,0) << endl;
}
