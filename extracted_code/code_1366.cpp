int find_path ( int a [ ] [ 100 ] , int p , int q , int n , int div [ ] [ 100 ] ) { int val1 , val2 ; if ( p > n ) return ( 0 ) ; if ( div [ p ] [ q ] != 0 ) return ( div [ p ] [ q ] ) ; val1 = find_path ( a , p + 1 , q , n , div ) ; div [ p + 1 ] [ q ] = 1 ; val2 = find_path ( a , p + 1 , q + 1 , n , div ) ; div [ p + 1 ] [ q + 1 ] = 1 ; if ( val1 > a [ p ] [ q ] ) { return ( a [ p ] [ q ] + val1 ) ; div [ p ] [ q ] = a [ p ] [ q ] + val1 ; } else { return ( a [ p ] [ q ] + val2 ) ; div [ p ] [ q ] = a [ p ] [ q ] + val2 ; } } int main ( ) { int i = 0 , j = 0 , k , num , rowmax , val , count , m = 0 ; int tri [ 100 ] [ 100 ] , div [ 100 ] [ 100 ] ; int result [ 1000 ] ; scanf ( "%d" , & num ) ; while ( m < num ) { for ( k = 0 ; k < 100 ; k ++ ) { for ( count = 0 ; count < 100 ; count ++ ) { div [ k ] [ count ] = 0 ; } } scanf ( "%d" , & rowmax ) ; for ( k = 0 ; k < rowmax ; k ++ ) { for ( count = 0 ; count <= k ; count ++ ) { scanf ( "%d" , & tri [ k ] [ count ] ) ; } } val = find_path ( tri , i , j , k , div ) ; printf ( "%d\n" , val ) ; } return ( 0 ) ; }