int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long long int n , a , min , i ; scanf ( "%lld" , & n ) ; min = 100000 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & a ) ; if ( a < min ) min = a ; } long long int score ; score = min * ( n - 1 ) ; printf ( "%lld\n" , score ) ; } return 0 ; }