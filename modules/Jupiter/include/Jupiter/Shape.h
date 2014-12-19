/*
 * Shape.h
 *
 *  Created on: Dec 16, 2014
 *      Author: pavel
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>
#include <vector>
#include <cstdint>

namespace jupiter
{

class Shape
{
public:
    enum class Type
    {
        Triangles, TriangleFan, TriangleStrip, LineStrip
    };

    Shape() = default;
    Shape(const std::string&);
    Shape(const std::vector<float>& data, Type);
    virtual ~Shape() = default;

    int32_t vertexCount() const;
    const float* vertexData() const;
    Type type() const;

private:
    std::vector<float> _data; // {{{x, y, z}, {tx, ty}}, ...} size = _vertexCount * 5
    Type _type = Type::TriangleStrip;

    static const int DATA_IN_ONE_VERTEX = 5;
};

} /* namespace jupiter */

#endif /* SHAPE_H_ */
