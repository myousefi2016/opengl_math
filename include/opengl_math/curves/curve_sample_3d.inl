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
namespace opengl_math
{
  template<typename realT>
  curve_sample_3d<realT>::curve_sample_3d() :
    _position(),
    _tangent(),
    _parameter(realT(0))
  {}

  template<typename realT>
  curve_sample_3d<realT>::curve_sample_3d(const point_3d<realT> &position,
    const vector_3d<realT>& tangent, realT parameter) :
    _position(position),
    _tangent(tangent),
    _parameter(parameter)
  {}

  template<typename realT>
  void curve_sample_3d<realT>::normalize_tangent()
  {
    if (!float_equals(_tangent.magnitude(), realT(0),
      std::numeric_limits<float>::epsilon())) {
      _tangent.normalize();
    }
  }
}
