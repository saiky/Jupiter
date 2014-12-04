/*
 * DummySound.h
 *
 *  Created on: Jun 2, 2014
 *      Author: ingener
 */

#ifndef DUMMYSOUND_H_
#define DUMMYSOUND_H_

#include <Jupiter/ISound.h>

namespace jupiter
{

class DummySound: public ISound
{
public:
    DummySound();
    virtual ~DummySound();

    virtual void play(bool loop = false);
    virtual void stop();
};

} /* namespace ndk_game */

#endif /* DUMMYSOUND_H_ */
