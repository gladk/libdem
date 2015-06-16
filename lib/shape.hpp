/*
    This file is part of libdem
    libdem is the library, implementing discrete element method functionality.
    Copyright (C) 2015 TU Bergakademie Freiberg, Institute for Mechanics and Fluid Dynamics

    Author: 2015 Anton Gladky <gladky.anton@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libdem is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libdem.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include "base.hpp"

class shape {
  private:
    v3 _color=v3::Zero();
  public:
    shape() {};
    const v3 color() const {return _color;}
};

class sphere : public shape {
  private:
    real _rad;
  public:
    sphere(real rad) : _rad(rad) {}
    real const rad() const {return _rad;} 
};

