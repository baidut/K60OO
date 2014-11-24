#include "dialogselectpin.h"
#include "ui_dialogselectpin.h"

DialogSelectPin::DialogSelectPin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSelectPin)
{
    ui->setupUi(this);
}

DialogSelectPin::~DialogSelectPin()
{
    delete ui;
}

// 默认为Gpio，即全部管脚，可以设置为筛选含有某功能的管脚
// 从管脚图中读取空闲的管脚，显示满足条件的管脚，确认后将空闲管脚设置成使用为某个功能
// 管脚图采用小型数据库比较直观，更容易操作

// 后期可以显示单片机各个引脚，允许拖动配置引脚，更加直观
