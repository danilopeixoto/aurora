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

#include <aurora/Color.h>
#include <aurora/Math.h>

#include <cmath>

AURORA_NAMESPACE_BEGIN

Color3::Color3() : r(0), g(0), b(0) {}
Color3::Color3(const Color3 & color3) : r(color3.r), g(color3.g), b(color3.b) {}
Color3::Color3(double r, double g, double b) : r(r), g(g), b(b) {}
Color3::~Color3() {}

double & Color3::operator [](size_t i) {
    return (&r)[i];
}
const double & Color3::operator [](size_t i) const {
    return (&r)[i];
}
Color3 Color3::operator +() const {
    return *this;
}
Color3 Color3::operator -() const {
    return Color3(-r, -g, -b);
}
Color3 Color3::operator +(const Color3 & rhs) const {
    return Color3(*this) += rhs;
}
Color3 Color3::operator -(const Color3 & rhs) const {
    return Color3(*this) -= rhs;
}
Color3 Color3::operator *(const Color3 & rhs) const {
    return Color3(*this) *= rhs;
}
Color3 Color3::operator *(double rhs) const {
    return Color3(*this) *= rhs;
}
Color3 operator *(double lhs, const Color3 & rhs) {
    return rhs * lhs;
}
Color3 Color3::operator /(const Color3 & rhs) const {
    return Color3(*this) /= rhs;
}
Color3 Color3::operator /(double rhs) const {
    return Color3(*this) /= rhs;
}
Color3 & Color3::operator +=(const Color3 & rhs) {
    r += rhs.r;
    g += rhs.g;
    b += rhs.b;

    return *this;
}
Color3 & Color3::operator -=(const Color3 & rhs) {
    r -= rhs.r;
    g -= rhs.g;
    b -= rhs.b;

    return *this;
}
Color3 & Color3::operator *=(const Color3 & rhs) {
    r *= rhs.r;
    g *= rhs.g;
    b *= rhs.b;

    return *this;
}
Color3 & Color3::operator *=(double rhs) {
    r *= rhs;
    g *= rhs;
    b *= rhs;

    return *this;
}
Color3 & Color3::operator /=(const Color3 & rhs) {
    r /= rhs.r;
    g /= rhs.g;
    b /= rhs.b;

    return *this;
}
Color3 & Color3::operator /=(double rhs) {
    r /= rhs;
    g /= rhs;
    b /= rhs;

    return *this;
}
bool Color3::operator ==(const Color3 & rhs) const {
    return r == rhs.r && g == rhs.g && b == rhs.b;
}
bool Color3::operator !=(const Color3 & rhs) const {
    return !(*this == rhs);
}
std::ostream & operator <<(std::ostream & lhs, const Color3 & rhs) {
    return lhs << '[' << rhs.r << ' ' << rhs.g << ' ' << rhs.b << ']';
}

Color3 & Color3::applyGamma(double gamma) {
    double t = 1.0 / gamma;

    r = std::pow(r, t);
    g = std::pow(g, t);
    b = std::pow(b, t);

    return *this;
}
Color3 & Color3::applyExposure(double exposure) {
    double t = std::pow(2.0, exposure);

    r *= t;
    g *= t;
    b *= t;

    return *this;
}
Color3 & Color3::saturate() {
    r = clamp(r, 0, 1.0);
    g = clamp(g, 0, 1.0);
    b = clamp(b, 0, 1.0);

    return *this;
}

Color4::Color4() : r(0), g(0), b(0), a(0) {}
Color4::Color4(const Color4 & color4) : r(color4.r), g(color4.g), b(color4.b), a(color4.a) {}
Color4::Color4(double r, double g, double b, double a) : r(r), g(g), b(b), a(a) {}
Color4::~Color4() {}

double & Color4::operator [](size_t i) {
    return (&r)[i];
}
const double & Color4::operator [](size_t i) const {
    return (&r)[i];
}
Color4 Color4::operator +() const {
    return *this;
}
Color4 Color4::operator -() const {
    return Color4(-r, -g, -b, a);
}
Color4 Color4::operator +(const Color4 & rhs) const {
    return Color4(*this) += rhs;
}
Color4 Color4::operator -(const Color4 & rhs) const {
    return Color4(*this) -= rhs;
}
Color4 Color4::operator *(const Color4 & rhs) const {
    return Color4(*this) *= rhs;
}
Color4 Color4::operator *(double rhs) const {
    return Color4(*this) *= rhs;
}
Color4 operator *(double lhs, const Color4 & rhs) {
    return rhs * lhs;
}
Color4 Color4::operator /(const Color4 & rhs) const {
    return Color4(*this) /= rhs;
}
Color4 Color4::operator /(double rhs) const {
    return Color4(*this) /= rhs;
}
Color4 & Color4::operator +=(const Color4 & rhs) {
    r += rhs.r;
    g += rhs.g;
    b += rhs.b;

    return *this;
}
Color4 & Color4::operator -=(const Color4 & rhs) {
    r -= rhs.r;
    g -= rhs.g;
    b -= rhs.b;

    return *this;
}
Color4 & Color4::operator *=(const Color4 & rhs) {
    r *= rhs.r;
    g *= rhs.g;
    b *= rhs.b;

    return *this;
}
Color4 & Color4::operator *=(double rhs) {
    r *= rhs;
    g *= rhs;
    b *= rhs;

    return *this;
}
Color4 & Color4::operator /=(const Color4 & rhs) {
    r /= rhs.r;
    g /= rhs.g;
    b /= rhs.b;

    return *this;
}
Color4 & Color4::operator /=(double rhs) {
    r /= rhs;
    g /= rhs;
    b /= rhs;

    return *this;
}
bool Color4::operator ==(const Color4 & rhs) const {
    return r == rhs.r && g == rhs.g && b == rhs.b && a == rhs.a;
}
bool Color4::operator !=(const Color4 & rhs) const {
    return !(*this == rhs);
}
std::ostream & operator <<(std::ostream & lhs, const Color4 & rhs) {
    return lhs << '[' << rhs.r << ' ' << rhs.g << ' ' << rhs.b << ' ' << rhs.a << ']';
}

Color4 & Color4::applyGamma(double gamma) {
    double t = 1.0 / gamma;

    r = std::pow(r, t);
    g = std::pow(g, t);
    b = std::pow(b, t);

    return *this;
}
Color4 & Color4::applyExposure(double exposure) {
    double t = std::pow(2.0, exposure);

    r *= t;
    g *= t;
    b *= t;

    return *this;
}
Color4 & Color4::saturate() {
    r = clamp(r, 0, 1.0);
    g = clamp(g, 0, 1.0);
    b = clamp(b, 0, 1.0);

    return *this;
}

AURORA_NAMESPACE_END
