int main ( ) { int testCases , sizeData , itrInner , itrOuter , max = 0 , addThis ; int data [ MAX ] [ MAX ] ; int maxPath [ MAX ] [ MAX ] ; scanf ( "%d" , & testCases ) ; while ( testCases -- ) { scanf ( "%d" , & sizeData ) ; for ( itrInner = 0 ; itrInner < sizeData ; itrInner ++ ) { for ( itrOuter = 0 ; itrOuter < sizeData ; itrOuter ++ ) { if ( itrOuter <= itrInner ) scanf ( "%d" , & data [ itrInner ] [ itrOuter ] ) ; else data [ itrInner ] [ itrOuter ] = 0 ; } } max = 0 ; for ( itrInner = 0 ; itrInner < sizeData ; itrInner ++ ) { for ( itrOuter = 0 ; itrOuter <= itrInner ; itrOuter ++ ) { if ( itrInner != 0 && itrOuter != 0 ) { addThis = ( maxPath [ itrInner - 1 ] [ itrOuter ] >= maxPath [ itrInner - 1 ] [ itrOuter - 1 ] ) ? maxPath [ itrInner - 1 ] [ itrOuter ] : maxPath [ itrInner - 1 ] [ itrOuter - 1 ] ; } else if ( itrInner == 0 && itrOuter == 0 ) addThis = 0 ; else if ( itrInner != 0 && itrOuter == 0 ) { addThis = maxPath [ itrInner - 1 ] [ itrOuter ] ; } maxPath [ itrInner ] [ itrOuter ] = data [ itrInner ] [ itrOuter ] + addThis ; } } for ( itrInner = 0 ; itrInner < sizeData ; itrInner ++ ) { if ( max < maxPath [ sizeData - 1 ] [ itrInner ] ) max = maxPath [ sizeData - 1 ] [ itrInner ] ; } printf ( "%d\n" , max ) ; } }