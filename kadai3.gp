set terminal eps color enhanced
set output "kadai3.eps"
set xlabel "x"
set ylabel "u"
set key 
plot "kadai3_1.txt" title "{t=1}" with lines  linewidth 5 ,\
"kadai3_2.txt" title "{t=2}" with lines  linewidth 5 ,\
"kadai3_3.txt" title "{t=3}" with lines  linewidth 5 ,\
"kadai3_4.txt" title "{t=4}" with lines  linewidth 5,\
"kadai3_5.txt" title "{t=5}" with lines  linewidth 5,\
"kadai3_6.txt" title "{t=6}" with lines  linewidth 5,\
"kadai3_7.txt" title "{t=7}" with lines  linewidth 5,\
"kadai3_8.txt" title "{t=8}" with lines  linewidth 5,\