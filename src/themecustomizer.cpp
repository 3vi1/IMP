/*
 * Imp:  Copyright 2016, 2017 Jesse Litton (imp@eternaldusk.com)
 *
 * This file is part of Imp.
 *
 * Imp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Imp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Imp.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "themecustomizer.h"
#include "ui_themecustomizer.h"

#include <QColorDialog>
#include <QFileDialog>

ThemeCustomizer::ThemeCustomizer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThemeCustomizer)
{
    ui->setupUi(this);

    ui->imageBackColor->setScene(&colorScene);
    ui->imageLineColor->setScene(&colorScene);
}

ThemeCustomizer::~ThemeCustomizer()
{
    delete ui;
}

void ThemeCustomizer::loadValues(Theme *theme)
{
    m_theme = theme;

    // Background attributes
    ui->imageBackColor->setBackgroundBrush(theme->getAttribute("backColor").value<QColor>());
    ui->labelBackFile->setText(theme->getAttribute("backGraphic").toString());
    ui->spinBackScale->setValue(theme->getAttribute("backScale").toDouble());
    ui->spinBackOpacity->setValue(theme->getAttribute("backOpacity").toDouble());
    ui->spinBackX->setValue(theme->getAttribute("backXOffset").toDouble());
    ui->spinBackY->setValue(theme->getAttribute("backYOffset").toDouble());
    ui->spinBackZ->setValue(theme->getAttribute("backZ").toDouble());

    // Finder attributes
    ui->labelFindFile->setText(theme->getAttribute("findGraphic").toString());
    ui->spinFindScale->setValue(theme->getAttribute("findScale").toDouble());
    ui->spinFindOpacity->setValue(theme->getAttribute("findOpacity").toDouble());
    ui->spinFindX->setValue(theme->getAttribute("findXOffset").toDouble());
    ui->spinFindY->setValue(theme->getAttribute("findYOffset").toDouble());
    ui->spinFindZ->setValue(theme->getAttribute("findZ").toDouble());

    // Font attributes
    QStringList fontAttributes = theme->getAttribute("defaultNameFont").toStringList();
    QFont font = QFont(fontAttributes[0]);
    ui->systemFont->setFont(font);
    ui->systemFontSize->setValue(fontAttributes[1].toInt());

    fontAttributes = theme->getAttribute("defaultTimeFont").toStringList();
    font = QFont(fontAttributes[0]);
    ui->timerFont->setFont(font);
    ui->timerFontSize->setValue(fontAttributes[1].toInt());

    // Line attributes
    ui->imageLineColor->setBackgroundBrush(theme->getAttribute("lineColor").value<QColor>());
    ui->spinLineOpacity->setValue(theme->getAttribute("lineOpacity").toDouble());
    ui->spinLineWidth->setValue(theme->getAttribute("lineWidth").toInt());
    ui->spinLineZ->setValue(theme->getAttribute("lineZ").toDouble());

    // Pilot attributes
    ui->labelPilotFile->setText(theme->getAttribute("pilotGraphic").toString());
    ui->spinPilotScale->setValue(theme->getAttribute("pilotScale").toDouble());
    ui->spinPilotOpacity->setValue(theme->getAttribute("pilotOpacity").toDouble());
    ui->spinPilotX->setValue(theme->getAttribute("pilotXOffset").toDouble());
    ui->spinPilotY->setValue(theme->getAttribute("pilotYOffset").toDouble());
    ui->spinPilotZ->setValue(theme->getAttribute("pilotZ").toDouble());
}

void ThemeCustomizer::on_buttonBackColor_clicked()
{
    QColor c = QColorDialog::getColor(
                Qt::white,
                this,
                "Background Color",
                QColorDialog::DontUseNativeDialog);

    if(c.isValid())
    {
        ui->imageBackColor->setBackgroundBrush(c);

        m_theme->setAttribute("backColor", MAP, "back", "color", c);
    }
}

void ThemeCustomizer::on_buttonBackImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("Background Image"),
                QString(),
                tr("Image Files (*.bmp *.png *.jpg *.jpeg *.svg)") );

    if(fileName.length() > 0)
    {
        ui->labelBackFile->setText(fileName);

        m_theme->setAttribute("backGraphic", MAP, "back", "graphic", ui->labelBackFile->text());
    }
}

void ThemeCustomizer::on_buttonFindImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("Finder Image"),
                QString(),
                tr("Image Files (*.svg)") );

    if(fileName.length() > 0)
    {
        ui->labelFindFile->setText(fileName);

        m_theme->setAttribute("findGraphic", FIND, "find", "graphic", fileName);
    }
}

void ThemeCustomizer::on_buttonPilotImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("Pilot Image"),
                QString(),
                tr("Image Files (*.svg)") );

    if(fileName.length() > 0)
    {
        ui->labelPilotFile->setText(fileName);

        m_theme->setAttribute("pilotGraphic", PILOT, "pilot", "graphic", fileName);
    }
}

void ThemeCustomizer::on_buttonLineColor_clicked()
{
    QColor c = QColorDialog::getColor(
                Qt::black,
                this,
                "Line Color",
                QColorDialog::DontUseNativeDialog);

    if(c.isValid())
    {
        ui->imageLineColor->setBackgroundBrush(c);

        m_theme->setAttribute("lineColor", LINES, "line", "color", c);
    }
}

void ThemeCustomizer::on_spinBackScale_valueChanged(double scale)
{
    m_theme->setAttribute("backScale", MAP, "back", "scale", scale);
}

void ThemeCustomizer::on_spinBackOpacity_valueChanged(double opacity)
{
    m_theme->setAttribute("backOpacity", MAP, "back", "opacity", opacity);
}

void ThemeCustomizer::on_spinBackX_valueChanged(double backX)
{
    m_theme->setAttribute("backXOffset", MAP, "back", "xOffset", backX);
}

void ThemeCustomizer::on_spinBackY_valueChanged(double backY)
{
    m_theme->setAttribute("backYOffset", MAP, "back", "yOffset", backY);
}

void ThemeCustomizer::on_spinBackZ_valueChanged(double backZ)
{
    m_theme->setAttribute("backZ", MAP, "back", "z", backZ);
}

void ThemeCustomizer::on_spinFindScale_valueChanged(double scale)
{
    m_theme->setAttribute("findScale", FIND, "find", "scale", scale);
}

void ThemeCustomizer::on_spinFindOpacity_valueChanged(double opacity)
{
    m_theme->setAttribute("findOpacity", FIND, "find", "opacity", opacity);
}

void ThemeCustomizer::on_spinFindX_valueChanged(double x)
{
    m_theme->setAttribute("findXOffset", FIND, "find", "xOffset", x);
}

void ThemeCustomizer::on_spinFindY_valueChanged(double y)
{
    m_theme->setAttribute("findYOffset", FIND, "find", "yOffset", y);
}

void ThemeCustomizer::on_spinFindZ_valueChanged(double z)
{
    m_theme->setAttribute("findZ", FIND, "find", "z", z);
}

void ThemeCustomizer::on_systemFont_currentTextChanged(const QString fontName)
{
    QStringList newSystemFont = {fontName, QString::number(ui->systemFontSize->value())};

    m_theme->setAttribute("defaultNameFont",
                      SYSTEM,
                      "font",
                      "name",
                      newSystemFont);
}

void ThemeCustomizer::on_systemFontSize_valueChanged(int size)
{
    QStringList newSystemFont = {ui->systemFont->currentText(), QString::number(size)};

    m_theme->setAttribute("defaultNameFont",
                      SYSTEM,
                      "font",
                      "name",
                      newSystemFont);
}

void ThemeCustomizer::on_timerFont_currentIndexChanged(const QString &fontName)
{
    QStringList newTimeFont = {fontName, QString::number(ui->timerFontSize->value())};

    m_theme->setAttribute("defaultTimeFont",
                      SYSTEM,
                      "font",
                      "time",
                      newTimeFont);
}

void ThemeCustomizer::on_timerFontSize_valueChanged(int size)
{
    QStringList newTimeFont = {ui->timerFont->currentText(), QString::number(size)};

    m_theme->setAttribute("defaultTimeFont",
                      SYSTEM,
                      "font",
                      "time",
                      newTimeFont);
}

void ThemeCustomizer::on_spinLineWidth_valueChanged(int width)
{
    m_theme->setAttribute("lineWidth", LINES, "line", "width", width);
}

void ThemeCustomizer::on_spinLineOpacity_valueChanged(double opacity)
{
    m_theme->setAttribute("lineOpacity", LINES, "line", "opacity", opacity);
}

void ThemeCustomizer::on_spinLineZ_valueChanged(double z)
{
    m_theme->setAttribute("lineZ", LINES, "line", "z", z);
}

void ThemeCustomizer::on_spinPilotScale_valueChanged(double scale)
{
    m_theme->setAttribute("pilotScale", PILOT, "pilot", "scale", scale);
}

void ThemeCustomizer::on_spinPilotOpacity_valueChanged(double opacity)
{
    m_theme->setAttribute("pilotOpacity", PILOT, "pilot", "opacity", opacity);
}

void ThemeCustomizer::on_spinPilotX_valueChanged(double x)
{
    m_theme->setAttribute("pilotXOffset", PILOT, "pilot", "xOffset", x);
}

void ThemeCustomizer::on_spinPilotY_valueChanged(double y)
{
    m_theme->setAttribute("pilotYOffset", PILOT, "pilot", "yOffset", y);
}

void ThemeCustomizer::on_spinPilotZ_valueChanged(double z)
{
    m_theme->setAttribute("pilotZ", PILOT, "pilot", "z", z);
}
