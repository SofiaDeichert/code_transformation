int sum ( int a [ 100 ] [ 100 ] , int n , int i , int j ) { int t1 , t2 , max , t ; if ( i > n ) return 0 ; t1 = sum ( a , n , i + 1 , j ) ; t2 = sum ( a , n , i + 1 , j + 1 ) ; if ( t1 > t2 ) max = t1 ; else max = t2 ; t = max + a [ i ] [ j ] ; return t ; } int main ( ) { int t , ans , i , j , n , a [ 100 ] [ 100 ] ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } ans = sum ( a , n , 0 , 0 ) ; printf ( "%d\n" , ans ) ; } }