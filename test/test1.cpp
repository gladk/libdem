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

TEST(BasicParticleCreation, Trivial) {
  const auto mat1 = make_shared<material>(1000, 0.5);
  EXPECT_EQ(1000, mat1->rho());
  EXPECT_EQ(0.5, mat1->frict());
  
  auto p1 = make_shared<sphere>(sphere(0.005, v3(0,  0,0),mat1));
  EXPECT_EQ(0.005, p1->rad());
  EXPECT_EQ(true, p1->active());
  p1->disable();
  EXPECT_EQ(false, p1->active());
  p1->enable();
  EXPECT_EQ(true, p1->active());
  
  auto p2 = make_shared<sphere>(sphere(0.007, v3(0.1,0,0),mat1));
  EXPECT_EQ(0.007, p2->rad());
  EXPECT_EQ(1, p1->nodes());
  
  auto sceneCur = scene();
  const auto p1_id = sceneCur.addBody(p1);
  EXPECT_EQ(1, p1_id);
  const auto p2_id = sceneCur.addBody(p2);
  EXPECT_EQ(2, p2_id);
  EXPECT_EQ(2, sceneCur.len());
  
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

