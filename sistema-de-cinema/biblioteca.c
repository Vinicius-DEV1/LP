#include <stdio.h>
#include <string.h>
#define QTD 50 
#define MAX_ID 99

int main(){
	int opc = 0;
	int n = 0;

	int id[QTD] = {0}, anoLancamento[QTD] = {0};
	char titulo[MAX_ID][50], sinopse [MAX_ID][255], genero[MAX_ID][50];

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

		if( opc == 1 )
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
			fgets(titulo[n], QTD, stdin);
			printf("Digite a Sinopse: ");
			fgets(sinopse[n], 50, stdin);
			printf("Digite o genero: ");
			fgets(genero[n], 50, stdin);
			printf("Digite o ano de Lançamento: ");
			scanf("%d", &anoLancamento[n]);
			printf("CADASTRADO COM SUCESSO!!!\n\n");
			
			opc=0; //retorna ao menu
		}

		if( opc == 2 )
		{			
			printf("Digite o id do Filme para EDITAR: ");
			scanf("%d", &n);
			printf("\n");

			for( int i = 1; i <= MAX_ID; i++ )
			{
				if( ( id[i] != 0 ) && ( id[i] == n ) )
				{
					printf("EXIBINDO INFORMAÇÕES ATUAIS.\n");
					printf("TITULO : %s", titulo[n]);
					printf("SINOPSE : %s", sinopse[n]);
					printf("GENERO : %s", genero[n]);
					printf("ANO : %d", anoLancamento[n]);

					printf("\n");

					printf("DIGITE AS NOVAS INFORMAÇÕES\n");
					getchar(); //limpar o buffer
					printf("TITULO: ");
					fgets(titulo[n], QTD, stdin);
					printf("SINOPSE: ");
					fgets(sinopse[n], QTD, stdin);
					printf("GENERO: ");
					fgets(genero[n], QTD , stdin);
					printf("ANO: ");
					scanf("%d", &anoLancamento);
					
					printf("INFORMAÇÕES MODIFICADAS COM SUCESSO\n");
					break;
				}
			}

			opc=0;
		}

		if(opc==3)
		{
           printf("DIGITE O ID DO FILME A SER DELETADO!");
           scanf("%d", &n);

           if ( ( n <= MAX_ID ) && ( n != 0 ) && id[n] != 0 ) //se satisfaz VAI existir um filme nesse id! 
             {
               while (n != 0)
                {
                    if( id[n+1] == 0 )  
                    {
                    	id[n]=0;
                    	printf("EXCLUSAO CONCLUIDA");
                    	break;
                    }
                    anoLancamento[n] = anoLancamento[n+1];
                    strcpy(titulo[n], titulo[n + 1]);
                    strcpy(sinopse[n], sinopse[n + 1]);
                    strcpy(genero[n], genero[n + 1]);
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
			for(int i = 1; i <= MAX_ID; i++)
			{
				if( id[i] == 0 ){
					printf("TODOS OS FILMES FORAM EXIBIDOS!\n\n");
					break;
				}
				printf("%d.%s", i, titulo[i] );
				printf("SINOPSE: %s", sinopse[i]);
				printf("GENERO: %s", genero[i]);
				printf("ANO DE LANÇAMENTO: %d\n\n", anoLancamento[i]);
			}
			opc=0;
		}

		if(opc==5)
		{
			printf("PROGRAMA ENCERRADO!!!\n");
			break;
		}

	}
}
