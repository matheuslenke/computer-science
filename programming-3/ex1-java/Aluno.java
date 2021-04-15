public class Aluno {
  String nome;
  double nota;

  public Aluno(String nome, double nota) {
    this.nome = nome;
    this.nota = nota;
  }

  String obterNome() {
    return nome;
  }

  double obterNota() {
    return nota;
  }

  public int compareTo(Aluno outro) {
    return this.nome.compareTo(outro.nome);
  }

}