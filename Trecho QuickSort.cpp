//Função Quicksort- rearranja os dados em partições menores
int particiona(int *V, int inicio, int final){
	int esq, dir, pivo, aux;
//Escolha do pivô
	esq = inicio;
	dir = final;
	pivo = V[inicio];
//Variável esq será incrementada até que se encontre uma posição com valor maior que o pivô
	while(esq < dir){
		while (V[esq] <= pivo)
			esq++;
//Variável dir será decrementada até que se encontre uma posição com valor menor ou igual ao pivô
		while (V[dir] > pivo)
			dir--;
//Comparação de dir e esq, se esq for menor que dir os valores são trocados repetidamente
		if(esq < dir){
			aux = V[esq];
			V[esq] = V[dir];
			V[dir] = aux;
		}
	}
//Posição do inicio recebe o valor dir que recebe o valor do pivô
	V[inicio] = V[dir];
	V[dir] = pivo;
//Retorno do pivô escolhido
	return dir;
}
//Gerenciar a ordenação de cada partição quicksort
void quicksort (int *V, int inicio, int fim){
	int pivo;
//Verifica se o array tem mais de um elemento
	if(fim > inicio){
//Quando há mais de um elemento é calculado o pivô
		pivo = particiona(V, inicio, fim);
//Chama a si mesma para as duas partições criadas
		quicksort (V, inicio, pivo-1);
		quicksort(V, pivo+1, fim);
	}
}


