//
// Created by Dante Klijn on 05/05/2020.
//

#include "MovmentStrategy.h"

void RegularMovementStrategy::set_x(double x){this->_x = x;};
void RegularMovementStrategy::set_y(double y){this->_y = y;};
void RegularMovementStrategy::set_dx(double x){this->_dx = x;};
void RegularMovementStrategy::set_dy(double y){this->_dy = y;};

void LockDownMovementStrategy::set_x(double x){};
void LockDownMovementStrategy::set_y(double y){};
void LockDownMovementStrategy::set_dx(double x){};
void LockDownMovementStrategy::set_dy(double y){};

void ExitMovementStrategy::set_x(double x){this->_x = x;};
void ExitMovementStrategy::set_y(double y){this->_y = y;};
void ExitMovementStrategy::set_dx(double x){this->_dx = x / _modifier;};
void ExitMovementStrategy::set_dy(double y){this->_dy = y / _modifier;};