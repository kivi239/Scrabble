#pragma once
#include "mainHeader.h"
#include <QThread>
#include "trie.h"

class Worker : public QObject
{
    Q_OBJECT
    QThread workerThread;
public slots:
    void doWork(Trie *tr);
signals:
    void resultIsReady(Trie *tr);
private:
    void dfs(Trie *in, string cur, int v, Trie *out);
    int tmp;
};

class TrieCreator : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:

    TrieCreator(Trie *trie);
    ~TrieCreator()
    {
        workerThread.quit();
        workerThread.wait();
    }

public slots:
    void handleResult(Trie *res)
    {
        emit resultReady(res);
    }

signals:
    void resultReady(Trie *result);
    void startCreating(Trie *start);
};

