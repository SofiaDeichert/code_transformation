int main ( ) { long t , n , min , x , c , i ; scanf ( "&1d" , & t ) ; while ( t > 0 ) { min = 1000000 ; scanf ( "" , & n ) ; for ( i = 1 ; i < n ; i ++ ) { scanf ( "" , & x ) ; if ( x < min ) { min = x ; } } c = min * ( n - 1 ) ; printf ( "\n" , c ) ; t -- ; } return 0 ; }