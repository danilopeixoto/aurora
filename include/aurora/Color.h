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
#ifndef AURORA_COLOR_H
#define AURORA_COLOR_H

#include <aurora/Global.h>

#include <ostream>

// Início de "namespace" da biblioteca
AURORA_NAMESPACE_BEGIN

// Cor RGB linear
class Color3 {
public:
    // Componentes de cor
    double r, g, b;

    // Construtor padrão (cor preta)
    Color3();
    // Construtor cópia
    Color3(const Color3 & color3);
    // Construtor para valores iniciais
    Color3(double r, double g, double b);
    // Destrutor padrão
    ~Color3();

    // Sobrecarga da operação "cor[i]" (retorno mutável)
    double & operator [](size_t i);
    // Sobrecarga da operação "cor[i]" (retorno imutável)
    const double & operator [](size_t i) const;
    // Sobrecarga da operação "+cor"
    Color3 operator +() const;
    // Sobrecarga da operação "-cor"
    Color3 operator -() const;
    // Sobrecarga da operação "corA + corB"
    Color3 operator +(const Color3 & rhs) const;
    // Sobrecarga da operação "corA - corB"
    Color3 operator -(const Color3 & rhs) const;
    // Sobrecarga da operação "corA * corB"
    Color3 operator *(const Color3 & rhs) const;
    // Sobrecarga da operação "cor * escalar"
    Color3 operator *(double rhs) const;
    // Sobrecarga da operação "escalar * cor"
    friend Color3 operator *(double lhs, const Color3 & rhs);
    // Sobrecarga da operação "corA / corB"
    Color3 operator /(const Color3 & rhs) const;
    // Sobrecarga da operação "cor / escalar"
    Color3 operator /(double rhs) const;
    // Sobrecarga da operação "corA += corB"
    Color3 & operator +=(const Color3 & rhs);
    // Sobrecarga da operação "corA -= corB"
    Color3 & operator -=(const Color3 & rhs);
    // Sobrecarga da operação "corA *= corB"
    Color3 & operator *=(const Color3 & rhs);
    // Sobrecarga da operação "cor *= escalar"
    Color3 & operator *=(double rhs);
    // Sobrecarga da operação "corA /= corB"
    Color3 & operator /=(const Color3 & rhs);
    // Sobrecarga da operação "cor /= escalar"
    Color3 & operator /=(double rhs);
    // Sobrecarga da operação "corA == corB"
    bool operator ==(const Color3 & rhs) const;
    // Sobrecarga da operação "corA != corB"
    bool operator !=(const Color3 & rhs) const;
    // Sobrecarga da operação "saída << cor" (imprimir saída de dados)
    friend std::ostream & operator <<(std::ostream & lhs, const Color3 & rhs);

    // Aplica correção gamma à cor
    Color3 & applyGamma(double gamma);
    // Aplica correção de exposição à cor
    Color3 & applyExposure(double exposure);
    // Satura cor (linear)
    Color3 & saturate();
};

// Cor RGBA linear
class Color4 {
public:
    // Componentes de cor
    double r, g, b, a;

    // Construtor padrão (transparente)
    Color4();
    // Construtor cópia
    Color4(const Color4 & color4);
    // Construtor para valores iniciais
    Color4(double r, double g, double b, double a);
    // Destrutor padrão
    ~Color4();

    // Sobrecarga da operação "cor[i]" (retorno mutável)
    double & operator [](size_t i);
    // Sobrecarga da operação "cor[i]" (retorno imutável)
    const double & operator [](size_t i) const;
    // Sobrecarga da operação "+cor"
    Color4 operator +() const;
    // Sobrecarga da operação "-cor"
    Color4 operator -() const;
    // Sobrecarga da operação "corA + corB"
    Color4 operator +(const Color4 & rhs) const;
    // Sobrecarga da operação "corA - corB"
    Color4 operator -(const Color4 & rhs) const;
    // Sobrecarga da operação "corA * corB"
    Color4 operator *(const Color4 & rhs) const;
    // Sobrecarga da operação "cor * escalar"
    Color4 operator *(double rhs) const;
    // Sobrecarga da operação "escalar * cor"
    friend Color4 operator *(double lhs, const Color4 & rhs);
    // Sobrecarga da operação "corA / corB"
    Color4 operator /(const Color4 & rhs) const;
    // Sobrecarga da operação "cor / escalar"
    Color4 operator /(double rhs) const;
    // Sobrecarga da operação "corA += corB"
    Color4 & operator +=(const Color4 & rhs);
    // Sobrecarga da operação "corA -= corB"
    Color4 & operator -=(const Color4 & rhs);
    // Sobrecarga da operação "corA *= corB"
    Color4 & operator *=(const Color4 & rhs);
    // Sobrecarga da operação "cor *= escalar"
    Color4 & operator *=(double rhs);
    // Sobrecarga da operação "corA /= corB"
    Color4 & operator /=(const Color4 & rhs);
    // Sobrecarga da operação "cor /= escalar"
    Color4 & operator /=(double rhs);
    // Sobrecarga da operação "corA == corB"
    bool operator ==(const Color4 & rhs) const;
    // Sobrecarga da operação "corA != corB"
    bool operator !=(const Color4 & rhs) const;
    // Sobrecarga da operação "saída << cor" (imprimir saída de dados)
    friend std::ostream & operator <<(std::ostream & lhs, const Color4 & rhs);

    // Aplica correção gamma à cor
    Color4 & applyGamma(double gamma);
    // Aplica correção de exposição à cor
    Color4 & applyExposure(double exposure);
    // Satura cor (linear)
    Color4 & saturate();
};

// Fim de "namespace" da biblioteca
AURORA_NAMESPACE_END

#endif
