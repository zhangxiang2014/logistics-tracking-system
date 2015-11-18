/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef BASICTOOLSPLUGIN_H
#define BASICTOOLSPLUGIN_H

#include <QRect>
#include <QObject>
#include <QtPlugin>
#include <QStringList>
#include <QPainterPath>
#include <QImage>
#include <QMainWindow>
#include <mainwindow2.h>
#include <timeline2.h>
#include <scribblearea.h>
#include <colorbox.h>

//! [0]
#include <CartoonDrawModule/drawmoduleinterface.h>
#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#include <QtUiPlugin/QDesignerCustomWidgetCollectionInterface>
//! [1]
class QActionGroup;
class Object;
class Editor;
class ScribbleArea;
class BaseDockWidget;
class ColorPaletteWidget;
class DisplayOptionWidget;
class ToolOptionWidget;
class TimeLine;
class ToolBoxWidget;
class Preferences;
class PreviewWidget;
class ColorBox;
class RecentFileMenu;
class Timeline2;

class DrawPlugin : public QObject,
                   public QDesignerCustomWidgetInterface,
                   public LoadDrawInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.DrawModuleInterface.LoadDrawInterface")
    Q_INTERFACES(LoadDrawInterface QDesignerCustomWidgetInterface)
public:
   explicit DrawPlugin(QObject *parent = 0);

    // LoadDrawInterface
   void LoadUI() Q_DECL_OVERRIDE;
   void setBottomUI(QWidget* videoUI) Q_DECL_OVERRIDE;

   // QDesignerCustomWidgetInterface
   ColorBox *mColorBox;
   ScribbleArea *mArea;
   MainWindow2 *pencil;
   ToolBoxWidget *mToolBox;
   bool isContainer() const Q_DECL_OVERRIDE;
   bool isInitialized() const Q_DECL_OVERRIDE;
   QIcon icon() const Q_DECL_OVERRIDE;
   QString domXml() const Q_DECL_OVERRIDE;
   QString group() const Q_DECL_OVERRIDE;
   QString includeFile() const Q_DECL_OVERRIDE;
   QString name() const Q_DECL_OVERRIDE;
   QString toolTip() const Q_DECL_OVERRIDE;
   QString whatsThis() const Q_DECL_OVERRIDE;
   QWidget *createWidget(QWidget *parent) Q_DECL_OVERRIDE;
   void initialize(QDesignerFormEditorInterface *core) Q_DECL_OVERRIDE;

private:
    bool initialized;
};


#endif