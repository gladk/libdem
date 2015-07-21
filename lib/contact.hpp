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
#include "node.hpp"

class contact {
  private:
    shared_ptr<node> _node_i;
    shared_ptr<node> _node_j;
    shared_ptr<material> _mat;
    
    real _kn = 0.;
    real _kt = 0.;
    real _cn = 0.;
    real _ct = 0.;
  public:
    contact(shared_ptr<node> node_i, shared_ptr<node>, node_j) : 
      _node_i(node_i), _node_j(node_j){};
    
    const real kn() const {return _kn;}
    const real kt() const {return _kt;}
    const real cn() const {return _cn;}
    const real ct() const {return _ct;}
};
