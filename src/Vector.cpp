// Copyright (c) 2019, Danilo Peixoto. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <aurora/Vector.h>
#include <aurora/Math.h>
#include <aurora/Matrix.h>

#include <cmath>

AURORA_NAMESPACE_BEGIN

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(const Vector2 & vector2) : x(vector2.x), y(vector2.y) {}
Vector2::Vector2(double x, double y) : x(x), y(y) {}
Vector2::~Vector2() {}

double & Vector2::operator [](size_t i) {
    return (&x)[i];
}
const double & Vector2::operator [](size_t i) const {
    return (&x)[i];
}
Vector2 Vector2::operator +() const {
    return *this;
}
Vector2 Vector2::operator -() const {
    return Vector2(-x, -y);
}
Vector2 Vector2::operator +(const Vector2 & rhs) const {
    return Vector2(*this) += rhs;
}
Vector2 Vector2::operator -(const Vector2 & rhs) const {
    return Vector2(*this) -= rhs;
}
Vector2 Vector2::operator *(const Matrix2 & rhs) const {
    return Vector2(*this) *= rhs;
}
Vector2 operator *(const Matrix2 & lhs, const Vector2 & rhs) {
    return Vector2(
        rhs.x * lhs[0][0] + rhs.y * lhs[0][1],
        rhs.x * lhs[1][0] + rhs.y * lhs[1][1]);
}
Vector2 Vector2::operator *(const Matrix3 & rhs) const {
    return Vector2(*this) *= rhs;
}
Vector2 operator *(const Matrix3 & lhs, const Vector2 & rhs) {
    return Vector2(
        rhs.x * lhs[0][0] + rhs.y * lhs[0][1] + lhs[0][2],
        rhs.x * lhs[1][0] + rhs.y * lhs[1][1] + lhs[1][2]);
}
Vector2 Vector2::operator *(double rhs) const {
    return Vector2(*this) *= rhs;
}
Vector2 operator *(double lhs, const Vector2 & rhs) {
    return rhs * lhs;
}
Vector2 Vector2::operator /(double rhs) const {
    return Vector2(*this) /= rhs;
}
Vector2 operator /(double lhs, const Vector2 & rhs) {
    return Vector2(1.0 / rhs.x, 1.0 / rhs.y);
}
Vector2 & Vector2::operator +=(const Vector2 & rhs) {
    x += rhs.x;
    y += rhs.y;

    return *this;
}
Vector2 & Vector2::operator -=(const Vector2 & rhs) {
    x -= rhs.x;
    y -= rhs.y;

    return *this;
}
Vector2 & Vector2::operator *=(const Matrix2 & rhs) {
    double t = x;

    x = x * rhs[0][0] + y * rhs[1][0];
    y = t * rhs[0][1] + y * rhs[1][1];

    return *this;
}
Vector2 & Vector2::operator *=(const Matrix3 & rhs) {
    double t = x;

    x = x * rhs[0][0] + y * rhs[1][0] + rhs[2][0];
    y = t * rhs[0][1] + y * rhs[1][1] + rhs[2][1];

    return *this;
}
Vector2 & Vector2::operator *=(double rhs) {
    x *= rhs;
    y *= rhs;

    return *this;
}
Vector2 & Vector2::operator /=(double rhs) {
    x /= rhs;
    y /= rhs;

    return *this;
}
bool Vector2::operator ==(const Vector2 & rhs) const {
    return x == rhs.x && y == rhs.y;
}
bool Vector2::operator !=(const Vector2 & rhs) const {
    return !(*this == rhs);
}
std::ostream & operator <<(std::ostream & lhs, const Vector2 & rhs) {
    return lhs << '[' << rhs.x << ' ' << rhs.y << ']';
}

double Vector2::dot(const Vector2 & rhs) const {
    return x * rhs.x + y * rhs.y;
}
double Vector2::cross(const Vector2 & rhs) const {
    return x * rhs.y - y * rhs.x;
}
Vector2 & Vector2::normalize() {
    double l2 = length2();

    if (l2 > AURORA_EPSILON)
        *this /= std::sqrt(l2);

    return *this;
}
double Vector2::length2() const {
    return dot(*this);
}
double Vector2::length() const {
    return std::sqrt(length2());
}
Vector2 Vector2::min(const Vector2 & rhs) const {
    return Vector2(std::fmin(x, rhs.x), std::fmin(y, rhs.y));
}
Vector2 Vector2::max(const Vector2 & rhs) const {
    return Vector2(std::fmax(x, rhs.x), std::fmax(y, rhs.y));
}

Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(const Vector3 & vector3) : x(vector3.x), y(vector3.y), z(vector3.z) {}
Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
Vector3::~Vector3() {}

double & Vector3::operator [](size_t i) {
    return (&x)[i];
}
const double & Vector3::operator [](size_t i) const {
    return (&x)[i];
}
Vector3 Vector3::operator +() const {
    return *this;
}
Vector3 Vector3::operator -() const {
    return Vector3(-x, -y, -z);
}
Vector3 Vector3::operator +(const Vector3 & rhs) const {
    return Vector3(*this) += rhs;
}
Vector3 Vector3::operator -(const Vector3 & rhs) const {
    return Vector3(*this) -= rhs;
}
Vector3 Vector3::operator *(const Matrix3 & rhs) const {
    return Vector3(*this) *= rhs;
}
Vector3 operator *(const Matrix3 & lhs, const Vector3 & rhs) {
    return Vector3(
        rhs.x * lhs[0][0] + rhs.y * lhs[0][1] + rhs.z * lhs[0][2],
        rhs.x * lhs[1][0] + rhs.y * lhs[1][1] + rhs.z * lhs[1][2],
        rhs.x * lhs[2][0] + rhs.y * lhs[2][1] + rhs.z * lhs[2][2]);
}
Vector3 Vector3::operator *(const Matrix4 & rhs) const {
    return Vector3(*this) *= rhs;
}
Vector3 operator *(const Matrix4 & lhs, const Vector3 & rhs) {
    return Vector3(
        rhs.x * lhs[0][0] + rhs.y * lhs[0][1] + rhs.z * lhs[0][2] + lhs[0][3],
        rhs.x * lhs[1][0] + rhs.y * lhs[1][1] + rhs.z * lhs[1][2] + lhs[1][3],
        rhs.x * lhs[2][0] + rhs.y * lhs[2][1] + rhs.z * lhs[2][2] + lhs[2][3]);
}
Vector3 Vector3::operator *(double rhs) const {
    return Vector3(*this) *= rhs;
}
Vector3 operator *(double lhs, const Vector3 & rhs) {
    return rhs * lhs;
}
Vector3 Vector3::operator /(double rhs) const {
    return Vector3(*this) /= rhs;
}
Vector3 operator /(double lhs, const Vector3 & rhs) {
    return Vector3(1.0 / rhs.x, 1.0 / rhs.y, 1.0 / rhs.z);
}
Vector3 & Vector3::operator +=(const Vector3 & rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;

    return *this;
}
Vector3 & Vector3::operator -=(const Vector3 & rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;

    return *this;
}
Vector3 & Vector3::operator *=(const Matrix3 & rhs) {
    Vector3 t(*this);

    x = t.x * rhs[0][0] + t.y * rhs[1][0] + t.z * rhs[2][0];
    y = t.x * rhs[0][1] + t.y * rhs[1][1] + t.z * rhs[2][1];
    z = t.x * rhs[0][2] + t.y * rhs[1][2] + t.z * rhs[2][2];

    return *this;
}
Vector3 & Vector3::operator *=(const Matrix4 & rhs) {
    Vector3 t(*this);

    x = t.x * rhs[0][0] + t.y * rhs[1][0] + t.z * rhs[2][0] + rhs[3][0];
    y = t.x * rhs[0][1] + t.y * rhs[1][1] + t.z * rhs[2][1] + rhs[3][1];
    z = t.x * rhs[0][2] + t.y * rhs[1][2] + t.z * rhs[2][2] + rhs[3][2];

    return *this;
}
Vector3 & Vector3::operator *=(double rhs) {
    x *= rhs;
    y *= rhs;
    z *= rhs;

    return *this;
}
Vector3 & Vector3::operator /=(double rhs) {
    x /= rhs;
    y /= rhs;
    z /= rhs;

    return *this;
}
bool Vector3::operator ==(const Vector3 & rhs) const {
    return x == rhs.x && y == rhs.y && z == rhs.z;
}
bool Vector3::operator !=(const Vector3 & rhs) const {
    return !(*this == rhs);
}
std::ostream & operator <<(std::ostream & lhs, const Vector3 & rhs) {
    return lhs << '[' << rhs.x << ' ' << rhs.y << ' ' << rhs.z << ']';
}

double Vector3::dot(const Vector3 & rhs) const {
    return x * rhs.x + y * rhs.y + z * rhs.z;
}
double Vector3::triple(const Vector3 & a, const Vector3 & b) const {
    return dot(a.cross(b));
}
Vector3 Vector3::cross(const Vector3 & rhs) const {
    return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
}
Vector3 & Vector3::normalize() {
    double l2 = length2();

    if (l2 > AURORA_EPSILON)
        *this /= std::sqrt(l2);

    return *this;
}
double Vector3::length2() const {
    return dot(*this);
}
double Vector3::length() const {
    return std::sqrt(length2());
}
Vector3 Vector3::min(const Vector3 & rhs) const {
    return Vector3(
        std::fmin(x, rhs.x), std::fmin(y, rhs.y), std::fmin(z, rhs.z));
}
Vector3 Vector3::max(const Vector3 & rhs) const {
    return Vector3(
        std::fmax(x, rhs.x), std::fmax(y, rhs.y), std::fmax(z, rhs.z));
}

AURORA_NAMESPACE_END
