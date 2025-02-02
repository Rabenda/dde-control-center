/*
 * Copyright (C) 2017 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     LiLinling <lilinling_cm@deepin.com>
 *
 * Maintainer: LiLinling <lilinling_cm@deepin.com>
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
#pragma once

#include "interface/namespace.h"
#include "window/utils.h"
#include "window/insertplugin.h"

#include <dtkwidget_global.h>

#include <QWidget>
#include <QModelIndex>

DWIDGET_BEGIN_NAMESPACE
class DListView;
DWIDGET_END_NAMESPACE

QT_BEGIN_NAMESPACE
class QStandardItemModel;
class QVBoxLayout;
QT_END_NAMESPACE

namespace dcc {
namespace widgets {
class MultiSelectListView;
}
}

namespace DCC_NAMESPACE {
namespace personalization {
class PersonalizationList : public QWidget
{
    Q_OBJECT
public:
    explicit PersonalizationList(QWidget *parent = nullptr);
    virtual ~PersonalizationList() override;
    void showDefaultWidget();

Q_SIGNALS:
    void requestShowGeneral();
    void requestShowIconTheme();
    void requestShowCursorTheme();
    void requestShowFonts();
    void requestUpdateSecondMenu(bool);

public Q_SLOTS:
    void onCategoryClicked(const QModelIndex &index);
    void setCurrentIndex(int row);

private:
    bool configContent(const QString & configName);

private:
    QList<ListSubItem> m_itemList;
    dcc::widgets::MultiSelectListView *m_categoryListView;
    QStandardItemModel *m_model;
    QVBoxLayout *m_centralLayout;
    QModelIndex m_lastIndex;
};
}
}
