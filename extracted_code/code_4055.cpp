int main ( ) { int t , n , i , j , sum , * a ; scanf ( "%d" , & t ) ; while ( t -- ) { sum = 0 ; scanf ( "%d" , & n ) ; a = ( int * ) malloc ( sizeof ( int ) * n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; for ( i = 0 ; i < n ; i ++ ) { t = i ; for ( j = t + 1 ; j < n ; j ++ ) { if ( a [ j ] > a [ t ] ) { sum ++ ; t = j ; } else break ; } } free ( a ) ; printf ( "%d\n" , sum + n ) ; } return 0 ; }