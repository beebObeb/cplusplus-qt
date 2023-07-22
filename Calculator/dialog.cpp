#include "dialog.h"
#include "ui_dialog.h"

#include<QDebug>

#include<fstream>
#include<string>
#include<cstring>
#include<unistd.h>
#include<iostream>
#include<sstream>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //connection

    connect(ui->one,SIGNAL(clicked(bool)),this,SLOT(one_clicked()));
    connect(ui->two,SIGNAL(clicked(bool)),this,SLOT(two_clicked()));
    connect(ui->three,SIGNAL(clicked(bool)),this,SLOT(three_clicked()));
    connect(ui->four,SIGNAL(clicked(bool)),this,SLOT(four_clicked()));
    connect(ui->five,SIGNAL(clicked(bool)),this,SLOT(five_clicked()));
    connect(ui->six,SIGNAL(clicked(bool)),this,SLOT(six_clicked()));
    connect(ui->seven,SIGNAL(clicked(bool)),this,SLOT(seven_clicked()));
    connect(ui->eight,SIGNAL(clicked(bool)),this,SLOT(eight_clicked()));
    connect(ui->nine,SIGNAL(clicked(bool)),this,SLOT(nine_clicked()));
    connect(ui->zero,SIGNAL(clicked(bool)),this,SLOT(zero_clicked()));
    connect(ui->plus,SIGNAL(clicked(bool)),this,SLOT(plus_clicked()));
    connect(ui->times,SIGNAL(clicked(bool)),this,SLOT(times_clicked()));
    connect(ui->divide,SIGNAL(clicked(bool)),this,SLOT(divide_clicked()));
    connect(ui->dot,SIGNAL(clicked(bool)),this,SLOT(dot_clicked()));
    connect(ui->minus, SIGNAL(clicked(bool)), this, SLOT(minus_clicked()));
    connect(ui->clear, SIGNAL(clicked(bool)), this, SLOT(clear_clicked()));
    connect(ui->equal, SIGNAL(clicked(bool)), this, SLOT(equal_clicked()));
}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::one_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '1';
    ui->display->clear();
    ui->display->setText(qstr);
}

void Dialog::two_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '2';
    ui->display->clear();
    ui->display->setText(qstr);

}
void Dialog::three_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '3';
    ui->display->clear();
    ui->display->setText(qstr);

}
void Dialog::four_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '4';
    ui->display->clear();
    ui->display->setText(qstr);

}

void Dialog::five_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '5';
    ui->display->clear();
    ui->display->setText(qstr);

}

void Dialog::six_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '6';
    ui->display->clear();
    ui->display->setText(qstr);

}

void Dialog::seven_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '7';
    ui->display->clear();
    ui->display->setText(qstr);

}
void Dialog::eight_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '8';
    ui->display->clear();
    ui->display->setText(qstr);

}
void Dialog::nine_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '9';
    ui->display->clear();
    ui->display->setText(qstr);

}

void Dialog::zero_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '0';
    ui->display->clear();
    ui->display->setText(qstr);

}

void Dialog::plus_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '+';
    ui->display->clear();
    ui->display->setText(qstr);

}
void Dialog::minus_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '-';
    ui->display->clear();
    ui->display->setText(qstr);

}
void Dialog::times_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '*';
    ui->display->clear();
    ui->display->setText(qstr);

}
void Dialog::divide_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '/';
    ui->display->clear();
    ui->display->setText(qstr);

}

void Dialog::dot_clicked()
{
    computed();

    auto qstr = ui->display->text();
    qstr += '.';
    ui->display->clear();
    ui->display->setText(qstr);
}

void Dialog::clear_clicked()
{
    ui->display->clear();
}

void Dialog::equal_clicked()
{
    auto qstr = ui->display->text();
    std::string str = qstr.toStdString();

    std::string command = "echo '" + str + " ;scale=3;'" + "| bc >> ans.txt";

    // file to communicate the result with

    std::system(command.c_str());
    std::ifstream in("ans.txt", std::ios::in);

    //read the file

    str = "";

    while (!in.eof())
        str += in.get();

    //sanitize the result

    str = str.substr(0, str.size()-2);

    //delete the file

    std::system("rm ans.txt");

    //print the result

    qstr = QString::fromStdString(str);
    ui->display->clear();
    qstr  = "=" + qstr;

    //set the flag

    ui->display->setText(qstr);
    is_computed = true;
}

void Dialog::computed()
{
    if (is_computed)
    {
        is_computed = false;
        ui->display->clear();
    }
}
