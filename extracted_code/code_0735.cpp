int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long long int n ; scanf ( "%lld" , & n ) ; long long int a [ n ] ; long long int min ; for ( int j = 0 ; j < n ; j ++ ) { scanf ( "%lld" , & a [ j ] ) ; if ( j == 0 ) min = a [ j ] ; else if ( min > a [ j ] ) min = a [ j ] ; } long long int h = min * ( n - 1 ) ; printf ( "%lld\n" , h ) ; } return 0 ; }