#!/usr/bin/perl -w

$argc = @ARGV;

if ( $argc != 1 ) {
   die "need one arg\n";
}

open( INPUT, $ARGV[0] ) or die "Can't open file $ARGV[0]\n";
while ( $line1 = <INPUT> ) {
   if ( $line1 =~ m/SIMPLE_INCLUDE ([A-Za-z0-9_\-\.\/]*)/ ) {
      open( INPUT2, $1 ) or die "Can't open file $1\n";
      while ( $line2 = <INPUT2> ) {
          print $line2;
      }
      close( INPUT2 );
   }
   else {
      print $line1;
   }
}
close( INPUT );

