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


#ifndef GENERICFILTER_H
#define GENERICFILTER_H
#include <QString>
#include <QRegExp>

class GenericFilter
{
	QString filterString;
	QRegExp filterReg;
	int priority;
public:
	GenericFilter (int prio, const QString& filter): filterString(filter), priority(prio) {}
	GenericFilter (int prio, const QRegExp& filter): filterReg(filter), priority(prio) {}
	bool operator<(const GenericFilter& other) const { return priority < other.priority; }
	bool match(const QString& s);
};

#endif // GENERICFILTER_H