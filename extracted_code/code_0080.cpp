int maxi ( int a , int b ) { return ( ( a > b ) ? a : b ) ; } int main ( ) { int * op ; int a [ 100 ] [ 100 ] ; int x , n , r , i , j , k , p , sum , max = 0 ; scanf ( "%d" , & n ) ; op = ( int * ) malloc ( sizeof ( int ) * n ) ; for ( x = 0 ; x < n ; x ++ ) { max = 0 ; scanf ( "%d" , & r ) ; for ( i = 0 ; i < r ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( j = 0 ; j < r - 1 ; j ++ ) { if ( a [ r - 1 ] [ j ] > a [ r - 1 ] [ j + 1 ] ) { sum = a [ r - 1 ] [ j ] ; } else { sum = a [ r - 1 ] [ j + 1 ] ; j ++ ; } k = r - 2 ; p = j ; while ( k > 0 ) { if ( p <= k && p - 1 >= 0 ) { sum += maxi ( a [ k ] [ p ] , a [ k ] [ p - 1 ] ) ; p -- ; } else if ( p <= k ) sum += a [ k ] [ p ] ; else { sum += a [ k ] [ p - 1 ] ; p -- ; } k -- ; } sum += a [ 0 ] [ 0 ] ; if ( sum > max ) max = sum ; } op [ x ] = max ; } for ( x = 0 ; x < n ; x ++ ) printf ( "%d\n" , op [ x ] ) ; return 0 ; }