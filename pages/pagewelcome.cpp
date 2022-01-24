/*
    Copyright 2016 - 2017 Benjamin Vedder	benjamin@vedder.se

    This file is part of VESC Tool.

    VESC Tool is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    VESC Tool is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

#include "pagewelcome.h"
#include "ui_pagewelcome.h"
#include "widgets/detectallfocdialog.h"

#include <QMessageBox>
#include <QQmlEngine>
#include <QQmlContext>
#include <QSettings>
#include <QmlHighlighter>
#include <QQuickItem>

PageWelcome::PageWelcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageWelcome)
{
    ui->setupUi(this);

    QString theme = Utility::getThemePath();
    ui->autoConnectButton->setIcon(QIcon(theme + "icons/Connected-96.png"));

    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = nullptr;
    ui->bgWidget->setPixmap(QPixmap("://res/bg.png"));
}

PageWelcome::~PageWelcome()
{
    delete ui;
}

VescInterface *PageWelcome::vesc() const
{
    return mVesc;
}

void PageWelcome::setVesc(VescInterface *vesc)
{
    mVesc = vesc;
}

void PageWelcome::on_autoConnectButton_clicked()
{
    Utility::autoconnectBlockingWithProgress(mVesc, this);
}
