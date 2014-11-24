#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
#include <ctime>  
#include <fstream>
#include "trie.h" 
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const ld pi = acos(-1.);
typedef pair<int,int> pii;
#define X first
#define Y second
typedef vector<int> vi;



vector<pii> figures[10000];

Trie changed;
int number = -1;

const int go[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void genFigures(int id, int depth)
{
   assert(number <= 9995);
   if (depth == 0) return;
   for (int dir = 0; dir < 4; dir++)
   {
      pii nw = figures[id].back();
      nw.X += go[dir][0];
      nw.Y += go[dir][1];
      bool ok = 1;
      for (int i = 0; i < (int)figures[id].size() && ok; i++)
        if (nw == figures[id][i]) ok = 0;
      if (!ok) continue;
      figures[number] = figures[id];
      figures[number].pb(nw);
      number++;
      genFigures(number-1, depth-1);
   }

}

string getWord(const vector<string> & area, const vector<pii> &figure)
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

bool ls1(const vector<pii> &a, const vector<pii> &b)
{
   return a.size() > b.size();
}


void dfs(Trie &in, string cur, int v, Trie &out)
{
   if (in.getValue(v) == 1)
   { 
     // cerr << "added" << endl;
      for (int i = 0; i < (int)cur.size(); i++)
      {
          string ncur = cur;
          ncur[i] = 'X';
          out.add(ncur);
      }         
   }
   for (char a = 'a'; a <= 'z'; a++)
   {
       if (in.nextVertex(v, a) == -1) continue;        
       string nc = cur;
       nc.pb(a);
       dfs(in, nc, in.nextVertex(v, a), out);   
   } 
}

vector<vector<bool> > used;
pair<vector<pii>, string> ans, cur;
int bestAnswer;


void gen(const vector<string> &area, int vertex, pair<vector<pii>, string> cur, int n)
{
  //  cerr << "v=" << vertex << " cur=" << cur.Y << endl;
    if (changed.getValue(vertex) == 1)
    {
       if ((int)cur.second.size() > bestAnswer)
       {
           ans = cur;
           bestAnswer = cur.second.size();
       }
    }
    for (int dir = 0; dir < 4; dir++)
    {
        pii to = cur.first.back();
        to.X += go[dir][0];
        to.Y += go[dir][1];
        if (to.X < 0 || to.X >= n || to.Y < 0 || to.Y >= n) continue;
        if (changed.nextVertex(vertex, area[to.X][to.Y]) == -1 || used[to.X][to.Y]) continue;
        used[to.X][to.Y] = 1;
        pair<vector<pii>, string> ncur = cur;
        ncur.first.pb(to);
        ncur.second.pb(area[to.X][to.Y]);
        used[to.X][to.Y] = 1;
        gen(area, changed.nextVertex(vertex, area[to.X][to.Y]), ncur, n);
        used[to.X][to.Y] = 0;
    }
}

                                           
pair<vector<pii>, string> getTheBestWord(vector<string> area, pii point, Trie &vocab)
{  
   if (number == -1)
   {
      figures[0].clear();
      figures[0].pb(mp(0,0));
      number = 1;
      genFigures(0, 6);
      cerr << "number=" << number << endl;
      sort(figures, figures + number, ls1);

      dfs(vocab, "", 0, changed);
      for (int i = 'a'; i <= 'z'; i++)
         cerr << changed.nextVertex(0, i) << ' ';
      cerr << endl;
   
   }

   int n = area.size();
   for (int i = 0; i < n; i++)
      assert((int)area[i].size() == n);

  /* int bestlen = -1;
   pair<vector<pii>, string> ans;
   for (int i = 0; i < number; i++)          
      {
      //   cout << "starti=" << starti << " startj=" << startj << endl;
         if ((int)figures[i].size() <= bestlen) {
            //cout << figures[i].size() << ' ' << bestlen << endl;
            break;
         }
         for (int si = 0; si < (int)figures[i].size(); si++)        
         
         {
            int starti = point.X - figures[i][si].X;
            int startj = point.Y - figures[i][si].Y;
             
            bool ok = true, haspoint = false;
            vector<pii> tmp = figures[i];
            for (int j = 0; j < (int)figures[i].size(); j++)
               tmp[j].X += starti, tmp[j].Y += startj;


            for (int j = 0; j < (int)tmp.size() && ok; j++)
            {
               if (tmp[j].X < 0 || tmp[j].X >= n || tmp[j].Y < 0 || tmp[j].Y >= n)
                  ok = false;                   
               if (tmp[j].X == point.X && tmp[j].Y == point.Y) haspoint = true;
            }
            if (!ok || !haspoint) continue;
          //  cout << "ok!" << endl;   
          //  for (int j = 0; j < (int)tmp.size(); j++)
          //     cout << "(" << tmp[j].X << ":" << tmp[j].Y << ")  ";
          //  cout << endl;
            string word = getWord(area, tmp);

         //   cout << word << endl;
            if (vocab.hasWord(word))
            {
               
               if ((int)word.size() > bestlen)
               {
                  bestlen = word.size();
                  ans = mp(tmp, word);
               } 
            }
         }
      } 

      
  // cerr << ans.second << endl;
   if (bestlen < 0) ans.second = "";
   return ans;

   */

   bestAnswer = 0;
   area[point.X][point.Y] = 'X';
  // cerr << "SOME" << endl;
  // for (int i =0 ; i < n; i++)
  //     cerr << area[i] << endl;
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
       if (changed.nextVertex(0, area[i][j]) == -1) continue;
       gen(area, changed.nextVertex(0, area[i][j]), cur, n);  
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
              if (vocab.hasWord(u))
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


void modify(vector<string> &area, pair<vector<pii>, string> a)
{
   for (int i = 0; i < (int)a.X.size(); i++)
   {
      assert(area[a.X[i].X][a.X[i].Y] == '*' || area[a.X[i].X][a.X[i].Y] == a.Y[i]);
      area[a.X[i].X][a.X[i].Y] = a.Y[i];
   }
}

pair<vector<pii>, string> deepOptimise(vector<string> area, const Trie &vocab, int &bestscore, int deepening = 3)   //area should NOT be a pointer
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
                 assert(vocab.hasWord(bestOne.second));                  
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

pair<vector<pii>, string> deepOptimise(vector<string> area, const Trie &vocab)   //area should NOT be a pointer
{
    int some;
    return deepOptimise(area, vocab, some);
}

// * - nothing !!!!!

int main()
{
    ifstream vocab("vocabulary.txt");
    string word;
    Trie all;

    while (vocab >> word) all.add(word);
    int n;
    cin >> n;
    vector<string> area(n);
    for (int i = 0; i < n; i++)
        cin >> area[i];
    for (int i = 0; i < 20; i++)
    {     
       int tmp0;
       pair<vector<pii>, string> q = deepOptimise(area, all);
       modify(area, q);
       if (q.second == "") cout <<"!!!" << endl;
       cout << q.second << endl;
       cout << "--" << endl;
       for (int j = 0; j < n; j++)
          cout << area[j] << endl;
       cout << endl;
       
    }  
}