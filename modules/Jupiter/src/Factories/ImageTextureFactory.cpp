/*
 * ImageTextureBuilder.cpp
 *
 *  Created on: Dec 15, 2014
 *      Author: pavel
 */

#include <GL/glew.h>

#include <Jupiter/Image.h>
#include <Jupiter/Tools.h>

#include "ImageTextureFactory.h"
#include "../TextureImpl.h"

namespace jupiter
{

using namespace std;

std::shared_ptr<TextureImpl> ImageTextureFactory::create(const std::string& texture)
{
    Image im{texture};

    GLuint textureId = 0;

    glGenTextures(1, &textureId);
    Tools::glError();

    glBindTexture(GL_TEXTURE_2D, textureId);
    Tools::glError();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    auto type = im.getType() == Image::Type::RGBA ? GL_RGBA : GL_RGB;

    auto wp2 = upperPowerOfTwo(im.getWidth()), hp2 = upperPowerOfTwo(im.getHeight());

    glTexImage2D(GL_TEXTURE_2D, 0, type, wp2, hp2, 0, type, GL_UNSIGNED_BYTE, im.getData());
    Tools::glError();

    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, im.getWidth(), im.getHeight(), GL_UNSIGNED_BYTE, type, im.getData());
    Tools::glError();

    return make_shared<TextureImpl>(textureId, type, wp2, hp2);
}

} /* namespace jupiter */
