int arr [ 100100 ] [ 101 ] , indArr [ 1005 ] ; int init ( ) { int i = 0 , j = 0 ; for ( ; i < 100100 ; i ++ ) { for ( ; j < 101 ; j ++ ) arr [ i ] [ j ] = - 1 ; } for ( i = 0 ; i < 1005 ; i ++ ) indArr [ i ] = - 1 ; indArr [ 0 ] = 0 ; } int findMax ( int index , int rowC ) { int indexM = 0 , i = 0 ; for ( ; i <= rowC ; i ++ ) { if ( arr [ index ] [ i ] > arr [ index ] [ indexM ] ) indexM = i ; } return indexM ; } int findMax2 ( int index , int rowC ) { if ( rowC == 0 ) return rowC ; else if ( arr [ index ] [ rowC ] == - 1 ) return rowC - 1 ; else { if ( arr [ index ] [ rowC ] > arr [ index ] [ rowC - 1 ] ) return rowC ; else return rowC - 1 ; } } void SumMaxLength ( int startI , int rowC ) { int sumMax = 0 , j = rowC - 2 , indexM = 0 ; indexM = findMax ( startI + rowC - 1 , rowC ) ; sumMax = arr [ startI + rowC - 1 ] [ indexM ] ; for ( ; j >= 0 ; j -- ) { indexM = findMax2 ( startI + j , indexM ) ; sumMax += arr [ startI + j ] [ indexM ] ; } printf ( "%d\n" , sumMax ) ; } int main ( ) { int i = 0 , cnt = 0 , len = 0 , val , j = 0 , indarr = 0 ; scanf ( "%d" , & cnt ) ; indArr [ indarr ++ ] = 0 ; while ( cnt -- ) { scanf ( "%d" , & val ) ; indArr [ indarr ] = indArr [ indarr - 1 ] + val ; len = 1 ; while ( val -- ) { for ( j = 0 ; j < len ; j ++ ) scanf ( "%d" , & arr [ i ] [ j ] ) ; i ++ ; len ++ ; } SumMaxLength ( indArr [ indarr - 1 ] , indArr [ indarr ] - indArr [ indarr - 1 ] ) ; indarr ++ ; } return 0 ; }