int main ( ) { int t ; scanf ( "%d" , & t ) ; long long int i , j , temp ; long long int n ; long long int * a ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%lld" , & n ) ; a = ( long long int * ) malloc ( sizeof ( long long int ) * n ) ; for ( j = 0 ; j < n ; j ++ ) { scanf ( "%d" , & a [ j ] ) ; } temp = a [ 0 ] ; for ( j = 0 ; j < n ; j ++ ) { if ( temp > a [ j ] ) { temp = a [ j ] ; } } printf ( "%lld\n" , temp * ( n - 1 ) ) ; free ( a ) ; } }