#include "dialog.h"
#include "ui_dialog.h"

#include <QSizePolicy>

#include "gomokuboardwidget.h"
#include "createserverdialog.h"
#include "connectserverdialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_board(new GomokuBoardWidget(this))
{
    ui->setupUi(this);
    ui->horizontalLayout->insertWidget(0, m_board, 2);

    connect(ui->pushButton_create, SIGNAL(clicked(bool)), this, SLOT(showCreateServerDialog()));
    connect(ui->pushButton_connect, SIGNAL(clicked(bool)), this, SLOT(showConnectServerDialog()));
}

void Dialog::showCreateServerDialog()
{
    CreateServerDialog dlg(this);
    dlg.exec();
}

void Dialog::showConnectServerDialog()
{
    ConnectServerDialog dlg(this);
    dlg.exec();
}

Dialog::~Dialog()
{
    delete ui;
}
