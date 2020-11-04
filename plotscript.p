set output "Errors_in_series_sum.eps"
set title "Errors in Series Sum"
set xlabel "log_{10}(N)"
set ylabel "log_{10}((S^{(1)}_N-S^{(3)}_N)/S^3_N)"
set yrange [-1:0]
plot "series1.txt" u 1:2
set term x11
