close all;
clear all;
filename = "../build_pc/pc/Control signal_PID Controller_Drone Pitch Controller_Drone controller_.txt"
A = readmatrix(filename);
size_of = size(A,1);
sample_time = 1/100;

plot(A)

