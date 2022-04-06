clc; clear;
% DN(gun)     X(deniz)       Y(elipsoit)

%%% Verileri *.txt içerisinden okuma yaptır %%%
T = readtable('bitirme.txt');

%%% Özellikle işlem yapılmak istenilen yerleri al %%%
% X = deniz yüksekliği
X = T(1:5,2:2);
% Y = elipsoit yüksekliği
Y = T(1:5,3:3);

%%% table to array yap %%%
% X değerlerini array yap
X = table2array(X);
% Y değerlerini array yap
Y = table2array(Y);

X + Y


