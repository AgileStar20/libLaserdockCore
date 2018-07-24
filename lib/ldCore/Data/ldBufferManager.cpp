/**
    libLaserdockCore
    Copyright(c) 2018 Wicked Lasers

    This file is part of libLaserdockCore.

    libLaserdockCore is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libLaserdockCore is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libLaserdockCore.  If not, see <https://www.gnu.org/licenses/>.
**/

#include "ldBufferManager.h"

#include <QtCore/QDebug>
#include <QtCore/QThread>

#include "ldCore/Filter/ldFilterManager.h"

#include "ldFrameBuffer.h"

ldBufferManager::ldBufferManager(QObject *parent)
    : QObject(parent)
{
    qDebug() << __FUNCTION__;
}


void ldBufferManager::registerBuffer(ldFrameBuffer *buffer)
{
    // register auto update
    connect(buffer, &ldFrameBuffer::isCleaned, this, [&,buffer]() {
        emit bufferNeedsContent(buffer);
    }, Qt::DirectConnection);
}


