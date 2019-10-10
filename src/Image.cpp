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

#include <aurora/Image.h>
#include <aurora/Color.h>

AURORA_NAMESPACE_BEGIN

Image3::Image3() : width(0), height(0) {}
Image3::Image3(const Image3 & image3) {
    create(image3);
}
Image3::Image3(size_t width, size_t height) {
    create(width, height);
}
Image3::Image3(size_t width, size_t height, const std::vector<Color3> & pixels) {
    create(width, height, pixels);
}
Image3::~Image3() {}

Color3 & Image3::operator [](size_t i) {
    return pixels[i];
}
const Color3 & Image3::operator [](size_t i) const {
    return pixels[i];
}
Color3 & Image3::operator ()(size_t i, size_t j) {
    return pixels[i + j * width];
}
const Color3 & Image3::operator ()(size_t i, size_t j) const {
    return pixels[i + j * width];
}
Image3 Image3::operator +() const {
    return *this;
}
Image3 Image3::operator -() const {
    Image3 t(width, height);

    for (size_t i = 0; i < width * height; i++)
        t[i] = -pixels[i];

    return t;
}
Image3 Image3::operator +(const Image3 & rhs) const {
    return Image3(*this) += rhs;
}
Image3 Image3::operator -(const Image3 & rhs) const {
    return Image3(*this) -= rhs;
}
Image3 Image3::operator *(double rhs) const {
    return Image3(*this) *= rhs;
}
Image3 operator *(double lhs, const Image3 & rhs) {
    return rhs * lhs;
}
Image3 Image3::operator /(double rhs) const {
    return Image3(*this) /= rhs;
}
Image3 & Image3::operator +=(const Image3 & rhs) {
    for (size_t i = 0; i < width * height; i++)
        pixels[i] += rhs[i];

    return *this;
}
Image3 & Image3::operator -=(const Image3 & rhs) {
    for (size_t i = 0; i < width * height; i++)
        pixels[i] -= rhs[i];

    return *this;
}
Image3 & Image3::operator *=(double rhs) {
    for (size_t i = 0; i < width * height; i++)
        pixels[i] *= rhs;

    return *this;
}
Image3 & Image3::operator /=(double rhs) {
    for (size_t i = 0; i < width * height; i++)
        pixels[i] /= rhs;

    return *this;
}
bool Image3::operator ==(const Image3 & rhs) const {
    return width == rhs.width && height == rhs.height && pixels == rhs.pixels;
}
bool Image3::operator !=(const Image3 & rhs) const {
    return !(*this == rhs);
}
std::ostream & operator <<(std::ostream & lhs, const Image3 & rhs) {
    return lhs << "Width: " << rhs.getWidth() << std::endl << "Height: " << rhs.getHeight();
}

Image3 & Image3::setPixel(size_t i, size_t j, const Color3 & pixel) {
    pixels[i + j * width] = pixel;
    return *this;
}
const Color3 & Image3::getPixel(size_t i, size_t j) const {
    return pixels[i + j * width];
}
size_t Image3::getWidth() const {
    return width;
}
size_t Image3::getHeight() const {
    return height;
}
size_t Image3::getPixelCount() const {
    return width * height;
}
double Image3::getAspectRatio() const {
    return width / (double)height;
}

Image3 & Image3::create(const Image3 & image3) {
    width = image3.width;
    height = image3.height;
    pixels = image3.pixels;

    return *this;
}
Image3 & Image3::create(size_t width, size_t height) {
    this->width = width;
    this->height = height;
    pixels.resize(width * height);

    return *this;
}
Image3 & Image3::create(size_t width, size_t height, const std::vector<Color3> & pixels) {
    this->width = width;
    this->height = height;
    this->pixels = pixels;

    return *this;
}

Image3 & Image3::applyGamma(double gamma) {
    for (size_t i = 0; i < width * height; i++)
        pixels[i].applyGamma(gamma);

    return *this;
}
Image3 & Image3::applyExposure(double exposure) {
    for (size_t i = 0; i < width * height; i++)
        pixels[i].applyExposure(exposure);

    return *this;
}
Image3 & Image3::saturate() {
    for (size_t i = 0; i < width * height; i++)
        pixels[i].saturate();

    return *this;
}

Image4::Image4() : width(0), height(0) {}
Image4::Image4(const Image4 & image4) {
    create(image4);
}
Image4::Image4(size_t width, size_t height) {
    create(width, height);
}
Image4::Image4(size_t width, size_t height, const std::vector<Color4> & pixels) {
    create(width, height, pixels);
}
Image4::~Image4() {}

Color4 & Image4::operator [](size_t i) {
    return pixels[i];
}
const Color4 & Image4::operator [](size_t i) const {
    return pixels[i];
}
Color4 & Image4::operator ()(size_t i, size_t j) {
    return pixels[i + j * width];
}
const Color4 & Image4::operator ()(size_t i, size_t j) const {
    return pixels[i + j * width];
}
Image4 Image4::operator +() const {
    return *this;
}
Image4 Image4::operator -() const {
    Image4 t(width, height);

    for (size_t i = 0; i < width * height; i++)
        t[i] = -pixels[i];

    return t;
}
Image4 Image4::operator +(const Image4 & rhs) const {
    return Image4(*this) += rhs;
}
Image4 Image4::operator -(const Image4 & rhs) const {
    return Image4(*this) -= rhs;
}
Image4 Image4::operator *(double rhs) const {
    return Image4(*this) *= rhs;
}
Image4 operator *(double lhs, const Image4 & rhs) {
    return rhs * lhs;
}
Image4 Image4::operator /(double rhs) const {
    return Image4(*this) /= rhs;
}
Image4 & Image4::operator +=(const Image4 & rhs) {
    for (size_t i = 0; i < width * height; i++)
        pixels[i] += rhs[i];

    return *this;
}
Image4 & Image4::operator -=(const Image4 & rhs) {
    for (size_t i = 0; i < width * height; i++)
        pixels[i] -= rhs[i];

    return *this;
}
Image4 & Image4::operator *=(double rhs) {
    for (size_t i = 0; i < width * height; i++)
        pixels[i] *= rhs;

    return *this;
}
Image4 & Image4::operator /=(double rhs) {
    for (size_t i = 0; i < width * height; i++)
        pixels[i] /= rhs;

    return *this;
}
bool Image4::operator ==(const Image4 & rhs) const {
    return width == rhs.width && height == rhs.height && pixels == rhs.pixels;
}
bool Image4::operator !=(const Image4 & rhs) const {
    return !(*this == rhs);
}
std::ostream & operator <<(std::ostream & lhs, const Image4 & rhs) {
    return lhs << "Width: " << rhs.getWidth() << std::endl << "Height: " << rhs.getHeight();
}

Image4 & Image4::setPixel(size_t i, size_t j, const Color4 & pixel) {
    pixels[i + j * width] = pixel;
    return *this;
}
const Color4 & Image4::getPixel(size_t i, size_t j) const {
    return pixels[i + j * width];
}
size_t Image4::getWidth() const {
    return width;
}
size_t Image4::getHeight() const {
    return height;
}
size_t Image4::getPixelCount() const {
    return width * height;
}
double Image4::getAspectRatio() const {
    return width / (double)height;
}

Image4 & Image4::create(const Image4 & image3) {
    width = image3.width;
    height = image3.height;
    pixels = image3.pixels;

    return *this;
}
Image4 & Image4::create(size_t width, size_t height) {
    this->width = width;
    this->height = height;

    pixels.clear();
    pixels.resize(width * height);

    return *this;
}
Image4 & Image4::create(size_t width, size_t height, const std::vector<Color4> & pixels) {
    this->width = width;
    this->height = height;
    this->pixels = pixels;

    return *this;
}

Image4 & Image4::applyGamma(double gamma) {
    for (size_t i = 0; i < width * height; i++)
        pixels[i].applyGamma(gamma);

    return *this;
}
Image4 & Image4::applyExposure(double exposure) {
    for (size_t i = 0; i < width * height; i++)
        pixels[i].applyExposure(exposure);

    return *this;
}
Image4 & Image4::saturate() {
    for (size_t i = 0; i < width * height; i++)
        pixels[i].saturate();

    return *this;
}

AURORA_NAMESPACE_END
