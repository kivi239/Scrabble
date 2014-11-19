#pragma once
#include "vocabulary.h"
#include <QObject>
#include <QtCore/QObject>
#include <QtTest/QtTest>


class VocabularyTest : public QObject
{
    Q_OBJECT
public:
  explicit VocabularyTest(QObject *parent = 0);

private slots:

  void init()
  {
    testObject = new Vocabulary;
  }

  void buildTest()
  {
    testObject->build();
  }

  void addTest()
  {
    testObject->build();
    string tmp = "accepted";
    bool fl1 = testObject->add(tmp);
    bool fl2 = testObject->add(tmp);
    fl2 = !fl2;
    QVERIFY(fl1 && fl2);
  }

  void cleanup()
  {
    delete testObject;
  }


private:
  Vocabulary * testObject;

};

