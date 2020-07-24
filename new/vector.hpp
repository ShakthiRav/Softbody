#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

class Vector {
public:
    double x, y;

    Vector ();
    Vector (double x, double y);

    Vector operator+ () const;
    Vector operator- () const;
    Vector operator+ (const Vector & rhs) const;
    Vector operator- (const Vector & rhs) const;
    Vector operator* (double a) const;
    Vector operator/ (double a) const;
    Vector& operator+= (const Vector &);
    Vector& operator-= (const Vector &);
    Vector& operator*= (double a);
    Vector& operator/= (double a);

    double dot (const Vector & rhs) const;
    double norm () const;
};

Vector operator* (double a, const Vector & v);

#endif /* end of include guard: __VECTOR_HPP__ */
