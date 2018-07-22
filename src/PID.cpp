#include "PID.h"
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

/*
* TODO: Complete the PID class.
*/

void PID::updateError(double cte)
{
	this->d_error = cte - this->p_error;
	this->p_error = cte;
	this->i_error += cte;
}

double PID::calcTotalError()
{
	double yaw = ( - this->Kp * this->p_error - this->Kd * this->d_error - this->Ki * this->i_error);
	applyLimits(yaw);
	return yaw;
}

void PID::applyLimits(double &val)
{
	if (val > 1.0) val = 1.0;
	else if (val < -1.0) val = -1.0;
}

