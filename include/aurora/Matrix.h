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

// Evita redefinição de símbolos do arquivo de cabeçalho (caso já tenha sido incluído)
#ifndef AURORA_MATRIX_H
#define AURORA_MATRIX_H

#include <aurora/Global.h>

#include <ostream>

// Início de "namespace" da biblioteca
AURORA_NAMESPACE_BEGIN

// Declaração de tipo incompleto no cabeçalho evita dependência cíclica de arquivos
class Vector2;
class Vector3;

// Matriz real 2x2
class Matrix2 {
private:
    // Elementos da matriz
    double m[2][2];

public:
    // Construtor padrão (matriz zero)
    Matrix2();
    // Construtor cópia
    Matrix2(const Matrix2 & matrix2);
    // Construtor para valores iniciais
    Matrix2(
        double m00, double m01,
        double m10, double m11);
    // Destrutor padrão
    ~Matrix2();

    // Sobrecarga da operação "matriz[i]" permite operação "matriz[i][j]" (retorno mutável)
    double * operator [](size_t i);
    // Sobrecarga da operação "matriz[i]" permite operação "matriz[i][j]" (retorno imutável)
    const double * operator [](size_t i) const;
    // Sobrecarga da operação "+matriz"
    Matrix2 operator +() const;
    // Sobrecarga da operação "-matriz"
    Matrix2 operator -() const;
    // Sobrecarga da operação "matrizA + matrizB"
    Matrix2 operator +(const Matrix2 & rhs) const;
    // Sobrecarga da operação "matrizA - matrizB"
    Matrix2 operator -(const Matrix2 & rhs) const;
    // Sobrecarga da operação "matrizA * matrizB"
    Matrix2 operator *(const Matrix2 & rhs) const;
    // Sobrecarga da operação "matriz * escalar"
    Matrix2 operator *(double rhs) const;
    // Sobrecarga da operação "escalar * matriz"
    friend Matrix2 operator *(double lhs, const Matrix2 & rhs);
    // Sobrecarga da operação "matrizA / matrizB" realiza operação "matrizA.inverse(matrizB)"
    Matrix2 operator /(const Matrix2 & rhs) const;
    // Sobrecarga da operação "matriz / escalar"
    Matrix2 operator /(double rhs) const;
    // Sobrecarga da operação "matrizA += matrizB"
    Matrix2 & operator +=(const Matrix2 & rhs);
    // Sobrecarga da operação "matrizA -= matrizB"
    Matrix2 & operator -=(const Matrix2 & rhs);
    // Sobrecarga da operação "matrizA *= matrizB"
    Matrix2 & operator *=(const Matrix2 & rhs);
    // Sobrecarga da operação "matriz *= escalar"
    Matrix2 & operator *=(double rhs);
    // Sobrecarga da operação "matrizA /= matrizB" realiza operação "matrizA = matrizA.inverse(matrizB)"
    Matrix2 & operator /=(const Matrix2 & rhs);
    // Sobrecarga da operação "matriz /= escalar"
    Matrix2 & operator /=(double rhs);
    // Sobrecarga da operação "matrizA == matrizB"
    bool operator ==(const Matrix2 & rhs) const;
    // Sobrecarga da operação "matrizA != matrizB"
    bool operator !=(const Matrix2 & rhs) const;
    // Sobrecarga da operação "saída << matriz" (imprimir saída de dados)
    friend std::ostream & operator <<(std::ostream & lhs, const Matrix2 & rhs);

    // Retorna determinante
    double determinant() const;
    // Retorna traço
    double trace() const;
    // Retorna menor da submatriz sem a linha "i" e coluna "j"
    double minor(size_t i, size_t j) const;
    // Transpõe matriz (matriz transposta)
    Matrix2 & transpose();
    // Retorna inversa
    Matrix2 inverse() const;
    // Retorna adjunta
    Matrix2 adjugate() const;
};

// Matriz real 3x3
class Matrix3 {
private:
    // Elementos da matriz
    double m[3][3];

public:
    // Construtor padrão (matriz zero)
    Matrix3();
    // Construtor cópia
    Matrix3(const Matrix3 & matrix3);
    // Construtor para valores iniciais
    Matrix3(
        double m00, double m01, double m02,
        double m10, double m11, double m12,
        double m20, double m21, double m22);
    // Destrutor padrão
    ~Matrix3();

    // Sobrecarga da operação "matriz[i]" permite operação "matriz[i][j]" (retorno mutável)
    double * operator [](size_t i);
    // Sobrecarga da operação "matriz[i]" permite operação "matriz[i][j]" (retorno imutável)
    const double * operator [](size_t i) const;
    // Sobrecarga da operação "+matriz"
    Matrix3 operator +() const;
    // Sobrecarga da operação "-matriz"
    Matrix3 operator -() const;
    // Sobrecarga da operação "matrizA + matrizB"
    Matrix3 operator +(const Matrix3 & rhs) const;
    // Sobrecarga da operação "matrizA - matrizB"
    Matrix3 operator -(const Matrix3 & rhs) const;
    // Sobrecarga da operação "matrizA * matrizB"
    Matrix3 operator *(const Matrix3 & rhs) const;
    // Sobrecarga da operação "matriz * escalar"
    Matrix3 operator *(double rhs) const;
    // Sobrecarga da operação "escalar * matriz"
    friend Matrix3 operator *(double lhs, const Matrix3 & rhs);
    // Sobrecarga da operação "matrizA / matrizB" realiza operação "matrizA.inverse(matrizB)"
    Matrix3 operator /(const Matrix3 & rhs) const;
    // Sobrecarga da operação "matriz / escalar"
    Matrix3 operator /(double rhs) const;
    // Sobrecarga da operação "matrizA += matrizB"
    Matrix3 & operator +=(const Matrix3 & rhs);
    // Sobrecarga da operação "matrizA -= matrizB"
    Matrix3 & operator -=(const Matrix3 & rhs);
    // Sobrecarga da operação "matrizA *= matrizB"
    Matrix3 & operator *=(const Matrix3 & rhs);
    // Sobrecarga da operação "matriz *= escalar"
    Matrix3 & operator *=(double rhs);
    // Sobrecarga da operação "matrizA /= matrizB" realiza operação "matrizA = matrizA.inverse(matrizB)"
    Matrix3 & operator /=(const Matrix3 & rhs);
    // Sobrecarga da operação "matriz /= escalar"
    Matrix3 & operator /=(double rhs);
    // Sobrecarga da operação "matrizA == matrizB"
    bool operator ==(const Matrix3 & rhs) const;
    // Sobrecarga da operação "matrizA != matrizB"
    bool operator !=(const Matrix3 & rhs) const;
    // Sobrecarga da operação "saída << matriz" (imprimir saída de dados)
    friend std::ostream & operator <<(std::ostream & lhs, const Matrix3 & rhs);

    // Configura como matriz identidade
    Matrix3 & setIdentity();
    // Configura como matriz de translação "T" a partir dos deslocamentos "(dx, dy)"
    Matrix3 & setTranslation(const Vector2 & translation);
    // Configura como matriz de rotação "R" anti-horária a partir de um ângulo de Euler "a" em radiano
    Matrix3 & setRotation(double rotation);
    // Configura como matriz de escala "S" a partir dos fatores de escala "(sx, sy)"
    Matrix3 & setScaling(const Vector2 & scaling);
    // Configura como matriz de deformação "Sh" a partir dos componentes de deformação "(shx, shy)"
    Matrix3 & setShearing(const Vector2 & shearing);
    // Configura como matriz de transformação "M = S Sh R T"
    Matrix3 & setTransformation(
        const Vector2 & translation, double rotation,
        const Vector2 & scaling, const Vector2 & shearing);

    // Retorna determinante
    double determinant() const;
    // Retorna traço
    double trace() const;
    // Retorna menor da submatriz sem a linha "i" e coluna "j"
    double minor(size_t i, size_t j) const;
    // Transpõe matriz (matriz transposta)
    Matrix3 & transpose();
    // Retorna inversa
    Matrix3 inverse() const;
    // Retorna adjunta
    Matrix3 adjugate() const;
};

// Matriz real 4x4
class Matrix4 {
private:
    // Elementos da matriz
    double m[4][4];

public:
    // Construtor padrão (matriz zero)
    Matrix4();
    // Construtor cópia
    Matrix4(const Matrix4 & matrix4);
    // Construtor para valores iniciais
    Matrix4(
        double m00, double m01, double m02, double m03,
        double m10, double m11, double m12, double m13,
        double m20, double m21, double m22, double m23,
        double m30, double m31, double m32, double m33);
    // Destrutor padrão
    ~Matrix4();

    // Sobrecarga da operação "matriz[i]" permite operação "matriz[i][j]" (retorno mutável)
    double * operator [](size_t i);
    // Sobrecarga da operação "matriz[i]" permite operação "matriz[i][j]" (retorno imutável)
    const double * operator [](size_t i) const;
    // Sobrecarga da operação "+matriz"
    Matrix4 operator +() const;
    // Sobrecarga da operação "-matriz"
    Matrix4 operator -() const;
    // Sobrecarga da operação "matrizA + matrizB"
    Matrix4 operator +(const Matrix4 & rhs) const;
    // Sobrecarga da operação "matrizA - matrizB"
    Matrix4 operator -(const Matrix4 & rhs) const;
    // Sobrecarga da operação "matrizA * matrizB"
    Matrix4 operator *(const Matrix4 & rhs) const;
    // Sobrecarga da operação "matriz * escalar"
    Matrix4 operator *(double rhs) const;
    // Sobrecarga da operação "escalar * matriz"
    friend Matrix4 operator *(double lhs, const Matrix4 & rhs);
    // Sobrecarga da operação "matrizA / matrizB" realiza operação "matrizA.inverse(matrizB)"
    Matrix4 operator /(const Matrix4 & rhs) const;
    // Sobrecarga da operação "matriz / escalar"
    Matrix4 operator /(double rhs) const;
    // Sobrecarga da operação "matrizA += matrizB"
    Matrix4 & operator +=(const Matrix4 & rhs);
    // Sobrecarga da operação "matrizA -= matrizB"
    Matrix4 & operator -=(const Matrix4 & rhs);
    // Sobrecarga da operação "matrizA *= matrizB"
    Matrix4 & operator *=(const Matrix4 & rhs);
    // Sobrecarga da operação "matriz *= escalar"
    Matrix4 & operator *=(double rhs);
    // Sobrecarga da operação "matrizA /= matrizB" realiza operação "matrizA = matrizA.inverse(matrizB)"
    Matrix4 & operator /=(const Matrix4 & rhs);
    // Sobrecarga da operação "matriz /= escalar"
    Matrix4 & operator /=(double rhs);
    // Sobrecarga da operação "matrizA == matrizB"
    bool operator ==(const Matrix4 & rhs) const;
    // Sobrecarga da operação "matrizA != matrizB"
    bool operator !=(const Matrix4 & rhs) const;
    // Sobrecarga da operação "saída << matriz" (imprimir saída de dados)
    friend std::ostream & operator <<(std::ostream & lhs, const Matrix4 & rhs);

    // Configura como matriz identidade
    Matrix4 & setIdentity();
    // Configura como matriz de translação "T" a partir dos deslocamentos "(dx, dy, dz)"
    Matrix4 & setTranslation(const Vector3 & translation);
    // Configura como matriz de rotação "R = Rx Ry Rz" anti-horária a partir dos ângulos de Euler "(ax, ay, az)" em radiano
    Matrix4 & setRotation(const Vector3 & rotation);
    // Configura como matriz de escala "S" a partir dos fatores de escala "(sx, sy, sz)"
    Matrix4 & setScaling(const Vector3 & scaling);
    // Configura como matriz de deformação "Sh" a partir dos componentes de deformação "(shxy, shxz, shyz)"
    Matrix4 & setShearing(const Vector3 & shearing);
    // Configura como matriz de transformação "M = S Sh R T"
    Matrix4 & setTransformation(
        const Vector3 & translation, const Vector3 & rotation,
        const Vector3 & scaling, const Vector3 & shearing);

    // Retorna determinante
    double determinant() const;
    // Retorna traço
    double trace() const;
    // Retorna menor da submatriz sem a linha "i" e coluna "j"
    double minor(size_t i, size_t j) const;
    // Transpõe matriz (matriz transposta)
    Matrix4 & transpose();
    // Retorna inversa
    Matrix4 inverse() const;
    // Retorna adjunta
    Matrix4 adjugate() const;
};

// Fim de "namespace" da biblioteca
AURORA_NAMESPACE_END

#endif
