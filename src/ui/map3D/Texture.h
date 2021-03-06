/*=====================================================================

QGroundControl Open Source Ground Control Station

(c) 2009, 2010 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>

This file is part of the QGROUNDCONTROL project

    QGROUNDCONTROL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    QGROUNDCONTROL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with QGROUNDCONTROL. If not, see <http://www.gnu.org/licenses/>.

======================================================================*/

/**
 * @file
 *   @brief Definition of the class Texture.
 *
 *   @author Lionel Heng <hengli@student.ethz.ch>
 *
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#if (defined __APPLE__) & (defined __MACH__)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <inttypes.h>
#include <QSharedPointer>

#include "WebImage.h"

class Texture
{
public:
    Texture();

    const QString& getSourceURL(void) const;

    void setID(GLuint id);

    void sync(const WebImagePtr& image);

    void draw(float x1, float y1, float x2, float y2,
              bool smoothInterpolation) const;
    void draw(float x1, float y1, float x2, float y2,
              float x3, float y3, float x4, float y4,
              bool smoothInterpolation) const;

    bool is3D(void) const;

private:
    enum State
    {
        UNINITIALIZED = 0,
        REQUESTED = 1,
        READY = 2
    };

    State state;
    QString sourceURL;
    GLuint id;

    int32_t textureWidth;
    int32_t textureHeight;

    int32_t imageWidth;
    int32_t imageHeight;

    bool _is3D;
    QVector< QVector<int32_t> > heightModel;

    float maxU;
    float maxV;
};

typedef QSharedPointer<Texture> TexturePtr;

#endif // TEXTURE_H
