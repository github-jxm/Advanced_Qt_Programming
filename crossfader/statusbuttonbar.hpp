#ifndef STATUSBUTTONBAR_HPP
#define STATUSBUTTONBAR_HPP
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

#include <QLabel>
#include <QWidget>


class QCheckBox;
class QDialogButtonBox;


class StatusButtonBar : public QWidget
{
    Q_OBJECT

public:
    explicit StatusButtonBar(QWidget *parent=0);

    QLabel *label() { return m_label; }
    QCheckBox *checkBox() { return m_checkBox; }
    QDialogButtonBox *buttonBox() { return m_buttonBox; }

public slots:
    void showMessage(const QString &message, int timeoutMSec=0);
    void clear() { m_label->clear(); }

private:
    QLabel *m_label;
    QCheckBox *m_checkBox;
    QDialogButtonBox *m_buttonBox;
};

#endif // STATUSBUTTONBAR_HPP
