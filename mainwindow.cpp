#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkValue(bool flag, QColor color, QString typeName)
{

    if (flag)
    {
        ui->centralWidget->setAutoFillBackground(true);
        QPalette backgroundPalette = ui->centralWidget->palette();
        backgroundPalette.setColor(QPalette::Background, color);

        ui->centralWidget->setPalette(backgroundPalette);
        ui->label_type->setText(typeName);

        return true;
    }
    return false;
}

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
