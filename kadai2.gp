set terminal eps color enhanced
set output "kadai2_b025.eps"
set xlabel "x"
set ylabel "u"
set key 
plot "kadai2_b025_10.txt" title "{t=10}" with lines  linewidth 5 ,\
"kadai2_b025_20.txt" title "{t=20}" with lines  linewidth 5 ,\
"kadai2_b025_30.txt" title "{t=30}" with lines  linewidth 5 ,\
"kadai2_b025_40.txt" title "{t=40}" with lines  linewidth 5