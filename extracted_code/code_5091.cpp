main ( ) { int t ; long long int r , a , b , x , y , l ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%lld %lld" , & x , & y ) ; a = ( x > y ) ? x : y ; b = ( x < y ) ? x : y ; r = b ; while ( a % b != 0 ) { r = a % b ; a = b ; b = r ; } l = ( x * y ) / r ; printf ( "%lld %lld\n" , r , l ) ; } }