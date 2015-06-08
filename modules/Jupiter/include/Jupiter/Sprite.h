/*
 * Sprite.h
 *
 *  Created on: 25 ��� 2014 �.
 *      Author: Admin
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#ifdef SWIG
#else
    #include <memory>
#endif

#include "Jupiter/Texture.h"
#include "Jupiter/Shape.h"
#include "Jupiter/Shader.h"
#include "Jupiter/Node.h"

namespace jupiter {

//class Shape;
//class Texture;
//class Shader;

class Sprite: virtual public Node {
public:
    Sprite() = default;
    virtual ~Sprite() = default;

    Sprite(const Sprite&);
    virtual Sprite* clone(Sprite*);

    Texture* getTexture();
    Sprite* setTexture(Texture*);

    Shape* getShape();
    Sprite* setShape(Shape*);

    Shader* getProgram();
    Sprite* setProgram(Shader*);

    virtual Sprite* accept(NodeVisitor* nv);
protected:
    Ref<Texture> _texture;
    Ref<Shape>   _shape;
    Ref<Shader>  _program;

    Sprite& operator=(const Sprite&) = default;
};

} /* namespace ndk_game */

#endif /* SPRITE_H_ */
