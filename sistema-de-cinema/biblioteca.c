#include <stdio.h>
#include <string.h>
#define QTD 50 // Defina o valor de qtd aqui
#define MAX_ID 99 // define quantos ids de filmes podem existir

int main(){
	int opc=0;
	int n=0;

	int id[QTD] = {0}, anoLancamento[QTD] = {0};
	char titulo[QTD][50], sinopse [QTD][255], genero[QTD][50];

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
			for(int i = 1; i <= 99; i++){
				if( id[i] == 0) {
					n=i;
					break;
				}
			}

			printf("CADASTRANDO FILME N^: %d %d", n, id[n]);
			id[n] =  id[n-1] + 1; //continua a seq. de id.
			
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
			
			opc=0; //retorna ao menu
		}

		if(opc==2)
		{
			//MODIFICAR
			//DIGITE O ID DO FILME A SER EDITADO:
			  //verifica se o id existe, se está no intervalo dos filmes criados.
			//EXIBIR AS INFORMAÇÕES ATUAIS DO FILME
			//APOS ISSO INICIA A EDIÇÃO
			

			printf("Digite o id do Filme para EDITAR: ");
			scanf("%d", &n);
			printf("\n");

			for(int i = 1; i <= MAX_ID; i++)
			{
				if( ( id[i] != 0 ) && ( id[i] == n ) )
				{
					//exibe info
					printf("EXIBINDO INFORMAÇÕES ATUAIS.\n");
					printf("TITULO : %s", titulo[n]);
					printf("GENERO : %s", sinopse[n]);
					printf("ANO : %d", anoLancamento[n]);

					printf("\n");

					printf("DIGITE AS NOVAS INFORMAÇÕES\n");
					getchar(); //limpar o buffer
					printf("TITULO: ");
					fgets(titulo[n], 50, stdin);
					printf("SINOPSE: ");
					fgets(sinopse[n], 50, stdin);
					printf("GENERO: ");
					fgets(genero[n], 50 , stdin);
					printf("ANO: ");
					scanf("%d", &anoLancamento);
					
					printf("INFORMAÇÕES MODIFICADAS\n");
					break;
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
           scanf("%d", &n);

           if ( ( n <= MAX_ID ) && ( n != 0 ) && id[n] != 0 ) //se satisfaz VAI existir um filme nesse id! 
             {
                //logica ir movendo do maior id para o menor. até que encontre um id=0
               while (n != 0)
                {
					//se o próximo id for 0, ou seja o fim, encerra o while.
                    if( id[n+1] == 0 )  
                    {
                    	id[n]=0;
                    	printf("EXCLUSAO CONCLUIDA");
                    	break;
                    }
                	//id deve permanecer o mesmo, oque muda são as informações
                    //titulo[n] = titulo[n+1];
                    //sinopse[n] = sinopse[n+1];
                    anoLancamento[n] = anoLancamento[n+1];
                    strcpy(titulo[n], titulo[n + 1]);
                    strcpy(sinopse[n], sinopse[n + 1]);
                    //anoLancamento[j] = anoLancamento[j + 1];
                    n++;
                }
             }
             else
             {
             	printf("NÃO É POSSIVEL DELETAR\nESSE ID NÃO EXISTE\n\n");
             }
    
          opc=0;
		}

		if(opc==4)
		{
			printf("===TODOS OS FILMES===\n");
			
			//se não houver nenhum filme alertar
			for(int i = 1; i <= MAX_ID; i++){
				if( id[i] == 0 ){
					printf("\nTODOS OS FILMES FORAM EXIBIDOS!\n\n");
					break;
				}
				printf("%d.%s", i, titulo[i] );
			}
			opc=0;
		}

		if(opc==5)
		{
			printf("ENCERRADO\n");
			break;
		}

	}
}
