#ifndef __SPRING_HPP__
#define __SPRING_HPP__

class Point;

class Spring {
  private:
    Point * start, * end;
    double natLen, k, lambda, prevLen;
  public:
    Spring (Point & start, Point & end, double k, double lambda);
    void applyForce ();
};

#endif /* end of include guard: __SPRING_HPP__ */
