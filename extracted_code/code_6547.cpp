int tab [ 100 ] [ 100 ] ; int rows ; static inline int max ( int a , int b ) { return a > b ? a : b ; } int getsum ( int row , int col ) { int val ; if ( row == rows ) return 0 ; val = tab [ row ] [ col ] ; return max ( val + getsum ( row + 1 , col ) , val + getsum ( row + 1 , col + 1 ) ) ; } int main ( ) { int n ; int i , j ; int sum ; scanf ( "%d" , & n ) ; while ( n -- > 0 ) { scanf ( "%d" , & rows ) ; for ( i = 0 ; i < rows ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & tab [ i ] [ j ] ) ; } } sum = max ( tab [ 0 ] [ 0 ] + getsum ( 1 , 0 ) , tab [ 0 ] [ 0 ] + getsum ( 1 , 1 ) ) ; printf ( "%d\n" , sum ) ; } return 0 ; }