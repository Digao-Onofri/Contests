memo[size];
vet[size];

memo[0] = vet[0];
memo[1] = max(vet[0], vet[i]);
for(i = 2; i < size; i++){
    memo[i] = max(memo[i - 1], vet[i] + memo[i - 2]);
}

memo[size];