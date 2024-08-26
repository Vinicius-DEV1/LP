#include <stdio.h>

//começar do id 1

int main(){
	int opc=0;
	int n=0;

	#define qtd 50 // Defina o valor de qtd aqui
	#define MAX_ID 99 // define quantos ids de filmes podem existir

	int id[qtd] = {0}, anoLancamento[qtd];
	char titulo[qtd][50], sinopse [qtd][255], genero[qtd][50];

	while(opc != 5)
	{
		printf("1.Cadastar Filme\n");
		printf("2.Editar Filme\n");
		printf("3.Deletar Filme\n");
		printf("4.Exibir todos os filmes\n");
		printf("5.Sair\n");
		printf("Digite uma opcao: ");
		scanf("%d", &opc);
		printf("\n");

		if(opc==1)
		{
			/*
			procurar o primeiro id = 0.
			percorrer o vetor do inicio até encontrar um id=0;
			apos encontrar soma o anterior + 1
			*/
			for(int i=0; i<=99; i++){
				if(id[i]==0){
					n=i;
					break;
				}
			}

			printf("DEBUG: %d\n", n);
			id[n] =  id[n-1] + 1;
			
			printf("===CADASTRAR FILME===\n");
			printf("Informações sobre o filme\n");
			printf("Digite o Titulo: ");
			getchar(); //limpar o buffer
			fgets(titulo[n], 50, stdin);
			//scanf("%[^\n]", titulo[n]);
			printf("Digite a Sinopse: ");
			fgets(sinopse[n], 50, stdin);
			//scanf("%[^\n]", sinopse[n]);
			printf("Digite o ano de Lançamento: ");
			scanf("%d", &anoLancamento[n]);
			printf("CADASTRADO COM SUCESSO!!!\n");
			opc=0;
		}

		if(opc==2)
		{
			//MODIFICAR
			//DIGITE O ID DO FILME A SER EDITADO:
			  //verifica se o id existe, se está no intervalo dos filmes criados.
			//EXIBIR AS INFORMAÇÕES ATUAIS DO FILME
			//APOS ISSO INICIA A EDIÇÃO

			printf("Digite o id do Filme: ");
			scanf("%d", id_buscar);

			for(int i = 0; i <= MAX_ID; i++)
			{
				if(id != 0 && id==id_buscar)
				{
					//exibe info
					printf("EXIBINDO INFORMAÇÕES ATUAIS.")
					printf("TITULO %d \n", titulo[id]);
					printf("GENERO\n", );
					printf("ANO\n", );

					printf("\n");

					printf("DIGITE AS NOVAS INFORMAÇÕES\n")
					printf("TITULO\n");
					fgets(titulo[id],50,stdin)
					printf("GENERO\n");
					fgets(genero[id],50, stdin);
					printf("ANO\n");
					scanf("%d", &anoLancamento);
					
					printf("INFORMAÇÕES MODIFICADAS\n");
				}
			}

			opc=0;
		}

		if(opc==3)
		{
			//como deletar???
			//vai movendo as informações
            //recebe o id
            //primeiro verificar se o id existe,com um for que vai do id escolhido até o max, e verifica se o id != 0.


           //a partir dela vai movedando o da direita para esquerda ou seja, em um while enquanto id != 0
           //titulo[remover] = titulo[substituo], id=[remover] = id[substituto]
           printf("DIGITE O ID DO FILME A SER DELETADO!");
           scanf("%d", id_buscar);

           if (id_buscar <= MAX_ID && id_buscar != 0) //se satisfaz existe um filme nesse id! 
             {
                //logica ir movendo do maior id para o menor. até que encontre um id=0
               while (id_buscar != 0)
                {
					//se o próximo id for 0, ou seja o fim, encerra o while.
                    if(id_buscar+1 != id_buscar+1)
                    {
                    	break;
                    }

                	//id deve permanecer o mesmo, oque muda sao as informações
                    titulo[id_buscar] = id[id_buscar+1]
                    id_buscar++;
                    opc=0;


                }
             }
             else
             {
             	printf("NÃO É POSSIVEL DELETAR\nESSE ID NÃO EXISTE\n");
             }
    

		}

		if(opc==4)
		{
			printf("===TODOS OS FILMES===\n");
			
			for(int i=0; i <= MAX_ID; i++){
				printf("%d.%s", i, titulo[i]);
				opc=0;
				if(id[i]==0){
					printf("\n");
					break;
				}
			}
		}

		if(opc==5)
		{
			printf("ENCERRADO\n");
			break;
		}

	}
}
