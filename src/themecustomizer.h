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

#ifndef THEMECUSTOMIZER_H
#define THEMECUSTOMIZER_H

#include <QGraphicsScene>
#include <QWidget>

#include "theme.h"


namespace Ui {
class ThemeCustomizer;
}

class ThemeCustomizer : public QWidget
{
    Q_OBJECT

public:
    explicit ThemeCustomizer(QWidget *parent = 0);
    ~ThemeCustomizer();

    void loadValues(Theme* theme);

private slots:
    void on_buttonBackColor_clicked();
    void on_buttonBackImage_clicked();
    void on_buttonFindImage_clicked();
    void on_buttonPilotImage_clicked();
    void on_buttonLineColor_clicked();
    void on_buttonSystemImage_clicked();
    void on_buttonWormholeImage_clicked();
    void on_spinBackScale_valueChanged(double scale);
    void on_spinBackOpacity_valueChanged(double opacity);
    void on_spinBackX_valueChanged(double backX);
    void on_spinBackY_valueChanged(double backY);
    void on_spinBackZ_valueChanged(double backZ);
    void on_spinFindScale_valueChanged(double scale);
    void on_spinFindOpacity_valueChanged(double opacity);
    void on_spinFindX_valueChanged(double x);
    void on_spinFindY_valueChanged(double y);
    void on_spinFindZ_valueChanged(double z);
    void on_systemFont_currentTextChanged(const QString fontName);
    void on_systemFontSize_valueChanged(int size);
    void on_timerFont_currentIndexChanged(const QString &fontName);
    void on_timerFontSize_valueChanged(int size);
    void on_spinLineWidth_valueChanged(int width);
    void on_spinLineOpacity_valueChanged(double opacity);
    void on_spinLineZ_valueChanged(double z);
    void on_spinPilotScale_valueChanged(double scale);
    void on_spinPilotOpacity_valueChanged(double opacity);
    void on_spinPilotX_valueChanged(double x);
    void on_spinPilotY_valueChanged(double y);
    void on_spinPilotZ_valueChanged(double z);
    void on_spinSystemScale_valueChanged(double scale);
    void on_spinSystemOpacity_valueChanged(double opacity);
    void on_spinSystemX_valueChanged(double x);
    void on_spinSystemY_valueChanged(double y);
    void on_spinSystemZ_valueChanged(double z);
    void on_spinWormholeScale_valueChanged(double scale);
    void on_spinWormholeOpacity_valueChanged(double opacity);
    void on_spinWormholeX_valueChanged(double x);
    void on_spinWormholeY_valueChanged(double y);
    void on_spinWormholeZ_valueChanged(double z);

private:
    Ui::ThemeCustomizer *ui;
    QGraphicsScene colorScene;
    Theme* m_theme = NULL;
};

#endif // THEMECUSTOMIZER_H
