#pragma once

#include <iostream>
#include <cmath>

class Complex {

private:

    double _re;
    double _im;

public:

    Complex (const double& re= 0.0,
             const double& im= 0.0)
        : _re(re), _im(im) {
    }

	double re() const {
		return _re;
	}

	double im() const {
		return _im;
	}
	

    Complex operator+(const Complex& other) const;

    Complex& operator+=(const Complex& other) {
        _re+= other._re;
        _im+= other._im;
        return *this; 
    }

       friend bool operator<(const Complex& c1, const Complex& c2) {
        double a = c1._re*c1._re + c1._im*c1._im;
        double b = c2._re*c2._re + c2._im*c2._im;
        a = std::sqrt(a);
        b = std::sqrt(b);
        return a<b;
    }


        friend bool operator>(const Complex& c1, const Complex& c2) {
       
        return c2 < c1;
    }

      friend bool operator==(const Complex& c1, const Complex& c2) {
       
        return (!(c1 < c2) && !(c1 > c2));
    }

    friend bool operator!=(const Complex& c1, const Complex& c2) {
       
        return !(c1 == c2);
    }

       friend bool operator>=(const Complex& c1, const Complex& c2) {
       
        return ((c1 > c2) || (c1 == c2));
       }

        friend bool operator<=(const Complex& c1, const Complex& c2) {
       
        return ((c1 < c2) || (c1 == c2));
       }

    Complex& operator-=(const Complex& other) {
        _re-= other._re;
        _im-= other._im;
        return *this;
    }

    // prefix increment:
    Complex& operator++() {
        _re++;
        return *this;
    }

    // postfix increment:
    Complex operator++(int dummy_flag_for_postfix_increment) {
        Complex copy = *this;
        _re++;
        return copy;
    }
    

   friend std::ostream& operator<<(std::ostream& output, const Complex& c) {
    return (output << c._re << '+' << c._im << 'i');
    }   
    
}; 