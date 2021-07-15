-module(tut1).

-export([fac/1, mult/2]).

% O ; diz que a função fac não termina sua definição só no primeiro termo
fac(1) -> 1;
fac(N) -> N * fac(N - 1).

mult(X, Y) -> X * Y.
% o ponto final indica que não tem mais partes nessa função