u_k = 1;
T_s = 1/100;
t_s = 1;
t_z=T_s/(T_s+t_s );
y_k(1) = 0;

for i=2:1000
y_k(i)=(1-t_z )*y_k(i-1)+t_z*u_k;
end

plot(y_k)