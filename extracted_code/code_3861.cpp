int small ( unsigned int temp [ ] , unsigned int t ) { int i , j , k ; k = temp [ 0 ] ; for ( i = 0 ; i < t ; i ++ ) { if ( k > temp [ i ] && temp [ i ] != 0 ) { k = temp [ i ] ; } } return k ; } void re ( unsigned int temp [ ] , unsigned int t ) { int i , j , k ; for ( i = 0 ; i < t ; i ++ ) { k = temp [ i ] ; for ( j = i + 1 ; j < t ; j ++ ) { if ( k == temp [ j ] ) { temp [ j ] = 0 ; } } } } int main ( ) { unsigned int n , s , temp [ 100 ] , t , k ; int i , j ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & t ) ; t = ( t * t + t ) / 2 ; for ( j = 0 ; j < t ; j ++ ) { scanf ( "%d" , & temp [ j ] ) ; } re ( temp , t ) ; k = small ( temp , t ) ; unsigned int sum = 0 ; for ( j = 0 ; j < t ; j ++ ) { sum = sum + temp [ j ] ; } sum = sum - k ; printf ( "%d\n" , sum ) ; } return 0 ; }