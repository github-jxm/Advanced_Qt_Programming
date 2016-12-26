#ifndef ALT_KEY_HPP
#define ALT_KEY_HPP

/*
    Copyright (c) 2008-10 Qtrac Ltd. All rights reserved.
    This program or module is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 2 of
    the License, or version 3 of the License, or (at your option) any
    later version. This program is distributed in the hope that it will
    be useful, but WITHOUT ANY WARRANTY; without even the implied
    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.

    This module is used to show where keyboard accelerators should go in
    menu option texts and dialog labels and instantly produces optimal
    results using the Kuhn-Munkres algorithm. It easily outperforms all
    the naive algorithms.
*/

#include <QList>
#include <QObject>
#include <QPair>
#include <QStringList>


class QAction;
class QWidget;


namespace AQP {

const QString Alphabet = QObject::tr(
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", "Accelerator Keys");

QStringList accelerated(const QStringList &strings,
                        const QString &alphabet=Alphabet);
void accelerateMenu(QWidget *menuOrMenuBar,
                    const QString &alphabet=Alphabet);
void accelerateActions(QList<QAction*> actions,
                       const QString &alphabet=Alphabet);
void accelerateWidget(QWidget *widget, const QString &alphabet=Alphabet);
void accelerateWidgets(QList<QWidget*> widgets,
                       const QString &alphabet=Alphabet);

bool isValid(const QStringList &listOfStrings,
             QPair<int, int> *where=0, const QString &alphabet=Alphabet);
int numberAccelerated(const QStringList &listOfStrings);
double quality(const QStringList &listOfStrings);

} // namespace AQP

#endif // ALT_KEY_HPP
