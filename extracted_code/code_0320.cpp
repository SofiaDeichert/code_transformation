int main ( ) { int num , n , i , j , k , a [ 101 ] [ 101 ] , sum = 0 , pos = 0 , s = 0 ; scanf ( "%d" , & num ) ; for ( k = 0 ; k < num ; k ++ ) { sum = 0 ; pos = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < 101 ; i ++ ) for ( j = 0 ; j < 101 ; j ++ ) a [ i ] [ j ] = 0 ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = 0 ; i < n ; i ++ ) { s = 0 ; for ( j = pos - 1 ; j <= ( pos + 1 ) ; j ++ ) { if ( j >= 0 ) { if ( s < a [ i ] [ j ] ) s = a [ i ] [ j ] ; } sum += s ; } } scanf ( "%d\n" , sum ) ; } return 0 ; }