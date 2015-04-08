/*
 * FileShader.cpp
 *
 *  Created on: 19 марта 2015 г.
 *      Author: pavel
 */

#include <iterator>
#include "Jupiter/File.h"
#include "Jupiter/FileShader.h"

namespace jupiter {

using namespace std;

FileShader::FileShader(class File* vertex, class File* fragment) {
    string vertexShaderSource { (istreambuf_iterator<char>(vertex->getStream())), istreambuf_iterator<char>() };
    string fragmentShaderSource { (istreambuf_iterator<char>(fragment->getStream())), istreambuf_iterator<char>() };
    _program = createProgram(vertexShaderSource, fragmentShaderSource);
}

FileShader::~FileShader() {
    glDeleteProgram(_program);
}

} /* namespace jupiter */
