main ( ) { int z , i , t , a [ 50000 ] , n , small , k ; scanf ( "%d" , & t ) ; for ( int j = 0 ; j < t ; j ++ ) { k = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } small = a [ 0 ] ; for ( i = 0 ; i < n ; i ++ ) { if ( a [ i ] < small ) { small = a [ i ] ; } } for ( int i = 0 ; i < n ; i ++ ) { if ( a [ i ] > small ) { k ++ ; } } z = small * k ; printf ( "%d" , z ) ; printf ( "\n" ) ; } }