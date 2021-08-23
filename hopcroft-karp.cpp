#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define FIN "cuplaj.in"
#define FOUT "cuplaj.out"
#define SIZE 10011

bool used[ SIZE ];
int L[ SIZE ], R[ SIZE ];


using namespace std;

vector< int> G[ SIZE ];

bool was;


//Depth First Search
bool PairUp(int x) {

     if( used[ x ] ) {

       return false;

     }

     used[ x ] = true;

     vector< int >::iterator it = G[ x ].begin(), end = G[ x ].end();

     for(; it < end; ++it)

           if(!R[ *it ] || PairUp( R[*it] )) {

               L[ x ] = *it;

               R[ *it ] = x;

               return true;
           }

           return false;

}

//main function
int main(int argc, char const *argv[]) {

  int N, //number of vertex from L
      M, //number of vertex from R
      E, //number of edges
      x, y, //vertex1 -> vertex2
      components = 0;//number of components; initially is zero

      ifstream fin( FIN );
      ofstream fout( FOUT );

      //read the graph
      for(fin>>N>>M>>E; E; E--) {
          fin>>x>>y;
          G[x].push_back(y);
      }

      while( true ) {

           was = true;

           fill(used + 1, used + N + 1, false);

           for( int i = 1; i <= N; ++i )

               if( !L[ i ] && PairUp( i ) ) {

                  components++;

                  was = false;
               }

           if( was ) break;
      }

      fout<<components<<"\n";
      cout<<components<<"\n";


      for(int x = 1; components && x <= N; ++x)

          if( L[ x ] ) {

              cout<<x<<" "<<L[x]<<"\n";
              fout<<x<<" "<<L[x]<<"\n";

              components--;
          }
}
