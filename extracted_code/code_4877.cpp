int main ( ) { long long int s , c , i , p = 0 ; long long int N , T ; long int A [ 100001 ] ; scanf ( "%d" , & T ) ; while ( T -- ) { int m = 1 ; scanf ( "%lld" , & N ) ; for ( i = 0 ; i < N ; i ++ ) scanf ( "%lld" , & A [ i ] ) ; s = 1 ; c = N ; for ( i = 0 ; i < N ; i ++ ) { if ( A [ i ] <= A [ i + 1 ] ) { c = c + s ; s = s ++ ; } else s = 1 ; } printf ( "%d\n" , c ) ; } return 0 ; }