int triangle [ 100 ] [ 100 ] ; int levels ; int computed [ 100 ] [ 100 ] ; int main ( ) { int tests ; scanf ( "%d" , & tests ) ; while ( tests -- > 0 ) { scanf ( "%d" , & levels ) ; int y , x , value ; for ( y = 0 ; y < levels ; y += 1 ) { for ( x = 0 ; x < 1 + y ; x += 1 ) { scanf ( "%d" , & value ) ; triangle [ y ] [ x ] = value ; computed [ y ] [ x ] = - 1 ; } } printf ( "%d \n" , bestSum ( 0 , 0 ) ) ; } return 0 ; } int bestSum ( int y , int x ) { if ( y == levels ) return 0 ; if ( computed [ y ] [ x ] == - 1 ) { int a = bestSum ( y + 1 , x ) ; int b = bestSum ( y + 1 , x + 1 ) ; computed [ y ] [ x ] = a > b ? a : b ; } return computed [ y ] [ x ] + triangle [ y ] [ x ] ; }