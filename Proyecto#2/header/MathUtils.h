#pragma once
#include <SFML/System/Vector2.hpp>

using namespace sf;

namespace MathUtils {
   Vector2f interpolate(const Vector2f& p0, const Vector2f& p1,
        const Vector2f& m0, const Vector2f& m1, float t);
   Vector2f calculateTangent(const Vector2f& prev, const Vector2f& next);
}