/****************************************************************************
**
** Copyright (C) 2012 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Commercial Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/


#ifndef CHARTS_H
#define CHARTS_H
#include "window.h"
#include <QList>
#include <QString>
#include <qchartglobal.h>

QTCOMMERCIALCHART_BEGIN_NAMESPACE
class QChart;
QTCOMMERCIALCHART_END_NAMESPACE

QTCOMMERCIALCHART_USE_NAMESPACE

class Chart
{
public:
    Chart();

    virtual ~Chart();

    virtual void initialize();
    virtual QChart* createChart(const DataTable& table) = 0;
    virtual QString name() = 0;
    virtual QString category() = 0;
    virtual QString subCategory() = 0;

};

namespace Charts
{

typedef QList<Chart*> ChartList;

inline ChartList& chartList()
{
    static ChartList list;
    return list;
}

inline bool findChart(Chart* chart)
{
    ChartList& list = chartList();
    if (list.contains(chart)) {
        return true;
    }
    foreach (Chart* item, list) {
        if (item->name() == chart->name() && item->category() == chart->category() && item->subCategory() == chart->subCategory()) {
            return true;
        }
    }
    return false;
}

inline void addChart(Chart* chart)
{
    ChartList& list = chartList();
    if (!findChart(chart)) {
        list.append(chart);
    }
}
}

#define DECLARE_CHART(chartName) static chartName t;

#endif
