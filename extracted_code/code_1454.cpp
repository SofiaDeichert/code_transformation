int main ( ) { int t , sz , i , sum = 0 ; scanf ( "%d" , & t ) ; while ( t ) { scanf ( "%d" , & sz ) ; int a [ sz ] ; for ( i = 0 ; i < sz ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } sum = 0 ; for ( i = 0 ; i < sz ; i ++ ) { sum = sum + ( a [ i ] > a [ i + 1 ] ? a [ i + 1 ] : a [ i ] ) ; } printf ( "%d\n" , sum ) ; t -- ; } return 0 ; }