void main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int i = 0 , n ; scanf ( "%d" , & n ) ; long long int a [ n ] , cnt ; while ( i < n ) scanf ( "%lld" , & a [ i ++ ] ) ; if ( n < 3 ) cnt = 1 ; else cnt = ( ( n - 1 ) * ( n - 2 ) ) / 2 ; printf ( "%lld " , cnt ) ; } }