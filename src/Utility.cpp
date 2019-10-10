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

#include <aurora/Utility.h>
#include <aurora/Math.h>
#include <aurora/Vector.h>
#include <aurora/Color.h>
#include <aurora/Image.h>
#include <aurora/TriangleMesh.h>

#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <chrono>

AURORA_NAMESPACE_BEGIN

Image3 * readImage(const std::string & filename) {
    std::ifstream file(filename, std::ifstream::in | std::ofstream::binary);

    if (!file.is_open())
        return nullptr;

    std::string magic, comment;
    size_t width, height, depth;

    file >> magic;

    file.ignore();

    if (file.peek() == '#')
        std::getline(file, comment);

    file >> width >> height >> depth;

    file.ignore();

    if (magic != "P6" || depth == 0) {
        file.close();
        return nullptr;
    }

    size_t size = width * height;

    std::vector<Color3> pixels;
    pixels.resize(size);

    for (size_t i = 0; i < size; i++) {
        unsigned char data[3];

        file.read((char *)data, sizeof(data));

        pixels[i] = Color3(
            clamp(data[0] / (double)depth, 0, 1.0),
            clamp(data[1] / (double)depth, 0, 1.0),
            clamp(data[2] / (double)depth, 0, 1.0));
    }

    file.close();

    return new Image3(width, height, pixels);
}
bool writeImage(const std::string & filename, const Image3 * image3) {
    std::ofstream file(filename, std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);

    if (!file.is_open())
        return false;

    size_t depth = 255;

    file << "P6" << ' ' << image3->getWidth() << ' ' << image3->getHeight() << ' ' << depth << std::endl;

    for (size_t i = 0; i < image3->getPixelCount(); i++) {
        const Color3 & pixel = (*image3)[i];
        unsigned char data[3];

        data[0] = (unsigned char)(clamp(pixel.r, 0, 1.0) * depth);
        data[1] = (unsigned char)(clamp(pixel.g, 0, 1.0) * depth);
        data[2] = (unsigned char)(clamp(pixel.b, 0, 1.0) * depth);

        file.write((const char *)data, sizeof(data));
    }

    file.close();

    return true;
}

TriangleMesh * readMesh(const std::string & filename) {
    std::ifstream file(filename, std::ifstream::in);
    
    if (!file.is_open())
        return nullptr;

    std::vector<Vector3> vertices, normals;
    std::vector<Vector2> textureCoordinates;
    std::vector<size_t> vertexIndices, normalIndices, textureIndices;

    std::string line;

    while (std::getline(file, line)) {
        std::istringstream attributes(line);

        std::string type;
        attributes >> type;

        if (type == "v") {
            Vector3 vertex;
            attributes >> vertex.x >> vertex.y >> vertex.z;

            vertices.push_back(vertex);
        }
        else if (type == "vt") {
            Vector2 uvCoordinates;
            attributes >> uvCoordinates.x >> uvCoordinates.y;

            textureCoordinates.push_back(uvCoordinates);
        }
        else if (type == "vn") {
            Vector3 normal;
            attributes >> normal.x >> normal.y >> normal.z;

            normals.push_back(normal);
        }
        else if (type == "f") {
            for (size_t i = 0; i < 3; i++) {
                std::string tokens;
                attributes >> tokens;

                std::replace(tokens.begin(), tokens.end(), '/', ' ');

                std::istringstream indices(tokens);
                size_t index;

                indices >> index;
                vertexIndices.push_back(index - 1);

                if (indices.peek() == ' ') {
                    indices.ignore();

                    if (indices.peek() == ' ') {
                        indices.ignore();

                        indices >> index;
                        normalIndices.push_back(index - 1);
                    }
                    else {
                        indices >> index;
                        textureIndices.push_back(index - 1);

                        if (indices.peek() == ' ') {
                            indices.ignore();

                            indices >> index;
                            normalIndices.push_back(index - 1);
                        }
                    }
                }
            }
        }
    }

    file.close();

    return new TriangleMesh(vertices, normals, textureCoordinates,
        vertexIndices, normalIndices, textureIndices);
}
bool writeMesh(const std::string & filename, const TriangleMesh * triangleMesh) {
    std::ofstream file(filename, std::ofstream::out | std::ofstream::trunc);

    if (!file.is_open())
        return false;

    file.setf(std::ofstream::fixed);
    file.precision(5);

    for (size_t i = 0; i < triangleMesh->getVertexCount(); i++) {
        const Vector3 & vertex = triangleMesh->getVertex(i);
        file << "v " << vertex.x << ' ' << vertex.y << ' ' << vertex.z << std::endl;
    }

    for (size_t i = 0; i < triangleMesh->getTextureCoordinateCount(); i++) {
        const Vector2 & uvCoordinates = triangleMesh->getTextureCoordinates(i);
        file << "vt " << uvCoordinates.x << ' ' << uvCoordinates.y << std::endl;
    }

    for (size_t i = 0; i < triangleMesh->getNormalCount(); i++) {
        const Vector3 & normal = triangleMesh->getNormal(i);
        file << "vn " << normal.x << ' ' << normal.y << ' ' << normal.z << std::endl;
    }

    size_t triangleCount = triangleMesh->getTriangleCount();

    bool hasNormals = triangleMesh->hasNormals();
    bool hasTextureCoordinates = triangleMesh->hasTextureCoordinates();

    for (size_t i = 0; i < triangleCount; i++) {
        size_t vertexIndices[3], textureIndices[3], normalIndices[3];

        triangleMesh->getVertexIndices(i, vertexIndices[0], vertexIndices[1], vertexIndices[2]);

        if (hasTextureCoordinates)
            triangleMesh->getTextureIndices(i, textureIndices[0], textureIndices[1], textureIndices[2]);

        if (hasNormals)
            triangleMesh->getNormalIndices(i, normalIndices[0], normalIndices[1], normalIndices[2]);

        file << "f ";

        for (size_t j = 0; j < 3; j++) {
            file << vertexIndices[j] + 1;

            if (hasTextureCoordinates)
                file << '/' << textureIndices[j] + 1;

            if (hasNormals) {
                if (!hasTextureCoordinates)
                    file << '/';

                file << '/' << normalIndices[j] + 1;
            }

            if (j < 2)
                file << ' ';
        }

        if (i < triangleCount - 1)
            file << std::endl;
    }

    file.close();

    return true;
}

Vector3 barycentric(
    const Vector3 & point,
    const Vector3 & vertex0, const Vector3 & vertex1, const Vector3 & vertex2) {
    Vector3 v0 = vertex1 - vertex0;
    Vector3 v1 = vertex2 - vertex0;
    Vector3 v2 = point - vertex0;

    double inverseD = 1.0 / (v0.x * v1.y - v0.y * v1.x);

    double v = (v2.x * v1.y - v2.y * v1.x) * inverseD;
    double w = (v0.x * v2.y - v0.y * v2.x) * inverseD;

    return Vector3(1.0 - v - w, v, w);
}
Vector3 calculateNormal(
    const Vector3 & vertex0, const Vector3 & vertex1, const Vector3 & vertex2) {
    return (vertex1 - vertex0).cross(vertex2 - vertex0).normalize();
}

size_t time() {
    std::chrono::system_clock::time_point time = std::chrono::system_clock::now();
    std::chrono::system_clock::duration duration = time.time_since_epoch();

    return (size_t)std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

void randomSeed(size_t seed) {
    std::srand(seed);
}
double uniformRandom() {
    return std::rand() / (RAND_MAX + 1.0);
}
Vector2 uniformSampleDisk(const Vector2 & sample) {
    double radius = std::sqrt(sample.x);
    double theta = 2.0 * AURORA_PI * sample.y;

    return radius * Vector2(std::cos(theta), std::sin(theta));
}
Vector2 concentricSampleDisk(const Vector2 & sample) {
    Vector2 offset = 2.0 * sample - Vector2(1.0, 1.0);
    
    if (offset.x == 0 && offset.y == 0)
        return Vector2(0, 0);
    
    double radius, theta;
    
    if (std::abs(offset.x) > std::abs(offset.y)) {
        radius = offset.x;
        theta = 0.25 * AURORA_PI * offset.y / offset.x;
    }
    else {
        radius = offset.y;
        theta = AURORA_PI * (0.5 - 0.25 * offset.x / offset.y);
    }
    
    return radius * Vector2(std::cos(theta), std::sin(theta));
}
Vector3 uniformSampleHemisphere(const Vector2 & sample) {
    double z = 1.0 - sample.x;
    double s = std::sqrt(1.0 - z * z);
    double phi = 2.0 * AURORA_PI * sample.y;

    return Vector3(s * std::cos(phi), s * std::sin(phi), z);
}
Vector3 uniformSampleCosineWeightedHemisphere(const Vector2 & sample) {
    double s = std::sqrt(sample.x);
    double phi = 2.0 * AURORA_PI * sample.y;

    return Vector3(s * std::cos(phi), s * std::sin(phi), std::sqrt(1.0 - sample.x));
}
Vector3 uniformSampleTriangle(const Vector2 & sample) {
    double s = std::sqrt(sample.x);
    double u = 1.0 - s;
    double v = s * sample.y;

    return Vector3(u, v, 1.0 - u - v);
}

Color3 toColor3(const Vector3 & vector3) {
	return Color3(vector3.x, vector3.y, vector3.z);
}
Color4 toColor4(const Vector3 & vector3) {
	return Color4(vector3.x, vector3.y, vector3.z, 1.0);
}

AURORA_NAMESPACE_END
