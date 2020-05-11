#ifndef WINDOWSAVEFILE_H
#define WINDOWSAVEFILE_H

#include <QDialog>

namespace Ui {
class WindowSaveFile;
}

class WindowSaveFile : public QDialog
{
    Q_OBJECT

public:
    explicit WindowSaveFile(QWidget *parent = nullptr);
    ~WindowSaveFile();

    QString mFilename;
    QString mFileroute;

    void setFilename(QString Filename) { mFilename = Filename; }
    QString Filename() const { return mFilename; }
private slots:
    void on_ok_button_clicked();

    void on_cancel_button_clicked();

private:
    void checked();
private:

    Ui::WindowSaveFile *ui;
};

#endif // WINDOWSAVEFILE_H
