/*  StartupWizard.cpp
 *
 *  Copyright (C) 2016  Jim Evins <evins@snaught.com>
 *
 *  This file is part of gLabels-qt.
 *
 *  gLabels-qt is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  gLabels-qt is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with gLabels-qt.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "StartupWizard.h"

#include "File.h"
#include <QtDebug>


///
/// Constructor
///
StartupWizard::StartupWizard( QWidget *parent )
	: QDialog(parent)
{
	setupUi( this );

	QString subtitle = tr("Label Designer");

	QString markup = "<span style='font-size:24pt; font-weight:600;'>gLabels  </span><span style='font-size:16pt; color:#333333;'>"
		+ subtitle + "</span>";

	titleLabel->setText( markup );
}


///
/// "New Project" Button Clicked Slot
///
void StartupWizard::onNewProjectButtonClicked()
{
	hide();
	
	if ( File::newLabel() )
	{
		close();
	}
	else
	{
		show();
	}
}


///
/// "Open Project" Button Clicked Slot
///
void StartupWizard::onOpenProjectButtonClicked()
{
	hide();
	
	if ( File::open() )
	{
		close();
	}
	else
	{
		show();
	}
}