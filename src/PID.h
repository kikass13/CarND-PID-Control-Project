#ifndef PID_H
#define PID_H

#include <vector>

class PID 
{

public:
	PID(){}
	PID(double Kp, double Ki, double Kd)
	{
		this->Kp = Kp;
	    this->Ki = Ki;
		this->Kd = Kd;
	}
	virtual ~PID(){}

public: 
	// update the PID error variables given cross track error.
	void updateError(double cte);

	// calculate the total PID error.
	double calcTotalError();

	void setLimits(double lower, double upper){this->llimit = lower; this->ulimit = upper;}
	void applyLimits(double &val);

private:
	//errors
	double p_error;
	double i_error;
	double d_error;

	// coefficients
	double Kp;
	double Ki;
	double Kd;

	//limits
	double llimit = -1.0;
	double ulimit = 1.0;

};

#endif /* PID_H */
