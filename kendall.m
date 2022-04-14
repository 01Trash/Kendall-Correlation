clc; clear;
% DN(gun)     X(deniz)       Y(elipsoit)

%%% Verileri *.txt içerisinden al %%%
T = readtable('bitirme.txt');

%%% Özellikle işlem yapılmak istenilen yerleri al %%%
% DN = gün
DN = T(1:5,1:1);
% X = deniz yüksekliği
X = T(1:5,2:2);
% Y = elipsoit yüksekliği
Y = T(1:5,3:3);

%%% table to array yap %%%
% DN table to array yap
DN = table2array(DN);
% X table to array yap
X = table2array(X);
% Y table to array yap
Y = table2array(Y);









