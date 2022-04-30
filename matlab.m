clc; clear;

%%% Özellikle işlem yapılmak istenilen yerleri al %%%
% DN => gün
% X => elipsoit yüksekliği
% Y => deniz yüksekliği

%%% Verileri çek
filename = 'data.xlsx';
data_source = xlsread(filename);


[n,m] = size(data_source);
for i = 1:n;

    X(i,1) = data_source(i,2);
    Y(i,1) = data_source(i,3);


    i = i + 1;
end


toplam = 0;

for i = 1:n;

    %fprintf("i: %.3d\n", i);

    for j = 1:n;

        %fprintf("j: %.3d\n", j);

        if (i<j)

            aa = 0;
            aa = X(i,1) - X(j,1);
            %fprintf("aa: %4.7f\n", aa);
            if(aa>0.00000)
                aa=1;
            elseif (aa<0.000000)
                aa=-1;
            else
                aa=0;
            end
            %fprintf("aa: %4.7f\n", aa);

            bb = 0;
            bb = Y(i,1) - Y(j,1);
            %fprintf("bb: %4.7f\n", bb);
            if(bb>0.00000)
                bb=1;
            elseif (bb<0.000000)
                bb=-1;
            else
                bb=0;
            end
            %fprintf("bb: %4.7f\n", bb);

            toplam = toplam + aa * bb;
            %fprintf("aa*bb: %4.7f\n", aa*bb);

        end

    end

    K = (2.0 / (n*(n-1.0))) * toplam;
    %fprintf("%.3d K: %4.13f\n", i, K);

    grafik(i,1) = K;

    i = i + 1;

end

fprintf("Kendall: %4.13f\n", K);

