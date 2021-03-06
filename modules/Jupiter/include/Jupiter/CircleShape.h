/*
 * CircleShape.h
 *
 *  Created on: Jun 3, 2015
 *      Author: pavel
 */

#ifndef MODULES_JUPITER_INCLUDE_JUPITER_CIRCLESHAPE_H_
#define MODULES_JUPITER_INCLUDE_JUPITER_CIRCLESHAPE_H_

#ifdef SWIG
#else
    #include <Box2D/Box2D.h>
#endif

#include "PhysicsShape.h"

namespace jupiter {

class Image;

class CircleShape: public PhysicsShape {
public:
    CircleShape(Image*, b2FixtureDef, float scale = 1.f);
    virtual ~CircleShape();

    virtual void setScale(float x, float y);
    virtual float getScaleX() const;
    virtual float getScaleY() const;
    virtual int shapesCount() const;
    virtual b2FixtureDef* getFixtureDef(int index);

protected:
    float _radius = 0.f, _scale = 1.f;
    b2FixtureDef  _fixtureDef;
    b2CircleShape _shape;
};

} /* namespace jupiter */

#endif /* MODULES_JUPITER_INCLUDE_JUPITER_CIRCLESHAPE_H_ */
