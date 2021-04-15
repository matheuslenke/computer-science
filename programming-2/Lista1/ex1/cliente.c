#include "aluno.h"
#include "turma.h"
#include "curso.h"
#include "cursos.h"
#include <stdio.h>


int main(int argc, char const *argv[])
{
    tAluno aluno;

    // lerAluno(&aluno);
    // apresentarAluno(&aluno);

    FILE* file;
    tTurma turma;
    tCurso curso;
    tCursos cursos;
    file = fopen("entrada.txt", "r");
     if (file == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
    } 
    else {
        // lerTurma(&turma, file);
        // apresentarTurma(&turma);
        // printf("Agora ordenadas: \n");
       // lerCurso(&curso, file);
     //   apresentarCurso(&curso);
      //  ordernaTurma(&turma, comparaMatricula);
       // apresentarTurma(&turma);
       lerCodigos(&cursos, file);
       //apresentarCursos(&cursos);
       lerCursos(&cursos, file);
       apresentarCursos(&cursos);
    }
    return 0;
}
