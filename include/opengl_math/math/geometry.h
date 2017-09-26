/* Copyright (C)
 *
 * Copyright 2013 Matthew Everett Hoggan
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writting, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef MATH_GEOMETRY_H_INCLUDED
#define MATH_GEOMETRY_H_INCLUDED

#include "opengl_math/math/vector.h"
#include "opengl_math/primitives/points/type_point_3d.h"
#include "opengl_math/primitives/vectors/type_vector_3d.h"
#include "opengl_math/shapes/line.h"
#include "opengl_math/shapes/sphere.h"
#include "opengl_math/shapes/triangle.h"

#include <cmath>
#include <iterator>
#include <limits>
#include <unordered_map>
#include <vector>

namespace opengl_math
{
  template<typename T>
  bool points_of_triangle_are_collinear(
    const triangle<T> &tri,
    float epsilon = std::numeric_limits<float>::epsilon());

  template<typename T, typename I>
  void tessellate_triangle_by_subdivision(
    const triangle<T> &tri,
    std::size_t subdivision_count,
    I &current_index,
    subdivided_tessellated_triangle_data<T, I> &out);

  template<typename T, typename I>
  void tessellate_triangles_by_subdivision(
    std::vector<triangle<T>> &tris,
    std::size_t subdivision_count,
    I &current_index,
    subdivided_tessellated_triangle_data<T, I> &out);

  template<typename T, typename I>
  void tessellate_triangle_by_midpoint_subdivision(
    const triangle<T> &tri,
    std::size_t subdivision_count,
    I &current_index,
    subdivided_tessellated_triangle_data<T, I> &out);

  template<typename T, typename I>
  void tessellate_triangles_by_midpoint_subdivision(
    std::vector<triangle<T>> &tris,
    std::size_t subdivision_count,
    I &current_index,
    subdivided_tessellated_triangle_data<T, I> &out);

  template<typename T>
  point_3d<T> centroid_of_triangle(const triangle<T> &tri);

  template<typename T>
  point_3d<T> midpoint_of_line(const line<T> &line);
}

namespace std
{
  template <typename T>
  struct hash<opengl_math::point_3d<T>>
  {
    std::size_t operator()(const opengl_math::point_3d<T> &k) const
    {
      return ((std::hash<T>()(k._x) ^ (std::hash<T>()(k._y) << 1)) >> 1) ^
        (hash<float>()(k._z) << 1);
    }
  };
}

#include "geometry.inl"
#endif
