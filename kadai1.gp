set terminal eps color enhanced
set output "kadai1_3.eps"
set xlabel "x"
set ylabel "u"
set key 
plot "kadai1_3_1.txt" title "{t=1}" with lines  linewidth 5 ,\
"kadai1_3_2.txt" title "{t=2}" with lines  linewidth 5 ,\
"kadai1_3_3.txt" title "{t=3}" with lines  linewidth 5 ,\
"kadai1_3_4.txt" title "{t=4}" with lines  linewidth 5 ,\
"kadai1_3_5.txt" title "{t=5}" with lines  linewidth 5