m = 0.5;
l = 0.25;
I_xx = 0.0196;
I_yy = I_xx;
I_zz = 0.0264;
Jr = 0.001;
T = [7.39, 5.39, 5.39, 5.39];
b = 3.0 *10^-5;
d = 1.1*10^-6;
R = sqrt(T/b);
Omega_r = sqrt(R(1)^2-R(2)^2+R(3)^2-R(4)^2);
Omega = sqrt(R.^2);
U1 = b*(Omega(1)^2+Omega(2)^2+Omega(3)^2+Omega(4)^2);
U2 = b*(-Omega(4)^2+Omega(4)^2);
U3 = b*(Omega(1)^2-Omega(3)^2);
U4 = d*(-Omega(1)^2+Omega(2)^2-Omega(3)^2+Omega(4)^2);


g = 9.82;
roll_vel = 0;
pitch_vel = 0;
yaw_vel = 0;


ux = cos(roll_vel)*sin(pitch_vel)*cos(yaw_vel)+sin(roll_vel)+sin(yaw_vel);
uy = cos(roll_vel)*sin(pitch_vel)*cos(yaw_vel)-sin(roll_vel)+sin(yaw_vel);

roll_acc(1) = pitch_vel*yaw_vel*((I_yy-I_zz)/I_xx)+pitch_vel*(Jr/I_xx)*Omega_r+(l/I_xx)*U2;
pitch_acc(1) = roll_vel*yaw_vel*((I_zz-I_xx)/I_yy)+roll_vel*(Jr/I_yy)*Omega_r+(l/I_yy)*U2;
yaw_acc(1) = pitch_vel*yaw_vel*((I_xx-I_yy)/I_zz) + (1/I_zz)*U4;

z_acc(1) = g - (cos(roll_vel)*cos(pitch_vel))*(U1/m)
x_acc(1) = ux*(U1/m)
y_acc(1) = uy*(U1/m)



