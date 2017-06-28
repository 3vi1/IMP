#ifndef THEMECUSTOMIZER_H
#define THEMECUSTOMIZER_H

#include <QWidget>

namespace Ui {
class ThemeCustomizer;
}

class ThemeCustomizer : public QWidget
{
    Q_OBJECT

public:
    explicit ThemeCustomizer(QWidget *parent = 0);
    ~ThemeCustomizer();

private:
    Ui::ThemeCustomizer *ui;
};

#endif // THEMECUSTOMIZER_H
