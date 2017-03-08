#include "themecustomizationdialog.h"
#include "ui_themecustomizationdialog.h"

#include <QColorDialog>
#include <QFileDialog>

ThemeCustomizationDialog::ThemeCustomizationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThemeCustomizationDialog)
{
    ui->setupUi(this);
    ui->imageBackColor->setScene(&colorScene);
    ui->imageLineColor->setScene(&colorScene);

    applyButton = ui->buttonBox->button(QDialogButtonBox::Apply);
    connect(applyButton, &QPushButton::clicked,
            this, &ThemeCustomizationDialog::on_buttonBox_apply);
}

ThemeCustomizationDialog::~ThemeCustomizationDialog()
{
    delete ui;
}

void ThemeCustomizationDialog::on_buttonBox_accepted()
{
    this->close();
    this->setResult(QDialog::Accepted);
}

void ThemeCustomizationDialog::on_buttonBox_apply(bool /*checked = false*/)
{
    sendChanges(m_theme);
}

void ThemeCustomizationDialog::on_buttonBox_rejected()
{
    this->close();
    this->setResult(QDialog::Rejected);
}

void ThemeCustomizationDialog::loadValues(Theme *theme)
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

void ThemeCustomizationDialog::sendChanges(Theme *theme)
{
    // Background attributes
    QColor c = ui->imageBackColor->backgroundBrush().color();
    if(c != theme->getAttribute("backColor").value<QColor>())
    {
        theme->setAttribute("backColor", MAP, "back", "color", c);
    }

    if(ui->labelBackFile->text() != theme->getAttribute("backGraphic").toString())
    {
        theme->setAttribute("backGraphic", MAP, "back", "graphic", ui->labelBackFile->text());
    }

    if(ui->spinBackScale->value() != theme->getAttribute("backScale").toDouble())
    {
        theme->setAttribute("backScale", MAP, "back", "scale", ui->spinBackScale->value());
    }

    if(ui->spinBackOpacity->value() != theme->getAttribute("backOpacity").toDouble())
    {
        theme->setAttribute("backOpacity", MAP, "back", "opacity", ui->spinBackOpacity->value());
    }

    if(ui->spinBackX->value() != theme->getAttribute("backXOffset").toDouble())
    {
        theme->setAttribute("backXOffset", MAP, "back", "xOffset", ui->spinBackX->value());
    }

    if(ui->spinBackY->value() != theme->getAttribute("backYOffset").toDouble())
    {
        theme->setAttribute("backYOffset", MAP, "back", "yOffset", ui->spinBackY->value());
    }

    if(ui->spinBackZ->value() != theme->getAttribute("backZ").toDouble())
    {
        theme->setAttribute("backZ", MAP, "back", "z", ui->spinBackZ->value());
    }


    // Finder attributes
    if(ui->labelFindFile->text() != theme->getAttribute("findGraphic").toString())
    {
        theme->setAttribute("findGraphic", FIND, "find", "graphic", ui->labelFindFile->text());
    }

    if(ui->spinFindScale->value() != theme->getAttribute("findScale").toDouble())
    {
        theme->setAttribute("findScale", FIND, "find", "scale", ui->spinFindScale->value());
    }

    if(ui->spinFindOpacity->value() != theme->getAttribute("findOpacity").toDouble())
    {
        theme->setAttribute("findOpacity", FIND, "find", "opacity", ui->spinFindOpacity->value());
    }

    if(ui->spinFindX->value() != theme->getAttribute("findXOffset").toDouble())
    {
        theme->setAttribute("findXOffset", FIND, "find", "xOffset", ui->spinFindX->value());
    }

    if(ui->spinFindY->value() != theme->getAttribute("findYOffset").toDouble())
    {
        theme->setAttribute("findYOffset", FIND, "find", "yOffset", ui->spinFindY->value());
    }

    if(ui->spinFindZ->value() != theme->getAttribute("findZ").toDouble())
    {
        theme->setAttribute("findZ", FIND, "find", "z", ui->spinFindZ->value());
    }


    // Font attributes
    QStringList newSystemFont = {ui->systemFont->currentText(), QString::number(ui->systemFontSize->value())};

    if(newSystemFont[0] != theme->getAttribute("defaultNameFont").toStringList()[0] ||
            newSystemFont[1] != theme->getAttribute("defaultNameFont").toStringList()[1])
    {
        m_theme->setAttribute("defaultNameFont",
                          SYSTEM,
                          "font",
                          "name",
                          newSystemFont);
    }

    QStringList newTimeFont = {ui->timerFont->currentText(), QString::number(ui->timerFontSize->value())};

    if(newTimeFont[0] != theme->getAttribute("defaultTimeFont").toStringList()[0] ||
            newTimeFont[1] != theme->getAttribute("defaultTimeFont").toStringList()[1])
    {
        m_theme->setAttribute("defaultTimeFont",
                          SYSTEM,
                          "font",
                          "time",
                          newTimeFont);
    }


    // Line attributes
    c = ui->imageLineColor->backgroundBrush().color();
    if(c != theme->getAttribute("lineColor").value<QColor>())
    {
        theme->setAttribute("lineColor", LINES, "line", "color", c);
    }

    if(ui->spinLineOpacity->value() != theme->getAttribute("lineOpacity").toDouble())
    {
        theme->setAttribute("lineOpacity", LINES, "line", "opacity", ui->spinLineOpacity->value());
    }

    if(ui->spinLineWidth->value() != theme->getAttribute("lineWidth").toInt())
    {
        theme->setAttribute("lineWidth", LINES, "line", "width", ui->spinLineWidth->value());
    }

    if(ui->spinLineZ->value() != theme->getAttribute("lineZ").toDouble())
    {
        theme->setAttribute("lineZ", LINES, "line", "z", ui->spinLineZ->value());
    }


    // Pilot attributes
    if(ui->labelPilotFile->text() != theme->getAttribute("pilotGraphic").toString())
    {
        theme->setAttribute("pilotGraphic", PILOT, "pilot", "graphic", ui->labelPilotFile->text());
    }

    if(ui->spinPilotScale->value() != theme->getAttribute("pilotScale").toDouble())
    {
        theme->setAttribute("pilotScale", PILOT, "pilot", "scale", ui->spinPilotScale->value());
    }

    if(ui->spinPilotOpacity->value() != theme->getAttribute("pilotOpacity").toDouble())
    {
        theme->setAttribute("pilotOpacity", PILOT, "pilot", "opacity", ui->spinPilotOpacity->value());
    }

    if(ui->spinPilotX->value() != theme->getAttribute("pilotXOffset").toDouble())
    {
        theme->setAttribute("pilotXOffset", PILOT, "pilot", "xOffset", ui->spinPilotX->value());
    }

    if(ui->spinPilotY->value() != theme->getAttribute("pilotYOffset").toDouble())
    {
        theme->setAttribute("pilotYOffset", PILOT, "pilot", "yOffset", ui->spinPilotY->value());
    }

    if(ui->spinPilotZ->value() != theme->getAttribute("pilotZ").toDouble())
    {
        theme->setAttribute("pilotZ", PILOT, "pilot", "z", ui->spinPilotZ->value());
    }
}

void ThemeCustomizationDialog::on_buttonBackColor_clicked()
{
    QColor c = QColorDialog::getColor(
                Qt::white,
                this,
                "Background Color",
                QColorDialog::DontUseNativeDialog);

    if(c.isValid())
    {
        ui->imageBackColor->setBackgroundBrush(c);
    }
}

void ThemeCustomizationDialog::on_buttonBackImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("Background Image"),
                QString(),
                tr("Image Files (*.bmp *.png *.jpg *.jpeg *.svg)") );

    if(fileName.length() > 0)
    {
        ui->labelBackFile->setText(fileName);
    }
}

void ThemeCustomizationDialog::on_buttonFindImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("Finder Image"),
                QString(),
                tr("Image Files (*.svg)") );

    if(fileName.length() > 0)
    {
        ui->labelFindFile->setText(fileName);
    }
}

void ThemeCustomizationDialog::on_buttonPilotImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("Pilot Image"),
                QString(),
                tr("Image Files (*.svg)") );

    if(fileName.length() > 0)
    {
        ui->labelPilotFile->setText(fileName);
    }
}

void ThemeCustomizationDialog::on_buttonLineColor_clicked()
{
    QColor c = QColorDialog::getColor(
                Qt::black,
                this,
                "Line Color",
                QColorDialog::DontUseNativeDialog);

    if(c.isValid())
    {
        ui->imageLineColor->setBackgroundBrush(c);
    }
}
