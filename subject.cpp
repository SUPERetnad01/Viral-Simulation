// Corona Simulation - basic simulation of a human transmissable virus
// Copyright (C) 2020  wbrinksma

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "subject.h"
#include <iostream>
#include <math.h>

namespace corsim
{

double Subject::x()
{
    return this->Strategy->x();
}

double Subject::y()
{
    return this->Strategy->y();
}

void Subject::set_x(double x)
{
    this->Strategy->set_x(x);
}

void Subject::set_y(double y)
{
    this->Strategy->set_y(y);
}

double Subject::dx()
{
    return this->Strategy->dx();
}

double Subject::dy()
{
    return this->Strategy->dy();
}

void Subject::set_dx(double dx)
{
    this->Strategy->set_dx(dx);
}

void Subject::set_dy(double dy)
{
    this->Strategy->set_dy(dy);
}

int Subject::radius()
{
    return this->_radius;
}

bool Subject::infected()
{
    return this->_infected;
}

void Subject::infect()
{
    this->_infected = true;
}

double Subject::angle()
{
    return atan2(dy(),dx());
}

double Subject::speed()
{
    return sqrt(dx() * dx() + dy() * dy());
}
void Subject::tick(){
    if(mod > 1){
        if(_tick == 0){
            this->Strategy = new ExitMovementStrategy(x(),y(),mod,dx(),dy());
            mod--;
            _tick = 100;
        }else{
            _tick--;
        }
    }else{
        auto p = this->dx();
        auto l = this->dy();
        this->Strategy = new RegularMovementStrategy(x(),y(),dx(),dy());
        this->set_dx(p);
        this->set_dy(l);
    }


}

}