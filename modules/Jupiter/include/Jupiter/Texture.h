/*
 * Texture.h
 *
 *  Created on: 25 ��� 2014 �.
 *      Author: Admin
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <memory>
#include <GL/glew.h>

namespace jupiter
{

class TextureImpl;

class Texture
{
public:
    Texture() = default;
    Texture(const std::string& texture);

    void bind() const;

    int getWidth() const;
    int getHeight() const;

private:
    std::shared_ptr<TextureImpl> _impl;
};

} /* namespace ndk_game */

#endif /* TEXTURE_H_ */
