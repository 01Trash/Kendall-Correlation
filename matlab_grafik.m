clc; clear;

%%% Özellikle işlem yapılmak istenilen yerleri al %%%
% DN => gün
% X => elipsoit yüksekliği
% Y => deniz yüksekliği

%%% Verileri çek
filename = 'data_grafik.xlsx';
data_source = xlsread(filename);


[n,m] = size(data_source);
for i = 1:n;

    %X(i,1) = logical(data_source(i,2));
    X(i,1) = log(data_source(i,2));
    Y(i,1) = data_source(i,3);


    i = i + 1;
end

y = [X, Y];
bar(y);
legend({'Elipsoit Yüksekliği','Deniz Yüksekliği'}, 'Location', 'north');
title('Elipsoit Yüksekliği - Deniz Yüksekliği');



