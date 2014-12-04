/*
 * TextureLoader.h
 *
 *  Created on: May 25, 2014
 *      Author: ingener
 */

#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include <Jupiter/Image.h>

namespace jupiter
{

class TextureLoader
{
public:
    TextureLoader();
    virtual ~TextureLoader();

    virtual Image load();

private:
    Image _image;
};

} /* namespace ndk_game */

#endif /* TEXTURELOADER_H_ */
