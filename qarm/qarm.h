/* -*- mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/*
 * uARM
 *
 * Copyright (C) 2013 Marco Melletti
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef QARM_H
#define QARM_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QTimer>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include "armProc/machine.h"
#include "mainbar.h"
#include "guiConst.h"
#include "procdisplay.h"
#include "QLine.h"

class qarm : public QMainWindow{
    Q_OBJECT
public:

    qarm();

signals:
    void resetDisplay();
    void resetMachine(unsigned long memSize);

private slots:
    void start(int speed);
    void step();
    void stop();
    void open(QString fname);
    void showRam();

private:
    bool resetFlag;
    machine *mac;
    unsigned long ramSize;

    QWidget *mainWidget;
    procDisplay *display;
    QVBoxLayout *layout;
    mainBar *toolbar;
    QTimer *clock;

    void fillMemory(ramMemory *ram, QDataStream *in);
};

#endif // QARM_H
