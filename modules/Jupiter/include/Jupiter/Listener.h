/*
 * Listener.h
 *
 *  Created on: May 14, 2015
 *      Author: pavel
 */

#ifndef MODULES_JUPITER_INCLUDE_JUPITER_LISTENER_H_
#define MODULES_JUPITER_INCLUDE_JUPITER_LISTENER_H_

#ifdef SWIG
    namespace jupiter {
        %feature("director") Listener;
    }
#else
#endif

namespace jupiter {

class Node;

class Listener {
public:
    Listener();
    virtual ~Listener();

    Node* getNode();
    Listener* setNode(Node*);

private:
    Node* _node = nullptr;
};

} /* namespace jupiter */

#endif /* MODULES_JUPITER_INCLUDE_JUPITER_LISTENER_H_ */
