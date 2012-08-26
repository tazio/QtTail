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


#ifndef NEWFILTER_H
#define NEWFILTER_H

#include <QDialog>
#include <QTextCharFormat>
#include <QPair>
#include "ui_filters.h"
#include "genericfilter.h"
#include "filtervalidator.h"



class NewFilter:public QDialog
{
	Q_OBJECT
	
	Ui::NewFilterDialog ui;

	bool suppressor;

	QColor getBackGroundColor() const;
	QColor getForeGroundColor() const;
private slots:
	void changeFilterType(int type);
	void changeFilterMatch(int type);

protected:
	void changeEvent(QEvent *e);
public:
	NewFilter (QWidget * parent = 0);
	QPair<GenericFilter, QTextCharFormat> getFilterAndFormat() const;
	GenericFilter getFilter() const;
	QTextCharFormat getFormat() const;
	QString getName() const;
	bool isSuppressor() const { return suppressor; }
	virtual ~NewFilter();
signals:
	void typeChanged(filterType f);
};

#endif // NEWFILTER_H
