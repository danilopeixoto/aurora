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

#include <aurora/TriangleMesh.h>
#include <aurora/Vector.h>
#include <aurora/Matrix.h>

AURORA_NAMESPACE_BEGIN

TriangleMesh::TriangleMesh() {}
TriangleMesh::TriangleMesh(const TriangleMesh & triangleMesh) {
    create(triangleMesh);
}
TriangleMesh::TriangleMesh(size_t vertexCount, size_t triangleCount,
    size_t normalCount, size_t textureCoordinateCount) {
    create(vertexCount, triangleCount, normalCount, textureCoordinateCount);
}
TriangleMesh::TriangleMesh(
    const std::vector<Vector3> & vertices,
    const std::vector<size_t> & vertexIndices) {
    create(vertices, vertexIndices);
}
TriangleMesh::TriangleMesh(
    const std::vector<Vector3> & vertices,
    const std::vector<Vector3> & normals,
    const std::vector<size_t> & vertexIndices,
    const std::vector<size_t> & normalIndices) {
    create(vertices, normals, vertexIndices, normalIndices);
}
TriangleMesh::TriangleMesh(
    const std::vector<Vector3> & vertices,
    const std::vector<Vector3> & normals,
    const std::vector<Vector2> & textureCoordinates,
    const std::vector<size_t> & vertexIndices,
    const std::vector<size_t> & normalIndices,
    const std::vector<size_t> & textureIndices) {
    create(vertices, normals, textureCoordinates,
        vertexIndices, normalIndices, textureIndices);
}
TriangleMesh::~TriangleMesh() {}

bool TriangleMesh::operator ==(const TriangleMesh & rhs) const {
    return vertices == rhs.vertices
        && normals == rhs.normals
        && textureCoordinates == rhs.textureCoordinates
        && vertexIndices == rhs.vertexIndices
        && normalIndices == rhs.normalIndices
        && textureIndices == rhs.textureIndices;
}
bool TriangleMesh::operator !=(const TriangleMesh & rhs) const {
    return !(*this == rhs);
}
std::ostream & operator <<(std::ostream & lhs, const TriangleMesh & rhs) {
    return lhs << "Vertices: " << rhs.getVertexCount() << std::endl
        << "Triangles: " << rhs.getTriangleCount() << std::endl
        << "Normals: " << rhs.getNormalCount() << std::endl
        << "Texture coordinates: " << rhs.getTextureCoordinateCount();
}

TriangleMesh & TriangleMesh::setVertices(const std::vector<Vector3> & vertices) {
    this->vertices = vertices;
    return *this;
}
TriangleMesh & TriangleMesh::setNormals(const std::vector<Vector3> & normals) {
    this->normals = normals;
    return *this;
}
TriangleMesh & TriangleMesh::setTextureCoordinates(const std::vector<Vector2> & textureCoordinates) {
    this->textureCoordinates = textureCoordinates;
    return *this;
}
TriangleMesh & TriangleMesh::setVertexIndices(const std::vector<size_t> & vertexIndices) {
    this->vertexIndices = vertexIndices;
    return *this;
}
TriangleMesh & TriangleMesh::setNormalIndices(const std::vector<size_t> & normalIndices) {
    this->normalIndices = normalIndices;
    return *this;
}
TriangleMesh & TriangleMesh::setTextureIndices(const std::vector<size_t> & textureIndices) {
    this->textureIndices = textureIndices;
    return *this;
}
TriangleMesh & TriangleMesh::setVertex(size_t i, const Vector3 & vertex) {
    vertices[i] = vertex;
    return *this;
}
TriangleMesh & TriangleMesh::setNormal(size_t i, const Vector3 & normal) {
    normals[i] = normal;
    return *this;
}
TriangleMesh & TriangleMesh::setTextureCoordinates(size_t i, const Vector2 & textureCoordinates) {
    this->textureCoordinates[i] = textureCoordinates;
    return *this;
}
TriangleMesh & TriangleMesh::setVertexIndices(size_t i, size_t v0, size_t v1, size_t v2) {
    vertexIndices[i * 3] = v0;
    vertexIndices[i * 3 + 1] = v1;
    vertexIndices[i * 3 + 2] = v2;

    return *this;
}
TriangleMesh & TriangleMesh::setNormalIndices(size_t i, size_t v0, size_t v1, size_t v2) {
    normalIndices[i * 3] = v0;
    normalIndices[i * 3 + 1] = v1;
    normalIndices[i * 3 + 2] = v2;

    return *this;
}
TriangleMesh & TriangleMesh::setTextureIndices(size_t i, size_t v0, size_t v1, size_t v2) {
    textureIndices[i * 3] = v0;
    textureIndices[i * 3 + 1] = v1;
    textureIndices[i * 3 + 2] = v2;

    return *this;
}
const std::vector<Vector3> & TriangleMesh::getVertices() const {
    return vertices;
}
const std::vector<Vector3> & TriangleMesh::getNormals() const {
    return normals;
}
const std::vector<Vector2> & TriangleMesh::getTextureCoordinates() const {
    return textureCoordinates;
}
const std::vector<size_t> & TriangleMesh::getVertexIndices() const {
    return vertexIndices;
}
const std::vector<size_t> & TriangleMesh::getNormalIndices() const {
    return normalIndices;
}
const std::vector<size_t> & TriangleMesh::getTextureIndices() const {
    return textureIndices;
}
const Vector3 & TriangleMesh::getVertex(size_t i) const {
    return vertices[i];
}
const Vector3 & TriangleMesh::getNormal(size_t i) const {
    return normals[i];
}
const Vector2 & TriangleMesh::getTextureCoordinates(size_t i) const {
    return textureCoordinates[i];
}
void TriangleMesh::getVertexIndices(size_t i, size_t & v0, size_t & v1, size_t & v2) const {
    v0 = vertexIndices[i * 3];
    v1 = vertexIndices[i * 3 + 1];
    v2 = vertexIndices[i * 3 + 2];
}
void TriangleMesh::getNormalIndices(size_t i, size_t & v0, size_t & v1, size_t & v2) const {
    v0 = normalIndices[i * 3];
    v1 = normalIndices[i * 3 + 1];
    v2 = normalIndices[i * 3 + 2];
}
void TriangleMesh::getTextureIndices(size_t i, size_t & v0, size_t & v1, size_t & v2) const {
    v0 = textureIndices[i * 3];
    v1 = textureIndices[i * 3 + 1];
    v2 = textureIndices[i * 3 + 2];
}
size_t TriangleMesh::getVertexCount() const {
    return vertices.size();
}
size_t TriangleMesh::getNormalCount() const {
    return normals.size();
}
size_t TriangleMesh::getTextureCoordinateCount() const {
    return textureCoordinates.size();
}
size_t TriangleMesh::getTriangleCount() const {
    return vertexIndices.size() / 3;
}
bool TriangleMesh::hasNormals() const {
    return !normalIndices.empty();
}
bool TriangleMesh::hasTextureCoordinates() const {
    return !textureIndices.empty();
}

TriangleMesh & TriangleMesh::create(const TriangleMesh & triangleMesh) {
    vertices = triangleMesh.vertices;
    normals = triangleMesh.normals;
    textureCoordinates = triangleMesh.textureCoordinates;
    vertexIndices = triangleMesh.vertexIndices;
    normalIndices = triangleMesh.normalIndices;
    textureIndices = triangleMesh.textureIndices;

    return *this;
}
TriangleMesh & TriangleMesh::create(
    size_t vertexCount, size_t triangleCount,
    size_t normalCount, size_t textureCoordinateCount) {
    vertices.clear();
    normals.clear();
    textureCoordinates.clear();
    vertexIndices.clear();
    normalIndices.clear();
    textureIndices.clear();

    vertices.resize(vertexCount);
    normals.resize(normalCount);
    textureCoordinates.resize(textureCoordinateCount);

    size_t size = triangleCount * 3;

    vertexIndices.resize(size);
    normalIndices.resize(normalCount ? size : 0);
    textureIndices.resize(textureCoordinateCount ? size : 0);

    return *this;
}
TriangleMesh & TriangleMesh::create(
    const std::vector<Vector3> & vertices,
    const std::vector<size_t> & vertexIndices) {
    this->vertices = vertices;
    this->vertexIndices = vertexIndices;

    normals.clear();
    textureCoordinates.clear();
    normalIndices.clear();
    textureIndices.clear();

    return *this;
}
TriangleMesh & TriangleMesh::create(
    const std::vector<Vector3> & vertices,
    const std::vector<Vector3> & normals,
    const std::vector<size_t> & vertexIndices,
    const std::vector<size_t> & normalIndices) {
    this->vertices = vertices;
    this->normals = normals;
    this->vertexIndices = vertexIndices;
    this->normalIndices = normalIndices;

    textureCoordinates.clear();
    textureIndices.clear();

    return *this;
}
TriangleMesh & TriangleMesh::create(
    const std::vector<Vector3> & vertices,
    const std::vector<Vector3> & normals,
    const std::vector<Vector2> & textureCoordinates,
    const std::vector<size_t> & vertexIndices,
    const std::vector<size_t> & normalIndices,
    const std::vector<size_t> & textureIndices) {
    this->vertices = vertices;
    this->normals = normals;
    this->textureCoordinates = textureCoordinates;
    this->vertexIndices = vertexIndices;
    this->normalIndices = normalIndices;
    this->textureIndices = textureIndices;

    return *this;
}

AURORA_NAMESPACE_END
