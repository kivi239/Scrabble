#include "nyashbot.h"

NyashBot::NyashBot(Trie *nTrie)
{
    go[0][0] = 0;
    go[0][1] = 1;
    go[1][0] = 1;
    go[1][1] = 0;
    go[2][0] = 0;
    go[2][1] = -1;
    go[3][0] = -1;
    go[3][1] = 0;
    changed = nTrie;
}
#define pb push_back
#define mp make_pair
#define X first
#define Y second
string NyashBot::getWord(const vector<string> & area, const vector<pii> &figure)
{
   int n = area.size();
   for (int i = 0; i < n; i++)
      assert((int)area[i].size() == n);

   string ans = "";
   for (int i = 0; i < (int)figure.size(); i++)
   {
      assert(figure[i].X >= 0 && figure[i].X < n && figure[i].Y >= 0 && figure[i].Y < n);
      ans.pb(area[figure[i].X][figure[i].Y]);
   }
   return ans;
}

bool NyashBot::ls1(const vector<pii> &a, const vector<pii> &b)
{
    return a.size() > b.size();
}

void NyashBot::addWord(const string &word)
{
    for (int i = 0; i < word.size(); ++i)
    {
        string tmp = word;
        tmp[i] = 'X';
        changed->setWord(tmp);
    }
}




void NyashBot::gen(const vector<string> &area, int vertex, pair<vector<pii>, string> cur, int n)
{
  //  cerr << "v=" << vertex << " cur=" << cur.Y << endl;
    if (changed->getValue(vertex) == 1)
    {
       if ((int)cur.second.size() > bestAnswer)
       {
           ans = cur;
           bestAnswer = cur.second.size();
       }
    }
    used[cur.first.back().X][cur.first.back().Y] = 1;
    for (int dir = 0; dir < 4; dir++)
    {
        pii to = cur.first.back();
        to.X += go[dir][0];
        to.Y += go[dir][1];
        if (to.X < 0 || to.X >= n || to.Y < 0 || to.Y >= n) continue;
        if (changed->nextVertex(vertex, area[to.X][to.Y]) == -1 || used[to.X][to.Y]) continue;
        used[to.X][to.Y] = 1;
        pair<vector<pii>, string> ncur = cur;
        ncur.first.pb(to);
        ncur.second.pb(area[to.X][to.Y]);
        used[to.X][to.Y] = 1;
        gen(area, changed->nextVertex(vertex, area[to.X][to.Y]), ncur, n);
        used[to.X][to.Y] = 0;
    }
    used[cur.first.back().X][cur.first.back().Y] = 0;
}


pair<vector<pii>, string> NyashBot::getTheBestWord(vector<string> area, pii point, Trie *vocab)
{
   int n = area.size();
   for (int i = 0; i < n; i++)
      assert((int)area[i].size() == n);

   bestAnswer = 0;
   area[point.X][point.Y] = 'X';
   for (int i = 0; i < n; i++)
     for (int j = 0; j < n; j++)
     {
       used.clear();
       used.resize(n);
       for (int k = 0; k < n; k++) used[k].resize(n,0);
       pair<vector<pii>, string> cur;
       cur.X.clear();
       cur.Y.clear();
       cur.X.pb(mp(i,j));
       cur.Y.pb(area[i][j]);
     //  cerr << "i=" << i << " j=" << j << "(" << area[i][j] << ")" << endl;
       if (changed->nextVertex(0, area[i][j]) == -1) continue;
       gen(area, changed->nextVertex(0, area[i][j]), cur, n);
     }
   if (bestAnswer == 0)
   {
      pair<vector<pii>, string> cur;      
      return cur;
   }
   for (int i = 0; i < (int)ans.Y.size(); i++)
   {
       if (ans.Y[i] == 'X')
       {
          for (char nw = 'a'; nw <= 'z'; nw++)
          {
              string u = ans.Y;
              u[i] = nw;
              if (vocab->hasWord(u))
              {
                  ans.Y = u;
                  return ans;
              }
          }
       }
   }
   assert(false);
   return ans; ///////////////
}


bool ls0(const pair<vector<pii>, string> &a, const pair<vector<pii>, string> &b)
{
   return a.X.size() > b.X.size();
}


void NyashBot::modify(vector<string> &area, pair<vector<pii>, string> a)
{
   for (int i = 0; i < (int)a.X.size(); i++)
   {
      assert(area[a.X[i].X][a.X[i].Y] == '*' || area[a.X[i].X][a.X[i].Y] == a.Y[i]);
      area[a.X[i].X][a.X[i].Y] = a.Y[i];
   }
}

pair<vector<pii>, string> NyashBot::deepOptimise(vector<string> area, Trie *vocab, int &bestscore, int deepening)   //area should NOT be a pointer
{
   int n = area.size();
   for (int i = 0; i < n; i++)
      assert((int)area[i].size() == n);


 //  cerr << "deepOptimise" << endl;
 //  for (int i = 0; i < n; i++)
 //     cerr << area[i] << endl;
 //  cerr << endl;
   vector<pair<vector<pii>, string> > poss;
   int p = 0;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
         if (area[i][j] == '*') p++;
      }
   if (p > 10) deepening = min(deepening,2);
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
         if (area[i][j] == '*')
         {
                 pair<vector<pii>, string> bestOne = getTheBestWord(area, mp(i, j), vocab);
                 if (bestOne.second == "") continue;
                 bool hasij = 0;
               //  cout << "!!" << bestOne.Y << endl;
                 for (int p = 0; p < (int)bestOne.Y.size(); p++)
                 {
                  //  cout << bestOne.X[p].X << ' ' << bestOne.X[p].Y << endl;
                  //  assert(narea[bestOne.X[p].X][bestOne.X[p].Y] == bestOne.Y[p]);
                    if (bestOne.X[p].X == i && bestOne.X[p].Y == j) hasij = 1;
                 }
                 assert(hasij);
                 assert(vocab->hasWord(bestOne.second));
                 poss.pb(bestOne);

         }
      }
   if (poss.size() == 0)
   {
      pair<vector<pii>, string> u;
      u.second = "";
      bestscore = 0;
      return u;
   }
   sort(poss.begin(), poss.end(), ls0);
   if (deepening == 0)
   {
      bestscore = poss[0].X.size();
      return poss[0];
   }
   int bestid = 0, bans = poss[0].X.size();
   for (int i = 0; i < (int)poss.size(); i++)
   {
      vector<string> narea = area;
      modify(narea, poss[i]);
      int ans = -1;
      deepOptimise(narea, vocab, ans, deepening - 1);
      if (-ans + (int)poss[i].X.size() > bans)
      {
           bestid = i;
           bans = -ans + poss[i].X.size();
      }
   }
   return poss[bestid];
}

pair<vector<pii>, string> NyashBot::deepOptimise(vector<string> area, Trie *vocab)
{
    int some = 0;
    return deepOptimise(area, vocab, some, 2);
}




vector<Cell> NyashBot::nextTurn(Field *field, Vocabulary *vocabulary)
{
    botField = field;    
    results.clear();
    results.push_back(vector<Cell>());
    vector<string> area(Size);
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            area[i].pb(field->getCell(i,j));
            if (area[i][j] == '\0') area[i][j] = '*';
        }
    }
    pair<vector<pii>, string> result = deepOptimise(area, vocabulary->getTrie());
    for (int i = 0; i < (int)result.first.size(); i++)
        results[0].pb(Cell(result.first[i].first, result.first[i].second, result.second[i]));    
    return results[0];
}

NyashBot::~NyashBot()
{
    delete changed;
}

#undef pb
#undef mp
#undef X
#undef Y
