int main ( ) { int ic , ir , r , n , a [ 100 ] [ 100 ] , max , i , b , br , c , colast , icol ; int s , paths ; scanf ( "%d" , & c ) ; for ( ic = 1 ; ic < c + 1 ; ic ++ ) { scanf ( "%d" , & n ) ; for ( ir = 1 ; ir < n + 1 ; ir ++ ) { for ( icol = 1 ; icol < ir + 1 ; icol ++ ) { fscanf ( stdin , "%d" , & a [ ir ] [ icol ] ) ; } } max = 0 ; paths = 1 ; for ( i = 1 ; i < n + 1 ; i ++ ) { paths = paths * 2 ; } for ( i = 0 ; i < paths ; i ++ ) { colast = 1 ; s = a [ 1 ] [ 1 ] ; br = i ; for ( ir = 2 ; ir < n + 1 ; ir ++ ) { b = br - 2 * ( br / 2 ) ; br = br / 2 ; c = colast + b ; colast = c ; s = s + a [ ir ] [ c ] ; } if ( s > max ) max = s ; } printf ( "%d " , max ) ; } return 0 ; }