int main ( ) { long long int t , n , i , min ; scanf ( "%lld" , & t ) ; while ( t -- ) { min = 100001 ; scanf ( "%lld" , & n ) ; long long int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & a [ i ] ) ; if ( a [ i ] < min ) min = a [ i ] ; } min = min * ( n - 1 ) ; printf ( "%lld\n" , min ) ; } return 0 ; }