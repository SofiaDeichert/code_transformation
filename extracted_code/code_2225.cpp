int main ( ) { long int t , l , x , i ; long int ans = 1 ; long int m , j , k , count = 1 , a [ 100 ] ; scanf ( "%ld" , & t ) ; for ( i = 1 ; i <= t ; i ++ ) { scanf ( "%ld" , & l ) ; for ( m = 0 ; m < 100 ; m ++ ) a [ m ] = 0 ; for ( j = 1 ; j <= l ; j ++ ) { for ( k = 1 ; k <= count ; k ++ ) { scanf ( "%ld" , & x ) ; if ( a [ x ] == 0 ) a [ x ] = 1 ; else a [ x ] = 2 ; if ( a [ x ] == 1 ) ans += x ; } count ++ ; } if ( a [ 1 ] != 0 ) ans = ans - 1 ; printf ( "%ld\n" , ans - 1 ) ; ans = 1 ; count = 1 ; } return 0 ; }