int main ( ) { int count ; int i , N ; int min ; int a ; long long cost ; scanf ( "%d" , & count ) ; while ( count -- ) { scanf ( "%d" , & N ) ; min = 100000 ; for ( i = 0 ; i < N ; i ++ ) { scanf ( "%d" , & a ) ; if ( min > a ) { min = a ; } } if ( N == 1 ) { cost = ( long ) min ; } else cost = ( long long ) min * ( long long ) ( N - 1 ) ; printf ( "%lld\n" , cost ) ; } return 0 ; }