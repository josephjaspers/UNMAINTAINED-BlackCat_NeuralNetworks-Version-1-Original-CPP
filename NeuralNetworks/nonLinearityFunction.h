#pragma once
#ifndef nonLinearityFunct_h
#define nonLinearityFunct_h

#include "Matrices.h"
class nonLinearityFunct {
	static constexpr double e = 2.71828;

	//These are the crush functions 
	static Vector& sigmoid(Vector& x) {
		for (int i = 0; i < x.length(); ++i) {
			x[i] = 1 / (1 + pow(2.7182, -x[i]));
		}
		return x;
	}
	static Vector sigmoid_deriv(Vector x) {
		for (int i = 0; i < x.length(); ++i) {
			x[i] *= (1 - x[i]);
		}
		return x;
	}
	static Vector& tanh(Vector& x) {
		for (int i = 0; i < x.length(); ++i) {
			x[i] = std::tanh(x[i]);
		}
		return x;
	}
	static Vector tanh_deriv(Vector x) {
		for (int i = 0; i < x.length(); ++i) {
			x[i] = (1 - pow(x[i], 2));
		}
		return x;
	}

	int nonLinearity = 0;

public:

	//operator for sigmoidfunction
	Vector& operator() (Vector& x) {
		switch (nonLinearity) {
		case 0: return sigmoid(x);
		case 1: return tanh(x);
		default: std::cout << " nonlineariy function not enabled -- returning without effect " << std::endl;
		}
	}
	//deriv and d are same methods 
	Vector deriv(const Vector& x) {
		switch (nonLinearity) {
		case 0: return sigmoid_deriv(x);
		case 1: return tanh_deriv(x);
		default: std::cout << " non linerity deriv error: set to invalid integer, returning " << std::endl;
		}
	}
	Vector d(const Vector& x) {
		switch (nonLinearity) {
		case 0: return sigmoid_deriv(x);
		case 1: return tanh_deriv(x);
		default: std::cout << " non linerity deriv error: set to invalid integer, returning " << std::endl;
		}
	}
	//non Lin differs as it returns a cpy of the parameter opposed to effecting it directly 
	Vector nonLin(Vector x) {
		switch (nonLinearity) {
		case 0: return sigmoid(x);
		case 1: return tanh(x);
		}
	}

	void setSigmoid() {
		nonLinearity = 0;
	}
	void setTanh() {
		nonLinearity = 1;
	}

};

#endif