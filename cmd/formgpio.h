#ifndef FORMGPIO_H
#define FORMGPIO_H

#include <QWidget>

namespace Ui {
class FormGpio;
}

class FormGpio : public QWidget
{
    Q_OBJECT

public:
    explicit FormGpio(QWidget *parent = 0);
    ~FormGpio();

private:
    Ui::FormGpio *ui;
};

#endif // FORMGPIO_H
