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

#include "body.hpp"

sphere::sphere (real rad, v3 pos, shared_ptr<material> mat) {
  _nodes.push_back(make_shared<node>(shape(rad), state(pos), mat));
}

const real sphere::rad() const {
  return _nodes[0]->_shape.rad();
}

