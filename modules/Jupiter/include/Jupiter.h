/*
 * Engine.h
 *
 *  Created on: 25 ��� 2014 �.
 *      Author: Admin
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include "Jupiter/Game.h"
#include "Jupiter/JsonGame.h"

#include "Jupiter/Node.h"
#include "Jupiter/JsonNode.h"

#include "Jupiter/Sprite.h"
#include "Jupiter/Controller.h"
#include "Jupiter/Image.h"
#include "Jupiter/PngImage.h"
#include "Jupiter/JupiterError.h"
#include "Jupiter/Texture.h"
#include "Jupiter/File.h"
#include "Jupiter/LinuxFileFactory.h"

#include "Jupiter/IShaderLoader.h"
#include "Jupiter/SimpleShaderLoader.h"
#include "Jupiter/ResourceShaderLoader.h"

#include "Jupiter/ISpriteLoader.h"
#include "Jupiter/SimpleSpriteLoader.h"
#include "Jupiter/RectSpriteLoader.h"

#include "Jupiter/ISoundEngine.h"
#include "Jupiter/DummySoundEngine.h"

#include "Jupiter/ISound.h"
#include "Jupiter/DummySound.h"

#include "Jupiter/Tools.h"
#include "Jupiter/Rect.h"

#ifdef ANDROID
	#include "Jupiter/SLESSound.h"
	#include "Jupiter/SLESSoundEngine.h"
	#include "Jupiter/AssetTextureLoader.h"
	#include "Jupiter/GLES20Engine.h"
#else
#endif

#endif /* ENGINE_H_ */
