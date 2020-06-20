//Intercalação dos dados dos arrays de forma ordenada em um array maior
void merge (int *V, int inicio, int meio , int fim){
	int *temp, p1, p2, tamanho, i ,j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio+1;
	temp = (int *) malloc (tamanho*sizeof(int));
	if(temp != NULL){
		for(i=0; i<tamanho; i++){
			if(!fim1 && !fim2){
//Menor elemento inserido em temp e verificação de qual array tem o menor elemento
				if(V[p1] < V[p2])
					temp[i]=V[p1++];
				else
					temp[i]=V[p2++];
//Utilizado caso o array chegue ao final	
				if(p1>meio) fim1=1;
				if(p2>fim) fim2=1;
			} else {
//Copia o restante do array que sobrou para o final de temp
				if(!fim1)
					temp[i]=V[p1++];
				else
					temp[í]=V[p2++];
			}
		}
//Copia os dados de temp para o array original
		for(j=0, k=inicio; j<tamanho; j++, k++)
			V[k]=temp[j];
	}
	free(temp);
}
//Divisão dos dados em arrays cada vez menores
void mergesort(int *V, int inicio, int fim){
	int meio;
//Função mergesort divide o array ao meio se tiver mais de um elemento
	if(inicio < fim){
//Se tiver mais de um elemento, é calculado o valor que corresponde ao meio do array
		meio = floor((inicio+fim)/2);
//Chama a si própria para as duas metades
		mergesort(V,inicio,meio);
		mergesort(V,meio+1,fim);
//Termino da recursão e inicio da intercalação dos arrays pela função
		merge(V,inicio,meio,fim);
	}
}



