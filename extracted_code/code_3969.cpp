int main ( ) { long t , i , n , min ; long long int sum ; scanf ( "%ld" , & t ) ; while ( t -- ) { sum = 0 ; scanf ( "%ld" , & n ) ; long int a [ n ] ; min = 100001 ; for ( i = 0 ; i <= n - 1 ; i ++ ) { scanf ( "%ld" , & a [ i ] ) ; if ( a [ i ] < min ) min = a [ i ] ; } sum = min * ( n - 1 ) ; printf ( "%lld\n" , sum ) ; } return 0 ; }