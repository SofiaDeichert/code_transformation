int arr [ 100 ] [ 100 ] ; int solve ( int i , int j ) ; int x , t ; int main ( ) { int i , j , result , n ; scanf ( "%d" , & n ) ; while ( n ) { scanf ( "%d" , & x ) ; for ( i = 0 ; i < x ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; } } result = solve ( 0 , 0 ) ; printf ( "\n%d" , result ) ; n -- ; } return 0 ; } int max ( int a , int b ) { if ( a > b ) return a ; else return b ; } int solve ( int i , int j ) { int t1 , t2 ; if ( i >= x ) { return 0 ; } else { t1 = solve ( i + 1 , j ) ; t2 = solve ( i + 1 , j + 1 ) ; t = max ( t1 , t2 ) + arr [ i ] [ j ] ; return t ; } }