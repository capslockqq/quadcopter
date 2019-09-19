% pt = [0 0 0];
% dir = [1 1 0 1];
% h = quiver3(pt(1),pt(2),pt(3), dir(1),dir(2),dir(3));
% xlim([-1 1])
% ylim([-1 1])
% zlim([-1 1])

% Generates a random signal to display
% a = randn(1,1e5);
% a = cumsum(a);  %I want some correlation in the signal...
% fs = 2e3;  %sampling frequency
% timeBase = 2;   %sec
% hF = figure;
% hAx = gca;
% N = length(a);
% maxA = max(a);  minA = min(a);
% nSamples = round(fs*timeBase);
% ind = 1;
% hLine = plot(hAx,(1:nSamples)/fs,a(:,ind:ind+nSamples-1));
% xlabel('[sec]');
% ylim([minA maxA]);
% tic;    %start time measuring
% % I added the "ishandle" so the program will end in case u closed the figure
% while (ind < N-nSamples) & ishandle(hLine)
%   
%    %instead of using plot I directly change the data in the line
%    % this is faster the plot if only because you don't need to reedefine the limits and labels...
%    set(hLine,'ydata',a(:,ind:ind+nSamples-1));
%    
%    drawnow  %updates the display
%    
%    t = toc; %measuring current time
%    ind = round(t*fs); 
%    ind = max(ind,1);
%    
% end
% close all;
% clear all;
% data = readmatrix('data.txt');
% data_length = length(data);
% 
% hLine = plot(data)
% pause(2);
% data = readmatrix('data.txt');
% if length(data) > data_length
%     set(hLine, data)
%     drawnow
% end
h = animatedline;

data = readmatrix('data.txt');
data_length = length(data);
k = 1;
while k < data_length
    
    addpoints(h,k, data(k));
    drawnow
    if k == data_length-1
        pause(0.05);
        data = readmatrix('data.txt'); 
        if length(data) > data_length
            display(length(data))
            display(data_length)
            data_length = length(data);
        end
    end
    k = k + 1;
end


