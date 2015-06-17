/*
 * Box2dNode.h
 *
 *  Created on: May 14, 2015
 *      Author: pavel
 */

#ifndef MODULES_JUPITER_INCLUDE_JUPITER_BODY_H_
#define MODULES_JUPITER_INCLUDE_JUPITER_BODY_H_

#ifdef SWIG
#else
    #include <Box2D/Box2D.h>
    #include <json.hpp>
#endif

#include "Node.h"

namespace jupiter {

class Image;
class NodeVisitor;
class Physics;
class CollisionListener;
class PhysicsShape;

class Body: public Node {
public:
    friend class Physics;

    Body();
    Body(Physics*, b2BodyDef, PhysicsShape*);
    virtual ~Body();

    Body(const Body&);
    virtual Body* clone(Body*);

    virtual Body* setParent(Node*);

    virtual Body* accept(NodeVisitor*);

    virtual nlohmann::json getJson() const;
    friend std::ostream& operator<<(std::ostream&, Body const&);

    Body* setPhysicsShape(PhysicsShape*);
    PhysicsShape* getPhysicsShape();

    b2Body* getPhysicsBody();
    b2Fixture* getPhysicsFixture();

    CollisionListener* getCollisionListener();
    Body* setCollisionListener(CollisionListener*);

protected:
    Ref<Physics>              _visitor;

    b2BodyDef                 _bodyDef;
    b2Body*                   _body               = nullptr;

    Ref<PhysicsShape>         _shape;
    std::vector<b2Fixture*>   _fixtures;

    Ref<CollisionListener>    _collisionListener;

    Body& operator=(const Body&)  = default;

    void updateBody();
    void updateFixtures();
};

} /* namespace jupiter */

#endif /* MODULES_JUPITER_INCLUDE_JUPITER_BODY_H_ */
