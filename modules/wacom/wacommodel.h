/*
 * Copyright (C) 2011 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WACOMMODEL_H
#define WACOMMODEL_H

#include <QObject>

namespace  dcc
{
namespace wacom
{
class WacomModelBase;
class WacomModel : public QObject
{
    Q_OBJECT
    friend class MouseWorker;
public:
    explicit WacomModel(QObject *parent = 0);
    ~WacomModel();
    WacomModelBase *getWacomModelBase();

    bool exist() const;
    void setExist(bool exist);

    bool getCursorMode() const;
    void setCursorMode(bool cursorMode);

Q_SIGNALS:
    void existChanged(bool exist);
    void cursorModeChanged(const bool cursorMode);

private:
    WacomModelBase *m_wacomModelBase;
    bool m_exist;
    bool m_cursorMode;
};
}
}

#endif // WACOMMODEL_H
