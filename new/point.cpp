#include "point.hpp"
#include <cstdlib>
#include <iostream>
Point::Point (const Vector & position, const Vector & velocity) :
  position(position) {
    prevPosition = position - velocity;
}

void Point::update (double dt) {
    handleWallCollisions();
    handleFloorCollisions();
    Vector temp = position;

    position += (position - prevPosition)  + totalAcceleration * dt*dt ;
    prevPosition = temp;

}

void Point::addForce (const Vector & f) {

  totalAcceleration += f/mass;

}

void Point::resetAcceleration() {
  totalAcceleration = Vector(0, g);
}

void Point::handleWallCollisions(){
    double wall_k = 100;
    double y_direction;
    Vector normal_f;
    Vector friction_f;
    
    if (position.x > 1200){
        normal_f = Vector(-(position.x - 1200)*wall_k, 0);
        y_direction = ((position - prevPosition).y > 0) - ((position - prevPosition).y < 0);
        friction_f = Vector(0, - y_direction * -normal_f.x * mu );
        }
    
    else if (position.x < 0){
        normal_f = Vector((- position.x)*wall_k, 0);
        y_direction = ((position - prevPosition).y > 0) - ((position - prevPosition).y < 0);
        friction_f = Vector(0, - y_direction * normal_f.x * mu );
    }
    
    addForce(normal_f + friction_f);
        
    }

void Point::handleFloorCollisions(){
    double floor_k = 10000;
    double x_direction;
    Vector normal_f;
    Vector friction_f;
    if (position.y > 600){
        normal_f = Vector(0, -(position.y - 600)*floor_k);
        x_direction = ((position - prevPosition).x > 0) - ((position - prevPosition).x < 0);
        friction_f = Vector( - x_direction * -normal_f.y * mu,0 );
        
    }
    addForce(normal_f + friction_f);
    
}
    
    
    

  
