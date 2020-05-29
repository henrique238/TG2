clc;
clear;

Fs = 1/17.0e-6;
Fb = 3900;
Fh = 4100;
n = 2;
[b,a] = butter(n,[Fb Fh]/(Fs/2));

t = 0:1/Fs:0.05;
freq=4000;
x=0;

s = sawtooth(2*pi*100*t+pi);
m = 0.75*sin(2*pi*1000*t);
n = length(s);

for i=1:n
    if m(i)>=s(i)
        pwm(i)=1;
    elseif m(i)<=s(i)
        pwm(i)=0;
    end
end
x = pwm;

      
%for j = 1:+2:15
      
      %x = (1/j)*sin(2*pi*j*freq*t)+x;
%end

N = length(t);

y = zeros(1,N);
for i = 5:N
    
%0.15e-6    %y(i) = 1.0e-03*0.0877*x(i) - 1.0e-03*0.1753*x(i-2) + 1.0e-03*0.0877*x(i-4) +...
                   %3.6945*y(i-1) - 5.3858*y(i-2) + 3.6456*y(i-3) - 0.9737*y(i-4);
            %0.0001         0   -0.0002         0    0.0001    1.0000   -3.6945    5.3858   -3.6456    0.9737

             y(i) = 0.0001*x(i) - 0.0002*x(i-2) + 0.0001*x(i-4) +...
                    3.6131*y(i-1) - 5.2337*y(i-2) + 3.5590*y(i-3) - 0.9702*y(i-4);
%0.17e-6    %0.0001         0   -0.0002         0    0.0001    1.0000   -3.6131    5.2337   -3.5590    0.9702
end

gain = 1.33779;

y = gain*y;

figure(1);
subplot(2,1,1);
plot(t,x)
grid on;
subplot(2,1,2);
plot(t,y)
grid on;

X = 2*abs( fft(x) )/ N;
Y = 2*abs( fft(y) )/ N;
f = (0:(N/2))*Fs/N;

figure(2);
plot(f,X(1:N/2+1),f,Y(1:N/2+1));
grid on;