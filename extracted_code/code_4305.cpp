main ( ) { long long int a , b , t , i , x , y ; scanf ( "%lld" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%lld %lld" , & a , & b ) ; y = a * b ; if ( a < b ) { a = a + b ; b = a - b ; a = a - b ; } x = a % b ; while ( x != 0 ) { a = b ; b = x ; x = a % b ; } printf ( "%lld %lld\n" , b , y / b ) ; } return 0 ; }