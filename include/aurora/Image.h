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
#ifndef AURORA_IMAGE_H
#define AURORA_IMAGE_H

#include <aurora/Global.h>

#include <vector>
#include <ostream>

// Início de "namespace" da biblioteca
AURORA_NAMESPACE_BEGIN

// Declaração de tipo incompleto no cabeçalho evita dependência cíclica de arquivos
class Color3;
class Color4;

// Imagem de pixels RGB
class Image3 {
private:
    size_t width; // Resolução horizontal
    size_t height; // Resolução vertical
    std::vector<Color3> pixels; // Matriz de pixels RGB no formato linha majoritária

public:
    // Construtor padrão (imagem nula)
    Image3();
    // Construtor cópia
    Image3(const Image3 & image3);
    // Construtor para alocação de pixels RGB
    Image3(size_t width, size_t height);
    // Construtor para parâmetros iniciais
    Image3(size_t width, size_t height, const std::vector<Color3> & pixels);
    // Destrutor padrão
    ~Image3();

    // Sobrecarga da operação "imagem[i]" (retorno mutável)
    Color3 & operator [](size_t i);
    // Sobrecarga da operação "imagem[i]" (retorno imutável)
    const Color3 & operator [](size_t i) const;
    // Sobrecarga da operação "imagem(i, j)" (retorno mutável)
    Color3 & operator ()(size_t i, size_t j);
    // Sobrecarga da operação "imagem(i, j)" (retorno imutável)
    const Color3 & operator ()(size_t i, size_t j) const;
    // Sobrecarga da operação "+imagem"
    Image3 operator +() const;
    // Sobrecarga da operação "-imagem"
    Image3 operator -() const;
    // Sobrecarga da operação "imagemA + imagemB"
    Image3 operator +(const Image3 & rhs) const;
    // Sobrecarga da operação "imagemA - imagemB"
    Image3 operator -(const Image3 & rhs) const;
    // Sobrecarga da operação "imagem * escalar"
    Image3 operator *(double rhs) const;
    // Sobrecarga da operação "escalar * imagem"
    friend Image3 operator *(double lhs, const Image3 & rhs);
    // Sobrecarga da operação "imagem / escalar"
    Image3 operator /(double rhs) const;
    // Sobrecarga da operação "imagemA += imagemB"
    Image3 & operator +=(const Image3 & rhs);
    // Sobrecarga da operação "imagemA -= imagemB"
    Image3 & operator -=(const Image3 & rhs);
    // Sobrecarga da operação "imagem *= escalar"
    Image3 & operator *=(double rhs);
    // Sobrecarga da operação "imagem /= escalar"
    Image3 & operator /=(double rhs);
    // Sobrecarga da operação "imagemA == imagemB"
    bool operator ==(const Image3 & rhs) const;
    // Sobrecarga da operação "imagemA != imagemB"
    bool operator !=(const Image3 & rhs) const;
    // Sobrecarga da operação "saída << imagem" (imprimir informações na saída de dados)
    friend std::ostream & operator <<(std::ostream & lhs, const Image3 & rhs);

    // Configura um pixel RGB pelos índices
    Image3 & setPixel(size_t i, size_t j, const Color3 & pixel);
    // Retorna pixel RGB pelos índices
    const Color3 & getPixel(size_t i, size_t j) const;
    // Retorna resolução horizontal
    size_t getWidth() const;
    // Retorna resolução vertical
    size_t getHeight() const;
    // Retorna número de pixels
    size_t getPixelCount() const;
    // Retorna relação entre resolução horizontal e vertical (proporção)
    double getAspectRatio() const;

    // Cria imagem por cópia
    Image3 & create(const Image3 & image3);
    // Cria imagem alocando memória para pixels RGB
    Image3 & create(size_t width, size_t height);
    // Cria imagem com parâmetros iniciais
    Image3 & create(size_t width, size_t height, const std::vector<Color3> & pixels);

    // Aplica correção gamma à imagem
    Image3 & applyGamma(double gamma);
    // Aplica correção de exposição à imagem
    Image3 & applyExposure(double exposure);
    // Satura cor (linear)
    Image3 & saturate();
};

// Imagem de pixels RGBA
class Image4 {
private:
    size_t width; // Resolução horizontal
    size_t height; // Resolução vertical
    std::vector<Color4> pixels; // Matriz de pixels RGBA no formato linha majoritária

public:
    // Construtor padrão (imagem nula)
    Image4();
    // Construtor cópia
    Image4(const Image4 & image4);
    // Construtor para alocação de pixels RGBA
    Image4(size_t width, size_t height);
    // Construtor para parâmetros iniciais
    Image4(size_t width, size_t height, const std::vector<Color4> & pixels);
    // Destrutor padrão
    ~Image4();

    // Sobrecarga da operação "imagem[i]" (retorno mutável)
    Color4 & operator [](size_t i);
    // Sobrecarga da operação "imagem[i]" (retorno imutável)
    const Color4 & operator [](size_t i) const;
    // Sobrecarga da operação "imagem(i, j)" (retorno mutável)
    Color4 & operator ()(size_t i, size_t j);
    // Sobrecarga da operação "imagem(i, j)" (retorno imutável)
    const Color4 & operator ()(size_t i, size_t j) const;
    // Sobrecarga da operação "+imagem"
    Image4 operator +() const;
    // Sobrecarga da operação "-imagem"
    Image4 operator -() const;
    // Sobrecarga da operação "imagemA + imagemB"
    Image4 operator +(const Image4 & rhs) const;
    // Sobrecarga da operação "imagemA - imagemB"
    Image4 operator -(const Image4 & rhs) const;
    // Sobrecarga da operação "imagem * escalar"
    Image4 operator *(double rhs) const;
    // Sobrecarga da operação "escalar * imagem"
    friend Image4 operator *(double lhs, const Image4 & rhs);
    // Sobrecarga da operação "imagem / escalar"
    Image4 operator /(double rhs) const;
    // Sobrecarga da operação "imagemA += imagemB"
    Image4 & operator +=(const Image4 & rhs);
    // Sobrecarga da operação "imagemA -= imagemB"
    Image4 & operator -=(const Image4 & rhs);
    // Sobrecarga da operação "imagem *= escalar"
    Image4 & operator *=(double rhs);
    // Sobrecarga da operação "imagem /= escalar"
    Image4 & operator /=(double rhs);
    // Sobrecarga da operação "imagemA == imagemB"
    bool operator ==(const Image4 & rhs) const;
    // Sobrecarga da operação "imagemA != imagemB"
    bool operator !=(const Image4 & rhs) const;
    // Sobrecarga da operação "saída << imagem" (imprimir informações na saída de dados)
    friend std::ostream & operator <<(std::ostream & lhs, const Image4 & rhs);

    // Configura um pixel RGBA pelos índices
    Image4 & setPixel(size_t i, size_t j, const Color4 & pixel);
    // Retorna pixel RGBA pelos índices
    const Color4 & getPixel(size_t i, size_t j) const;
    // Retorna resolução horizontal
    size_t getWidth() const;
    // Retorna resolução vertical
    size_t getHeight() const;
    // Retorna número de pixels
    size_t getPixelCount() const;
    // Retorna relação entre resolução horizontal e vertical (proporção)
    double getAspectRatio() const;

    // Cria imagem por cópia
    Image4 & create(const Image4 & image4);
    // Cria imagem alocando memória para pixels RGBA
    Image4 & create(size_t width, size_t height);
    // Cria imagem com parâmetros iniciais
    Image4 & create(size_t width, size_t height, const std::vector<Color4> & pixels);

    // Aplica correção gamma à imagem
    Image4 & applyGamma(double gamma);
    // Aplica correção de exposição à imagem
    Image4 & applyExposure(double exposure);
    // Satura cor (linear)
    Image4 & saturate();
};

// Fim de "namespace" da biblioteca
AURORA_NAMESPACE_END

#endif
