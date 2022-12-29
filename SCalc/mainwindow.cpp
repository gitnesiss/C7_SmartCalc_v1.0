#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->gBox_graph->hide();
    ui->gBox_credit->hide();
    ui->gBox_deposit->hide();
    this->setGeometry(300, 300, 580, 562);
    this->setMaximumSize(580, 562);
    this->setMinimumSize(580, 562);

//    for (int i = 0; i < 200; i++) {
//        x.push_back(i);
//        y.push_back(QRandomGenerator::global()->generate() % 150);
//    }
//    // По поводу qrand()
//    // https://forum.qt.io/topic/115390/qt-5-15-depricated-qrand-is-deprecated-use-qrandomgenerator-instead

//    // Настроим систему координат
//    ui->widget->xAxis->setRange(0, 200);
//    ui->widget->yAxis->setRange(0, 250);

//    // Добавим график. Установим графику значения координатных осей из x и y
//    ui->widget->addGraph();
//    ui->widget->graph(0)->setData(x, y);

//    // Нарисуем график функцией
    ui->widget->replot();

    // Подключение зуммирования графика (без перемещения графика мышкой с зажатой кнопкой
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    // Подключение возможности перемещения графика с помощью зажатой кнопки мыши
    ui->widget->setInteraction(QCP::iRangeDrag, true);
}

// График, Кредитный калькулятор, Депозитный калькулятор
//    0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    x
//    .,    +,    -,    *,    /,  mod,    ^,    (,    ),    =
//        sin,  cos,  tan, asin, acos, atan, sqrt,  log,   ln

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pB_2_clicked()  // pBox_graph
{
    ui->gBox_graph->show();
    ui->gBox_credit->hide();
    ui->gBox_deposit->hide();
//    this->setGeometry(300, 300, 1260, 562);
    ui->gBox_graph->setGeometry(585, 5, 670, 530);
    this->setMaximumSize(1260, 562);
    this->setMinimumSize(1260, 562);
}

void MainWindow::on_pB_34_clicked()  // pBox_credit
{
    ui->gBox_graph->hide();
    ui->gBox_credit->show();
    ui->gBox_deposit->hide();
//    this->setGeometry(300, 300, 1260, 562);
    ui->gBox_credit->setGeometry(585, 5, 670, 530);
    this->setMaximumSize(1260, 562);
    this->setMinimumSize(1260, 562);
}

void MainWindow::on_pB_35_clicked()  // pBox_deposit
{
    ui->gBox_graph->hide();
    ui->gBox_credit->hide();
    ui->gBox_deposit->show();
//    this->setGeometry(300, 300, 1260, 562);
    ui->gBox_deposit->setGeometry(585, 5, 670, 530);
    this->setMaximumSize(1260, 562);
    this->setMinimumSize(1260, 562);
}

void MainWindow::on_pB_30_clicked()  // pBox_hide
{
//    this->setGeometry(300, 300, 580, 562);
    this->setMaximumSize(580, 562);
    this->setMinimumSize(580, 562);
    ui->gBox_graph->hide();
    ui->gBox_credit->hide();
    ui->gBox_deposit->hide();
//    this->setGeometry(300, 300, 580, 562);
}

void MainWindow::on_pB_1_clicked()
{
    QString s = ui->pB_16->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText("");
}

void MainWindow::on_pB_18_clicked()
{
    QString s = ui->pB_18->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_29_clicked()
{
    QString s = ui->pB_29->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_16_clicked()
{
    QString s = ui->pB_16->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_15_clicked()
{
    QString s = ui->pB_15->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_10_clicked()
{
    QString s = ui->pB_10->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_12_clicked()
{
    QString s = ui->pB_12->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_11_clicked()
{
    QString s = ui->pB_11->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_6_clicked()
{
    QString s = ui->pB_6->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_8_clicked()
{
    QString s = ui->pB_8->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_7_clicked()
{
    QString s = ui->pB_7->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_20_clicked()
{
    QString s = ui->pB_20->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_17_clicked()
{
    QString s = ui->pB_17->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_13_clicked()
{
    QString s = ui->pB_13->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_9_clicked()
{
    QString s = ui->pB_9->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_5_clicked()
{
    QString s = ui->pB_5->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_4_clicked()
{
    QString s = ui->pB_4->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_3_clicked()
{
    QString s = ui->pB_3->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_33_clicked()  // x
{
    QString s = ui->pB_33->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_31_clicked()  // (
{
    QString s = ui->pB_31->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_32_clicked()  // )
{
    QString s = ui->pB_32->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_14_clicked()  // sin
{
    QString s = ui->pB_14->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_21_clicked()  // cos
{
    QString s = ui->pB_21->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_22_clicked()  // tan
{
    QString s = ui->pB_22->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_23_clicked()  // asin
{
    QString s = ui->pB_23->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_24_clicked()  // acos
{
    QString s = ui->pB_24->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_25_clicked()  // atan
{
    QString s = ui->pB_25->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_26_clicked()  // sqrt
{
    QString s = ui->pB_26->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_27_clicked()  // log
{
    QString s = ui->pB_27->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_28_clicked()  // ln
{
    QString s = ui->pB_28->text();
    QString str= ui->lineEdit->text();
    ui->lineEdit->setText(str + s);
}

void MainWindow::on_pB_19_clicked()  // =
{
    QString text = ui->lineEdit->text();
    QString result;
    QString text_x = ui->lineEdit_2->text();
    double x;
//    text.replace(" ", "");

    double res = 0;
    if (text_x == "") {
        x = 0;
    } else {
        x = text_x.toDouble();
    }
    int error = 0;
    const char *cLine;
    QByteArray inArr = text.toUtf8();
    cLine = inArr.constData();
//    qDebug() << res;
//    qDebug() << x;
//    qDebug() << cLine;

    error = calc(cLine, x, &res);

    if (error == 0) {
      ui->lineEdit->setText(result.setNum(res));
    } else {
      ui->lineEdit->setText("ERROR = " + text.setNum(error));
    }
//    qDebug() << "res " << res;
//    qDebug() << "x " << x;
}

void MainWindow::print()
{
    QString xst = ui->spinBox_9->text();  // отрезок на поле графика диапазона отрисовки точек Х min
    double  x_start = xst.toDouble();
    QString xfi = ui->spinBox_10->text();  // отрезок на поле графика диапазона отрисовки точек  X max
    double  x_finish = xfi.toDouble();
    QString toc = ui->spinBox_11->text();  // отрезок на поле графика диапазона отрисовки точек Количество точек
    double tochnost = toc.toDouble();

    QString xmi = ui->spinBox_5->text();  // x_min
    double  x_min = xmi.toDouble();
    QString xma = ui->spinBox_6->text();  // x_max
    double  x_max = xma.toDouble();

    QString ymi = ui->spinBox_7->text();  // y_min
    double  y_min = ymi.toDouble();
    QString yma = ui->spinBox_8->text();  // y_max
    double  y_max = yma.toDouble();

    QString res;
    QString function = ui->lineEdit->text();
    function = function.toLower();
//    qDebug() << "function " << function;
    const char *cLine;
    QByteArray inArr = function.toUtf8();
    cLine = inArr.constData();
//    qDebug() << "cLine " << cLine;
    int num_error = 0;
    double result = 0;

    double step = 1/tochnost;
    QVector<double> x((abs(x_start) + x_finish)*tochnost), y((abs(x_start) + x_finish)*tochnost); // initialize with entries 0..100
    double otrezok = 0;
    if ((x_start < 0 && x_finish < 0) ||
            (x_start > 0 && x_finish > 0)) {
        otrezok = x_finish - x_start;
    } else {
        otrezok = x_finish + abs(x_start);
    }
    int l = otrezok * tochnost;
    for (int i=0; i<l; i++) {
        num_error = calc(cLine,x_start,&result);
        x[i] = x_start; // x goes from -1 to 1
        y[i] = result; // let's plot a quadratic function
        x_start += step;
    }
    if (num_error > 0) {
        res = res.setNum(num_error);
        ui->lineEdit->setText("ERROR = " + res) ;
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QColor(255, 100, 0));  //задаем цвет точки

    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);//убираем линии
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 0.5));
    ui->widget->graph(0)->setData(x, y);
    ui->widget->xAxis->setRange(x_min, x_max);// ось Х
    ui->widget->yAxis->setRange(y_min, y_max);// ось У
    ui->widget->replot();
}

void MainWindow::on_pB_39_clicked()  // pB_39 Graph
{
    print();
}

void MainWindow::on_spinBox_8_textChanged(const QString &arg1)  // y_max spinBox_8
{
    QString src_min = ui->spinBox_7->text();
    int max = arg1.toInt();
    int min = src_min.toInt();
    if (max <= min) {
        max = min + 1;
        ui->spinBox_8->setValue(max);
    }
    print();
}

void MainWindow::on_spinBox_7_textChanged(const QString &arg1)  // y_min spinBox_7
{
    QString src_max = ui->spinBox_8->text();
    int max = src_max.toInt();
    int min = arg1.toInt();
    if (min >= max) {
        min = max - 1;
        ui->spinBox_7->setValue(min);
    }
    print();
}

void MainWindow::on_spinBox_5_textChanged(const QString &arg1)  // x_min spinBox_5
{
    QString src_max = ui->spinBox_6->text();
    int max = src_max.toInt();
    int min = arg1.toInt();
    if (min >= max) {
        min = max - 1;
        ui->spinBox_5->setValue(min);
    }
    print();
}

void MainWindow::on_spinBox_6_textChanged(const QString &arg1)  // y_max spinBox_6
{
    QString src_min = ui->spinBox_5->text();
    int max = arg1.toInt();
    int min = src_min.toInt();
    if (max <= min) {
        max = min + 1;
        ui->spinBox_6->setValue(max);
    }
    print();
}

void MainWindow::on_spinBox_9_textChanged(const QString &arg1)
{
    QString src_max = ui->spinBox_10->text();
    int max = src_max.toInt();
    int min = arg1.toInt();
    if (min >= max) {
        min = max - 1;
        ui->spinBox_9->setValue(min);
    }
    print();
}

void MainWindow::on_spinBox_10_textChanged(const QString &arg1)
{
    QString src_min = ui->spinBox_9->text();
    int max = arg1.toInt();
    int min = src_min.toInt();
    if (max <= min) {
        max = min + 1;
        ui->spinBox_10->setValue(max);
    }
    print();
}

void MainWindow::on_spinBox_11_textChanged(const QString &arg1)
{
    print();
}

void MainWindow::on_pB_36_clicked()  // pb_36 Credit (Annuit and Different)
{
    QString res_cred_summa = ui->lineEdit_3->text();  // снятие данных с поля Сумма кредита
    double cred_summa = res_cred_summa.toDouble();
    QString res_cred_percent = ui->doubleSpinBox->text();  // снятие данных с поля Процентная ставка
    double cred_percent = res_cred_percent.toDouble();
    QString res_cred_time = ui->spinBox->text();  // снятие данных с поля Процентная ставка
    double cred_time = res_cred_time.toDouble();

    cred_percent = cred_percent/1200;

    QString pl = "";
    QString it = "";
    QString c = "";
    QString per = "";

    if (ui->annuit->isChecked()) {
        double platez = cred_summa * cred_percent / ((1 - pow((1 + cred_percent),-cred_time)));
        double itog = cred_time * platez;
        pl = pl.setNum(platez);
//        pl = QString::number(platez, 'g', 20);
        ui->lineEdit_7->setText(pl);

        it = it.setNum(itog);
//        it = QString::number(itog, 'f', 20);
        ui->lineEdit_9->setText(it);

        per= per.setNum(itog-cred_summa);
//        per= QString::number(itog-cred_summa, 'g', 12);
        ui->lineEdit_8->setText(per);

        double flag_string = cred_time;
        double count = 1;
        while (cred_time) {
            QString kr= ui->textEdit->toPlainText();
            if (cred_time != flag_string) {
                ui->textEdit->setText(kr + "\n" + c.setNum(count) + ":\t" + it.setNum(platez));
            } else {
                ui->textEdit->setText(c.setNum(count) + ":\t" + it.setNum(platez));
            }
            ui->lineEdit_9->setText(it.setNum(itog));
            cred_time--;
            count++;
        }
//        ui->textEdit->hide();
//        ui->textEdit->setText("");
    } else if (ui->differen->isChecked()) {
        ui->textEdit->setText("");
        ui->textEdit->show();
        double itog = 0;

        double part = cred_summa / cred_time;
        ui->lineEdit_7->setText(pl.setNum(part));

        double flag_string = cred_time;
        double count = 1;
        while (cred_time) {
            QString kr= ui->textEdit->toPlainText();
            double platez;
            platez = cred_summa * cred_percent + cred_summa / cred_time;
            itog += platez;
            if (cred_time != flag_string) {
                ui->textEdit->setText(kr + "\n" + c.setNum(count) + ":\t" + it.setNum(platez));
            } else {
                ui->textEdit->setText(c.setNum(count) + ":\t" + it.setNum(platez));
            }
            ui->lineEdit_9->setText(it.setNum(itog));
            cred_summa = cred_summa - part;
            cred_time--;
            count++;
        }
        part = 0;
        ui->lineEdit_7->setText(pl.setNum(part));
        double perepl;
        perepl = itog - res_cred_summa.toDouble();
        ui->lineEdit_8->setText(per.setNum(perepl));
    } else {
        ui->lineEdit_9->setText(it);
        ui->lineEdit_7->setText(pl);
        ui->lineEdit_8->setText(per);
    }
}

void MainWindow::on_pB_38_clicked()  // pb_38 Deposit_calc
{
    QString nal = ui->D_nalog->text();  //налог
    double nalog = nal.toDouble() / 100;

    QString stcb = ui->D_stavka_cb->text();  //ставка ЦБ
    double cb = stcb.toDouble() / 100;

    QString per = ui->m_plus->text();  //переиод пополнения
    int dop_period = per.toDouble();
    QString dvk = ui->v_dop->text();  //сумма пополнения
    double dop_vklad = dvk.toDouble();

    QString per2 = ui->m_minus->text();  //переиод снятия
    int snyarie_period = per2.toDouble();
    QString mvk = ui->v_minus->text();  //сумма снятия
    double minus_vklad = mvk.toDouble();

    if (dop_period == 0) {
        dop_period = 1;
        dop_vklad = 0;
    }

    if (snyarie_period == 0) {
        snyarie_period = 1;
        minus_vklad = 0;
    }

    QString m = ui->dat->text();
    double month = m.toDouble();
    QString y = ui->year->text();
    int year = y.toInt();
    QString itog;
    QString ks = ui->v_sum->text();
    double ksum = ks.toDouble();
    QString sr = ui->v_srok->text();
    double srok = sr.toDouble();
    QString st = ui->v_stavka->text();
    double stavka = st.toDouble() / 100;
    double newsum = ksum;
    double bonus = 0;
    double days;  // дней в месяце
    int len_year = 365;
    QString s,b,rez,head;
    QString p_viplat = ui->p_viplat->text();
    int p_v= p_viplat.toDouble();
    int count = 1;
    head ="MM - YYYY  -  Сумма  -  Капитализация  -  Пополнение  -  Снятие  -  Налог\n";
    ui->result->setText(head + m.setNum(month) + "  -  " + y.setNum(year) + "  -  " + s.setNum(newsum) + "  -  " + b.setNum(bonus)+"\n");
    double nalogi;
    for (int i = 1; i <= srok; i++) {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            days = 31;
        } else if (month == 2) {
            days = 28;
        } else {
            days = 30;
        }

        bonus = (newsum * (stavka / len_year)) * days;
        if (stavka > cb) {
            nalogi = ((stavka - cb) * bonus) * nalog;
            bonus -= nalogi;
            nal = nal.setNum(nalogi);
        } else {
            nal = "0";
        }
        newsum += bonus;

        rez = ui->result->toPlainText();
        month++;
        if (month == 13) {
            month = 1;
            year++;
            if ((year% 4) == 0) {
                len_year = 366;
            } else {
                len_year = 365;
            }
        }
        if (i % dop_period == 0 && i != srok){  //пополнение вклада
            newsum += dop_vklad;
            dvk = dvk.setNum(dop_vklad);
        } else {
            dvk = "0";
        }

        if ( i % snyarie_period == 0 && i != srok){  //снятие со вклада
            newsum -= minus_vklad;
            mvk = "(-" + mvk.setNum(minus_vklad) + ")";
        } else {
            mvk = "0";
        }
        if (count%p_v == 0) {
            ui->result->setText(rez + m.setNum(month) + "  -  " + y.setNum(year) + "  -  " + s.setNum(newsum) + "  -  " + b.setNum(bonus)
                                + "  -  " + dvk + "  -  " + mvk + "  -  " + nal + "\n");
        }
        count++;
    }
    ui->v_itog->setText(itog.setNum(newsum));
}


void MainWindow::on_action_triggered()
{
    QApplication::quit();
}
