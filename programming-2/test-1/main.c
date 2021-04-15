#include <stdio.h>
#include "Catalogo.h"
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
/**
 * Modificações do trabalho:
 * Modificação na ordenação a e b, antes o vetor estava pegando a quantidade certa, mas ao inves de pegar os "mais caros em ordem decrescente
 * " por exemplo. A ordenação estava correta, mas as quantidades não. O que eu fiz foi inverter o loop, começando a partir do ultimo
 * elemento e inserindo até o 0, pegando assim de forma correta.
 * A ordenação também não estava genérica
 * A ordenação c foi o mesmo caso, porém não estava retornando todas as casas dentro do limite provavelmente por um erro
 * de operação matemática ali, porque eu só coloquei as contas em uma variável externa antes e ele conseguiu comparar direito
 *
 */
int main() {

    //Lendo o catalogo
    tCatalogo* catalogo;
    char catalogo_path[150];
//    scanf("%s", catalogo_path);
//    FILE* arq_catalogo = fopen(catalogo_path, "r");
   FILE* arq_catalogo = fopen("../catalogo.txt", "r");
    if (!arq_catalogo) {
        printf("falhou em abrir catalogo.txt");
        exit(1);
    }
    catalogo =leCatalogo(arq_catalogo, catalogo);
    fclose(arq_catalogo);

    //Atualizando o catalogo
    char atual_path[150];
//    scanf("%s", atual_path);
//    FILE* arq_atual = fopen(atual_path, "r");
    FILE* arq_atual = fopen("../atual.txt", "r");
    if (!arq_atual) {
        printf("falhou em abrir atual.txt");
        exit(1);
    }
    catalogo = atualizaCatalogo(arq_atual, catalogo);
    fclose(arq_atual);

    // Ordenando com as especificacoes!
    char spec_path[150];
//    scanf("%s", spec_path);
//    FILE* arq_spec = fopen(spec_path, "r");
    FILE* arq_spec = fopen("../espec.txt", "r");
    if (!arq_spec) {
        printf("falhou em abrir spec.txt");
        exit(1);
    }
    OrdenaCatalogoSpec(arq_spec, catalogo);
    fclose(arq_spec);
    liberaCatalogoTodo(catalogo);

    return 0;
}