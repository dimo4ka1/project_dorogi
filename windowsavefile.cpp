#include "windowsavefile.h"
#include "ui_windowsavefile.h"
#include<QPushButton>

WindowSaveFile::WindowSaveFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowSaveFile)
{

    ui->setupUi(this);

}

WindowSaveFile::~WindowSaveFile()
{
    delete ui;
}



void WindowSaveFile::on_ok_button_clicked()
{
    setFilename(ui->filename->text());

  close();

}

void WindowSaveFile::on_cancel_button_clicked()
{
    close();
}
