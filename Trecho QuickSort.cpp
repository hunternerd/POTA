//Fun��o Quicksort- rearranja os dados em parti��es menores
int particiona(int *V, int inicio, int final){
	int esq, dir, pivo, aux;
//Escolha do piv�
	esq = inicio;
	dir = final;
	pivo = V[inicio];
//Vari�vel esq ser� incrementada at� que se encontre uma posi��o com valor maior que o piv�
	while(esq < dir){
		while (V[esq] <= pivo)
			esq++;
//Vari�vel dir ser� decrementada at� que se encontre uma posi��o com valor menor ou igual ao piv�
		while (V[dir] > pivo)
			dir--;
//Compara��o de dir e esq, se esq for menor que dir os valores s�o trocados repetidamente
		if(esq < dir){
			aux = V[esq];
			V[esq] = V[dir];
			V[dir] = aux;
		}
	}
//Posi��o do inicio recebe o valor dir que recebe o valor do piv�
	V[inicio] = V[dir];
	V[dir] = pivo;
//Retorno do piv� escolhido
	return dir;
}
//Gerenciar a ordena��o de cada parti��o quicksort
void quicksort (int *V, int inicio, int fim){
	int pivo;
//Verifica se o array tem mais de um elemento
	if(fim > inicio){
//Quando h� mais de um elemento � calculado o piv�
		pivo = particiona(V, inicio, fim);
//Chama a si mesma para as duas parti��es criadas
		quicksort (V, inicio, pivo-1);
		quicksort(V, pivo+1, fim);
	}
}


