main ( ) { int t , g , l , a , b , m , n , i , j ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d %d" , & a , & b ) ; l = 1 ; m = a ; n = b ; j = 2 ; while ( a != 1 || b != 1 ) { if ( a % j == 0 && b % j == 0 ) { l = l * j ; a = a / j ; b = b / j ; } else if ( a % j == 0 ) { l = l * j ; a = a / j ; } else if ( b % j == 0 ) { l = l * j ; b = b / j ; } else j ++ ; } g = m * n / l ; printf ( "%d %d\n" , g , l ) ; } }