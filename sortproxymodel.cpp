/* This file is part of apt-offline.
*
* Copyright (c) 2011 - Christian Kurniawan Ginting S. <saa7_go@terralinux.org>
*
* apt-offline is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* apt-offline is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with apt-offline. If not, see <http://www.gnu.org/licenses/>. */

#include "sortproxymodel.h"
#include <QDebug>

SortProxyModel::SortProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
}

SortProxyModel::~SortProxyModel()
{
    qDebug() << this << "destroyed!";
}

bool SortProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QVariant leftData = sourceModel()->data(left, Qt::EditRole);
    QVariant rigthData = sourceModel()->data(right, Qt::EditRole);

    if(leftData.type() == QVariant::Int)
        return leftData.toInt() < rigthData.toInt();
    else if(leftData.type() == QVariant::LongLong)
        return leftData.toLongLong() < rigthData.toLongLong();
    else {
        return QString::localeAwareCompare(leftData.toString(), rigthData.toString());
    }
}
