#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "rus");
    QCoreApplication a(argc, argv);

    QFile file("D:\\Projects\\C++\\qt\\chMode\\test.json");
    QByteArray content;

    if(file.open(QIODevice::ReadOnly|QIODevice::Text) == true)
    {
        content.append(file.readAll());
    }
    else
    {
        qInfo()<<"file open is false";
    }

    auto doc = QJsonDocument::fromJson(content).object();

//    for(auto i : doc.keys())
//    {
//        qInfo()<<i;
//        for(auto j : doc.value(i).toObject().keys())
//        {
//            qInfo()<<j<<" : "<<doc.value(i).toObject().value(j).type();
//        }
//    }

    if
    (
        doc.find("row1")->isUndefined() == false
        &&
        doc.value("row1").toObject().value("isActivate").toBool() ==true
    )
    {
        auto row = doc.value("row1").toObject();
        auto rowLength = doc.value("rowLength").toInt();

        auto firsNumber = row.value("firsNumber").toString();
        auto Name = row.value("Name").toString();
        auto Number = row.value("Number").toString();
        auto lastNumber = row.value("lastNumber").toString();
        auto fill = rowLength - firsNumber.length() - Name.length() - Number.length() - lastNumber.length() -2;
        auto resRow = firsNumber + " " + Name + " " + Number + QString().fill(' ', fill) + lastNumber;

        qInfo()<<resRow;
        qInfo()<<resRow.length();
    }


    if
    (
        doc.find("bonusInfo")->isUndefined() == false
        &&
        doc.value("bonusInfo").toObject().value("isActivate").toBool() == true
    )
    {
        auto row = doc.value("bonusInfo").toObject();
        qInfo() << QString().fill('-', 38);
        qInfo() << row.value("infoRow1").toString();
        qInfo() << row.value("infoRow2").toString();
    }


    if
    (
        doc.find("Discount")->isUndefined() == false
        &&
        doc.value("Discount").toObject().value("isActivate").toBool() == true
    )
    {
        auto row = doc.value("Discount").toObject();

        auto sWNDText = row.value("sWNDText").toString();
        auto sWND = row.value("sWND").toString();
        auto sWDText = row.value("sWDText").toString();
        auto sWD = row.value("sWD").toString();
        auto cur = row.value("cur").toString();

        qInfo() << QString().fill('-', 38);

        qInfo() << sWNDText + " " + sWND + cur;
        qInfo() << sWDText + " " + sWD + cur;
    }

    if
    (
        doc.find("Certificates")->isUndefined() == false
        &&
        doc.value("Certificates").toObject().value("isActivate").toBool() == true
    )
    {
        qInfo() << QString().fill('-', 38);

        auto row = doc.value("Certificates").toObject();
        qInfo()<<row.value("header").toString();


        for(int i = 0; i < row.value("serts").toArray().count(); i++)
        {
            qInfo()<<row.value("serts").toArray().at(i).toObject().value("num").toString()
            +" " + row.value("ratingText").toString()
            +" " + row.value("serts").toArray().at(i).toObject().value("rat").toString()
            +" " + row.value("cur").toString();
        }
    }


    if
    (
        doc.find("checkInfo")->isUndefined() == false
        &&
        doc.value("checkInfo").toObject().value("isActivate").toBool() == true
    )
    {
        auto row = doc.value("checkInfo").toObject();

        auto checkName = row.value("checkName").toString();
        auto checkNumber = row.value("checkNumber").toString();
        auto ppoIdentity = row.value("ppoIdentity").toString();

        qInfo() << QString().fill('-', 38);
        qInfo()<<checkName + " " + checkNumber + " " + ppoIdentity;
    }


    return a.exec();
}
