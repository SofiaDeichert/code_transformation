int main ( ) { int numOfLines ; int triHeight ; int triangles [ 1000 ] [ 1000 ] = { 0 } ; scanf ( "%d" , & numOfLines ) ; while ( numOfLines > 0 ) { scanf ( "%d" , & triHeight ) ; int i = 0 ; int j ; while ( i < triHeight ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & triangles [ i ] [ j ] ) ; } i ++ ; } triHeight -= 2 ; while ( triHeight >= 0 ) { for ( j = 0 ; j <= triHeight ; j ++ ) { int currentNumber = triangles [ triHeight ] [ j ] ; int leftBelow = triangles [ triHeight + 1 ] [ j ] + currentNumber ; int rightBelow = triangles [ triHeight + 1 ] [ j + 1 ] + currentNumber ; triangles [ triHeight ] [ j ] = leftBelow > rightBelow ? leftBelow : rightBelow ; } triHeight -- ; } printf ( "%d" , triangles [ 0 ] [ 0 ] ) ; numOfLines -- ; } return 0 ; }