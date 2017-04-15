#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H


class Polynomial
{
    private:
    LinkedList linked;
	int power;

    public:
        Polynomial(double arr[], int size);
        Polynomial(std::vector<float> &v);
        ~Polynomial();
        int get_power();
        float calculate_for_x(float x) ;
        float diff(int x);
        void diff();
        Polynomial mult_by(Polynomial p1);
        void print();



};

#endif // POLYNOMIAL_H
