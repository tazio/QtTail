/*
    QTail is a simple graphical implementation of tail -f
    Copyright (C) 2012  Tazio Ceri <praise@praisenet.darktech.org>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef FILTERCONFIG_H
#define FILTERCONFIG_H

#include <QDialog>
#include "genericfilter.h"
#include "ui_filtersconfig.h"

class FilterConfig : public QDialog
{
	Q_OBJECT

	Ui::FilterConfigDialog ui;
	QAbstractTableModel* Model;
	
	mutable int action;
private slots:
	void menuAdd(const QModelIndex&);
	void add2current();
	void delCurrent();
protected:
	void changeEvent(QEvent *e);
public: 
	FilterConfig (QAbstractTableModel* mod, QWidget * parent = 0);
	QAbstractTableModel* model() const { return Model; }
	virtual ~FilterConfig () { }

signals:
	void addFilter(const GenericFilter& filter);
};

#endif // FILTERCONFIG_H
