/*
 * Game.h
 *
 *  Created on: Dec 12, 2014
 *      Author: ingener
 */

#ifndef MODULES_JUPITER_INCLUDE_JUPITER_GAME_H_
#define MODULES_JUPITER_INCLUDE_JUPITER_GAME_H_

#ifdef SWIG
#else

#include <string>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Jupiter/RenderVisitor.h"
#include "Jupiter/Node.h"

#endif

namespace jupiter {

class Game {
public:
    Game() = default;
    virtual ~Game() = default;

    virtual void draw();

    virtual void input();

    virtual int getWidth() const;
    virtual int getHeight() const;

    Game* setHeight(int height = 0);
    Game* setWidth(int width = 0);

    virtual Game* setRootNode(Node*);
    virtual Node* getRootNode();

    virtual Game* setRender(RenderVisitor*);
    virtual RenderVisitor* getRender();

    virtual Game* setPhysicsEngine(NodeVisitor*);
    virtual NodeVisitor* getPhysicsEngine();

protected:
    RenderVisitor* render = nullptr;
    NodeVisitor* physics = nullptr;
    Node* node = nullptr;
    int width = 0;
    int height = 0;
};

inline int Game::getWidth() const {
    return width;
}

inline int Game::getHeight() const {
    return height;
}

inline Game* Game::setHeight(int height) {
    this->height = height;
    return this;
}

inline Game* Game::setWidth(int width) {
    this->width = width;
    return this;
}

inline Game* Game::setRootNode(Node* node) {
    Game::node = node;
    return this;
}

inline Node* Game::getRootNode() {
    return node;
}

inline Game* Game::setRender(RenderVisitor* render) {
    Game::render = render;
    return this;
}

inline RenderVisitor* Game::getRender() {
    return render;
}

inline Game* Game::setPhysicsEngine(NodeVisitor* physicsEngine) {
    physics = physicsEngine;
    return this;
}

inline NodeVisitor* Game::getPhysicsEngine() {
    return physics;
}

} /* namespace jupiter */

#endif /* MODULES_JUPITER_INCLUDE_JUPITER_GAME_H_ */
