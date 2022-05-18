#include "logindialog.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>
#include "picosha2.h"

LoginDialog::LoginDialog(QWidget* parent)
    :QDialog(parent)
{
    setUpGUI();
    setWindowTitle( tr("User Login") );
    setModal( true );
}

void LoginDialog::setUpGUI(){


    QGridLayout* formGridLayout = new QGridLayout( this );


    editUsername = new QLineEdit( this );
    editPassword = new QLineEdit( this );
    editPassword->setEchoMode( QLineEdit::Password );

    labelUsername = new QLabel( this );
    labelUsername->setText( tr( "Username" ) );
    labelUsername->setBuddy( editUsername );

    labelPassword = new QLabel( this );
    labelPassword->setText( tr( "Password" ) );
    labelPassword->setBuddy( editPassword );


    buttons = new QDialogButtonBox( this );
    buttons->addButton( QDialogButtonBox::Ok );
    buttons->addButton( QDialogButtonBox::Cancel );
    buttons->button( QDialogButtonBox::Ok )->setText( tr("Login") );
    buttons->button( QDialogButtonBox::Cancel )->setText( tr("Cancel") );

    connect( buttons->button( QDialogButtonBox::Cancel ),
        SIGNAL (clicked()),
        this,
        SLOT (close())
        );

    connect( buttons->button( QDialogButtonBox::Ok ),
        SIGNAL (clicked()),
        this,
        SLOT (slotAcceptLogin()) );


    formGridLayout->addWidget( labelUsername, 0, 0 );
    formGridLayout->addWidget( editUsername, 0, 1 );
    formGridLayout->addWidget( labelPassword, 1, 0 );
    formGridLayout->addWidget( editPassword, 1, 1 );
    formGridLayout->addWidget( buttons, 2, 0, 1, 2 );
    setLayout( formGridLayout );

}

void LoginDialog::setUsername(QString &username){

   editUsername->setText(username);
}

void LoginDialog::setPassword(QString &password){

    editPassword->setText( password );
}

void LoginDialog::slotAcceptLogin(){
    QString notFound = "Profile not found, check login information";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("C://Users/luisr/OneDrive/Desktop/QT stuff/BulkClub-System_v6/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,

    db.open();                                                                  //the .db file should be kept within the repository for now

    QString username = editUsername->text(); //pulls the values from the text edit lines
    QString password = editPassword->text();
    std::string passStr = password.toStdString();

    QSqlQueryModel model;//model is readonly access to query results
    QSqlRecord record;//record accesses records returned by a query
    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE username=(:name)");
    query.bindValue(":name",username);
    query.exec(); //query must be active before being moved into the model

    model.setQuery(std::move(query));
    record = model.record(0); //sets the record to the first record in the query results
    QString hashToComp = record.value(1).toString();
    QString salt = record.value(3).toString();
    passStr.append(salt.toStdString());

    //Hash stuff not worth worrying about, generates a hash to compare against the value in the db
    std::vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(passStr.begin(),passStr.end(),hash.begin(),hash.end());
    std::string saltedHashStr = picosha2::bytes_to_hex_string(hash.begin(),hash.end());
    QString saltedHash = saltedHash.fromStdString(saltedHashStr);

    bool admin = record.value(2).toBool();

    if (QString::compare(hashToComp,saltedHash,Qt::CaseSensitive) == 0){
        qDebug().noquote() << "correct login";

        if(admin){
            qDebug().noquote() << "Logging in as admin";
            adminWindow = new Admin;
            adminWindow->show();
        }
        else{
            qDebug().noquote() << "Logging in as a user";
            StoreManagerWindow = new StoreManager;
            StoreManagerWindow->show();
        }

        this->close();
    }
    else{
        qDebug().noquote() << notFound;
    }
}
