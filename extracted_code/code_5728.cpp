int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long long int n , i , j , min ; scanf ( "%lld" , & n ) ; long long int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & a [ i ] ) ; } min = a [ 0 ] ; for ( j = 1 ; j < n ; j ++ ) { if ( a [ j ] < min ) min = a [ j ] ; } printf ( "%lld\n" , min * ( n - 1 ) ) ; } return 0 ; }