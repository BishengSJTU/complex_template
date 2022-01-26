#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iostream>
using namespace std;

template<typename T>
class Complex
{
public :
    Complex<T>(): re_(0), im_(0)
    {}
    Complex<T>(double re,double im): re_(re), im_(im)
    {}

    Complex<T>& operator += (const Complex<T>& c);

    template<typename Q>
    friend Complex<Q>& DoAssignPlus (Complex<Q>* pc, const Complex<Q>& c);

    template<typename Q>
    friend Complex<Q> operator + (const Complex<Q>& c1, const Complex<Q>& c2);

    T real() const {return re_;}
    T image() const {return im_;}

private:
    T re_;
    T im_;
};

template<typename T>
Complex<T>& Complex<T>:: operator+=(const Complex<T> &c) {

    return DoAssignPlus(this, c);
}

template<typename Q>
Complex<Q>& DoAssignPlus(Complex<Q>* pc, const Complex<Q>& c)
{
    pc->re_ += c.re_;
    pc->im_ += c.im_;
    return (*pc);
}

template<typename Q>
Complex<Q> operator + (const Complex<Q>& c1, const Complex<Q>& c2)
{
    return Complex<Q>(c1.re_ + c2.re_, c1.im_ + c2.im_);
}

template<typename Q>
ostream& operator << (ostream& os, const Complex<Q>& c)
{
    return(os << "(" << c.real() << "," << c.image() << ")") << std::endl;
}

#endif //COMPLEX_COMPLEX_H
