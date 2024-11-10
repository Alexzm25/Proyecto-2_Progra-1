#include "../header/MathUtils.h"

Vector2f MathUtils::interpolate(const Vector2f& p0, const Vector2f& p1, const Vector2f& m0, const Vector2f& m1, float t) {

    float t2 = t * t;
    float t3 = t2 * t;

    float h00 = 2 * t3 - 3 * t2 + 1;
    float h10 = t3 - 2 * t2 + t;
    float h01 = -2 * t3 + 3 * t2;
    float h11 = t3 - t2;

    return h00 * p0 + h10 * m0 + h01 * p1 + h11 * m1;

}

Vector2f MathUtils::calculateTangent(const Vector2f& prev, const Vector2f& next) {

    float tension = 0.5f;

    return tension * (next - prev);
}

