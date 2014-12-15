#include "triecreator.h"

TrieCreator::TrieCreator(Trie *trie)
{
    Worker *worker = new Worker;
    worker->moveToThread(&workerThread);
    connect(&workerThread, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(this, SIGNAL(startCreating(Trie*)), worker, SLOT(doWork(Trie*)));
    connect(worker, SIGNAL(resultIsReady(Trie*)), this, SLOT(handleResult(Trie*)));
    workerThread.start();
    emit startCreating(trie);
}

void Worker::doWork(Trie *tr)
{
    tmp = 0;
    Trie *result = new Trie();
    dfs(tr, "", 0, result);
    emit resultIsReady(result);
}

void Worker::dfs(Trie *in, string cur, int v, Trie *out)
{
    if (in->getValue(v) == 1)
    {
        for (int i = 0; i < (int)cur.size(); i++)
       {
           string ncur = cur;
           ncur[i] = 'X';
           out->add(ncur);
       }
    }
    for (char a = 'a'; a <= 'z'; a++)
    {
        if (in->nextVertex(v, a) == -1) continue;
        string nc = cur;
        nc.push_back(a);
        dfs(in, nc, in->nextVertex(v, a), out);
    }
}
