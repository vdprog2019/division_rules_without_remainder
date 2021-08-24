#include "price_proj_qt.h"

int cnt_digits(int num) { return (num /= 10) ? 1 + cnt_digits(num) : 1; }

price_proj_qt::price_proj_qt(QWidget *parent)
    : QWidget(parent)
{
   
    ui.setupUi(this);

    //стартовые примеры для бокса 
    ui.comboBox->addItem("Choose example");
    ui.comboBox->addItem("Product, '" + QString::number(pr) + "' grn., count '" + QString::number(f_e) + "', Discount '" + QString::number(s_e) + "'.");
    ui.comboBox->addItem("Product, '" + QString::number(pr_2) + "' grn., count '" + QString::number(f_e_2) + "', Discount '" + QString::number(s_e_2) + "'.");
    ui.comboBox->addItem("Product, '" + QString::number(pr_3) + "' grn., count '" + QString::number(f_e_3) + "', Discount '" + QString::number(s_e_3) + "'.");

    connect(ui.pushButton, SIGNAL(clicked()), SLOT(create_price()));
    connect(ui.comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) { 
                                                                                if (ui.comboBox->currentIndex() == 1) {
                                                                                    ui.lineEdit->setText(QString::number(pr));
                                                                                    ui.lineEdit_2->setText(QString::number(f_e));
                                                                                    ui.lineEdit_3->setText(QString::number(s_e));
                                                                                }
                                                                                if (ui.comboBox->currentIndex() == 2) {
                                                                                    ui.lineEdit->setText(QString::number(pr_2));
                                                                                    ui.lineEdit_2->setText(QString::number(f_e_2));
                                                                                    ui.lineEdit_3->setText(QString::number(s_e_2));
                                                                                }
                                                                                if (ui.comboBox->currentIndex() == 3) {
                                                                                    ui.lineEdit->setText(QString::number(pr_3));
                                                                                    ui.lineEdit_2->setText(QString::number(f_e_3));
                                                                                    ui.lineEdit_3->setText(QString::number(s_e_3));
                                                                                }
                                                                                if (ui.comboBox->currentIndex() == 0) {
                                                                                    ui.lineEdit->setText("");
                                                                                    ui.lineEdit_2->setText("");
                                                                                    ui.lineEdit_3->setText("");
                                                                                }
                                                                                });
}


void price_proj_qt::create_price() {
    
    f_1 = ui.lineEdit->text();
    f_2 = ui.lineEdit_2->text();
    f_3 = ui.lineEdit_3->text();
    res = "Product, '" + f_1 + "' grn. , count '" + f_2 + "' , Discount '" + f_3 + "'.";
    
    //if (f_2.isEmpty() || f_3.isEmpty()) {
    //    QMessageBox::warning(this, tr("Line is empty"), tr("Please write something on lines with *"), QMessageBox::Ok);
    //}

    std::vector<QString> v;
    v.push_back(res);

    if (f_3.toInt() % f_2.toInt() == 0) {
        for (int i = 0; i < v.size(); i++)
            ui.listWidget->addItem(v[i]);
    }
    else {
        for (int i = 0; i < v.size(); i++)
            ui.listWidget_2->addItem(v[i]);
        
        QString str_lenght = QString::number(f_3.length());
        int f_n = f_2.toInt(); // первое
        int n = f_3.toInt() - 1; int n_ = f_3.toInt() - 2;
        int n1 = f_2.toInt() - 1;
        int n2 = f_2.toInt() - n1;
        QMessageBox m;
        
        // 3 23
        // 2 7
        // 1 2
        
        if (str_lenght == '1' /*|| str_lenght == '2'*/) {
            if (f_3.toInt() % 2 == 1) {
                f_3.toInt() - 1; 
                int n__res = n / 2; int r = f_3.toInt() - n;
                ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n1) + "' , Discount '" + QString::number(n__res) + "'.");
                ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n2) + "' , Discount '" + QString::number(r) + "'.");
                ui.listWidget_3->update();
            }
            else if (f_3.toInt() % 2 == 0) {
                f_3.toInt() - 2;
                int n_res = n_ / 2;
                int r = f_3.toInt() - n_;
                ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n1) + "' , Discount '" + QString::number(n_res) + "'.");
                ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n2) + "' , Discount '" + QString::number(r) + "'.");
                ui.listWidget_3->update();
            }
        }
        else if (str_lenght == '2' || str_lenght == '3' || str_lenght == '4' || str_lenght == '5' || str_lenght == '6') {
            f_2.toInt() - 1;
            if (f_2.toInt() - 1 == 3 || f_2.toInt() - 1 == 9) {
                long double p = ("%.9f", (f_3.toDouble() - 1) / (f_2.toDouble() - 1));  
                int r = f_3.toInt() - n;
                printf("%.9f", p);
                std::string s = std::to_string(("%.9f", p));

                char buff[100];
                sprintf(buff, "%.9f", p);
                std::string a(buff);

                ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n1) + "' , Discount '" + a.c_str() + "'.");
                ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n2) + "' , Discount '" + QString::number(r) + "'.");

            }
            else if (f_2.toInt() - 1 == 5) {
                int val = f_3.toInt();
                int l_n = val % 10;
                qDebug() << l_n;
                if (l_n == 0 || l_n == 5) {
                    ui.listWidget->addItem(("Product, '" + f_1 + "' grn. , count '" + f_2 + "' , Discount '" + f_3 + "'."));
                }
                else {
                    int n_ = val - l_n;
                    int res_v = n_ / n1;
                    ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n1) + "' , Discount '" + QString::number(res_v) + "'.");
                    ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n2) + "' , Discount '" + QString::number(l_n) + "'.");
                }
            }
            else if (f_2.toInt() - 1 == 4) {

                int val = f_3.toInt();
                int l_n = val % 100;
                qDebug() << l_n;
                if (l_n == 00 || l_n % 4 == 0) {
                    ui.listWidget->addItem(("Product, '" + f_1 + "' grn. , count '" + f_2 + "' , Discount '" + f_3 + "'."));
                }
                else {
                    int num = f_3.toInt() - l_n;
                    int r = num / n1;
                    ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n1) + "' , Discount '" + QString::number(r) + "'.");
                    ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n2) + "' , Discount '" + QString::number(l_n) + "'.");
                }
            }
            else if (f_2.toInt() - 1 == 8) {
                int val = f_3.toInt();
                int l_n = val % 1000;
                if (l_n == 000 || l_n % 4 == 0) {
                    ui.listWidget->addItem(("Product, '" + f_1 + "' grn. , count '" + f_2 + "' , Discount '" + f_3 + "'."));
                }
                else {
                    int num = f_3.toInt() - l_n;
                    int r = num / n1;
                    ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n1) + "' , Discount '" + QString::number(r) + "'.");
                    ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n2) + "' , Discount '" + QString::number(l_n) + "'.");
                }
            }
            else if (f_2.toInt() - 1 == 10) {
                int val = f_3.toInt();
                int l_n = val % 10;
                if (l_n == 0) {
                    ui.listWidget->addItem(("Product, '" + f_1 + "' grn. , count '" + f_2 + "' , Discount '" + f_3 + "'."));
                }
                else {
                    int num = f_3.toInt() - l_n;
                    int r = num / n1;
                    ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n1) + "' , Discount '" + QString::number(r) + "'.");
                    ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n2) + "' , Discount '" + QString::number(l_n) + "'.");
                }
            }
            else if (f_2.toInt() - 1 == 2) {
                int val = f_3.toInt();
                int l_n = val % 10;
                if (l_n % 2 == 0) {
                    ui.listWidget->addItem(("Product, '" + f_1 + "' grn. , count '" + f_2 + "' , Discount '" + f_3 + "'."));
                }
                else {
                    f_3.toInt() - 1;
                    int num = f_3.toInt() - 1;
                    int r = num / n1;
                    int rr = f_3.toInt() - num;
                    ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n1) + "' , Discount '" + QString::number(r) + "'.");
                    ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n2) + "' , Discount '" + QString::number(rr) + "'.");
                }
            }
            else if (f_2.toInt() - 1 == 25) {
                int val = f_3.toInt();
                int l_n = val % 100;
                if (l_n % 2 == 00 || l_n % 25 ==0) {
                    ui.listWidget->addItem(("Product, '" + f_1 + "' grn. , count '" + f_2 + "' , Discount '" + f_3 + "'."));
                }
                else {
                    int num = f_3.toInt() - l_n;
                    int r = num / n1;
                    ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n1) + "' , Discount '" + QString::number(r) + "'.");
                    ui.listWidget_3->addItem("Product, '" + f_1 + "' grn. , count '" + QString::number(n2) + "' , Discount '" + QString::number(l_n) + "'.");
                }
            }
            else if (f_2.toInt() - 1 == 11) {
                int n = f_3.toInt();
                int sum1 = 0, sum2 = 0;
                for (int i = 1; n > 0; i++) {
                    int tmp = n % 10;
                    if (i % 2 == 0) {
                        sum2 += tmp;
                    }
                    else {
                        sum1 += tmp;
                    };
                    n /= 10;
                };
                if ((sum2 - sum1) % 11 == 0) {
                    qDebug() << "ok" << endl;
                    ui.listWidget->addItem(("Product, '" + f_1 + "' grn. , count '" + f_2 + "' , Discount '" + f_3 + "'."));
                }
                else {
                    qDebug() << "error" << endl;
                }
            }
            
            
        }

        // 13 5525 

        //7 3754 
        //6 

        // 6 1233
        // 5 1233 - 3 == 1230
        // 1 3

        // 4        2 + 7 + 4
        // 3        2 + 7 + 3
        // 1        1
        // 
        // 
        // 4        3 + 4 + 8
        // 3        3 + 4 + 7
        // 1        1 




    }

}


    