int arr [ 100 ] [ 101 ] ; int main ( ) { int j , i , lines , cases , maxv ; scanf ( "%d" , & cases ) ; int rem = cases % 10 ; int fix = cases / 10 ; for ( ; rem ; rem -- ) { scanf ( "%d" , & lines ) ; scanf ( "%d" , & arr [ 1 ] [ 1 ] ) ; for ( i = 2 ; i <= lines ; i ++ ) { scanf ( "%d" , & arr [ i ] [ 1 ] ) ; arr [ i ] [ 1 ] += arr [ i - 1 ] [ 1 ] ; for ( j = 2 ; j < i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += ( arr [ i - 1 ] [ j ] > arr [ i - 1 ] [ j - 1 ] ? arr [ i - 1 ] [ j ] : arr [ i - 1 ] [ j - 1 ] ) ; } scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += arr [ i - 1 ] [ j - 1 ] ; } maxv = arr [ lines ] [ 1 ] ; for ( i = 2 ; i <= lines ; i ++ ) if ( arr [ lines ] [ i ] > maxv ) maxv = arr [ lines ] [ i ] ; printf ( "%d\n" , maxv ) ; } for ( ; fix ; fix -- ) { scanf ( "%d" , & lines ) ; scanf ( "%d" , & arr [ 1 ] [ 1 ] ) ; for ( i = 2 ; i <= lines ; i ++ ) { scanf ( "%d" , & arr [ i ] [ 1 ] ) ; arr [ i ] [ 1 ] += arr [ i - 1 ] [ 1 ] ; for ( j = 2 ; j < i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += ( arr [ i - 1 ] [ j ] > arr [ i - 1 ] [ j - 1 ] ? arr [ i - 1 ] [ j ] : arr [ i - 1 ] [ j - 1 ] ) ; } scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += arr [ i - 1 ] [ j - 1 ] ; } maxv = arr [ lines ] [ 1 ] ; for ( i = 2 ; i <= lines ; i ++ ) if ( arr [ lines ] [ i ] > maxv ) maxv = arr [ lines ] [ i ] ; printf ( "%d\n" , maxv ) ; scanf ( "%d" , & lines ) ; scanf ( "%d" , & arr [ 1 ] [ 1 ] ) ; for ( i = 2 ; i <= lines ; i ++ ) { scanf ( "%d" , & arr [ i ] [ 1 ] ) ; arr [ i ] [ 1 ] += arr [ i - 1 ] [ 1 ] ; for ( j = 2 ; j < i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += ( arr [ i - 1 ] [ j ] > arr [ i - 1 ] [ j - 1 ] ? arr [ i - 1 ] [ j ] : arr [ i - 1 ] [ j - 1 ] ) ; } scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += arr [ i - 1 ] [ j - 1 ] ; } maxv = arr [ lines ] [ 1 ] ; for ( i = 2 ; i <= lines ; i ++ ) if ( arr [ lines ] [ i ] > maxv ) maxv = arr [ lines ] [ i ] ; printf ( "%d\n" , maxv ) ; scanf ( "%d" , & lines ) ; scanf ( "%d" , & arr [ 1 ] [ 1 ] ) ; for ( i = 2 ; i <= lines ; i ++ ) { scanf ( "%d" , & arr [ i ] [ 1 ] ) ; arr [ i ] [ 1 ] += arr [ i - 1 ] [ 1 ] ; for ( j = 2 ; j < i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += ( arr [ i - 1 ] [ j ] > arr [ i - 1 ] [ j - 1 ] ? arr [ i - 1 ] [ j ] : arr [ i - 1 ] [ j - 1 ] ) ; } scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += arr [ i - 1 ] [ j - 1 ] ; } maxv = arr [ lines ] [ 1 ] ; for ( i = 2 ; i <= lines ; i ++ ) if ( arr [ lines ] [ i ] > maxv ) maxv = arr [ lines ] [ i ] ; printf ( "%d\n" , maxv ) ; scanf ( "%d" , & lines ) ; scanf ( "%d" , & arr [ 1 ] [ 1 ] ) ; for ( i = 2 ; i <= lines ; i ++ ) { scanf ( "%d" , & arr [ i ] [ 1 ] ) ; arr [ i ] [ 1 ] += arr [ i - 1 ] [ 1 ] ; for ( j = 2 ; j < i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += ( arr [ i - 1 ] [ j ] > arr [ i - 1 ] [ j - 1 ] ? arr [ i - 1 ] [ j ] : arr [ i - 1 ] [ j - 1 ] ) ; } scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += arr [ i - 1 ] [ j - 1 ] ; } maxv = arr [ lines ] [ 1 ] ; for ( i = 2 ; i <= lines ; i ++ ) if ( arr [ lines ] [ i ] > maxv ) maxv = arr [ lines ] [ i ] ; printf ( "%d\n" , maxv ) ; scanf ( "%d" , & lines ) ; scanf ( "%d" , & arr [ 1 ] [ 1 ] ) ; for ( i = 2 ; i <= lines ; i ++ ) { scanf ( "%d" , & arr [ i ] [ 1 ] ) ; arr [ i ] [ 1 ] += arr [ i - 1 ] [ 1 ] ; for ( j = 2 ; j < i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += ( arr [ i - 1 ] [ j ] > arr [ i - 1 ] [ j - 1 ] ? arr [ i - 1 ] [ j ] : arr [ i - 1 ] [ j - 1 ] ) ; } scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += arr [ i - 1 ] [ j - 1 ] ; } maxv = arr [ lines ] [ 1 ] ; for ( i = 2 ; i <= lines ; i ++ ) if ( arr [ lines ] [ i ] > maxv ) maxv = arr [ lines ] [ i ] ; printf ( "%d\n" , maxv ) ; scanf ( "%d" , & lines ) ; scanf ( "%d" , & arr [ 1 ] [ 1 ] ) ; for ( i = 2 ; i <= lines ; i ++ ) { scanf ( "%d" , & arr [ i ] [ 1 ] ) ; arr [ i ] [ 1 ] += arr [ i - 1 ] [ 1 ] ; for ( j = 2 ; j < i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += ( arr [ i - 1 ] [ j ] > arr [ i - 1 ] [ j - 1 ] ? arr [ i - 1 ] [ j ] : arr [ i - 1 ] [ j - 1 ] ) ; } scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += arr [ i - 1 ] [ j - 1 ] ; } maxv = arr [ lines ] [ 1 ] ; for ( i = 2 ; i <= lines ; i ++ ) if ( arr [ lines ] [ i ] > maxv ) maxv = arr [ lines ] [ i ] ; printf ( "%d\n" , maxv ) ; scanf ( "%d" , & lines ) ; scanf ( "%d" , & arr [ 1 ] [ 1 ] ) ; for ( i = 2 ; i <= lines ; i ++ ) { scanf ( "%d" , & arr [ i ] [ 1 ] ) ; arr [ i ] [ 1 ] += arr [ i - 1 ] [ 1 ] ; for ( j = 2 ; j < i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += ( arr [ i - 1 ] [ j ] > arr [ i - 1 ] [ j - 1 ] ? arr [ i - 1 ] [ j ] : arr [ i - 1 ] [ j - 1 ] ) ; } scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += arr [ i - 1 ] [ j - 1 ] ; } maxv = arr [ lines ] [ 1 ] ; for ( i = 2 ; i <= lines ; i ++ ) if ( arr [ lines ] [ i ] > maxv ) maxv = arr [ lines ] [ i ] ; printf ( "%d\n" , maxv ) ; scanf ( "%d" , & lines ) ; scanf ( "%d" , & arr [ 1 ] [ 1 ] ) ; for ( i = 2 ; i <= lines ; i ++ ) { scanf ( "%d" , & arr [ i ] [ 1 ] ) ; arr [ i ] [ 1 ] += arr [ i - 1 ] [ 1 ] ; for ( j = 2 ; j < i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += ( arr [ i - 1 ] [ j ] > arr [ i - 1 ] [ j - 1 ] ? arr [ i - 1 ] [ j ] : arr [ i - 1 ] [ j - 1 ] ) ; } scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += arr [ i - 1 ] [ j - 1 ] ; } maxv = arr [ lines ] [ 1 ] ; for ( i = 2 ; i <= lines ; i ++ ) if ( arr [ lines ] [ i ] > maxv ) maxv = arr [ lines ] [ i ] ; printf ( "%d\n" , maxv ) ; scanf ( "%d" , & lines ) ; scanf ( "%d" , & arr [ 1 ] [ 1 ] ) ; for ( i = 2 ; i <= lines ; i ++ ) { scanf ( "%d" , & arr [ i ] [ 1 ] ) ; arr [ i ] [ 1 ] += arr [ i - 1 ] [ 1 ] ; for ( j = 2 ; j < i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += ( arr [ i - 1 ] [ j ] > arr [ i - 1 ] [ j - 1 ] ? arr [ i - 1 ] [ j ] : arr [ i - 1 ] [ j - 1 ] ) ; } scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += arr [ i - 1 ] [ j - 1 ] ; } maxv = arr [ lines ] [ 1 ] ; for ( i = 2 ; i <= lines ; i ++ ) if ( arr [ lines ] [ i ] > maxv ) maxv = arr [ lines ] [ i ] ; printf ( "%d\n" , maxv ) ; scanf ( "%d" , & lines ) ; scanf ( "%d" , & arr [ 1 ] [ 1 ] ) ; for ( i = 2 ; i <= lines ; i ++ ) { scanf ( "%d" , & arr [ i ] [ 1 ] ) ; arr [ i ] [ 1 ] += arr [ i - 1 ] [ 1 ] ; for ( j = 2 ; j < i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += ( arr [ i - 1 ] [ j ] > arr [ i - 1 ] [ j - 1 ] ? arr [ i - 1 ] [ j ] : arr [ i - 1 ] [ j - 1 ] ) ; } scanf ( "%d" , & arr [ i ] [ j ] ) ; arr [ i ] [ j ] += arr [ i - 1 ] [ j - 1 ] ; } maxv = arr [ lines ] [ 1 ] ; for ( i = 2 ; i <= lines ; i ++ ) if ( arr [ lines ] [ i ] > maxv ) maxv = arr [ lines ] [ i ] ; printf ( "%d\n" , maxv ) ; } return 0 ; }