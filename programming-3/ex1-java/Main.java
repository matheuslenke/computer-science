import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) throws Exception {
    String nomeArquivo;

    Scanner scanner;

    if(args.length > 0) {
      nomeArquivo = args[0];
    }
    else {
      scanner = new Scanner(System.in);
      nomeArquivo = scanner.nextLine();
      scanner.close();
    }

    scanner = new Scanner(new File(nomeArquivo));
    int numAlunos = scanner.nextInt();
    scanner.nextLine();

    Aluno[] alunos = new Aluno[numAlunos];
    int idx = 0;

    while(scanner.hasNextLine()) {
      double nota = scanner.nextDouble();
      String nome = scanner.nextLine();
      alunos[idx++] = new Aluno(nome, nota);
    }

    scanner.close();

    for(Aluno aluno: alunos) {
      System.out.printf("O aluno %s tirou a nota %.2f\n", aluno.obterNome());
      aluno.obterNota();
    }

    PrintWriter out = new PrintWriter(new File("saida.csv"));
    out.println("Nome, Nota, Situação\n");
    for( Aluno aluno: alunos) {
      if (aluno.obterNota() >= 7.0) out.printf("%s,%.2lf,Aprovado\n",
      aluno.obterNome(), aluno.obterNota());
      else out.printf("%s,%.2f,Prova Final\n",
      aluno.obterNome(), aluno.obterNota());
    }
    out.close();
  }
}