int a [ 100 ] [ 100 ] ; int maxsum ( int rowno , int colno , int n ) { if ( rowno == n - 1 ) { return a [ rowno ] [ colno ] ; } else { if ( maxsum ( rowno + 1 , colno , n ) > maxsum ( rowno + 1 , colno + 1 , n ) ) { return a [ rowno ] [ colno ] + maxsum ( rowno + 1 , colno , n ) ; } else return a [ rowno ] [ colno ] + maxsum ( rowno + 1 , colno + 1 , n ) ; } } int main ( ) { int i , t , n , r , c ; int arr [ 10 ] ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d" , & n ) ; for ( r = 0 ; r < n ; r ++ ) { for ( c = 0 ; c <= r ; c ++ ) { scanf ( "%d" , & a [ r ] [ c ] ) ; } } arr [ i ] = maxsum ( 0 , 0 , n ) ; } for ( i = 0 ; i < t ; i ++ ) { printf ( "%d\n" , arr [ i ] ) ; } return 0 ; }