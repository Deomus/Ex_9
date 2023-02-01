#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setAutoFillBackground(true);
    backgroundPalette = ui->centralWidget->palette();
    backgroundPalette.setColor(QPalette::Background, Qt::gray);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// функция проверки значения на определенный тип
bool MainWindow::checkValue(bool flag, QColor color, QString typeName)
{

    if (flag)
    {
        backgroundPalette.setColor(QPalette::Background, color);
        ui->centralWidget->setPalette(backgroundPalette);
        ui->label_type->setText(typeName);

        return true;
    }
    return false;
}

// обраьотка нажатия на кнопку
void MainWindow::on_pushButton_answer_clicked()
{
    QString value = ui->lineEdit_input->text();
    bool flag;

    flag = value.isEmpty();
    if (checkValue(flag, Qt::red, "Пустая строка"))
        return;

    value.toLongLong(&flag);
    if (checkValue(flag, Qt::green, "Целочисленный"))
        return;

    value.toDouble(&flag);
    if (checkValue(flag, Qt::yellow, "Вещественный"))
        return;

    checkValue(true, Qt::gray, "Строка");

}
