int fact ( int n ) { if ( n == 0 || n == 1 ) return 1 ; else return ( n * fact ( n - 1 ) ) ; } int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , a [ 100000 ] , i , count = 0 , temp = 0 , num = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; for ( i = 0 ; i < n ; i ++ ) { if ( i == n - 1 && n > 1 && a [ i - 1 ] <= a [ i ] ) count = count + fact ( temp + 1 ) ; else if ( n == 1 ) count = 0 ; else if ( a [ i ] <= a [ i + 1 ] ) { num ++ ; temp ++ ; } else { count = count + fact ( temp + 1 ) ; temp = 0 ; } } count = count + ( n - num ) ; printf ( "%d\n" , count ) ; } return 0 ; }