int main ( ) { int x , y , i ; int min = 100001 ; scanf ( "%d" , & x ) ; while ( x > 0 ) { scanf ( "%d" , & y ) ; int a [ y ] ; for ( i = 0 ; i < y ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; if ( a [ i ] < min ) { min = a [ i ] ; } } printf ( "%d" , min * ( y - 1 ) ) ; x -- ; } return 0 ; }