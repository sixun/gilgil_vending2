#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void changemoney(int n);
    int money{0};

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbcoffee_clicked();

    void on_pbtea_clicked();

    void on_pbgongcha_clicked();

    void on_pushButton_clicked();

    void on_pbmoneyback_clicked();

    void on_pbmnbk_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
