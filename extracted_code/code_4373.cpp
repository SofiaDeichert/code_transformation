long long int fact ( int num ) { if ( num == 0 ) return 1 ; else return num * fact ( num - 1 ) ; } int main ( void ) { int t , n , i , top , lb , ub , * a ; long long int cnt ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; cnt = n ; top = lb = ub = 0 ; a = ( int * ) malloc ( n * sizeof ( int ) ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; if ( i > 0 && a [ i ] >= a [ i - 1 ] ) ub ++ ; else if ( lb != ub ) { cnt += fact ( ub - lb ) ; lb = ub = i ; } } if ( lb != ub ) cnt += fact ( ub - lb ) ; printf ( "%lld\n" , cnt ) ; free ( a ) ; } return 0 ; }