#ifndef RSSREADER_HPP
#define RSSREADER_HPP
/*
    Copyright (c) 2009-10 Qtrac Ltd. All rights reserved.

    This program or module is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version. It is provided
    for educational purposes and is distributed in the hope that it will
    be useful, but WITHOUT ANY WARRANTY; without even the implied
    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
    the GNU General Public License for more details.
*/

#include "rssitem.hpp"
#include <QVector>
#include <QXmlStreamReader>


class RssReader : public QXmlStreamReader
{
public:
    explicit RssReader() : QXmlStreamReader() {}

    bool read(QIODevice *device);

    const QVector<RssItem> items() const { return m_items; }

private:
    void readItem();
    void readUnknownElement();

    QVector<RssItem> m_items;
};

#endif // RSSREADER_HPP
