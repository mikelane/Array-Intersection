#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <cctype>
using namespace std;

int main(int argc, char ** argv)
{
  srand(time(NULL));

  bool verbose = false;

  if(argc < 3)
  {
    cerr << "Usage: " << argv[0] << " <arr a size> <arr b size>" << endl;
  } else if(argc == 4)
  {
    verbose = true;
  }

  long long alen = stoll(argv[1]);
  long long blen = stoll(argv[2]);
  long long * a = new long long[alen];
  long long * b = new long long[blen];
  long long * c = new long long[max(alen, blen)];

  if(verbose)
  {
    cerr << "alen: " << alen << endl
      << "blen: " << blen << endl << endl;

    cerr << "a: [ ";
  }

  for(int i=0; i < alen; ++i)
  {
    a[i] = rand() % alen;
    if(verbose) cerr << a[i] << " ";
  }
  if(verbose)
  {
    cerr << "]" << endl;

    cerr << "b: [ ";
  }

  for(int i=0; i < blen; ++i)
  {
    b[i] = rand() % blen/2;
    if(verbose) cerr << b[i] << " ";
  }
  if(verbose) cerr << "]" << endl;

  sort(a, a + alen);
  sort(b, b + blen);

  if(verbose)
  {
    cerr << "a: [ ";
    for(long long i=0; i < alen; ++i) cout << a[i] << " ";
    cerr << "]" << endl;
    cerr << "b: [ ";
    for(long long i=0; i < blen; ++i) cout << b[i] << " ";
    cerr << "]" << endl;
  }

  long long k=0;

  clock_t s = clock();
  for(long long i=0, j=0; i < alen && j < blen; ++i, ++j)
  {
    bool stop = false;
    while(i < alen-1 && !stop)
    {
      if(a[i] == a[i+1]) ++i;
      else stop = true;
    }

    stop = false;
    while(j < blen-1 && !stop)
    {
      if(b[j] == b[j+1]) ++j;
      else stop = true;
    }

    if(a[i] < b[j]) ++i;
    else if(a[i] > b[j]) ++j;
    else c[k++] = a[i];
  }

  double dur = (clock() - s) / (double) CLOCKS_PER_SEC;
  cout << alen << "," << dur << endl;


  if(verbose)
  {
    cerr << "c: [ ";
    for(long long i=0; i < k; ++i) cout << c[i] << " ";
    cerr << "]" << endl;
  }
  return 0;
}
