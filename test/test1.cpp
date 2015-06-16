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

#include "dem.hpp"
#include "gtest/gtest.h"

int Factorial(int n);

TEST(FactorialTest, Negative) {
  EXPECT_EQ(1, Factorial(-5));
}

int Factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}
  
int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  
  auto m = make_shared<material>();
  particle a = particle(0.05, v3(0,1,0),m);
  
  return RUN_ALL_TESTS();
}

