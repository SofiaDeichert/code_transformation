main ( ) { int n , l , i , max , j , k = 0 , p ; scanf ( "%d" , & n ) ; p = n ; int m [ n ] ; while ( p > 0 && p <= 1000 ) { scanf ( "%d" , & l ) ; if ( l > 0 && l < 100 ) { int arr [ 5 ] [ 5 ] = { 0 } ; int a [ 5 ] [ 5 ] = { 0 } ; for ( i = 0 ; i < l ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; } } a [ 0 ] [ 0 ] = arr [ 0 ] [ 0 ] ; for ( i = 0 ; i < l - 1 ; i ++ ) { a [ i + 1 ] [ 0 ] = arr [ i + 1 ] [ 0 ] + a [ i ] [ 0 ] ; for ( j = 0 ; j <= i ; j ++ ) { max = a [ i ] [ j ] + arr [ i + 1 ] [ j ] ; if ( max > a [ i + 1 ] [ j ] ) a [ i + 1 ] [ j ] = max ; a [ i + 1 ] [ j + 1 ] = arr [ i + 1 ] [ j + 1 ] + a [ i ] [ j ] ; } } m [ k ] = a [ l - 1 ] [ 0 ] ; for ( i = 0 ; i < l - 1 ; i ++ ) { if ( a [ l - 1 ] [ i + 1 ] > m [ k ] ) m [ k ] = a [ l - 1 ] [ i + 1 ] ; } k ++ ; } p -- ; } if ( n > 0 && n <= 1000 ) { for ( i = 0 ; i < n ; i ++ ) printf ( "%d\n" , m [ i ] ) ; } }