int main ( ) { int n , l , a [ 100 ] [ 100 ] , sum = 0 , i , j , k ; printf ( "enter the number of test cases" ) ; scanf ( "%d" , & n ) ; printf ( "enter the number of row" ) ; scanf ( "%d" , & l ) ; for ( k = 1 ; k <= n ; k ++ ) { for ( i = 0 ; i < l ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , a [ i ] [ j ] ) ; } } for ( i = 0 ; i <= l - 2 ; i ++ ) { if ( a [ i + 1 ] [ i ] > a [ i + 1 ] [ i + 1 ] ) { sum = sum + a [ i + 1 ] [ i ] ; } else { sum = sum + a [ i + 1 ] [ i + 1 ] ; } } } sum = sum + a [ 0 ] [ 0 ] ; printf ( "%d" , sum ) ; }