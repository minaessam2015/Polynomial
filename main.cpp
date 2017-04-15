#include <iostream>
#include<vector>
#include<cmath>
#include"LinkedList.h"
#define nullptr NULL
using namespace std;

int main()
{

	double arr1[3] = { 1,2,1 };
	double arr2[3] = { 3,5,0 };
	Polynomial p1 = Polynomial(arr1, 3);
	Polynomial p2 = Polynomial(arr2, 3);
	cout << "\n Testing the substitution operation \n";
	cout << "-------------------------------------------------\n";
	cout << "  P1(x) =  ";
	p1.print();
	cout << "  P1 At x=1" << "\n \n";
	cout << "    " << p1.calculate_for_x(1) << "\n \n";
	cout << "  P2(x) = ";
	p2.print();
	cout << "  P2 At x=2 " << "\n \n";
	cout << "    " << p2.calculate_for_x(2.0) << "\n \n";

	cout << "\n Testing the diffrentiation \n ";
	cout << "------------------------------------------------\n";
	cout << "   d P1(x)/dx =  " ;

	p1.diff();
	cout << "   At x= 1 \n";
	cout << "      " << p1.diff(1) << endl;
	cout << "\n   d P2(x)/dx =  ";

	p2.diff();
	cout << "   At x=1 -> " << endl;
	cout << "     ";
	cout << p2.diff(1) << "\n";

	cout << "\n Testing the multiplication \n";
	cout << "------------------------------------------------\n";
	Polynomial p3 = p1.mult_by(p2);
	cout << "   The result of  P1(x)*P2(x) is  P3(x)= \n " << endl;
	cout << "     ";
	p3.print();
	cout << " \n   The diff of P3(x) \n \n";
	cout << "     ";
	p3.diff();
	return 0;
}
