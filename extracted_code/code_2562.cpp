int temp = 0 ; void recursion ( int * arr , int n , int s , int count ) { if ( count == n - 1 ) { temp = ( s > temp ) ? s : temp ; } else { s = s + * arr ; recursion ( arr + n , n , s , count + 1 ) ; recursion ( arr + n + 1 , n , s , count + 1 ) ; } } void main ( ) { int n , i , j , s = 0 , count = - 1 , m ; scanf ( "%d" , & m ) ; while ( m -- ) { scanf ( "%d" , & n ) ; int arr [ n ] [ n ] ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & arr [ i ] [ j ] ) ; recursion ( & arr [ 0 ] [ 0 ] , n , s , count ) ; printf ( "%d\n" , temp ) ; } }