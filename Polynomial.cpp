#include<iostream>
#include "Polynomial.h"
#include"LinkedList.h"
#include<cmath>
using namespace std;

Polynomial::Polynomial(double arr[], int size){
 		linked = LinkedList(arr, size);
		power = size - 1;
}
Polynomial::Polynomial(std::vector<float> &v) {

		linked = LinkedList(v);
		power = v.size()-1;
	}

Polynomial::~Polynomial()
{

}
int Polynomial::get_power() {
		return power;
	}
float Polynomial::calculate_for_x(float x) {
		float result = 0;
		int pw = power;
		for (int i = 0; i <= power; ++i) {

			float num = linked.get(i);
			result += (num*pow(x, pw));
			pw--;
		}
		return result;
	}

float Polynomial::diff(int x) {
		int pw = power;
		float result = 0;
		float coof;
		for (int i = 0; i<power; ++i) {
			coof = linked.get(i)*pw;
			result += coof*pow(x, --pw);

		}

		return result;

	}

void Polynomial::diff() {

		int pw = power;

		for (int i = 0; i<power - 1; ++i) {
			float coof = linked.get(i)*pw;
			cout << coof << " X^" << --pw << " + ";

		}
		float coof = linked.get(power - 1)*pw;
		cout << coof;
		cout << "\n";
	}

Polynomial Polynomial::mult_by(Polynomial p1) {
		int power1 = this->get_power();
		int power2 = p1.get_power();
		double* arr = new double[power1 + power2 + 1];
		for (int i = 0; i <= power1 + power2; ++i) {
			arr[i] = 0;
		}

		for (int i = 0; i <= power1; ++i) {
			float coof1 = this->linked.get(i);
			for (int j = 0; j <= power2; ++j) {
				float coof2 = p1.linked.get(j);
				arr[i + j] += (coof1*coof2);
			}
		}

		return Polynomial(arr, power1 + power2 + 1);
	}

void Polynomial::print() {
		int pw = power;
		float coof;
		for (int i = 0; i<power; ++i) {
			coof = linked.get(i);
			cout << coof << " X^" << pw << " + ";
			pw--;
		}
		coof = linked.get(power);
		cout << coof << "\n";
	}

