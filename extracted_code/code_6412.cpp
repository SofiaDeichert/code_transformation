int main ( ) { long N , t ; scanf ( "%ld" , & t ) ; int i , j , sum = 0 , min ; for ( i = 1 ; i <= t ; i ++ ) { scanf ( "%ld" , & N ) ; int a [ N ] ; for ( j = 0 ; j < N ; j ++ ) { scanf ( "%d" , & a [ j ] ) ; } min = a [ 0 ] ; for ( j = 0 ; j < N ; j ++ ) { if ( a [ j ] < min ) { min = a [ j ] ; } } sum = min * ( N - 1 ) ; printf ( "\n%d" , sum ) ; } return 0 ; }