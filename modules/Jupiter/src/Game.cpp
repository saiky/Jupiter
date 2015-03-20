/*
 * Game.cpp
 *
 *  Created on: Dec 12, 2014
 *      Author: ingener
 */

#include <boost/filesystem.hpp>

#include "Jupiter/Game.h"
#include "Jupiter/JupiterError.h"
#include "Jupiter/Node.h"

namespace jupiter {

using namespace std;
using namespace glm;

void Game::draw() {
    if (!node)
        throw JupiterError("no root node");
    if (!render)
        throw JupiterError("no render");
    if(!physics)
        throw JupiterError("no physics");

    node->accept(physics);
    node->accept(render);
    render->draw();
}

void Game::input() {
}

} /* namespace jupiter */
