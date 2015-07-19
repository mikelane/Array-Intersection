/**
 *
 * Array Intersection
 * Mike Lane
 *
 * Generate two arrays from a size passed in from the command line. Return the
 * number of seconds it took to create a new array that has a single copy of
 * each integer that exists in both arrays.
 *
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <cctype>
using namespace std;

int main(int argc, char ** argv)
{
  //seed the rand() function
  srand(time(NULL));

  //A flag for debugging output
  bool verbose = false;

  //Usage hint
  if(argc < 3)
  {
    cerr << "Usage: " << argv[0] << " <arr a size> <arr b size>" << endl;
  } else if(argc == 4)
  {
    verbose = true;
  }

  //Set the length from the command line
  long long alen = atoll(argv[1]);
  long long blen = atoll(argv[2]);
  //allocate memory for the arrays. |c| <= min(|a|, |b|)
  long long * a = new long long[alen];
  long long * b = new long long[blen];
  long long * c = new long long[min(alen, blen)];

  //Debugging output
  if(verbose)
  {
    cerr << "alen: " << alen << endl
      << "blen: " << blen << endl << endl;

    cerr << "a: [ ";
  }

  //Generate the first array and fill it with random integers
  for(int i=0; i < alen; ++i)
  {
    a[i] = rand();
    //degugging output
    if(verbose) cerr << a[i] << " ";
  }
  if(verbose)
  {
    cerr << "]" << endl;

    cerr << "b: [ ";
  }

  //Generate the second array and fill it with random integers
  for(int i=0; i < blen; ++i)
  {
    b[i] = rand();
    if(verbose) cerr << b[i] << " ";
  }
  if(verbose) cerr << "]" << endl;

  //Use the built-in sort from the algorithm include
  sort(a, a + alen);
  sort(b, b + blen);

  //Debugging output
  if(verbose)
  {
    cerr << "a: [ ";
    for(long long i=0; i < alen; ++i) cout << a[i] << " ";
    cerr << "]" << endl;
    cerr << "b: [ ";
    for(long long i=0; i < blen; ++i) cout << b[i] << " ";
    cerr << "]" << endl;
  }

  //Set an index for array c
  long long k=0;

  //Start the timer, declare the end variable
  clock_t s = clock(), e;
  //While we haven't made it through the shorter of the two arrays...
  for(long long i=0, j=0; i < alen && j < blen; ++i, ++j)
  {
    //set a flag so a break is not used
    bool stop = false;
    //While we have elements in a to inspect
    while(i < alen-1 && !stop)
    {
      //if the current element in a is the same as the next element in a
      //increment the index and check again.
      if(a[i] == a[i+1]) ++i;
      //Otherwise, continue on.
      else stop = true;
    }

    //Reset the flag
    stop = false;
    //While we have elements in b to inspect
    while(j < blen-1 && !stop)
    {
      //If the current element in b is the same as the next element in b,
      //increment the index and check again.
      if(b[j] == b[j+1]) ++j;
      //Otherwise, continue on.
      else stop = true;
    }

    //If the value of the current index of a is less than b
    //increment a's index.
    if(a[i] < b[j]) ++i;
    //Otherwise, if the current index of b is less than a
    //increment b's index
    else if(a[i] > b[j]) ++j;
    //Otherwise the current value of a equals the current value of b
    //so copy the value to c and increment c's index.
    else c[k++] = a[i];
  }

  //Get the end time
  e = clock();

  //Calculate the duration
  double dur = (e - s) / (double) CLOCKS_PER_SEC;
  cout << alen << "," << dur << endl;

  //Debugging output.
  if(verbose)
  {
    cerr << "c: [ ";
    for(long long i=0; i < k; ++i) cout << c[i] << " ";
    cerr << "]" << endl;
  }

  return 0;
}
