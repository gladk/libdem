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

body::body () {}

const std::size_t body::nodes() const {
  return _nodes.size();
}

const real body::rad() const {
  return _rad;
}

const bool body::active() const {
  return _active;
}

void body::enable() {
  _active=true;
}

void body::disable() {
  _active=false;
}

const std::size_t body::id() const {
  return _id;
}

void body::id(std::size_t id) {
  _id = id;
}

sphere::sphere (real rad, v3 pos, shared_ptr<material> mat) {
  _nodes.push_back(make_shared<node>(state(pos), mat));
  _rad = rad;
}
