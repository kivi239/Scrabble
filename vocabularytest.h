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

    void cleanup()
    {
        delete testObject;
    }

    void buildTest()
    {
        testObject->build();
    }


private:
    Vocabulary * testObject;


};

