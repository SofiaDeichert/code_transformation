int main ( ) { int t , i , n , a , min ; long long int cost ; scanf ( "%d" , & t ) ; while ( t -- ) { min = 10000000 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a ) ; if ( a < min ) min = a ; } cost = min * ( n - 1 ) ; printf ( "%lld\n" , cost ) ; } return 0 ; }