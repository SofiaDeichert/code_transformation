int a , b , c , d , e ; int i , j , k , l ; int max ; void parse ( int p , int q , int row , int count , int array [ ] [ 99 ] ) { count = count + array [ p ] [ q ] ; if ( ( p + 1 ) >= row ) { if ( max < count ) max = count ; } else if ( ( q + 1 ) > p ) parse ( p + 1 , q , row , count , array ) ; else { parse ( p + 1 , q , row , count , array ) ; parse ( p + 1 , q + 1 , row , count , array ) ; } } int main ( ) { scanf ( "%d\n" , & a ) ; if ( a > 1000 || a <= 0 ) return 0 ; for ( i = 0 ; i < a ; i ++ ) { int array [ 99 ] [ 99 ] ; int count = 0 ; max = 0 ; scanf ( "%d\n" , & b ) ; if ( b > 100 || b < 0 ) return 0 ; for ( j = 0 ; j < b ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) { if ( k == j ) scanf ( "%d" , & e ) ; else scanf ( "%d " , & e ) ; if ( e > 100 || e < 0 ) return 0 ; else array [ j ] [ k ] = e ; } } parse ( 0 , 0 , b , count , array ) ; printf ( "%d\n" , max ) ; } return 0 ; }