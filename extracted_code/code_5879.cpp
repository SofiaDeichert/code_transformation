int Sum_of_triangle ( int * * arr , int j , int i , int n ) { if ( i == n ) return 0 ; int a , b ; a = Sum_of_triangle ( arr , j , i + 1 , n ) ; b = Sum_of_triangle ( arr , 1 + j , i + 1 , n ) ; if ( a > b ) return arr [ i ] [ j ] + a ; else return arr [ i ] [ j ] + b ; } int main ( ) { int t , n , * * arr ; int i , j ; scanf ( "%d" , & t ) ; while ( t -- ) { i = 0 ; scanf ( "%d" , & n ) ; arr = ( int * * ) malloc ( sizeof ( int * ) * n ) ; while ( i < n ) { arr [ i ] = ( int * ) malloc ( sizeof ( int ) * ( i + 1 ) ) ; i ++ ; } i = 0 ; while ( i < n ) { j = 0 ; while ( j < i + 1 ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; j ++ ; } i ++ ; } printf ( "%d\n" , Sum_of_triangle ( arr , 0 , 0 , n ) ) ; free ( arr ) ; } return 0 ; }