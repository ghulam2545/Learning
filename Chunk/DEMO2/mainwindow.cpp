#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn1_clicked()
{
    QMessageBox::about(this, "About me", "This is a text about me.");
}


void MainWindow::on_btn2_clicked()
{
    QMessageBox::aboutQt(this,"About Qt");
}


void MainWindow::on_btn3_clicked()
{
    QMessageBox::critical(this, "Cross work", "This button says doing cross work");
}


void MainWindow::on_btn4_clicked()
{
    QMessageBox::information(this, "Info share", "This info is sharing to you");
}


void MainWindow::on_btn5_clicked()
{
    QMessageBox::question(this, "Argee", "Are you agree with T&C");
}


void MainWindow::on_btn6_clicked()
{
    QMessageBox::warning(this, "Harm", "This will erase your all data");
}

