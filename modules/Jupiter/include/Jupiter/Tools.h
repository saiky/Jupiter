/*
 * Tools.h
 *
 *  Created on: May 25, 2014
 *      Author: ingener
 */

#ifndef TOOLS_H_
#define TOOLS_H_

#include <memory>
#include <utility>
#include "Jupiter/JupiterError.h"

namespace jupiter {

template<typename T, typename ... Args>
std::unique_ptr<T> make_unique_(Args ... args) {
    std::unique_ptr<T> ptr(new T(std::forward<Args>(args)...));
    return ptr;
}

class Tools {
public:
    Tools() = delete;
    virtual ~Tools() = delete;

    static uint32_t upperPowerOfTwo(uint32_t v);
    static void glError(const std::string& file = {}, int line = -1, const std::string& function = {}) throw (JupiterError);
};

#define CHECK_GL_ERROR Tools::glError(__FILE__, __LINE__, __FUNCTION__);

inline uint32_t Tools::upperPowerOfTwo(uint32_t v) {
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

} /* namespace ndk_game */

#endif /* TOOLS_H_ */
