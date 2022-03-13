
clear s

% Script usado para leer la informacion del puerto serial por donde manda
% datos Arduino
s = serialport("COM3",9600); %Abro el puerto serial
ts = 0.1; % Defino el periodo de muestreo usado en el arduino
temp =  [];
tic
for i = 1:1:200/ts
data = readline(s); % Leeo la data
temp(i) = str2num(data)   % la convierto a numero
end
toc
t = [0:1:length(temp)-1]*ts;  % Defino el vector tiempo en [s]

plot(t,temp) 
xlabel('Segundos[s]')
ylabel('Temperatura[°C]')

