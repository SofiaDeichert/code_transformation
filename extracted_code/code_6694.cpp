long long func ( long long int * * a , long long int pm , long long int ii , long long int n ) ; int main ( ) { long long t ; long long int n , i , j , maxim ; long long ans = 0 , p ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld" , & n ) ; long long int * * a = ( long long int * * ) malloc ( n * sizeof ( int * ) ) ; long long int * max = ( long long int * ) malloc ( n * sizeof ( n ) ) ; for ( i = 0 ; i < n ; i ++ ) { a [ i ] = ( long long int * ) malloc ( n * sizeof ( long long int ) ) ; } for ( i = 0 ; i < n ; i ++ ) { maxim = 0 ; for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%lld" , & a [ i ] [ j ] ) ; if ( a [ i ] [ j ] > maxim ) { max [ i ] = j ; maxim = a [ i ] [ j ] ; } } } ans = 0 ; for ( i = 1 ; i < n ; i ++ ) { p = func ( a , max [ i ] , i , n ) ; if ( p > ans ) ans = p ; } printf ( "%lld\n" , p ) ; } return 0 ; } long long func ( long long int * * a , long long int pm , long long int ii , long long int n ) { long long int i , j , prev = pm ; long long sum = a [ ii ] [ pm ] ; for ( i = ii + 1 ; i < n ; i ++ ) { if ( prev + 1 <= i ) { if ( a [ i ] [ prev ] > a [ i ] [ prev + 1 ] ) { sum += a [ i ] [ prev ] ; } else { sum += a [ i ] [ prev + 1 ] ; prev ++ ; } } else { sum += a [ i ] [ prev ] ; } } prev = pm ; for ( i = ii - 1 ; i >= 0 ; i -- ) { if ( prev - 1 >= 0 ) { if ( a [ i ] [ prev ] > a [ i ] [ prev - 1 ] ) { sum += a [ i ] [ prev ] ; } else { sum += a [ i ] [ prev - 1 ] ; prev -- ; } } else { sum += a [ i ] [ prev ] ; } } return sum ; }