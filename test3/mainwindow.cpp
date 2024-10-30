#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{

}

MainWindow::~MainWindow()
{
    setUpUI();
}

void MainWindow::setUpUI(){
    QWidget *w = new QWidget();
    this->setWindowTitle((new QString)->fromStdString("TODO List Application"));
    this->setFixedSize(*new QSize(300, 400));
    setCentralWidget(w);
    lineEdit = new QLineEdit();
    listWidget = new QListWidget();
    clear = new QPushButton();
    remove = new QPushButton();
    add = new QPushButton();
    QVBoxLayout *vBox = new QVBoxLayout(w);
    vBox->addWidget(lineEdit);
    vBox->addWidget(add);
    vBox->addWidget(listWidget);
    vBox->addWidget(remove);
    vBox->addWidget(clear);
    connect(add, &QPushButton::clicked , &MainWindow::addf);
    connect(remove, &QPushButton::clicked , &MainWindow::removef);
    connect(clear, &QPushButton::clicked , &MainWindow::clearf);

}

void MainWindow::addf() {
    if(!lineEdit->text().isEmpty()) {
        QString qs = lineEdit->text();
        listWidget->addItem(qs);
    }
}

void MainWindow::removef() {
    if(!listWidget->selectedItems().empty()) {
        QList<QListWidgetItem *> ql = listWidget->selectedItems();
        for(int i=0; i<ql.size(); i++) {
            listWidget->removeItemWidget(ql.at(i));
        }
    }
}

void MainWindow::clearf() {
    listWidget->clear();
}
