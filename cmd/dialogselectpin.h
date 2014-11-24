#ifndef DIALOGSELECTPIN_H
#define DIALOGSELECTPIN_H

#include <QDialog>

namespace Ui {
class DialogSelectPin;
}

class DialogSelectPin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSelectPin(QWidget *parent = 0);
    ~DialogSelectPin();

private:
    Ui::DialogSelectPin *ui;
};

#endif // DIALOGSELECTPIN_H
