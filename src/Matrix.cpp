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

#include <aurora/Matrix.h>
#include <aurora/Vector.h>

#include <cmath>

AURORA_NAMESPACE_BEGIN

Matrix2::Matrix2() {
    m[0][0] = 0; m[0][1] = 0;
    m[1][0] = 0; m[1][1] = 0;
}
Matrix2::Matrix2(const Matrix2 & matrix2) {
    m[0][0] = matrix2[0][0]; m[0][1] = matrix2[0][1];
    m[1][0] = matrix2[1][0]; m[1][1] = matrix2[1][1];
}
Matrix2::Matrix2(
    double m00, double m01,
    double m10, double m11) {
    m[0][0] = m00; m[0][1] = m01;
    m[1][0] = m10; m[1][1] = m11;
}
Matrix2::~Matrix2() {}

double * Matrix2::operator [](size_t i) {
    return m[i];
}
const double * Matrix2::operator [](size_t i) const {
    return m[i];
}
Matrix2 Matrix2::operator +() const {
    return *this;
}
Matrix2 Matrix2::operator -() const {
    return Matrix2(
        -m[0][0], -m[0][1],
        -m[1][0], -m[1][1]);
}
Matrix2 Matrix2::operator +(const Matrix2 & rhs) const {
    return Matrix2(*this) += rhs;
}
Matrix2 Matrix2::operator -(const Matrix2 & rhs) const {
    return Matrix2(*this) -= rhs;
}
Matrix2 Matrix2::operator *(const Matrix2 & rhs) const {
    return Matrix2(*this) *= rhs;
}
Matrix2 Matrix2::operator *(double rhs) const {
    return Matrix2(*this) *= rhs;
}
Matrix2 operator *(double lhs, const Matrix2 & rhs) {
    return rhs * lhs;
}
Matrix2 Matrix2::operator /(const Matrix2 & rhs) const {
    return Matrix2(*this) /= rhs;
}
Matrix2 Matrix2::operator /(double rhs) const {
    return Matrix2(*this) /= rhs;
}
Matrix2 & Matrix2::operator +=(const Matrix2 & rhs) {
    m[0][0] += rhs[0][0]; m[0][1] += rhs[0][1];
    m[1][0] += rhs[1][0]; m[1][1] += rhs[1][1];

    return *this;
}
Matrix2 & Matrix2::operator -=(const Matrix2 & rhs) {
    m[0][0] -= rhs[0][0]; m[0][1] -= rhs[0][1];
    m[1][0] -= rhs[1][0]; m[1][1] -= rhs[1][1];

    return *this;
}
Matrix2 & Matrix2::operator *=(const Matrix2 & rhs) {
    double t0 = m[0][0], t1 = m[0][1];

    m[0][0] = t0 * rhs[0][0] + t1 * rhs[1][0];
    m[0][1] = t0 * rhs[0][1] + t1 * rhs[1][1];

    t0 = m[1][0]; t1 = m[1][1];

    m[1][0] = t0 * rhs[0][0] + t1 * rhs[1][0];
    m[1][1] = t0 * rhs[0][1] + t1 * rhs[1][1];

    return *this;
}
Matrix2 & Matrix2::operator *=(double rhs) {
    m[0][0] *= rhs; m[0][1] *= rhs;
    m[1][0] *= rhs; m[1][1] *= rhs;

    return *this;
}
Matrix2 & Matrix2::operator /=(const Matrix2 & rhs) {
    return *this *= rhs.inverse();
}
Matrix2 & Matrix2::operator /=(double rhs) {
    m[0][0] /= rhs; m[0][1] /= rhs;
    m[1][0] /= rhs; m[1][1] /= rhs;

    return *this;
}
bool Matrix2::operator ==(const Matrix2 & rhs) const {
    return m[0][0] == rhs[0][0] && m[0][1] == rhs[0][1]
        && m[1][0] == rhs[1][0] && m[1][1] == rhs[1][1];
}
bool Matrix2::operator !=(const Matrix2 & rhs) const {
    return !(*this == rhs);
}
std::ostream & operator <<(std::ostream & lhs, const Matrix2 & rhs) {
    return lhs << '['
        << rhs[0][0] << ' ' << rhs[0][1] << "; "
        << rhs[1][0] << ' ' << rhs[1][1] << ']';
}

double Matrix2::determinant() const {
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}
double Matrix2::trace() const {
    return m[0][0] + m[1][1];
}
double Matrix2::minor(size_t i, size_t j) const {
    size_t i0 = i < 1 ? 1 : 0;
    size_t j0 = j < 1 ? 1 : 0;

    return m[i0][j0];
}
Matrix2 & Matrix2::transpose() {
    double t01 = m[0][1];

    m[0][1] = m[1][0];
    m[1][0] = t01;

    return *this;
}
Matrix2 Matrix2::inverse() const {
    return adjugate() / determinant();
}
Matrix2 Matrix2::adjugate() const {
    return Matrix2(
        minor(0, 0), -minor(1, 0),
        -minor(0, 1), minor(1, 1));
}

Matrix3::Matrix3() {
    m[0][0] = 0; m[0][1] = 0; m[0][2] = 0;
    m[1][0] = 0; m[1][1] = 0; m[1][2] = 0;
    m[2][0] = 0; m[2][1] = 0; m[2][2] = 0;
}
Matrix3::Matrix3(const Matrix3 & matrix3) {
    m[0][0] = matrix3[0][0]; m[0][1] = matrix3[0][1]; m[0][2] = matrix3[0][2];
    m[1][0] = matrix3[1][0]; m[1][1] = matrix3[1][1]; m[1][2] = matrix3[1][2];
    m[2][0] = matrix3[2][0]; m[2][1] = matrix3[2][1]; m[2][2] = matrix3[2][2];
}
Matrix3::Matrix3(
    double m00, double m01, double m02,
    double m10, double m11, double m12,
    double m20, double m21, double m22) {
    m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
    m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
    m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
}
Matrix3::~Matrix3() {}

double * Matrix3::operator [](size_t i) {
    return m[i];
}
const double * Matrix3::operator [](size_t i) const {
    return m[i];
}
Matrix3 Matrix3::operator +() const {
    return *this;
}
Matrix3 Matrix3::operator -() const {
    return Matrix3(
        -m[0][0], -m[0][1], -m[0][2],
        -m[1][0], -m[1][1], -m[1][2],
        -m[2][0], -m[2][1], -m[2][2]);
}
Matrix3 Matrix3::operator +(const Matrix3 & rhs) const {
    return Matrix3(*this) += rhs;
}
Matrix3 Matrix3::operator -(const Matrix3 & rhs) const {
    return Matrix3(*this) -= rhs;
}
Matrix3 Matrix3::operator *(const Matrix3 & rhs) const {
    return Matrix3(*this) *= rhs;
}
Matrix3 Matrix3::operator *(double rhs) const {
    return Matrix3(*this) *= rhs;
}
Matrix3 operator *(double lhs, const Matrix3 & rhs) {
    return rhs * lhs;
}
Matrix3 Matrix3::operator /(const Matrix3 & rhs) const {
    return Matrix3(*this) /= rhs;
}
Matrix3 Matrix3::operator /(double rhs) const {
    return Matrix3(*this) /= rhs;
}
Matrix3 & Matrix3::operator +=(const Matrix3 & rhs) {
    m[0][0] += rhs[0][0]; m[0][1] += rhs[0][1]; m[0][2] += rhs[0][2];
    m[1][0] += rhs[1][0]; m[1][1] += rhs[1][1]; m[1][2] += rhs[1][2];
    m[2][0] += rhs[2][0]; m[2][1] += rhs[2][1]; m[2][2] += rhs[2][2];

    return *this;
}
Matrix3 & Matrix3::operator -=(const Matrix3 & rhs) {
    m[0][0] -= rhs[0][0]; m[0][1] -= rhs[0][1]; m[0][2] -= rhs[0][2];
    m[1][0] -= rhs[1][0]; m[1][1] -= rhs[1][1]; m[1][2] -= rhs[1][2];
    m[2][0] -= rhs[2][0]; m[2][1] -= rhs[2][1]; m[2][2] -= rhs[2][2];

    return *this;
}
Matrix3 & Matrix3::operator *=(const Matrix3 & rhs) {
    double t0 = m[0][0], t1 = m[0][1], t2 = m[0][2];

    m[0][0] = t0 * rhs[0][0] + t1 * rhs[1][0] + t2 * rhs[2][0];
    m[0][1] = t0 * rhs[0][1] + t1 * rhs[1][1] + t2 * rhs[2][1];
    m[0][2] = t0 * rhs[0][2] + t1 * rhs[1][2] + t2 * rhs[2][2];

    t0 = m[1][0]; t1 = m[1][1]; t2 = m[1][2];

    m[1][0] = t0 * rhs[0][0] + t1 * rhs[1][0] + t2 * rhs[2][0];
    m[1][1] = t0 * rhs[0][1] + t1 * rhs[1][1] + t2 * rhs[2][1];
    m[1][2] = t0 * rhs[0][2] + t1 * rhs[1][2] + t2 * rhs[2][2];

    t0 = m[2][0]; t1 = m[2][1]; t2 = m[2][2];

    m[2][0] = t0 * rhs[0][0] + t1 * rhs[1][0] + t2 * rhs[2][0];
    m[2][1] = t0 * rhs[0][1] + t1 * rhs[1][1] + t2 * rhs[2][1];
    m[2][2] = t0 * rhs[0][2] + t1 * rhs[1][2] + t2 * rhs[2][2];

    return *this;
}
Matrix3 & Matrix3::operator *=(double rhs) {
    m[0][0] *= rhs; m[0][1] *= rhs; m[0][2] *= rhs;
    m[1][0] *= rhs; m[1][1] *= rhs; m[1][2] *= rhs;
    m[2][0] *= rhs; m[2][1] *= rhs; m[2][2] *= rhs;

    return *this;
}
Matrix3 & Matrix3::operator /=(const Matrix3 & rhs) {
    return *this *= rhs.inverse();
}
Matrix3 & Matrix3::operator /=(double rhs) {
    m[0][0] /= rhs; m[0][1] /= rhs; m[0][2] /= rhs;
    m[1][0] /= rhs; m[1][1] /= rhs; m[1][2] /= rhs;
    m[2][0] /= rhs; m[2][1] /= rhs; m[2][2] /= rhs;

    return *this;
}
bool Matrix3::operator ==(const Matrix3 & rhs) const {
    return m[0][0] == rhs[0][0] && m[0][1] == rhs[0][1] && m[0][2] == rhs[0][2]
        && m[1][0] == rhs[1][0] && m[1][1] == rhs[1][1] && m[1][2] == rhs[1][2]
        && m[2][0] == rhs[2][0] && m[2][1] == rhs[2][1] && m[2][2] == rhs[2][2];
}
bool Matrix3::operator !=(const Matrix3 & rhs) const {
    return !(*this == rhs);
}
std::ostream & operator <<(std::ostream & lhs, const Matrix3 & rhs) {
    return lhs << '['
        << rhs[0][0] << ' ' << rhs[0][1] << ' ' << rhs[0][2] << ' ' << "; "
        << rhs[1][0] << ' ' << rhs[1][1] << ' ' << rhs[1][2] << ' ' << "; "
        << rhs[2][0] << ' ' << rhs[2][1] << ' ' << rhs[2][2] << ']';
}

Matrix3 & Matrix3::setIdentity() {
    m[0][0] = 1.0;
    m[0][1] = 0;
    m[0][2] = 0;

    m[1][0] = 0;
    m[1][1] = 1.0;
    m[1][2] = 0;

    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = 1.0;

    return *this;
}
Matrix3 & Matrix3::setTranslation(const Vector2 & translation) {
    m[0][0] = 1.0;
    m[0][1] = 0;
    m[0][2] = 0;

    m[1][0] = 0;
    m[1][1] = 1.0;
    m[1][2] = 0;

    m[2][0] = translation.x;
    m[2][1] = translation.y;
    m[2][2] = 1.0;

    return *this;
}
Matrix3 & Matrix3::setRotation(double rotation) {
    double c = std::cos(rotation);
    double s = std::sin(rotation);

    m[0][0] = c;
    m[0][1] = s;
    m[0][2] = 0;

    m[1][0] = -s;
    m[1][1] = c;
    m[1][2] = 0;

    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = 1.0;

    return *this;
}
Matrix3 & Matrix3::setScaling(const Vector2 & scaling) {
    m[0][0] = scaling.x;
    m[0][1] = 0;
    m[0][2] = 0;

    m[1][0] = 0;
    m[1][1] = scaling.y;
    m[1][2] = 0;

    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = 1.0;

    return *this;
}
Matrix3 & Matrix3::setShearing(const Vector2 & shearing) {
    m[0][0] = 1.0;
    m[0][1] = shearing.y;
    m[0][2] = 0;

    m[1][0] = shearing.x;
    m[1][1] = 1.0;
    m[1][2] = 0;

    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = 1.0;

    return *this;
}
Matrix3 & Matrix3::setTransformation(
    const Vector2 & translation, double rotation,
    const Vector2 & scaling, const Vector2 & shearing) {
    double c = std::cos(rotation);
    double s = std::sin(rotation);

    m[0][0] = (c - s * shearing.x) * scaling.x;
    m[0][1] = (s + c * shearing.x) * scaling.x;
    m[0][2] = 0;

    m[1][0] = (c * shearing.y - s) * scaling.y;
    m[1][1] = (c + s * shearing.y) * scaling.y;
    m[1][2] = 0;

    m[2][0] = translation.x;
    m[2][1] = translation.y;
    m[2][2] = 1.0;

    return *this;
}

double Matrix3::determinant() const {
    return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
        + m[0][1] * (m[1][2] * m[2][0] - m[1][0] * m[2][2])
        + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}
double Matrix3::trace() const {
    return m[0][0] + m[1][1] + m[2][2];
}
double Matrix3::minor(size_t i, size_t j) const {
    size_t i0 = i < 1 ? 1 : 0;
    size_t i1 = i < 2 ? 2 : 1;

    size_t j0 = j < 1 ? 1 : 0;
    size_t j1 = j < 2 ? 2 : 1;

    return m[i0][j0] * m[i1][j1] - m[i0][j1] * m[i1][j0];
}
Matrix3 & Matrix3::transpose() {
    Matrix3 t(*this);

    m[0][1] = t[1][0]; m[0][2] = t[2][0];
    m[1][0] = t[0][1]; m[1][2] = t[2][1];
    m[2][0] = t[0][2]; m[2][1] = t[1][2];

    return *this;
}
Matrix3 Matrix3::inverse() const {
    return adjugate() / determinant();
}
Matrix3 Matrix3::adjugate() const {
    return Matrix3(
        minor(0, 0), -minor(1, 0), minor(2, 0),
        -minor(0, 1), minor(1, 1), -minor(2, 1),
        minor(0, 2), -minor(1, 2), minor(2, 2));
}

Matrix4::Matrix4() {
    m[0][0] = 0; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
    m[1][0] = 0; m[1][1] = 0; m[1][2] = 0; m[1][3] = 0;
    m[2][0] = 0; m[2][1] = 0; m[2][2] = 0; m[2][3] = 0;
    m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 0;
}
Matrix4::Matrix4(const Matrix4 & matrix4) {
    m[0][0] = matrix4[0][0]; m[0][1] = matrix4[0][1]; m[0][2] = matrix4[0][2]; m[0][3] = matrix4[0][3];
    m[1][0] = matrix4[1][0]; m[1][1] = matrix4[1][1]; m[1][2] = matrix4[1][2]; m[1][3] = matrix4[1][3];
    m[2][0] = matrix4[2][0]; m[2][1] = matrix4[2][1]; m[2][2] = matrix4[2][2]; m[2][3] = matrix4[2][3];
    m[3][0] = matrix4[3][0]; m[3][1] = matrix4[3][1]; m[3][2] = matrix4[3][2]; m[3][3] = matrix4[3][3];
}
Matrix4::Matrix4(
    double m00, double m01, double m02, double m03,
    double m10, double m11, double m12, double m13,
    double m20, double m21, double m22, double m23,
    double m30, double m31, double m32, double m33) {
    m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
    m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
    m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
    m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
}
Matrix4::~Matrix4() {}

double * Matrix4::operator [](size_t i) {
    return m[i];
}
const double * Matrix4::operator [](size_t i) const {
    return m[i];
}
Matrix4 Matrix4::operator +() const {
    return *this;
}
Matrix4 Matrix4::operator -() const {
    return Matrix4(
        -m[0][0], -m[0][1], -m[0][2], -m[0][3],
        -m[1][0], -m[1][1], -m[1][2], -m[1][3],
        -m[2][0], -m[2][1], -m[2][2], -m[2][3],
        -m[3][0], -m[3][1], -m[3][2], -m[3][3]);
}
Matrix4 Matrix4::operator +(const Matrix4 & rhs) const {
    return Matrix4(*this) += rhs;
}
Matrix4 Matrix4::operator -(const Matrix4 & rhs) const {
    return Matrix4(*this) -= rhs;
}
Matrix4 Matrix4::operator *(const Matrix4 & rhs) const {
    return Matrix4(*this) *= rhs;
}
Matrix4 Matrix4::operator *(double rhs) const {
    return Matrix4(*this) *= rhs;
}
Matrix4 operator *(double lhs, const Matrix4 & rhs) {
    return rhs * lhs;
}
Matrix4 Matrix4::operator /(const Matrix4 & rhs) const {
    return Matrix4(*this) /= rhs;
}
Matrix4 Matrix4::operator /(double rhs) const {
    return Matrix4(*this) /= rhs;
}
Matrix4 & Matrix4::operator +=(const Matrix4 & rhs) {
    m[0][0] += rhs[0][0]; m[0][1] += rhs[0][1]; m[0][2] += rhs[0][2]; m[0][3] += rhs[0][3];
    m[1][0] += rhs[1][0]; m[1][1] += rhs[1][1]; m[1][2] += rhs[1][2]; m[1][3] += rhs[1][3];
    m[2][0] += rhs[2][0]; m[2][1] += rhs[2][1]; m[2][2] += rhs[2][2]; m[2][3] += rhs[2][3];
    m[3][0] += rhs[3][0]; m[3][1] += rhs[3][1]; m[3][2] += rhs[3][2]; m[3][3] += rhs[3][3];

    return *this;
}
Matrix4 & Matrix4::operator -=(const Matrix4 & rhs) {
    m[0][0] -= rhs[0][0]; m[0][1] -= rhs[0][1]; m[0][2] -= rhs[0][2]; m[0][3] -= rhs[0][3];
    m[1][0] -= rhs[1][0]; m[1][1] -= rhs[1][1]; m[1][2] -= rhs[1][2]; m[1][3] -= rhs[1][3];
    m[2][0] -= rhs[2][0]; m[2][1] -= rhs[2][1]; m[2][2] -= rhs[2][2]; m[2][3] -= rhs[2][3];
    m[3][0] -= rhs[3][0]; m[3][1] -= rhs[3][1]; m[3][2] -= rhs[3][2]; m[3][3] -= rhs[3][3];

    return *this;
}
Matrix4 & Matrix4::operator *=(const Matrix4 & rhs) {
    double t0 = m[0][0], t1 = m[0][1], t2 = m[0][2], t3 = m[0][3];

    m[0][0] = t0 * rhs[0][0] + t1 * rhs[1][0] + t2 * rhs[2][0] + t3 * rhs[3][0];
    m[0][1] = t0 * rhs[0][1] + t1 * rhs[1][1] + t2 * rhs[2][1] + t3 * rhs[3][1];
    m[0][2] = t0 * rhs[0][2] + t1 * rhs[1][2] + t2 * rhs[2][2] + t3 * rhs[3][2];
    m[0][3] = t0 * rhs[0][3] + t1 * rhs[1][3] + t2 * rhs[2][3] + t3 * rhs[3][3];

    t0 = m[1][0]; t1 = m[1][1]; t2 = m[1][2]; t3 = m[1][3];

    m[1][0] = t0 * rhs[0][0] + t1 * rhs[1][0] + t2 * rhs[2][0] + t3 * rhs[3][0];
    m[1][1] = t0 * rhs[0][1] + t1 * rhs[1][1] + t2 * rhs[2][1] + t3 * rhs[3][1];
    m[1][2] = t0 * rhs[0][2] + t1 * rhs[1][2] + t2 * rhs[2][2] + t3 * rhs[3][2];
    m[1][3] = t0 * rhs[0][3] + t1 * rhs[1][3] + t2 * rhs[2][3] + t3 * rhs[3][3];

    t0 = m[2][0]; t1 = m[2][1]; t2 = m[2][2]; t3 = m[2][3];

    m[2][0] = t0 * rhs[0][0] + t1 * rhs[1][0] + t2 * rhs[2][0] + t3 * rhs[3][0];
    m[2][1] = t0 * rhs[0][1] + t1 * rhs[1][1] + t2 * rhs[2][1] + t3 * rhs[3][1];
    m[2][2] = t0 * rhs[0][2] + t1 * rhs[1][2] + t2 * rhs[2][2] + t3 * rhs[3][2];
    m[2][3] = t0 * rhs[0][3] + t1 * rhs[1][3] + t2 * rhs[2][3] + t3 * rhs[3][3];

    t0 = m[3][0]; t1 = m[3][1]; t2 = m[3][2]; t3 = m[3][3];

    m[3][0] = t0 * rhs[0][0] + t1 * rhs[1][0] + t2 * rhs[2][0] + t3 * rhs[3][0];
    m[3][1] = t0 * rhs[0][1] + t1 * rhs[1][1] + t2 * rhs[2][1] + t3 * rhs[3][1];
    m[3][2] = t0 * rhs[0][2] + t1 * rhs[1][2] + t2 * rhs[2][2] + t3 * rhs[3][2];
    m[3][3] = t0 * rhs[0][3] + t1 * rhs[1][3] + t2 * rhs[2][3] + t3 * rhs[3][3];

    return *this;
}
Matrix4 & Matrix4::operator *=(double rhs) {
    m[0][0] *= rhs; m[0][1] *= rhs; m[0][2] *= rhs; m[0][3] *= rhs;
    m[1][0] *= rhs; m[1][1] *= rhs; m[1][2] *= rhs; m[1][3] *= rhs;
    m[2][0] *= rhs; m[2][1] *= rhs; m[2][2] *= rhs; m[2][3] *= rhs;
    m[3][0] *= rhs; m[3][1] *= rhs; m[3][2] *= rhs; m[3][3] *= rhs;

    return *this;
}
Matrix4 & Matrix4::operator /=(const Matrix4 & rhs) {
    return *this *= rhs.inverse();
}
Matrix4 & Matrix4::operator /=(double rhs) {
    m[0][0] /= rhs; m[0][1] /= rhs; m[0][2] /= rhs; m[0][3] /= rhs;
    m[1][0] /= rhs; m[1][1] /= rhs; m[1][2] /= rhs; m[1][3] /= rhs;
    m[2][0] /= rhs; m[2][1] /= rhs; m[2][2] /= rhs; m[2][3] /= rhs;
    m[3][0] /= rhs; m[3][1] /= rhs; m[3][2] /= rhs; m[3][3] /= rhs;

    return *this;
}
bool Matrix4::operator ==(const Matrix4 & rhs) const {
    return m[0][0] == rhs[0][0] && m[0][1] == rhs[0][1] && m[0][2] == rhs[0][2] && m[0][3] == rhs[0][3]
        && m[1][0] == rhs[1][0] && m[1][1] == rhs[1][1] && m[1][2] == rhs[1][2] && m[1][3] == rhs[1][3]
        && m[2][0] == rhs[2][0] && m[2][1] == rhs[2][1] && m[2][2] == rhs[2][2] && m[2][3] == rhs[2][3]
        && m[3][0] == rhs[3][0] && m[3][1] == rhs[3][1] && m[3][2] == rhs[3][2] && m[3][3] == rhs[3][3];
}
bool Matrix4::operator !=(const Matrix4 & rhs) const {
    return !(*this == rhs);
}
std::ostream & operator <<(std::ostream & lhs, const Matrix4 & rhs) {
    return lhs << '['
        << rhs[0][0] << ' ' << rhs[0][1] << ' ' << rhs[0][2] << ' ' << rhs[0][3] << "; "
        << rhs[1][0] << ' ' << rhs[1][1] << ' ' << rhs[1][2] << ' ' << rhs[1][3] << "; "
        << rhs[2][0] << ' ' << rhs[2][1] << ' ' << rhs[2][2] << ' ' << rhs[2][3] << "; "
        << rhs[3][0] << ' ' << rhs[3][1] << ' ' << rhs[3][2] << ' ' << rhs[3][3] << ']';
}

Matrix4 & Matrix4::setIdentity() {
    m[0][0] = 1.0;
    m[0][1] = 0;
    m[0][2] = 0;
    m[0][3] = 0;

    m[1][0] = 0;
    m[1][1] = 1.0;
    m[1][2] = 0;
    m[1][3] = 0;

    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = 1.0;
    m[2][3] = 0;

    m[3][0] = 0;
    m[3][1] = 0;
    m[3][2] = 0;
    m[3][3] = 1.0;

    return *this;
}
Matrix4 & Matrix4::setTranslation(const Vector3 & translation) {
    m[0][0] = 1.0;
    m[0][1] = 0;
    m[0][2] = 0;
    m[0][3] = 0;

    m[1][0] = 0;
    m[1][1] = 1.0;
    m[1][2] = 0;
    m[1][3] = 0;

    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = 1.0;
    m[2][3] = 0;

    m[3][0] = translation.x;
    m[3][1] = translation.y;
    m[3][2] = translation.z;
    m[3][3] = 1.0;

    return *this;
}
Matrix4 & Matrix4::setRotation(const Vector3 & rotation) {
    double cx = std::cos(rotation.x);
    double cy = std::cos(rotation.y);
    double cz = std::cos(rotation.z);

    double sx = std::sin(rotation.x);
    double sy = std::sin(rotation.y);
    double sz = std::sin(rotation.z);

    m[0][0] = cy * cz;
    m[0][1] = cy * sz;
    m[0][2] = -sy;
    m[0][3] = 0;

    m[1][0] = cz * sx * sy - cx * sz;
    m[1][1] = cx * cz + sx * sy * sz;
    m[1][2] = cy * sx;
    m[1][3] = 0;

    m[2][0] = cx * cz * sy + sx * sz;
    m[2][1] = cx * sy * sz - cz * sx;
    m[2][2] = cx * cy;
    m[2][3] = 0;

    m[3][0] = 0;
    m[3][1] = 0;
    m[3][2] = 0;
    m[3][3] = 1.0;

    return *this;
}
Matrix4 & Matrix4::setScaling(const Vector3 & scaling) {
    m[0][0] = scaling.x;
    m[0][1] = 0;
    m[0][2] = 0;
    m[0][3] = 0;

    m[1][0] = 0;
    m[1][1] = scaling.y;
    m[1][2] = 0;
    m[1][3] = 0;

    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = scaling.z;
    m[2][3] = 0;

    m[3][0] = 0;
    m[3][1] = 0;
    m[3][2] = 0;
    m[3][3] = 1.0;

    return *this;
}
Matrix4 & Matrix4::setShearing(const Vector3 & shearing) {
    m[0][0] = 1.0;
    m[0][1] = 0;
    m[0][2] = 0;
    m[0][3] = 0;

    m[1][0] = shearing.x;
    m[1][1] = 1.0;
    m[1][2] = 0;
    m[1][3] = 0;

    m[2][0] = shearing.y;
    m[2][1] = shearing.z;
    m[2][2] = 1.0;
    m[2][3] = 0;

    m[3][0] = 0;
    m[3][1] = 0;
    m[3][2] = 0;
    m[3][3] = 1.0;

    return *this;
}
Matrix4 & Matrix4::setTransformation(
    const Vector3 & translation, const Vector3 & rotation,
    const Vector3 & scaling, const Vector3 & shearing) {
    double cx = std::cos(rotation.x);
    double cy = std::cos(rotation.y);
    double cz = std::cos(rotation.z);

    double sx = std::sin(rotation.x);
    double sy = std::sin(rotation.y);
    double sz = std::sin(rotation.z);

    m[0][0] = cy * cz * scaling.x;
    m[0][1] = cy * sz * scaling.x;
    m[0][2] = -sy * scaling.x;
    m[0][3] = 0;

    m[1][0] = (cz * sx * sy - cx * sz + cy * cz * shearing.x) * scaling.y;
    m[1][1] = (cx * cz + sx * sy * sz + cy * sz * shearing.x) * scaling.y;
    m[1][2] = (cy * sx - sy * shearing.x) * scaling.y;
    m[1][3] = 0;

    double t0 = cz * sx * sy - cx * sz;
    double t1 = cx * cz * sy + sx * sz;
    double t2 = cx * cz + sx * sy * sz;
    double t3 = cx * sy * sz - cz * sx;

    m[2][0] = (cy * cz * shearing.y + t0 * shearing.z + t1) * scaling.z;
    m[2][1] = (cy * sz * shearing.y + t2 * shearing.z + t3) * scaling.z;
    m[2][2] = (cx * cy - sy * shearing.y + cy * sx * shearing.z) * scaling.z;
    m[2][3] = 0;

    m[3][0] = translation.x;
    m[3][1] = translation.y;
    m[3][2] = translation.z;
    m[3][3] = 1.0;

    return *this;
}

double Matrix4::determinant() const {
    double d = 0;

    if (m[0][0] != 0) d += m[0][0] * minor(0, 0);
    if (m[0][1] != 0) d -= m[0][1] * minor(0, 1);
    if (m[0][2] != 0) d += m[0][2] * minor(0, 2);
    if (m[0][3] != 0) d -= m[0][3] * minor(0, 3);

    return d;
}
double Matrix4::trace() const {
    return m[0][0] + m[1][1] + m[2][2] + m[3][3];
}
double Matrix4::minor(size_t i, size_t j) const {
    size_t i0 = i < 1 ? 1 : 0;
    size_t i1 = i < 2 ? 2 : 1;
    size_t i2 = i < 3 ? 3 : 2;

    size_t j0 = j < 1 ? 1 : 0;
    size_t j1 = j < 2 ? 2 : 1;
    size_t j2 = j < 3 ? 3 : 2;

    return m[i0][j0] * (m[i1][j1] * m[i2][j2] - m[i1][j2] * m[i2][j1])
        + m[i0][j1] * (m[i1][j2] * m[i2][j0] - m[i1][j0] * m[i2][j2])
        + m[i0][j2] * (m[i1][j0] * m[i2][j1] - m[i1][j1] * m[i2][j0]);
}
Matrix4 & Matrix4::transpose() {
    Matrix4 t(*this);

    m[0][1] = t[1][0]; m[0][2] = t[2][0]; m[0][3] = t[3][0];
    m[1][0] = t[0][1]; m[1][2] = t[2][1]; m[1][3] = t[3][1];
    m[2][0] = t[0][2]; m[2][1] = t[1][2]; m[2][3] = t[3][2];
    m[3][0] = t[0][3]; m[3][1] = t[1][3]; m[3][2] = t[2][3];

    return *this;
}
Matrix4 Matrix4::inverse() const {
    return adjugate() / determinant();
}
Matrix4 Matrix4::adjugate() const {
    return Matrix4(
        minor(0, 0), -minor(1, 0), minor(2, 0), -minor(3, 0),
        -minor(0, 1), minor(1, 1), -minor(2, 1), minor(3, 1),
        minor(0, 2), -minor(1, 2), minor(2, 2), -minor(3, 2),
        -minor(0, 3), minor(1, 3), -minor(2, 3), minor(3, 3));
}

AURORA_NAMESPACE_END
