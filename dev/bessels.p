set terminal postscript enhanced color solid 22
set output "bessels_v1.ps"
set format y "%0.2e"
set logscale y
set title "Bessels Function using Backward and Upward Recursions"
set xlabel  "l-values"
set ylabel  "j_{l}^{(up)}/j_{l}^{(down)}"
plot "Bessels.txt" u 1:3 title "Downward Recursion", "Bessels.txt" u 1:2 title "Upward Recursion"
set term x11
