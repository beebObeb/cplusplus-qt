#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void one_clicked();
    void two_clicked();
    void three_clicked();
    void four_clicked();
    void five_clicked();
    void six_clicked();
    void seven_clicked();
    void eight_clicked();
    void nine_clicked();
    void zero_clicked();
    void plus_clicked();
    void times_clicked();
    void minus_clicked();
    void divide_clicked();
    void dot_clicked();
    void clear_clicked();
    void equal_clicked();
private:
    Ui::Dialog *ui;
    //flag
    bool is_computed = false;

    //misc func

    void computed();
};
#endif // DIALOG_H
