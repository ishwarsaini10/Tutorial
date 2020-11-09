
set terminal postscript enhanced color solid 22
set output "bessels_v2.ps"
set format y "%0.2e"
set logscale y
set title "Bessels Function using Backward and Upward Recursions"
set xlabel  "l-values"
set ylabel  "|j_{l}^{(up)}-j_{l}^{(down)}|/|j_{l}^{(up)}|+|j_{l}^{(down)}|"
set yrange [10**-7:100]
plot "Bessels.txt" u 1:4 title "Erros" w lp ls 2
set term x11
